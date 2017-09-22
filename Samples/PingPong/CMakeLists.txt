cmake_minimum_required(VERSION 3.0)
project(pingpong)


set(projectName pingpong)
PBUILD(dep_${projectName} ${CMAKE_CURRENT_SOURCE_DIR}/pingpong.xml "c" ${CMAKE_CURRENT_SOURCE_DIR})














###################################
# Generic setup for each project
##################################

FILE(GLOB_RECURSE ${projectName}_psources PSrc/*)
FILE(GLOB_RECURSE ${projectName}_csources Src/*)
FILE(GLOB_RECURSE ${projectName}_gsources PGenerated/*.c)



add_executable(${projectName}
  ${${projectName}_gsources}
  ${${projectName}_csources}
  ${${projectName}_psources}
)

set (${projectName}_INCLUDE
${CMAKE_CURRENT_SOURCE_DIR}/PGenerated/
${CMAKE_CURRENT_SOURCE_DIR}/Includes/
)

set_property(TARGET ${projectName} PROPERTY C_STANDARD 99)
set_property(TARGET ${projectName} PROPERTY LINKER_LANGUAGE CXX)
add_dependencies(${projectName} dep_${projectName})

#include generic files
target_include_directories(${projectName} PRIVATE
${${projectName}_INCLUDE})

#include specific files
target_include_directories(${projectName} PRIVATE

)

target_link_libraries(${projectName}
  pruntime
  pthread
)








