set(ENCLAVE_SOURCE_FILES
        enclave2.cpp
        enclave2_t.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../EnclaveUtility/Utility_Enclave.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../TrustedMessaging/TrustedMessagingLib.cpp
        )

add_definitions(-DENCLAVE_STD_ALT -DENCLAVE2)

set_directory_properties(PROPERTIES
        ADDITIONAL_MAKE_CLEAN_FILES "enclave2_t.c; enclave2_t.h")

add_custom_command(
        OUTPUT enclave2_t.c
        COMMAND ${SGX_EDGER8R} --trusted enclave2.edl
        --search-path ${SGX_SDK}/include
        --search-path ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS enclave2.edl
        WORKING_DIRECTORY .
)

add_library(enclave2 SHARED ${ENCLAVE_SOURCE_FILES})

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SGX_SDK}/include
        ${SGX_SDK}/include/libcxx
        ${SGX_SDK}/include/tlibc
        ${SGX_SDK}/include/stlport
        ${CMAKE_CURRENT_SOURCE_DIR}/../Include
        ${CMAKE_CURRENT_SOURCE_DIR}/../EnclaveUtility
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SGX_COMMON_CFLAGS} -nostdinc -fvisibility=hidden -fpie -fstack-protector")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -std=c++11 -nostdinc++")

set_target_properties(enclave2 PROPERTIES PREFIX "")

target_link_libraries(enclave2 "${SGX_COMMON_CFLAGS} \
    -Wl,--no-undefined -nostdlib -nodefaultlibs -nostartfiles -L${SGX_LIBRARY_PATH} \
    -Wl,--whole-archive -l${SGX_TRTS_LIB} -Wl,--no-whole-archive \
    -Wl,--start-group -lsgx_tstdc -lsgx_tcxx -l${SGX_CRYPTO_LIB} -l${SGX_TSVC_LIB} -Wl,--end-group \
    -Wl,-Bstatic -Wl,-Bsymbolic -Wl,--no-undefined \
    -Wl,-pie,-eenclave_entry -Wl,--export-dynamic \
    -Wl,--defsym,__ImageBase=0")

add_custom_command(TARGET enclave2
        POST_BUILD
        COMMAND ${SGX_ENCLAVE_SIGNER} sign
        -key enclave2_private.pem
        -config enclave2.config.xml
        -enclave ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/enclave2.so
        -out ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/enclave2.signed.so
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Signing the enclave => ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/enclave2.signed.so")
