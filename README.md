# ProgrammingEnclaves

A programming language for writing Enclave programs

Build Instructions Below for PSecureV1 Sample

```shell
git clone https://github.com/ankushdesai/ProgrammingEnclaves.git
cd ProgrammingEnclaves/
git fetch --all
git checkout psecure
git submodule init
git submodule update --recursive
cd Submodule/P/
git submodule init
git submodule update --recursive
#if dotnet and JRE are not installed, do below steps to install
wget -q https://packages.microsoft.com/config/ubuntu/18.04/packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
sudo add-apt-repository universe
sudo apt-get install apt-transport-https
sudo apt-get update
sudo apt-get install dotnet-sdk-2.2
sudo apt-get install default-jre
#endif
./Bld/build-compiler.sh
cd .. && cd ..
mkdir build
cd build/
source /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment
cmake .. && make && cd Samples && cd PSecureV1 && ./app && cd .. && cd ..
```

NOTE: If this doesn’t work, need to modify Samples/PSecureV1/Src/app/CMakeLists.txt and change in target_link_libraries the following lines to your path:


~/Research/actual-temp/ProgrammingEnclaves-Temp/Samples/PSecureV1/Src/app/libsample_libcrypto.so


~/Research/actual-temp/ProgrammingEnclaves-Temp/Samples/PSecureV1/Src/app/libPrt_static.a
