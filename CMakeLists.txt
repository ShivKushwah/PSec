cmake_minimum_required(VERSION 3.0)
project(programmingenclaves)

set(SGX ON)
add_definitions( -DPRT_PLAT_SGXUSER )
#add_definitions( -DPRT_PLAT_LINUXUSER )

#include the helper functions and decls
include(HelperScripts/CMakeLists.txt)

#include PingPong Samples directory

#subdirs(Samples/PingPong/)
#subdirs(Samples/PingPongEnclave/)
#subdirs(Samples/VotingSystem/)
subdirs(Samples/ForeignTypesEnclave/)


##########################################################################
# Common header files used across project
##########################################################################
INCLUDE_DIRECTORIES(${P_LIB_INCLUDE_PATH})
