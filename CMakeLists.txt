cmake_minimum_required(VERSION 3.0)
project(programmingenclaves)

#include the helper functions and decls
include(HelperScripts/CMakeLists.txt)


#include PingPong Samples directory
subdirs(Samples/PingPong/)
subdirs(Samples/VotingSystem/)

##########################################################################
# Common header files used across project
##########################################################################
INCLUDE_DIRECTORIES(${P_LIB_INCLUDE_PATH})
