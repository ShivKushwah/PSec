# Intel SGX Installation
This installation process was tested on new Azure Confidential Compute Instances (Standard DC2s\_v2 instances with 2 vcpus and 8 GiB memory) running on 3.7GHz Intel Xeon E-2176G Processors with SGX technology on Ubuntu 18.04.
After this installation process, Intel SGX should work with both simulation and hardware mode programs.

### Install SGX Package
```shell
# Created on a fresh Azure instance with username shivendra, initial directory is home directory
mkdir Research
cd Research
mkdir Intel-SGX-Installation
cd Intel-SGX-Installation
git clone https://github.com/intel/linux-sgx-driver.git
cd linux-sgx-driver
git checkout b4d290b21b93c01687c92ed39e540b426707681e
dpkg-query -s linux-headers-$(uname -r)
sudo apt-get install linux-headers-$(uname -r)
# Need to do following steps on a completely new machine, skip if already installed
sudo apt install make      
sudo apt-get update
sudo apt install gcc
# Endif
make
sudo mkdir -p "/lib/modules/"`uname -r`"/kernel/drivers/intel/sgx"
sudo cp isgx.ko "/lib/modules/"`uname -r`"/kernel/drivers/intel/sgx"  
sudo sh -c "cat /etc/modules | grep -Fxq isgx || echo isgx >> /etc/modules"  
sudo /sbin/depmod
sudo /sbin/modprobe isgx
cd ..
git clone https://github.com/intel/linux-sgx.git
cd linux-sgx
git checkout dc07760567a424521a1f199de4798a649edfa3b7
sudo apt-get install build-essential ocaml ocamlbuild automake autoconf libtool wget python libssl-dev
sudo apt-get install libssl-dev libcurl4-openssl-dev protobuf-compiler libprotobuf-dev debhelper cmake
./download_prebuilt.sh
make
make sdk_install_pkg
make deb_pkg
sudo apt-get install build-essential python
cd linux/installer/bin
./sgx_linux_x64_sdk_2.5.101.50123.bin
# After running the previous step, we should have received the "source" command. In this case, it is 
# source /home/shivendra/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment
```

### Test SGX Simulation Mode
In order to verify that the Simulation setup works, do the following:
```shell
# The below command should be your custom source command
source /home/shivendra/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment
cd ..
cd ..
cd ..
cd SampleCode/LocalAttestation/
make SGX_MODE=SIM
./app
# Make sure the output is correct, and then run the following
cd ..
cd ..
```
If your machine doesn't have SGX hardware support, go directly to "Next Steps".
### Install SGX Hardware Mode
Now, we can begin to install the necessary components to enable hardware mode
```shell
sudo apt-get install libssl-dev libcurl4-openssl-dev libprotobuf-dev
cd linux/installer/deb
sudo dpkg -i ./libsgx-urts_2.5.101.50123-bionic1_amd64.deb ./libsgx-enclave-common_2.5.101.50123-bionic1_amd64.deb
sudo dpkg -i ./libsgx-enclave-common-dbgsym_2.5.101.50123-bionic1_amd64.ddeb
cd ..
cd ..
cd ..
# NEED TO RESTART VIRTUAL MACHINE TO GET THE LINUX-DRIVER TO INSTALL REMAINING DEPENDENCIES FOR HARDWARE MODE
# Restart machine here and go back to home directory
sudo apt install cpuid
cpuid |grep SGX
# Confirm output of previous command shows that machine has SGX support
sudo service aesmd restart
# Restart machine here again (this step is optional)
```
### Test SGX Hardware Mode
In order to test hardware mode. we need to enable it using a software command on a per program basis. Do the following to test:
```shell
source /home/shivendra/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment
unset LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu/:/opt/intel/sgxpsw/lib64
cd Research/Intel-SGX-Installation/linux-sgx/SampleCode/LocalAttestation/
```

Then, to the makefile, change 
```shell
App_Link_Flags := -L$(SGX_LIBRARY_PATH) -l$(Urts_Library_Name) -L. -lpthread -lLocalAttestation_unTrusted
```
to
```shell
App_Link_Flags := -L$(SGX_LIBRARY_PATH) -l$(Urts_Library_Name) -L. -lpthread -lLocalAttestation_unTrusted -lsgx_capable -Wl,-rpath=$(SGX_LIBRARY_PATH)
```
To App/App.cpp, add 

```shell
#include "sgx_uae_service.h"
#include "sgx_capable.h"
```

below 

```shell
#include <inttypes.h>
```

and add 
```shell
sgx_device_status_t sgx_device_status;
        sgx_status_t sgx_ret = sgx_cap_enable_device(&sgx_device_status);
        if (sgx_ret != SGX_SUCCESS) {
                printf("Failed to get SGX device status.\n");
                //return -1;
        }
        else {
                switch (sgx_device_status) {
                        case SGX_ENABLED:
                        printf("SGX device is enabled\n");
                        break;
                        case SGX_DISABLED_REBOOT_REQUIRED:
                        printf("SGX device has been enabled. Please reboot your machine.\n");
                        break;
                        case SGX_DISABLED_LEGACY_OS:
                        printf("SGX device can't be enabled on an OS that doesn't support EFI interface.\n");
                        break;
                        case SGX_DISABLED:
                        printf("SGX device not found.\n");
                        break;
                        default:
                        printf("Unexpected error.\n");
                        break;
                }
        }
```

below 

```shell
int _tmain(int argc, _TCHAR* argv[])
{
```

Finally, in the LocalAttestation directory, run 
```shell
make clean
make
./app
```

Expected output is 

```shell
SGX device is enabled
Available Enclaves
Enclave1 - EnclaveID 2
Enclave2 - EnclaveID 3
Enclave3 - EnclaveID 4
Secure Channel Establishment between Source (E1) and Destination (E2) Enclaves successful !!!
Enclave to Enclave Call between Source (E1) and Destination (E2) Enclaves successful !!!
Message Exchange between Source (E1) and Destination (E2) Enclaves successful !!!
Secure Channel Establishment between Source (E1) and Destination (E3) Enclaves successful !!!
Enclave to Enclave Call between Source (E1) and Destination (E3) Enclaves successful !!!
Message Exchange between Source (E1) and Destination (E3) Enclaves successful !!!
Secure Channel Establishment between Source (E2) and Destination (E3) Enclaves successful !!!
Enclave to Enclave Call between Source (E2) and Destination (E3) Enclaves successful !!!
Message Exchange between Source (E2) and Destination (E3) Enclaves successful !!!
Secure Channel Establishment between Source (E3) and Destination (E1) Enclaves successful !!!
Enclave to Enclave Call between Source (E3) and Destination (E1) Enclaves successful !!!
Message Exchange between Source (E3) and Destination (E1) Enclaves successful !!!
Close Session between Source (E1) and Destination (E2) Enclaves successful !!!
Close Session between Source (E1) and Destination (E3) Enclaves successful !!!
Close Session between Source (E2) and Destination (E3) Enclaves successful !!!
Close Session between Source (E3) and Destination (E1) Enclaves successful !!!
Hit a key....
```

Running `ldd app` should yield the following output:
```shell
    linux-vdso.so.1 (0x00007ffcb8bac000)
	libsgx_urts.so => /usr/lib/x86_64-linux-gnu/libsgx_urts.so (0x00007f1e6b3b9000)
	libsgx_capable.so => /home/shivendra/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/lib64/libsgx_capable.so (0x00007f1e6b1b6000)
	libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f1e6ae2d000)
	libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f1e6ac15000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f1e6a824000)
	libsgx_enclave_common.so.1 => /usr/lib/x86_64-linux-gnu/libsgx_enclave_common.so.1 (0x00007f1e6a61f000)
	libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f1e6a41b000)
	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f1e6a07d000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f1e6b7e6000)
	libsgx_uae_service.so => /usr/lib/x86_64-linux-gnu/libsgx_uae_service.so (0x00007f1e69e30000)
	libprotobuf.so.10 => /usr/lib/x86_64-linux-gnu/libprotobuf.so.10 (0x00007f1e699d7000)
	libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f1e697b8000)
	libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f1e6959b000)
```

### Next Steps
In order to build the repo, follow [this](RepoInstallation.md) next. For consistency, clone the repo into the Research folder created in the previous section.

