# ProgrammingEnclaves

A programming language for writing Enclave programs

Build Instructions Below for PSecureV1 Sample

```shell
git clone https://github.com/ShivKushwah/ProgrammingEnclaves-Temp.git
cd ProgrammingEnclaves-Temp/
git submodule init
git submodule update --recursive
cd Submodule/P/
git submodule init
git submodule update --recursive
./Bld/build-compiler.sh
cd ..
cd ..
mkdir build
cd build/
source /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment
cmake .. && make && cd Samples && cd PSecureV1 && ./app && cd .. && cd ..
```

NOTE: If this doesn’t work, need to modify Samples/PSecureV1/Src/app/CMakeLists.txt and change in target_link_libraries the following lines to your path:


~/Research/actual-temp/ProgrammingEnclaves-Temp/Samples/PSecureV1/Src/app/libsample_libcrypto.so


~/Research/actual-temp/ProgrammingEnclaves-Temp/Samples/PSecureV1/Src/app/libPrt_static.a
