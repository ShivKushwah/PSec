# need 3.0 for multiple line strings
cmake_minimum_required(VERSION 3.0)
project(ExampleEnclave)
set(CMAKE_BUILD_TYPE Debug)

set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPBankServerCode.p  ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPClientCode.p ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/OTPHeaderDeclarations.p)
set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/OTPBankServerCode.c ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/OTPClientCode.c ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/OTPBankServerCode.c)

# set (P_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PSrc/PingPongEnclave.p)
# set (P_SOURCE_C_CODE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/PingPongEnclave.c)

# NOTE if uncommenting/ changing files above, change the #include "OTPBankServerCode.h" statement in constants.h




set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(Src/enclave)
add_subdirectory(Src/app)
