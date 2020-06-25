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

#Move program to root context
os.chdir('..')

if is_sim:
    host2_lst = ['MEASURE OTPBASELINE START', 'MEASURE OTPBASELINE END']
else:
    host2_lst = ['MEASURE OTPBASELINE START', 'MEASURE OTPBASELINE END']

#Commands to build and run PSec PerformanceMetricsExample
build_cmd = 'cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make'

if is_sim:
    host_2_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/'
    environment_cmd = 'source ~/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment; '
else:
    host_2_app_cmd = 'cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.5:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/'
    environment_cmd = 'source ~/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment; unset LD_LIBRARY_PATH; export LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu/:/opt/intel/sgxpsw/lib64; '

#Build the program
bld = subprocess.Popen(environment_cmd + build_cmd, shell=True, executable="/bin/bash")
while bld.poll() is None:
    time.sleep(1)
print('Build Complete!')


#Setup data dictionary for all data points
data_dict = {}
for item in host2_lst:
    data_dict[item] = []

get_time = lambda: int(round(time.time() * 1000))
current_time_millis = get_time()

curr_iteration = 0
while curr_iteration < num_iterations:
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
    data = data2 = "" 

    # Reading data from file2 
    with open('build/Samples/PSecureV1/host2Output.txt') as fp: 
        data2 = fp.read() 
    
    data += data2 

    for i in range(len(host2_lst)):
        match1 = re.search(host2_lst[i] + ':(\d+)', data)
        data_lst = data_dict[host2_lst[i]]
        if match1 is not None:
            data_lst.append(int(match1.group(1)))
        else:
            print("No match found!")

    with open('PerformanceMetricsScript/OTPBaselineCacheHost2.txt', 'w') as file:
        file.write(json.dumps(data_dict)) # use `json.loads` to do the reverse
    
    print('Iteration: (' + str(curr_iteration + 1) + '/' + str(num_iterations) + ') in ' + str(get_time() - current_time_millis) + ' ms')
    current_time_millis = get_time()
    curr_iteration += 1

print(data_dict)