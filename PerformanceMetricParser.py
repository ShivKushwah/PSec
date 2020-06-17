import re
import subprocess
import time

#NOTE to use this script, make sure you build the PSec program separately before use

#Words to parse
search_lst1 = ['MEASURE UNTRUSTED CREATE START', 'MEASURE UNTRUSTED CREATE SSM START', 'MEASURE TRUSTED CREATE START', 'MEASURE TRUSTED SEND START', 'MEASURE TRUSTED SEND 2 START', 'MEASURE UNTRUSTED SEND START', 'MEASURE UNTRUSTED SEND 2 START']
search_lst2 = ['MEASURE UNTRUSTED CREATE END', 'MEASURE UNTRUSTED CREATE SSM END', 'MEASURE TRUSTED CREATE END', 'MEASURE TRUSTED SEND END', 'MEASURE TRUSTED SEND 2 END', 'MEASURE UNTRUSTED SEND END', 'MEASURE UNTRUSTED SEND 2 END']
id_lst = ['MEASURE UNTRUSTED CREATE', 'MEASURE UNTRUSTED CREATE SSM', 'MEASURE TRUSTED CREATE', 'MEASURE TRUSTED SEND', 'MEASURE TRUSTED SEND 2', 'MEASURE UNTRUSTED SEND', 'MEASURE UNTRUSTED SEND 2']

#Setup data dictionary for all data points
data_dict = {}
for item in id_lst:
    data_dict[item] = []

#Run KPS + host machines
kps = subprocess.Popen('source ~/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment; cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[ClientWebBrowser,ClientEnclave,UntrustedInitializer] 127.0.0.1:8080=[BankEnclave,TrustedInitializer,MeasureMachine] > kpsOutput.txt ;cd ~/Research/PSec', shell=True, executable="/bin/bash")
hostmachine1 = subprocess.Popen('source ~/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment; cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=False > host1Output.txt ;cd ~/Research/PSec', shell=True, executable="/bin/bash")
hostmachine2 = subprocess.Popen('source ~/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment; cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=True startMachine=UntrustedInitializer > host2Output.txt ;cd ~/Research/PSec', shell=True, executable="/bin/bash")

# while p.poll() is None:
#     print('Still sleeping')
#     time.sleep(1)

while hostmachine2.poll() is None:
    time.sleep(5)
    print('Executing PSec Program')

print('PSec Program finished executing')

#Add kill all commmand
p = subprocess.Popen('killall -9 app', shell=True)
while p.poll() is None:
    print('Waiting to kill all processes')
    time.sleep(1)
print("All process killed hopefully")

#Parse the output file
data = data2 = "" 
  
# Reading data from file1 
with open('build/Samples/PSecureV1/host1Output.txt') as fp: 
    data = fp.read() 
  
# Reading data from file2 
with open('build/Samples/PSecureV1/host2Output.txt') as fp: 
    data2 = fp.read() 
  
# Merging 2 files 
# To add the data of file2 
# from next line 
data += "\n"
data += data2 

for i in range(len(search_lst1)):
    match1 = re.search(search_lst1[i] + ':(\d+)', data)
    match2 = re.search(search_lst2[i] + ':(\d+)', data)

    data_lst = data_dict[id_lst[i]]
    data_lst.append(int(match2.group(1)) - int(match1.group(1)))

    # data_dict.add(id_lst[i], data_lst)

print(data_dict)