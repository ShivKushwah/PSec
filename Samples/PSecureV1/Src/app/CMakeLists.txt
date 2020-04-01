set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SGX_COMMON_CFLAGS} -fPIC -Wno-attributes")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -std=c++11")

# set(SGX OFF)
# remove_definitions( -DPRT_PLAT_SGXUSER )
# add_definitions( -DPRT_PLAT_LINUXUSER )
# remove_definitions(-DENCLAVE_STD_ALT)



# set(CLIENT_SRC_FILES enclave_u.c app.cpp enclave_untrusted_host.cpp sgx_utils/sgx_utils.cpp attestation_utils/network_ra.cpp kps.cpp attestation_utils/ias_ra.cpp attestation_utils/ecp.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../PGenerated/PingPong.c)

# set(CLIENT_SRC_FILES enclave_u.c app.cpp enclave_untrusted_host.cpp sgx_utils/sgx_utils.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../Src/shared/helper.cpp attestation_utils/network_ra.cpp attestation_utils/sample_messages.cpp kps.cpp attestation_utils/ias_ra.cpp attestation_utils/ecp.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../PGenerated/PingPongEnclave.c)
set(CLIENT_SRC_FILES enclave_u.c app.cpp enclave_untrusted_host.cpp sgx_utils/sgx_utils.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../Src/shared/helper.cpp attestation_utils/network_ra.cpp attestation_utils/sample_messages.cpp kps.cpp attestation_utils/ias_ra.cpp attestation_utils/ecp.cpp network_simulator.cpp ${P_SOURCE_C_CODE_LOCATION})
# FILE(GLOB_RECURSE psources ${CMAKE_CURRENT_SOURCE_DIR}/../../PSrc/PingPongEnclave.p) #used to be ${CMAKE_CURRENT_SOURCE_DIR}/../../PSrc/*
FILE(GLOB_RECURSE psources ${P_CODE_LOCATION}) #used to be ${CMAKE_CURRENT_SOURCE_DIR}/../../PSrc/*
PBUILD(dep_${projectName} psources ${CMAKE_CURRENT_SOURCE_DIR}/../../PGenerated/)
FILE(GLOB_RECURSE ${projectName}_psources ${CMAKE_CURRENT_SOURCE_DIR}../../PSrc/*)
FILE(GLOB_RECURSE ${projectName}_csources ./*)
FILE(GLOB_RECURSE ${projectName}_gsources ${CMAKE_CURRENT_SOURCE_DIR}../../PGenerated/*.c)

set (${projectName}_INCLUDE
)


set_directory_properties(PROPERTIES
        ADDITIONAL_MAKE_CLEAN_FILES "enclave_u.c; enclave_u.h")

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/enclave_u.c
        COMMAND ${SGX_EDGER8R} --untrusted enclave.edl
        --use-prefix
        --search-path ../enclave/ # enclave.edl
        --search-path ${SGX_SDK}/include
        --search-path ${MBEDTLS_SGX_ROOT_DIR}/lib # mbedtls_sgx.edl
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(app ${CLIENT_SRC_FILES})

include_directories(
        ${SGXSDK_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/../PHeaders
        ${CMAKE_CURRENT_SOURCE_DIR}/../../PGenerated
        ${CMAKE_CURRENT_SOURCE_DIR}/attestation_utils
        ${CMAKE_CURRENT_SOURCE_DIR}/../shared
        ${CMAKE_CURRENT_SOURCE_DIR}

)

set(LIBHANDLERLIB_PATH ${P_LIBHANDLER_PATH}/out/gcc-amd64-linux-gnu/debug/libhandler.a)

#add_library(Prt_static STATIC ~/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutside/Src/app/libPrt_static.a)
#set_target_properties(Prt_static PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(app
        -L${SGX_LIBRARY_PATH} -l${SGX_URTS_LIB} -l${SGX_USVC_LIB} -lsgx_ukey_exchange
        ${CMAKE_CURRENT_SOURCE_DIR}/libsample_libcrypto.so
        # ~/Research/PSecuredLang/ProgrammingEnclaves/Samples/PSecureV1/Src/app/libsample_libcrypto.so
        #~/Research/PSecuredLang/ProgrammingEnclaves/Samples/PSecureV1/Src/app/libPrt_static.a #TODO Unhardcode this
        Prt_static2
        ${LIBHANDLERLIB_PATH}
        -Wl,-rpath -Wl,/usr/local/lib
        -Wl,-rpath -Wl,${SGX_LIBRARY_PATH}
        -lpthread)

add_dependencies(app enclave )
# add_dependencies(app enclave)