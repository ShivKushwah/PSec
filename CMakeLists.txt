cmake_minimum_required(VERSION 3.0)
project(psec)

set(SGX ON)
add_definitions( -DPRT_PLAT_SGXUSER )

#include the helper functions and decls
include(HelperScripts/CMakeLists.txt)

#include the PSec samples
subdirs(Samples/PSecureV1/)



##########################################################################
# Common header files used across project
##########################################################################
#INCLUDE_DIRECTORIES(${P_LIB_INCLUDE_PATH})
#I recently commented the above line out in order to get PingEnclavePongOutside to compile with provided headers in PHeaders 
