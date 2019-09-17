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
CMAKE_SOURCE_DIR = /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP

# Include any dependencies generated for this target.
include src/app/CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include src/app/CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include src/app/CMakeFiles/app.dir/flags.make

src/app/enclave_u.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating enclave_u.c"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/bin/x64/sgx_edger8r --untrusted enclave.edl --search-path ../enclave/ --search-path /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/include --search-path /lib

src/app/CMakeFiles/app.dir/enclave_u.c.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/enclave_u.c.o: src/app/enclave_u.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/app/CMakeFiles/app.dir/enclave_u.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/enclave_u.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/enclave_u.c

src/app/CMakeFiles/app.dir/enclave_u.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/enclave_u.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/enclave_u.c > CMakeFiles/app.dir/enclave_u.c.i

src/app/CMakeFiles/app.dir/enclave_u.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/enclave_u.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/enclave_u.c -o CMakeFiles/app.dir/enclave_u.c.s

src/app/CMakeFiles/app.dir/enclave_u.c.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/enclave_u.c.o.requires

src/app/CMakeFiles/app.dir/enclave_u.c.o.provides: src/app/CMakeFiles/app.dir/enclave_u.c.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/enclave_u.c.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/enclave_u.c.o.provides

src/app/CMakeFiles/app.dir/enclave_u.c.o.provides.build: src/app/CMakeFiles/app.dir/enclave_u.c.o


src/app/CMakeFiles/app.dir/app.cpp.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/app.cpp.o: src/app/app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/app/CMakeFiles/app.dir/app.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/app.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/app.cpp

src/app/CMakeFiles/app.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/app.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/app.cpp > CMakeFiles/app.dir/app.cpp.i

src/app/CMakeFiles/app.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/app.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/app.cpp -o CMakeFiles/app.dir/app.cpp.s

src/app/CMakeFiles/app.dir/app.cpp.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/app.cpp.o.requires

src/app/CMakeFiles/app.dir/app.cpp.o.provides: src/app/CMakeFiles/app.dir/app.cpp.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/app.cpp.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/app.cpp.o.provides

src/app/CMakeFiles/app.dir/app.cpp.o.provides.build: src/app/CMakeFiles/app.dir/app.cpp.o


src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o: src/app/sgx_utils/sgx_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/sgx_utils/sgx_utils.cpp

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/sgx_utils/sgx_utils.cpp > CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.i

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/sgx_utils/sgx_utils.cpp -o CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.s

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.requires

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.provides: src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.provides

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.provides.build: src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o


src/app/CMakeFiles/app.dir/PingPong.c.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/PingPong.c.o: src/app/PingPong.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/app/CMakeFiles/app.dir/PingPong.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/PingPong.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/PingPong.c

src/app/CMakeFiles/app.dir/PingPong.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/PingPong.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/PingPong.c > CMakeFiles/app.dir/PingPong.c.i

src/app/CMakeFiles/app.dir/PingPong.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/PingPong.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/PingPong.c -o CMakeFiles/app.dir/PingPong.c.s

src/app/CMakeFiles/app.dir/PingPong.c.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/PingPong.c.o.requires

src/app/CMakeFiles/app.dir/PingPong.c.o.provides: src/app/CMakeFiles/app.dir/PingPong.c.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/PingPong.c.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/PingPong.c.o.provides

src/app/CMakeFiles/app.dir/PingPong.c.o.provides.build: src/app/CMakeFiles/app.dir/PingPong.c.o


# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/enclave_u.c.o" \
"CMakeFiles/app.dir/app.cpp.o" \
"CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o" \
"CMakeFiles/app.dir/PingPong.c.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: src/app/CMakeFiles/app.dir/enclave_u.c.o
app: src/app/CMakeFiles/app.dir/app.cpp.o
app: src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o
app: src/app/CMakeFiles/app.dir/PingPong.c.o
app: src/app/CMakeFiles/app.dir/build.make
app: src/app/libPrt_static.a
app: src/app/libhandler.a
app: src/app/CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../../app"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/app/CMakeFiles/app.dir/build: app

.PHONY : src/app/CMakeFiles/app.dir/build

src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/enclave_u.c.o.requires
src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/app.cpp.o.requires
src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.cpp.o.requires
src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/PingPong.c.o.requires

.PHONY : src/app/CMakeFiles/app.dir/requires

src/app/CMakeFiles/app.dir/clean:
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : src/app/CMakeFiles/app.dir/clean

src/app/CMakeFiles/app.dir/depend: src/app/enclave_u.c
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveWithAppinP/src/app/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/app/CMakeFiles/app.dir/depend

