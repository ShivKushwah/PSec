# set(ATTEST_SOURCE_FILES
#         EnclaveMessageExchange.c
#         LocalAttestationCode_t.c
#         )


# set_directory_properties(PROPERTIES
#         ADDITIONAL_MAKE_CLEAN_FILES "LocalAttestationCode_t.c; LocalAttestationCode_t.h")

# add_custom_command(
#         OUTPUT LocalAttestationCode_t.c
#         COMMAND ${SGX_EDGER8R} --trusted LocalAttestationCode.edl
#         --search-path ${SGX_SDK}/include
#         --search-path ${CMAKE_CURRENT_SOURCE_DIR}
#         DEPENDS LocalAttestationCode.edl
#         WORKING_DIRECTORY .
# )

# add_library(attest STATIC ${ATTEST_SOURCE_FILES})

# include_directories(
#         ${CMAKE_CURRENT_BINARY_DIR}
#         ${CMAKE_CURRENT_SOURCE_DIR}
#         ${SGX_SDK}/include
#         ${SGX_SDK}/include/tlibc
#         ${SGX_SDK}/include/stlport
#         ~/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/Include
# )

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SGX_COMMON_CFLAGS} -nostdinc -fvisibility=hidden -fpie -fstack-protector")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -std=c++11 -nostdinc++")

# set_target_properties(attest PROPERTIES PREFIX "")

# set(ATTEST_LIB attest)
