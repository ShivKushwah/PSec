# PSec Repo Installation

This instruction set assumes you have setup Docker with Intel SGX. It's highly recommended to follow [these SGX + Docker installation instructions](docs/SGXInstallation.md) for compatibility. Alternatively, you can use follow the [deprecated instructions](docs/SGXInstallation-Deprecated.md) if you want to avoid using Docker.

- Run `docker ps -a` and find the name of the container with the "sgx_sample" image. For the remainder of the instructions, we are assuming the name of this container was "gracious_gates"

Build Instructions Below:

```shell
docker exec -u root -t -i gracious_gates /bin/bash
cd
# Install sudo, wget, and git
apt-get update && \
    apt-get -y install sudo
sudo apt-get install git
sudo apt-get install wget
# Install PSec
mkdir Research
cd Research
git clone https://github.com/ShivKushwah/PSec.git
cd PSec/
git fetch --all
git submodule init
git submodule update --recursive
cd Submodule/P/
git submodule init
git submodule update --recursive
# Install dotnet and JRE
sudo apt-get install software-properties-common
sudo apt-get update
wget -q https://packages.microsoft.com/config/ubuntu/18.04/packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
sudo add-apt-repository universe
sudo apt-get install apt-transport-https
sudo apt-get update
sudo apt-get install dotnet-sdk-2.2
sudo apt-get install default-jre
# Resume PSec installation
git checkout master
./Bld/build-compiler.sh
cd .. && cd ..
mkdir build
apt-get install psmisc
apt-get update
sudo apt-get install build-essential cmake
apt-get update
```

Verify that correct version of `openSSL` is installed.
`openssl version -a` should yield the following:
```
openssl version -a
OpenSSL 1.1.1  11 Sep 2018
built on: Wed May 27 19:15:54 2020 UTC
platform: debian-amd64
options:  bn(64,64) rc4(16x,int) des(int) blowfish(ptr) 
compiler: gcc -fPIC -pthread -m64 -Wa,--noexecstack -Wall -Wa,--noexecstack -g -O2 -fdebug-prefix-map=/build/openssl-dyPhHZ/openssl-1.1.1=. -fstack-protector-strong -Wformat -Werror=format-security -DOPENSSL_USE_NODELETE -DL_ENDIAN -DOPENSSL_PIC -DOPENSSL_CPUID_OBJ -DOPENSSL_IA32_SSE2 -DOPENSSL_BN_ASM_MONT -DOPENSSL_BN_ASM_MONT5 -DOPENSSL_BN_ASM_GF2m -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM -DKECCAK1600_ASM -DRC4_ASM -DMD5_ASM -DAES_ASM -DVPAES_ASM -DBSAES_ASM -DGHASH_ASM -DECP_NISTZ256_ASM -DX25519_ASM -DPADLOCK_ASM -DPOLY1305_ASM -DNDEBUG -Wdate-time -D_FORTIFY_SOURCE=2
OPENSSLDIR: "/usr/lib/ssl"
ENGINESDIR: "/usr/lib/x86_64-linux-gnu/engines-1.1"
Seeding source: os-specific
```

In order to run sample programs, follow [this](Running.md) next.

# Testing Instructions
To test installation,  first change the selected sample to "PERFORMANCE_METRICS_EXAMPLE" (see [this](Running.md)).

- Run `docker ps -a` and find the name of the container with the "sgx_sample" image and the "sgx_aesm". For the remainder of the instructions, we are assuming the name of the "sgx_sample" container was "gracious_gates" and "sgx_aesm" was "sweet_grothendieck".
- Ensure the "sgx_sample" and "sgx_aesm" docker containers are running (in 2 separate terminal windows, you will need to re-ssh). If they are already running, you can skip the below command.
```shell
docker start -a -i gracious_gates
docker start -a -i sweet_grothendieck
```
- Make a third terminal window (you will need to re-ssh)
```shell
docker exec -u root -t -i gracious_gates /bin/bash
cd ~/Research/PSec
source /opt/intel/sgxsdk/environment
unset LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/usr/lib/:/opt/intel/sgxpsw/lib64
# Need to build application once before running the scripts!
cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && cmake .. && make && cd ..; cd ~/Research/PSec
cd Submodule/P && ./Bld/build-compiler.sh && cd .. && cd .. && cd build && make clean && cmake .. && make && cd ..; cd ~/Research/PSec
cd PerformanceMetricsScript/
# Ensure that the selected sample is PERFORMANCE_METRICS_EXAMPLE beforehand!
python3 ApplicationLevelPerformanceMetricsScript.py PERF_METRICS HW LOCAL 10 host1
```
- Make a fourth terminal window (you will need to re-ssh)
```shell
docker exec -u root -t -i gracious_gates /bin/bash
cd ~/Research/PSec
source /opt/intel/sgxsdk/environment
unset LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/usr/lib/:/opt/intel/sgxpsw/lib64
# Application is already built from the third tab
cd PerformanceMetricsScript/
python3 ApplicationLevelPerformanceMetricsScript.py PERF_METRICS HW LOCAL 10 host2
```

# Troubleshooting

- If you see the following, this means you added an extra space after the command
```shell
shivendra@shiv-azure3:~/Research/Intel-SGX-Installation/linux-sgx-driver$ sudo cp isgx.ko "/lib/modules/"`uname -r`"/kernel/drivers/intel/sgx"    
cp: -r not specified; omitting directory '/lib/modules/5.4.0-1031-azure/kernel/drivers/intel/sgx'
cp: -r not specified; omitting directory ' '
```

- If you see "Cannot connect to the server. Retrying... IP Address: ERROR Port:", this means that PSec cannot find the target machine it is looking for. This can happen if you pass in the wrong example, such as `python3 ApplicationLevelPerformanceMetricsScript.py OTP HW LOCAL 10 host1` instead of `python3 ApplicationLevelPerformanceMetricsScript.py PERF_METRICS HW LOCAL 10 host1` if that is what is specified on the cmakelists file.

