# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shiv/Research/temp-del/ProgrammingEnclaves

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shiv/Research/temp-del/ProgrammingEnclaves

# Utility rule file for dep_enclave.

# Include the progress variables for this target.
include Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/progress.make

Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building P /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PSecureV1/Src/enclave/../../PSrc/PingPongEnclave.p ..."
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PSecureV1/PGenerated && dotnet /home/shiv/Research/temp-del/ProgrammingEnclaves/Submodule/P/Bld/Drops/Release/Binaries/Pc.dll /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PSecureV1/Src/enclave/../../PSrc/PingPongEnclave.p -outputDir:/home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PSecureV1/Src/enclave/../../PGenerated/

dep_enclave: Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave
dep_enclave: Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/build.make

.PHONY : dep_enclave

# Rule to build all files generated by this target.
Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/build: dep_enclave

.PHONY : Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/build

Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/clean:
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PSecureV1/Src/enclave && $(CMAKE_COMMAND) -P CMakeFiles/dep_enclave.dir/cmake_clean.cmake
.PHONY : Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/clean

Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/depend:
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shiv/Research/temp-del/ProgrammingEnclaves /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PSecureV1/Src/enclave /home/shiv/Research/temp-del/ProgrammingEnclaves /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PSecureV1/Src/enclave /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Samples/PSecureV1/Src/enclave/CMakeFiles/dep_enclave.dir/depend
