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
CMAKE_SOURCE_DIR = /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging

# Include any dependencies generated for this target.
include src/app/CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include src/app/CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include src/app/CMakeFiles/app.dir/flags.make

src/app/enclave_u.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating enclave_u.c"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/bin/x64/sgx_edger8r --untrusted enclave.edl --search-path ../enclave/ --search-path /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/include --search-path /lib

src/app/enclave2_u.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating enclave2_u.c"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/bin/x64/sgx_edger8r --untrusted enclave2.edl --search-path ../enclave2/ --search-path /home/shiv/Research/Intel-SGX-Installation/linux-sgx/linux/installer/bin/sgxsdk/include --search-path /lib

src/app/CMakeFiles/app.dir/enclave_u.c.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/enclave_u.c.o: src/app/enclave_u.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/app/CMakeFiles/app.dir/enclave_u.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/enclave_u.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/enclave_u.c

src/app/CMakeFiles/app.dir/enclave_u.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/enclave_u.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/enclave_u.c > CMakeFiles/app.dir/enclave_u.c.i

src/app/CMakeFiles/app.dir/enclave_u.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/enclave_u.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/enclave_u.c -o CMakeFiles/app.dir/enclave_u.c.s

src/app/CMakeFiles/app.dir/enclave_u.c.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/enclave_u.c.o.requires

src/app/CMakeFiles/app.dir/enclave_u.c.o.provides: src/app/CMakeFiles/app.dir/enclave_u.c.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/enclave_u.c.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/enclave_u.c.o.provides

src/app/CMakeFiles/app.dir/enclave_u.c.o.provides.build: src/app/CMakeFiles/app.dir/enclave_u.c.o


src/app/CMakeFiles/app.dir/enclave2_u.c.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/enclave2_u.c.o: src/app/enclave2_u.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/app/CMakeFiles/app.dir/enclave2_u.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/enclave2_u.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/enclave2_u.c

src/app/CMakeFiles/app.dir/enclave2_u.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/enclave2_u.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/enclave2_u.c > CMakeFiles/app.dir/enclave2_u.c.i

src/app/CMakeFiles/app.dir/enclave2_u.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/enclave2_u.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/enclave2_u.c -o CMakeFiles/app.dir/enclave2_u.c.s

src/app/CMakeFiles/app.dir/enclave2_u.c.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/enclave2_u.c.o.requires

src/app/CMakeFiles/app.dir/enclave2_u.c.o.provides: src/app/CMakeFiles/app.dir/enclave2_u.c.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/enclave2_u.c.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/enclave2_u.c.o.provides

src/app/CMakeFiles/app.dir/enclave2_u.c.o.provides.build: src/app/CMakeFiles/app.dir/enclave2_u.c.o


src/app/CMakeFiles/app.dir/app.c.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/app.c.o: src/app/app.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/app/CMakeFiles/app.dir/app.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/app.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/app.c

src/app/CMakeFiles/app.dir/app.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/app.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/app.c > CMakeFiles/app.dir/app.c.i

src/app/CMakeFiles/app.dir/app.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/app.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/app.c -o CMakeFiles/app.dir/app.c.s

src/app/CMakeFiles/app.dir/app.c.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/app.c.o.requires

src/app/CMakeFiles/app.dir/app.c.o.provides: src/app/CMakeFiles/app.dir/app.c.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/app.c.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/app.c.o.provides

src/app/CMakeFiles/app.dir/app.c.o.provides.build: src/app/CMakeFiles/app.dir/app.c.o


src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o: src/app/sgx_utils/sgx_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/sgx_utils/sgx_utils.c

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/sgx_utils/sgx_utils.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/sgx_utils/sgx_utils.c > CMakeFiles/app.dir/sgx_utils/sgx_utils.c.i

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/sgx_utils/sgx_utils.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/sgx_utils/sgx_utils.c -o CMakeFiles/app.dir/sgx_utils/sgx_utils.c.s

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o.requires

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o.provides: src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o.provides

src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o.provides.build: src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o


src/app/CMakeFiles/app.dir/OTPServer.c.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/OTPServer.c.o: src/app/OTPServer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/app/CMakeFiles/app.dir/OTPServer.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/OTPServer.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/OTPServer.c

src/app/CMakeFiles/app.dir/OTPServer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/OTPServer.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/OTPServer.c > CMakeFiles/app.dir/OTPServer.c.i

src/app/CMakeFiles/app.dir/OTPServer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/OTPServer.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/OTPServer.c -o CMakeFiles/app.dir/OTPServer.c.s

src/app/CMakeFiles/app.dir/OTPServer.c.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/OTPServer.c.o.requires

src/app/CMakeFiles/app.dir/OTPServer.c.o.provides: src/app/CMakeFiles/app.dir/OTPServer.c.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/OTPServer.c.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/OTPServer.c.o.provides

src/app/CMakeFiles/app.dir/OTPServer.c.o.provides.build: src/app/CMakeFiles/app.dir/OTPServer.c.o


src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o: src/app/CMakeFiles/app.dir/flags.make
src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o: src/app/ForeignTypesImpl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/app.dir/ForeignTypesImpl.c.o   -c /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/ForeignTypesImpl.c

src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/ForeignTypesImpl.c.i"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/ForeignTypesImpl.c > CMakeFiles/app.dir/ForeignTypesImpl.c.i

src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/ForeignTypesImpl.c.s"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/ForeignTypesImpl.c -o CMakeFiles/app.dir/ForeignTypesImpl.c.s

src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o.requires:

.PHONY : src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o.requires

src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o.provides: src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o.requires
	$(MAKE) -f src/app/CMakeFiles/app.dir/build.make src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o.provides.build
.PHONY : src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o.provides

src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o.provides.build: src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o


# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/enclave_u.c.o" \
"CMakeFiles/app.dir/enclave2_u.c.o" \
"CMakeFiles/app.dir/app.c.o" \
"CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o" \
"CMakeFiles/app.dir/OTPServer.c.o" \
"CMakeFiles/app.dir/ForeignTypesImpl.c.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: src/app/CMakeFiles/app.dir/enclave_u.c.o
app: src/app/CMakeFiles/app.dir/enclave2_u.c.o
app: src/app/CMakeFiles/app.dir/app.c.o
app: src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o
app: src/app/CMakeFiles/app.dir/OTPServer.c.o
app: src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o
app: src/app/CMakeFiles/app.dir/build.make
app: src/app/libPrt_static.a
app: src/app/libhandler.a
app: src/app/CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable ../../app"
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/app/CMakeFiles/app.dir/build: app

.PHONY : src/app/CMakeFiles/app.dir/build

src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/enclave_u.c.o.requires
src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/enclave2_u.c.o.requires
src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/app.c.o.requires
src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/sgx_utils/sgx_utils.c.o.requires
src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/OTPServer.c.o.requires
src/app/CMakeFiles/app.dir/requires: src/app/CMakeFiles/app.dir/ForeignTypesImpl.c.o.requires

.PHONY : src/app/CMakeFiles/app.dir/requires

src/app/CMakeFiles/app.dir/clean:
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : src/app/CMakeFiles/app.dir/clean

src/app/CMakeFiles/app.dir/depend: src/app/enclave_u.c
src/app/CMakeFiles/app.dir/depend: src/app/enclave2_u.c
	cd /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app /home/shiv/Research/temp-del/ProgrammingEnclaves/ExampleEnclaveOTPServerSecureMessaging/src/app/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/app/CMakeFiles/app.dir/depend
