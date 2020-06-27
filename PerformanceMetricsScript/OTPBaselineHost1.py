import re
import subprocess
import time
import json
import statistics 
import time
import os

num_iterations = 2

# is_sim = False
is_sim = True

is_civitas = True
is_otp = False
# is_civitas = False
# is_otp = True

#Move program to root context
os.chdir('..')

if is_sim:
    host1_lst = []
else:
    host1_lst = []

#Commands to build and run PSec PerformanceMetricsExample
build_cmd = 'cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make'
if is_sim:
    environment_cmd = 'source ~/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment; '
    if is_otp:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[ClientWebBrowser,ClientEnclave] 127.0.0.1:8080=[BankEnclave,TrustedInitializer,UntrustedInitializer] > kpsOutput.txt ;cd ~/Research/PSec'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=UntrustedInitializer > host1Output.txt ;cd ~/Research/PSec/'
    elif is_civitas:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[VotingUSM,SecureVotingClientMachine] 127.0.0.1:8080=[InitializerMachine,SecureBallotBoxMachine,SecureBulletinBoardMachine,SecureSupervisorMachine,SecureTabulationTellerMachine,SecureTamperEvidentLogMachine] > kpsOutput.txt ;cd ~/Research/PSec/'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=InitializerMachine > host1Output.txt ;cd ~/Research/PSec/'
else:
    environment_cmd = 'source ~/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment; unset LD_LIBRARY_PATH; export LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu/:/opt/intel/sgxpsw/lib64; '
    if is_otp:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 10.0.0.5:8070=[ClientWebBrowser,ClientEnclave] 10.0.0.4:8080=[BankEnclave,TrustedInitializer,UntrustedInitializer] > kpsOutput.txt ;cd ~/Research/PSec'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.4:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=UntrustedInitializer > host1Output.txt ;cd ~/Research/PSec/'
    elif is_civitas:
        kps_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 10.0.0.5:8070=[VotingUSM,SecureVotingClientMachine] 10.0.0.4:8080=[InitializerMachine,SecureBallotBoxMachine,SecureBulletinBoardMachine,SecureSupervisorMachine,SecureTabulationTellerMachine,SecureTamperEvidentLogMachine] > kpsOutput.txt ;cd ~/Research/PSec/'
        host_1_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.4:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=InitializerMachine > host1Output.txt ;cd ~/Research/PSec/'


#Build the program
bld = subprocess.Popen(environment_cmd + build_cmd, shell=True, executable="/bin/bash")
while bld.poll() is None:
    time.sleep(1)
print('Build Complete!')


#Setup data dictionary for all data points
data_dict = {}
for item in host1_lst:
    data_dict[item] = []

get_time = lambda: int(round(time.time() * 1000))
current_time_millis = get_time()

curr_iteration = 0
while curr_iteration < num_iterations:
    #Run KPS + host machine 1
    kps = subprocess.Popen(environment_cmd + kps_app_cmd, shell=True, executable="/bin/bash")
    hostmachine1 = subprocess.Popen(environment_cmd + host_1_app_cmd, shell=True, executable="/bin/bash")

    while hostmachine1.poll() is None:
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
    with open('build/Samples/PSecureV1/host1Output.txt') as fp: 
        data = fp.read() 
    
    data += "\n"

    for i in range(len(host1_lst)):
        match1 = re.search(host1_lst[i] + ':(\d+)', data)
        data_lst = data_dict[host1_lst[i]]
        data_lst.append(int(match1.group(1)))
        if match1 is not None:
            data_lst.append(int(match1.group(1)))
        else:
            print("No match found!")

    with open('PerformanceMetricsScript/BaselineCacheHost1.txt', 'w') as file:
        file.write(json.dumps(data_dict)) # use `json.loads` to do the reverse
    
    print('Iteration: (' + str(curr_iteration + 1) + '/' + str(num_iterations) + ') in ' + str(get_time() - current_time_millis) + ' ms')
    current_time_millis = get_time()
    curr_iteration += 1

print(data_dict)