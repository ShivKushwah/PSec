SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_VERBOSE_MAKEFILE true)

###########################################################################
## P Compilation Related Helper Functions
###########################################################################

## Compile P source
set(P_COMPILER_PATH ${CMAKE_SOURCE_DIR}/Submodule/P/Bld/Drops/Release/Binaries/Pc.dll)
set(P_BUILT_LIB_PATH ${CMAKE_SOURCE_DIR}/Submodule/P/Bld/Drops/Prt)
set(P_LIBHANDLER_PATH ${CMAKE_SOURCE_DIR}/Submodule/P/Ext/libhandler)
set(P_LIB_INCLUDE_PATH ${P_BUILT_LIB_PATH}/include)
set(P_LIB_LINK_PATH ${P_BUILT_LIB_PATH}/lib)

# Setup SGX options.
if (SGX)
    set(SGX_SDK $ENV{SGX_SDK})
    set(SGX_ARCH x64)
    set(SGX_MODE SIM CACHE STRING "SGX mode: SIM or HW") # SGX mode: sim, hw
    set(COMPILE_EXAMPLES NO CACHE BOOL "Build examples")
    set(SGX_BUILD DEBUG CACHE STRING "Build: DEBUG, PRERELEASE or RELEASE")

    set(HELPER_SCRIPTS_DIR ${CMAKE_SOURCE_DIR}/HelperScripts/)
    set(CMAKE_MODULE_PATH ${HELPER_SCRIPTS_DIR} ${CMAKE_MODULE_PATH})
    include(${HELPER_SCRIPTS_DIR}/Init.cmake)
    include(${HELPER_SCRIPTS_DIR}/FindSGXSDK.cmake)
    include(${HELPER_SCRIPTS_DIR}/ConfigSGX.cmake)
endif()


## Initializing the P Runtime Library
add_subdirectory(${CMAKE_SOURCE_DIR}/Submodule/P/Src)

if(NOT EXISTS ${P_COMPILER_PATH})
Message(FATAL_ERROR ">|> ${P_COMPILER_PATH} not found. Build P")
else()
Message(STATUS ">|> Found P compiler at ${P_COMPILER_PATH}")
endif()


function (PBUILD depName pFiles outputDirect)
    ADD_CUSTOM_TARGET(
            ${depName} ALL
            COMMENT "Building P ${${pFiles}} ..."
            COMMAND dotnet ${P_COMPILER_PATH} ${${pFiles}} -outputDir:${outputDirect}
            WORKING_DIRECTORY ${outputDirect}
    )
endfunction(PBUILD)

##########################################################################
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
