# Intel SGX OTP Server

source /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/environment

cd src/app && dotnet ~/Research/P/Bld/Drops/Release/Binaries/Pc.dll OTPServer.p && cd .. && cd .. && cmake CMakeLists.txt && make && ./app 


cd src/app && dotnet ~/Research/P/Bld/Drops/Release/Binaries/Pc.dll OTPServer.p && cd .. && cd .. && make clean && cmake CMakeLists.txt && make && ./app

