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

# Include any dependencies generated for this target.
include Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/enclave_u.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating enclave_u.c"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/bin/x64/sgx_edger8r --untrusted enclave.edl --search-path ../enclave/ --search-path /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/include --search-path /lib

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/enclave_u.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/enclave_u.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/enclave_u.c

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/enclave_u.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/enclave_u.c > CMakeFiles/app.dir/enclave_u.c.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/enclave_u.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/enclave_u.c -o CMakeFiles/app.dir/enclave_u.c.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o


Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/app.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/app.cpp

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/app.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/app.cpp > CMakeFiles/app.dir/app.cpp.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/app.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/app.cpp -o CMakeFiles/app.dir/app.cpp.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o


Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/pong_enclave_attestation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/pong_enclave_attestation.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/pong_enclave_attestation.cpp

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/pong_enclave_attestation.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/pong_enclave_attestation.cpp > CMakeFiles/app.dir/pong_enclave_attestation.cpp.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/pong_enclave_attestation.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/pong_enclave_attestation.cpp -o CMakeFiles/app.dir/pong_enclave_attestation.cpp.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o


Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/sgx_utils/sgx_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/sgx_utils/sgx_utils.cpp

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/sgx_utils/sgx_utils.cpp > CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/sgx_utils/sgx_utils.cpp -o CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o


Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/network_ra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/network_ra.cpp

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/attestation_utils/network_ra.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/network_ra.cpp > CMakeFiles/app.dir/attestation_utils/network_ra.cpp.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/attestation_utils/network_ra.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/network_ra.cpp -o CMakeFiles/app.dir/attestation_utils/network_ra.cpp.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o


Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/service_provider.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/service_provider.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/service_provider.cpp

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/service_provider.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/service_provider.cpp > CMakeFiles/app.dir/service_provider.cpp.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/service_provider.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/service_provider.cpp -o CMakeFiles/app.dir/service_provider.cpp.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o


Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/ias_ra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/ias_ra.cpp

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/ias_ra.cpp > CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/ias_ra.cpp -o CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o


Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/ecp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/attestation_utils/ecp.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/ecp.cpp

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/attestation_utils/ecp.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/ecp.cpp > CMakeFiles/app.dir/attestation_utils/ecp.cpp.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/attestation_utils/ecp.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/attestation_utils/ecp.cpp -o CMakeFiles/app.dir/attestation_utils/ecp.cpp.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o


Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/flags.make
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o: Samples/PingEnclavePongOutsideRemoteAttestation/PGenerated/PingPong.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/PGenerated/PingPong.c

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/PGenerated/PingPong.c > CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.i

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/PGenerated/PingPong.c -o CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.s

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o.requires:

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o.requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o.provides: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o.requires
	$(MAKE) -f Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o.provides.build
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o.provides

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o.provides.build: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o


# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/enclave_u.c.o" \
"CMakeFiles/app.dir/app.cpp.o" \
"CMakeFiles/app.dir/pong_enclave_attestation.cpp.o" \
"CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o" \
"CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o" \
"CMakeFiles/app.dir/service_provider.cpp.o" \
"CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o" \
"CMakeFiles/app.dir/attestation_utils/ecp.cpp.o" \
"CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build.make
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/libsample_libcrypto.so
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutside/Src/app/libPrt_static.a
Samples/PingEnclavePongOutsideRemoteAttestation/app: Submodule/P/Ext/libhandler/out/gcc-amd64-linux-gnu/debug/libhandler.a
Samples/PingEnclavePongOutsideRemoteAttestation/app: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable ../../app"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build: Samples/PingEnclavePongOutsideRemoteAttestation/app

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/build

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/enclave_u.c.o.requires
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/app.cpp.o.requires
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/pong_enclave_attestation.cpp.o.requires
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.requires
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/network_ra.cpp.o.requires
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/service_provider.cpp.o.requires
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ias_ra.cpp.o.requires
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/attestation_utils/ecp.cpp.o.requires
Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/__/__/PGenerated/PingPong.c.o.requires

.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/requires

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/clean:
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/clean

Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/depend: Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/enclave_u.c
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shiv/Research/temp-del/ProgrammingEnclaves /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app /home/shiv/Research/temp-del/ProgrammingEnclaves /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app /home/shiv/Research/temp-del/ProgrammingEnclaves/Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Samples/PingEnclavePongOutsideRemoteAttestation/Src/app/CMakeFiles/app.dir/depend

