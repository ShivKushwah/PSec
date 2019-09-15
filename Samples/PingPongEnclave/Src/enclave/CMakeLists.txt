cmake_minimum_required(VERSION 3.0)
project(pingpong)

set(projectName enclave)
FILE(GLOB_RECURSE psources ${CMAKE_CURRENT_SOURCE_DIR}/../../PSrc/*)
PBUILD(dep_${projectName} psources ${CMAKE_CURRENT_SOURCE_DIR}/../../PGenerated/)


###################################
# Generic setup for each project
##################################

FILE(GLOB_RECURSE ${projectName}_psources ${CMAKE_CURRENT_SOURCE_DIR}../../PSrc/*)
FILE(GLOB_RECURSE ${projectName}_csources ./*)
FILE(GLOB_RECURSE ${projectName}_gsources ${CMAKE_CURRENT_SOURCE_DIR}../../PGenerated/*.c)

#add_executable(${projectName}
#  ${${projectName}_gsources}
#  ${${projectName}_csources}
#  ${${projectName}_psources}
#)

set (${projectName}_INCLUDE
../../PGenerated/
../../Includes/
)



set(ENCLAVE_SOURCE_FILES
        enclave.c
        enclave_t.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../PGenerated/PingPong.c
        #/home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingPongEnclave/PGenerated/PingPong.c
        #~/Research/temp-del/ProgrammingEnclaves/Samples/PingPongEnclave/PGenerated/PingPong.c
        )

add_definitions(-DENCLAVE_STD_ALT)

set_directory_properties(PROPERTIES
        ADDITIONAL_MAKE_CLEAN_FILES "enclave_t.c; enclave_t.h")

add_custom_command(
        OUTPUT enclave_t.c
        COMMAND ${SGX_EDGER8R} --trusted enclave.edl
        --search-path ${SGX_SDK}/include
        --search-path ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS enclave.edl
        WORKING_DIRECTORY .
)

cmake_policy(SET CMP0004 OLD)

add_library(enclave SHARED ${ENCLAVE_SOURCE_FILES} ${${projectName}_gsources} ${${projectName}_csources} ${${projectName}_psources})

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SGX_SDK}/include
        ${SGX_SDK}/include/tlibc
        ${SGX_SDK}/include/stlport
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SGX_COMMON_CFLAGS} -nostdinc -fvisibility=hidden -fpie -fstack-protector")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -std=c++03 -nostdinc++")

set_target_properties(enclave PROPERTIES PREFIX "")

target_link_libraries(enclave 
Prt_trusted_static
"${SGX_COMMON_CFLAGS} \
-Wl,--no-undefined -nostdlib -nodefaultlibs -nostartfiles -L${SGX_LIBRARY_PATH} \
-Wl,--whole-archive -l${SGX_TRTS_LIB} -Wl,--no-whole-archive \
-Wl,--start-group -lsgx_tstdc -lsgx_tcxx -l${SGX_CRYPTO_LIB} -l${SGX_TSVC_LIB} -Wl,--end-group \
-Wl,-Bstatic -Wl,-Bsymbolic -Wl,--no-undefined \
-Wl,-pie,-eenclave_entry -Wl,--export-dynamic \
-Wl,--defsym,__ImageBase=0")

add_custom_command(TARGET enclave
        POST_BUILD
        COMMAND ${SGX_ENCLAVE_SIGNER} sign
        -key enclave_private.pem
        -config enclave.config.xml
        -enclave ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/enclave.so
        -out ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/enclave.signed.so
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Signing the enclave => ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/enclave.signed.so")

    
set_property(TARGET ${projectName} PROPERTY C_STANDARD 99)
set_property(TARGET ${projectName} PROPERTY LINKER_LANGUAGE CXX)
add_dependencies(${projectName} dep_${projectName})

#include generic files
target_include_directories(${projectName} PRIVATE
${${projectName}_INCLUDE})

#include specific files
target_include_directories(${projectName} PRIVATE

)

set(LIBHANDLERLIB_PATH ${P_LIBHANDLER_PATH}/out/gcc-amd64-linux-gnu/debug/libhandler.a)

target_link_libraries(${projectName}
    Prt_trusted_static
    ${LIBHANDLERLIB_PATH} -lsgx_tstdc
#  #  pthread
)

