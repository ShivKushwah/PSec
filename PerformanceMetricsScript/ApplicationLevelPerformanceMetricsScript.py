import re
import subprocess
import time
import json
import statistics 
import time
import os
import sys

if (len(sys.argv) != 6):
    print("Insufficient arguments!")
    sys.exit()

example_name = sys.argv[1]
mode = sys.argv[2]
local_or_distributed = sys.argv[3]
num_iterations = int(sys.argv[4])
host = sys.argv[5]

is_civitas = False
is_otp = False
is_perf_metrics_example = False
is_sim = False
is_local = False
is_host1 = False 
is_host2 = False

if (example_name == 'CIVITAS'):
    is_civitas = True
elif (example_name == 'OTP'):
    is_otp = True
elif (example_name == 'PERF_METRICS'):
    is_perf_metrics_example = True
else:
    print("Example not supported!")
    sys.exit()

if (mode == 'SIM'):
    is_sim = True
elif (mode == 'HW'):
    is_sim = False
else:
    print("Incorrect SIM/HW argument!")
    sys.exit()

if (local_or_distributed == 'LOCAL'):
    is_local = True
elif (local_or_distributed == 'DIST'):
    is_local = False
else:
    print("Incorrect SIM/HW argument!")
    sys.exit()

if num_iterations <= 0:
    print("Invalid number of iterations!")
    sys.exit()

if (host == 'host1'):
    is_host1 = True
    host_num = 1
elif (host == 'host2'):
    is_host2 = True
    host_num = 2


# num_iterations = 2

# is_sim = False
# is_sim = True


# is_civitas = False
# is_otp = True

#Move program to root context
os.chdir('..')

if is_host1:
    if is_perf_metrics_example:
        host_lst = ['MEASURE UNTRUSTED CREATE START', 'MEASURE UNTRUSTED CREATE SSM START', 'MEASURE TRUSTED CREATE START', 'MEASURE TRUSTED SEND START', 'MEASURE TRUSTED SEND 2 START', 'MEASURE UNTRUSTED SEND END', 'MEASURE UNTRUSTED SEND 2 END']
    else:
        host_lst = []
elif is_host2:
    if is_perf_metrics_example:
        host_lst = ['MEASURE UNTRUSTED CREATE END', 'MEASURE UNTRUSTED CREATE SSM END', 'MEASURE TRUSTED CREATE END', 'MEASURE TRUSTED SEND END', 'MEASURE TRUSTED SEND 2 END', 'MEASURE UNTRUSTED SEND START', 'MEASURE UNTRUSTED SEND 2 START']
    else:
        host_lst = ['MEASURE BASELINE START', 'MEASURE BASELINE END']

#Commands to build and run PSec PerformanceMetricsExample
build_cmd = 'cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make'

if is_sim:
    environment_cmd = 'source /opt/intel/sgxsdk/environment; '
else:
    environment_cmd = 'source /opt/intel/sgxsdk/environment; unset LD_LIBRARY_PATH; export LD_LIBRARY_PATH=/usr/lib/:/opt/intel/sgxpsw/lib64; '

if is_local:
    if is_otp:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[ClientWebBrowser,ClientEnclave] 127.0.0.1:8080=[BankEnclave,TrustedInitializer,UntrustedInitializer] > kpsOutput.txt ;cd ~/Research/PSec'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=UntrustedInitializer > host1Output.txt ;cd ~/Research/PSec/'
        host_2_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/'
    elif is_civitas:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[VotingUSM,SecureVotingClientMachine] 127.0.0.1:8080=[InitializerMachine,SecureBallotBoxMachine,SecureBulletinBoardMachine,SecureSupervisorMachine,SecureTabulationTellerMachine,SecureTamperEvidentLogMachine] > kpsOutput.txt ;cd ~/Research/PSec/'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=InitializerMachine > host1Output.txt ;cd ~/Research/PSec/'
        host_2_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/'
    elif is_perf_metrics_example:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8080=[BankEnclave,TrustedInitializer,UntrustedInitializer] 127.0.0.1:8070=[ClientWebBrowser,ClientEnclave,MeasureMachine,MeasureMachine2,TempMachine] > kpsOutput.txt ;cd ~/Research/PSec'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=UntrustedInitializer > host1Output.txt ;cd ~/Research/PSec'
        host_2_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec'
else:
    if is_otp:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 10.0.0.5:8070=[ClientWebBrowser,ClientEnclave] 10.0.0.4:8080=[BankEnclave,TrustedInitializer,UntrustedInitializer] > kpsOutput.txt ;cd ~/Research/PSec'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.4:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=UntrustedInitializer > host1Output.txt ;cd ~/Research/PSec/'
        host_2_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.5:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/'
    elif is_civitas:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 10.0.0.5:8070=[VotingUSM,SecureVotingClientMachine] 10.0.0.4:8080=[InitializerMachine,SecureBallotBoxMachine,SecureBulletinBoardMachine,SecureSupervisorMachine,SecureTabulationTellerMachine,SecureTamperEvidentLogMachine] > kpsOutput.txt ;cd ~/Research/PSec/'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.4:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=InitializerMachine > host1Output.txt ;cd ~/Research/PSec/'
        host_2_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.5:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/'
    elif is_perf_metrics_example:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 10.0.0.5:8080=[BankEnclave,TrustedInitializer,UntrustedInitializer] 10.0.0.4:8070=[ClientWebBrowser,ClientEnclave,MeasureMachine,MeasureMachine2,TempMachine] > kpsOutput.txt ;cd ~/Research/PSec'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.4:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=UntrustedInitializer > host1Output.txt ;cd ~/Research/PSec'
        host_2_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.5:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec'

#Build the program
bld = subprocess.Popen(environment_cmd + build_cmd, shell=True, executable="/bin/bash")
while bld.poll() is None:
    time.sleep(1)
print('Build Complete!')


#Setup data dictionary for all data points
data_dict = {}
for item in host_lst:
    data_dict[item] = []

get_time = lambda: int(round(time.time() * 1000))
current_time_millis = get_time()

curr_iteration = 0
while curr_iteration < num_iterations:
    if is_host1:
        #Run KPS + host machine 1
        kps = subprocess.Popen(environment_cmd + kps_app_cmd, shell=True, executable="/bin/bash")
        hostmachine1 = subprocess.Popen(environment_cmd + host_1_app_cmd, shell=True, executable="/bin/bash")

        while hostmachine1.poll() is None:
            time.sleep(1)
    elif is_host2:
        #Run host machine 2 
        hostmachine2 = subprocess.Popen(environment_cmd + host_2_app_cmd, shell=True, executable="/bin/bash")

        while hostmachine2.poll() is None:
            time.sleep(1)

    #Kill Process after execution
    p = subprocess.Popen('killall -9 app', shell=True)
    while p.poll() is None:
        print('Waiting to kill all processes')
        time.sleep(1)
    print("All process killed hopefully")

    #Parse the output file
    data = "" 
    
    # Reading data from file1 
    with open('build/Samples/PSecureV1/host' + str(host_num) + 'Output.txt') as fp: 
        data = fp.read() 
    
    data += "\n"

    for i in range(len(host_lst)):
        match1 = re.search(host_lst[i] + ':(\d+)', data)
        data_lst = data_dict[host_lst[i]]
        if match1 is not None:
            data_lst.append(int(match1.group(1)))
        else:
            print("No match found!")

    with open('PerformanceMetricsScript/BaselineCacheHost' + str(host_num) + '.txt', 'w') as file:
        file.write(json.dumps(data_dict)) # use `json.loads` to do the reverse
    
    print('Iteration: (' + str(curr_iteration + 1) + '/' + str(num_iterations) + ') in ' + str(get_time() - current_time_millis) + ' ms')
    current_time_millis = get_time()
    curr_iteration += 1

print(data_dict)