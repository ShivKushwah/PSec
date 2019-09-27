set(ENCLAVE_SOURCE_FILES
        Utility_E1.cpp
        enclave.cpp
        TrustedMessaging.cpp
        enclave_t.c
        sealing/sealing.cpp
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

add_library(enclave SHARED ${ENCLAVE_SOURCE_FILES})

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SGX_SDK}/include
        ${SGX_SDK}/include/tlibc
        ${SGX_SDK}/include/stlport
        ~/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/Include
        # ~/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/LocalAttestationCode


)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SGX_COMMON_CFLAGS} -nostdinc -fvisibility=hidden -fpie -fstack-protector")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -std=c++03 -nostdinc++")

set_target_properties(enclave PROPERTIES PREFIX "")

target_link_libraries(enclave "${SGX_COMMON_CFLAGS} \
    -Wl,--no-undefined -nostdlib -nodefaultlibs -nostartfiles -L${SGX_LIBRARY_PATH} \
    -Wl,--whole-archive -l${SGX_TRTS_LIB} -Wl,--no-whole-archive \
    -Wl,--start-group -lsgx_tstdc -l${SGX_CRYPTO_LIB} -l${SGX_TSVC_LIB} -Wl,--end-group \
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

