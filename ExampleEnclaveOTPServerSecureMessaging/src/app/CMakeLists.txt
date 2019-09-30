set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SGX_COMMON_CFLAGS} -fPIC -Wno-attributes")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -std=c++11")

find_package (Threads)


set(CLIENT_SRC_FILES enclave_u.c enclave2_u.c app.cpp sgx_utils/sgx_utils.cpp
        ForeignTypesImpl.cpp
        OTPServer.c
        UntrustedMessaging.cpp
        )

set_directory_properties(PROPERTIES
        ADDITIONAL_MAKE_CLEAN_FILES "enclave_u.c; enclave_u.h; enclave2_u.c; enclave2_u.h")

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/enclave_u.c
        COMMAND ${SGX_EDGER8R} --untrusted enclave.edl
        --search-path ../enclave/ # enclave.edl
        --search-path ${SGX_SDK}/include
        --search-path ${MBEDTLS_SGX_ROOT_DIR}/lib # mbedtls_sgx.edl
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/enclave2_u.c
        COMMAND ${SGX_EDGER8R} --untrusted enclave2.edl
        --search-path ../enclave2/ # enclave.edl
        --search-path ${SGX_SDK}/include
        --search-path ${MBEDTLS_SGX_ROOT_DIR}/lib # mbedtls_sgx.edl
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(app ${CLIENT_SRC_FILES})

include_directories(
        ${SGXSDK_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/../PHeaders
        ${CMAKE_CURRENT_SOURCE_DIR}/../PLib
        ${CMAKE_CURRENT_SOURCE_DIR}/../Include
)

target_link_libraries(app
        ${CMAKE_CURRENT_SOURCE_DIR}/../PLib/libPrt_static.a
        ${CMAKE_CURRENT_SOURCE_DIR}/../PLib/libhandler.a
        ${CMAKE_THREAD_LIBS_INIT}
        -L${SGX_LIBRARY_PATH} -l${SGX_URTS_LIB} -l${SGX_USVC_LIB}
        -Wl,-rpath -Wl,/usr/local/lib
        -Wl,-rpath -Wl,${SGX_LIBRARY_PATH}
        -lpthread)

add_dependencies(app enclave enclave2)
