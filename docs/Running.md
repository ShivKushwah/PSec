# PSec Running Instructions

### Docker Setup
If you are running without docker, follow the legacy instructions [here](Running-Deprecated.md). Otherwise, this documentation assumes you have installed using our recommended instructions.

- Run `docker ps -a` and find the name of the container with the "sgx_sample" image and the "sgx_aesm" image. For the remainder of the instructions, we are assuming the name of the "sgx_sample" container was "gracious_gates" and "sgx_aesm" was "sweet_grothendieck".
- Ensure the "sgx_sample" and "sgx_aesm" docker containers are running (in 2 separate terminal windows, you will need to re-ssh). If they are already running, you can skip the below command.
```shell
docker start -a -i gracious_gates
docker start -a -i sweet_grothendieck
```
- For the remainder of the commands, open a new terminal and login to the "sgx_sample" instance as follows:
```shell
docker exec -u root -t -i gracious_gates /bin/bash
cd ~/Research/PSec
```

### Choose which Sample to Run
Go to `PSec/Samples/PSecureV1/CMakeLists.txt`
Uncomment the example that needs to be run. For example, in order to run the OTP sample, do the following:

```shell
# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/Civitas/CivitasHeaders.p  ...
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/CivitasHeaders.c) ...
# add_definitions(-DCIVITAS_EXAMPLE)

set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPExample/OTPBankServerCode.p  ...
set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/OTPBankServerCode.c) ...
add_definitions(-DOTP_EXAMPLE)

# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PerformanceMetricsExample/ ... 
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/PerformanceMachines1.c) ...
# add_definitions(-DPERFORMANCE_METRICS_EXAMPLE)
```

### Choose SIM mode or HW mode
To run the sample in simulation mode, 
1. Go to file `HelperScripts/CMakeLists.txt` and comment out `set(SGX_MODE HW)` and uncomment `set(SGX_MODE SIM)`
2. Run the custom source command for the Intel SGX environment: `source /home/shivendra/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment`

To run the sample in hardware mode,
1. Go to file `HelperScripts/CMakeLists.txt` and comment out `set(SGX_MODE SIM)` and uncomment `set(SGX_MODE HW)`
2. Run the custom source command for the Intel SGX environment: `source /home/shivendra/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment`
3. Run `unset LD_LIBRARY_PATH`
4. Run `export LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu/:/opt/intel/sgxpsw/lib64`

### Running the sample
##### Command Line Arguments
PSec requires the deploying the executable with different commandline arguments in order to specify different contexts for the executuable to run in. In the PSec paper, we outline that the system requires 1 Key Provisioning Server (KPS) and potentially multiple distributed hosts.

The executable produced (`./app`) takes in the following arguments for KPS deployment:
`./app isKPSProcess=True KpsIPAddress={KPSIPAddress:GeneralPort} {KPSAttestationPort}  KpsCertificateLocation={/path/to/pemfile} KpsCertificateKeysLocation={/path/to/keyfile} {DistributedHost1IPAddress:DistributedHost1Port}=[PSecMachine1,PSecMachine2,...] {DistributedHost2IPAddress:DistributedHost2Port}=[PSecMachine3,PSecMachine4,...]`
As seen above, which distributed hosts are responsible for hosting which PSec machines must be specified in the KPS executable

The executable takes in the following arguments for the deployment of a distributed host:
`./app isKPSProcess=False KpsIPAddress={KPSIPAddress:GeneralPort} {KPSAttestationPort} KpsCertificateLocation={/path/to/pemfile} currentHostMachineAddress={DistributedHost1IPAddress:DistributedHost1Port} currentHostMachineCertificateLocation={/path/to/pemfile} currentHostMachineCertificateKeysLocation={/path/to/keyfile} isStartMachine=False`
If the distributed host contains the PSecMachine that is to be the first created machine in the system, then
`./app isKPSProcess=False KpsIPAddress={KPSIPAddress:GeneralPort} {KPSAttestationPort} currentHostMachineAddress={DistributedHost1IPAddress:DistributedHost1Port} currentHostMachineCertificateLocation={/path/to/pemfile} currentHostMachineCertificateKeysLocation={/path/to/keyfile} isStartMachine=True startMachine={PSecMachineFirst}`

For all commands above, replace `{...}` with the requested value.

If the `@` command is used in the PSec code, this overrides the provided commandline creation locations (e.g. `{DistributedHost1IPAddress:DistributedHost1Port}=[PSecMachine1,PSecMachine2,...]`) and this `PSecMachine` is created in the distributed host specified by the `@` command.

##### Example Deployments
Before running any of the samples below, create 3 additional terminals and login to the "sgx_sample" docker instance:

In each tab, if you wish to run in simulation mode, do the following:
1. Run the custom source command for the Intel SGX environment: `source /opt/intel/sgxsdk/environment`

If you instead want to run in hardware mode, do the following in each tab:
1. Run the custom source command for the Intel SGX environment: `source /opt/intel/sgxsdk/environment`
2. Run `unset LD_LIBRARY_PATH`
3. Run `export LD_LIBRARY_PATH=/usr/lib/:/opt/intel/sgxpsw/lib64`

If running the distributed setting, follow these instructions above in all terminal tabs across both physical machines.

If running any of these samples for the first time, remove the `make clean` command from the provided instructions below.

TLS keys and certificates can optionally be regenerated by following the instructions [here](TLSDocumentation.md). 

These samples are documented in the [thesis](PSec-Masters-Thesis.pdf) in the Evaluation section. Changes have been made since the thesis was published, and git checkouting a version of this repo (between May 25 and May 31) will have versions of these samples consistent with the thesis documentation. 

Network timeout is set to 20 seconds, so run the different executables corresponding to one example within 20 seconds of each other.

###### Civitas (Local)
In this, we will deploy the Civitas example with the KPS, Distributed Host 1, and Distributed Host 2 all running within the same physical machine. 
Run this first to build the program:

`cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make && cd ..; cd ~/Research/PSec`

Then, run the following in different docker terminal tabs:

1. KPS: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[VotingUSM,SecureVotingClientMachine] 127.0.0.1:8080=[InitializerMachine,SecureBallotBoxMachine,SecureBulletinBoardMachine,SecureSupervisorMachine,SecureTabulationTellerMachine,SecureTamperEvidentLogMachine] > kpsOutput.txt ;cd ~/Research/PSec/`
2. Host 1: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=InitializerMachine > host1Output.txt ;cd ~/Research/PSec/`
3. Host2: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/`

###### OTP (Local)
In this, we will deploy the OTP example with the KPS, Distributed Host 1, and Distributed Host 2 all running within the same physical machine. 
Run this first to build:

`cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make && cd ..; cd ~/Research/PSec`

Then, run the following in different docker terminal tabs:

1. KPS: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[ClientWebBrowser,ClientEnclave] 127.0.0.1:8080=[BankEnclave,TrustedInitializer,UntrustedInitializer] > kpsOutput.txt ;cd ~/Research/PSec`
2. Host 1: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=UntrustedInitializer > host1Output.txt ;cd ~/Research/PSec/`
3. Host 2: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/`

###### Email Processing (Local)
In this, we will deploy the Email Processing example with the KPS, Distributed Host 1, and Distributed Host 2 all running within the same physical machine. 
Need to run the following in different docker terminal tabs (and in this order):

1. KPS: `cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[EmailUser,EmailUserEnclave] 127.0.0.1:8080=[SecureSpamFilter,TrustedInitializer,UntrustedInitializer] > kpsOutput.txt ;cd ~/Research/PSec`
2. Host 1: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=False > host1Output.txt ;cd ~/Research/PSec/`
3. Host 2: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=True startMachine=UntrustedInitializer > host2Output.txt ;cd ~/Research/PSec/`

###### Health Analysis (Local)
In this, we will deploy the Health Analysis example with the KPS, Distributed Host 1, and Distributed Host 2 all running within the same physical machine. 
Need to run the following in different docker terminal tabs (and in this order):

1. KPS: `cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[User, UserEnclave] 127.0.0.1:8080=[SecureHealthAnalyzer,awsMLHost,TrustedInitializer,UntrustedInitializer] > kpsOutput.txt ;cd ~/Research/PSec`
2. Host 1: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=False > host1Output.txt ;cd ~/Research/PSec/`
3. Host 2: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=True startMachine=UntrustedInitializer > host2Output.txt ;cd ~/Research/PSec/`

###### Performance Metrics Measurement (Local) [Deprecated]
In this, we will deploy the Performance Metrics example with the KPS, Distributed Host 1, and Distributed Host 2 all running within the same physical machine. 
Need to run the following in different docker terminal tabs (and in this order):

1. KPS: `cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build  && make clean && cmake .. && make && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 127.0.0.1:8070=[ClientWebBrowser,ClientEnclave,UntrustedInitializer] 127.0.0.1:8080=[BankEnclave,TrustedInitializer,MeasureMachine] > kpsOutput.txt ;cd ~/Research/PSec`
2. Host 1: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=False > host1Output.txt ;cd ~/Research/PSec`
3. Host 2: `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=127.0.0.1:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=127.0.0.1:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=True startMachine=UntrustedInitializer > host2Output.txt ;cd ~/Research/PSec`

###### Civitas (Distributed)
In this, we will deploy the Civitas example with the KPS and Distributed Host 1 in the same physical machine, and Distributed Host 2 in a different physical machine. We are assuming physical machine 1 has IP address 10.0.0.4 and physical machine 2 has IP address 10.0.0.5.
Run this first for both hosts in the corresponding docker terminal tab:

`cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make && cd ..; cd ~/Research/PSec`

Then, run the following in the corresponding docker terminal tabs across the hosts:

1. KPS (IP address: 10.0.0.4): `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 10.0.0.5:8070=[VotingUSM,SecureVotingClientMachine] 10.0.0.4:8080=[InitializerMachine,SecureBallotBoxMachine,SecureBulletinBoardMachine,SecureSupervisorMachine,SecureTabulationTellerMachine,SecureTamperEvidentLogMachine] > kpsOutput.txt ;cd ~/Research/PSec/`
2. Host 1 (IP address: 10.0.0.4): `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.4:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=InitializerMachine > host1Output.txt ;cd ~/Research/PSec/`
3. Host 2 (IP address: 10.0.0.5): `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.5:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/`

###### OTP (Distributed)
In this, we will deploy the OTP example with the KPS and Distributed Host 1 in the same physical machine, and Distributed Host 2 in a different physical machine. We are assuming physical machine 1 has IP address 10.0.0.4 and physical machine 2 has IP address 10.0.0.5.
Run the following:

1. KPS (IP address: 10.0.0.4): `cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 10.0.0.5:8070=[ClientWebBrowser,ClientEnclave] 10.0.0.4:8080=[BankEnclave,TrustedInitializer,UntrustedInitializer] > kpsOutput.txt ;cd ~/Research/PSec`
2. Host 1 (IP address: 10.0.0.4): `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.4:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=True startMachine=UntrustedInitializer > host1Output.txt ;cd ~/Research/PSec/`
3. Host 2 (IP address: 10.0.0.5): `cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.5:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=False > host2Output.txt ;cd ~/Research/PSec/`

###### Performance Metrics (Distributed) [Deprecated]
In this, we will deploy the Performance Metrics example with the KPS and Distributed Host 1 in the same physical machine, and Distributed Host 2 in a different physical machine. We are assuming physical machine 1 has IP address 10.0.0.4 and physical machine 2 has IP address 10.0.0.5.
Need to run the following in this order:

1. KPS (IP address: 10.0.0.4): `cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build  && make clean && cmake .. && make && cd Samples && cd PSecureV1 && ./app isKPSProcess=True KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem KpsCertificateKeysLocation=~/Research/PSec/keys/KPS.key 10.0.0.5:8070=[ClientWebBrowser,ClientEnclave,UntrustedInitializer] 10.0.0.4:8080=[BankEnclave,TrustedInitializer,MeasureMachine] > kpsOutput.txt ;cd ~/Research/PSec`
2. Host 1 (IP address: 10.0.0.4): `cd build && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.4:8080 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost.key isStartMachine=False > host1Output.txt ;cd ~/Research/PSec`
3. Host 2 (IP address: 10.0.0.5): `cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build  && make clean && cmake .. && make && cd Samples && cd PSecureV1 && ./app isKPSProcess=False KpsIPAddress=10.0.0.4:8092 8090 KpsCertificateLocation=~/Research/PSec/keys/KPS.pem currentHostMachineAddress=10.0.0.5:8070 currentHostMachineCertificateLocation=~/Research/PSec/keys/dstHost2.pem currentHostMachineCertificateKeysLocation=~/Research/PSec/keys/dstHost2.key isStartMachine=True startMachine=UntrustedInitializer > host2Output.txt ;cd ~/Research/PSec`


###### Additional Notes
To end the PSec instance, press `control-z` on the KPS instance and run `killall -9 app` to kill all instances of the application. If across 2 distributed machines, run this command across both.

In order to determine the current machine's IP address, run `ifconfig | grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -Eo '([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1'`

In order to run the debugger, 
1. Run the custom source command for the Intel SGX environment: `source /opt/intel/sgxsdk/environment`
2. `cd build && cd Samples && cd PSecureV1 && sgx-gdb ./app ;cd ~/Research/PSec/`
3. `(sgx-gdb) r {command-line arguments}`
Make sure you install gdb beforehand using `sudo apt-get install gdb`!

