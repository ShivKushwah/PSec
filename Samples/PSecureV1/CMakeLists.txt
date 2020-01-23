# need 3.0 for multiple line strings
cmake_minimum_required(VERSION 3.0)
project(ExampleEnclave)
set(CMAKE_BUILD_TYPE Debug)

set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPSampleCode.p)
set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/OTPSampleCode.c)

# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PingPongEnclave.p)
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/PingPongEnclave.c)




set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(Src/enclave)
add_subdirectory(Src/app)
