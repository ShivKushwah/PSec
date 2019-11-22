# need 3.0 for multiple line strings
cmake_minimum_required(VERSION 3.0)
project(ExampleEnclave)
set(CMAKE_BUILD_TYPE Debug)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(Src/enclave)
add_subdirectory(Src/enclave2)
add_subdirectory(Src/app)
