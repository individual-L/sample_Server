# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luo/code/sample_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luo/code/sample_server/build

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/src/Accept.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Accept.cpp.o: ../src/Accept.cpp
CMakeFiles/server.dir/src/Accept.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/src/Accept.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Accept.cpp.o -MF CMakeFiles/server.dir/src/Accept.cpp.o.d -o CMakeFiles/server.dir/src/Accept.cpp.o -c /home/luo/code/sample_server/src/Accept.cpp

CMakeFiles/server.dir/src/Accept.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Accept.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/Accept.cpp > CMakeFiles/server.dir/src/Accept.cpp.i

CMakeFiles/server.dir/src/Accept.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Accept.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/Accept.cpp -o CMakeFiles/server.dir/src/Accept.cpp.s

CMakeFiles/server.dir/src/Channel.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Channel.cpp.o: ../src/Channel.cpp
CMakeFiles/server.dir/src/Channel.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/src/Channel.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Channel.cpp.o -MF CMakeFiles/server.dir/src/Channel.cpp.o.d -o CMakeFiles/server.dir/src/Channel.cpp.o -c /home/luo/code/sample_server/src/Channel.cpp

CMakeFiles/server.dir/src/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/Channel.cpp > CMakeFiles/server.dir/src/Channel.cpp.i

CMakeFiles/server.dir/src/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/Channel.cpp -o CMakeFiles/server.dir/src/Channel.cpp.s

CMakeFiles/server.dir/src/Epolls.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Epolls.cpp.o: ../src/Epolls.cpp
CMakeFiles/server.dir/src/Epolls.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/src/Epolls.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Epolls.cpp.o -MF CMakeFiles/server.dir/src/Epolls.cpp.o.d -o CMakeFiles/server.dir/src/Epolls.cpp.o -c /home/luo/code/sample_server/src/Epolls.cpp

CMakeFiles/server.dir/src/Epolls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Epolls.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/Epolls.cpp > CMakeFiles/server.dir/src/Epolls.cpp.i

CMakeFiles/server.dir/src/Epolls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Epolls.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/Epolls.cpp -o CMakeFiles/server.dir/src/Epolls.cpp.s

CMakeFiles/server.dir/src/Eventloop.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Eventloop.cpp.o: ../src/Eventloop.cpp
CMakeFiles/server.dir/src/Eventloop.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/src/Eventloop.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Eventloop.cpp.o -MF CMakeFiles/server.dir/src/Eventloop.cpp.o.d -o CMakeFiles/server.dir/src/Eventloop.cpp.o -c /home/luo/code/sample_server/src/Eventloop.cpp

CMakeFiles/server.dir/src/Eventloop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Eventloop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/Eventloop.cpp > CMakeFiles/server.dir/src/Eventloop.cpp.i

CMakeFiles/server.dir/src/Eventloop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Eventloop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/Eventloop.cpp -o CMakeFiles/server.dir/src/Eventloop.cpp.s

CMakeFiles/server.dir/src/Inet_Addr.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Inet_Addr.cpp.o: ../src/Inet_Addr.cpp
CMakeFiles/server.dir/src/Inet_Addr.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server.dir/src/Inet_Addr.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Inet_Addr.cpp.o -MF CMakeFiles/server.dir/src/Inet_Addr.cpp.o.d -o CMakeFiles/server.dir/src/Inet_Addr.cpp.o -c /home/luo/code/sample_server/src/Inet_Addr.cpp

CMakeFiles/server.dir/src/Inet_Addr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Inet_Addr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/Inet_Addr.cpp > CMakeFiles/server.dir/src/Inet_Addr.cpp.i

CMakeFiles/server.dir/src/Inet_Addr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Inet_Addr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/Inet_Addr.cpp -o CMakeFiles/server.dir/src/Inet_Addr.cpp.s

CMakeFiles/server.dir/src/Server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Server.cpp.o: ../src/Server.cpp
CMakeFiles/server.dir/src/Server.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server.dir/src/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Server.cpp.o -MF CMakeFiles/server.dir/src/Server.cpp.o.d -o CMakeFiles/server.dir/src/Server.cpp.o -c /home/luo/code/sample_server/src/Server.cpp

CMakeFiles/server.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/Server.cpp > CMakeFiles/server.dir/src/Server.cpp.i

CMakeFiles/server.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/Server.cpp -o CMakeFiles/server.dir/src/Server.cpp.s

CMakeFiles/server.dir/src/Sock.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/Sock.cpp.o: ../src/Sock.cpp
CMakeFiles/server.dir/src/Sock.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server.dir/src/Sock.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/Sock.cpp.o -MF CMakeFiles/server.dir/src/Sock.cpp.o.d -o CMakeFiles/server.dir/src/Sock.cpp.o -c /home/luo/code/sample_server/src/Sock.cpp

CMakeFiles/server.dir/src/Sock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/Sock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/Sock.cpp > CMakeFiles/server.dir/src/Sock.cpp.i

CMakeFiles/server.dir/src/Sock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/Sock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/Sock.cpp -o CMakeFiles/server.dir/src/Sock.cpp.s

CMakeFiles/server.dir/src/sample_ser.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/sample_ser.cpp.o: ../src/sample_ser.cpp
CMakeFiles/server.dir/src/sample_ser.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/server.dir/src/sample_ser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/sample_ser.cpp.o -MF CMakeFiles/server.dir/src/sample_ser.cpp.o.d -o CMakeFiles/server.dir/src/sample_ser.cpp.o -c /home/luo/code/sample_server/src/sample_ser.cpp

CMakeFiles/server.dir/src/sample_ser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/sample_ser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/sample_ser.cpp > CMakeFiles/server.dir/src/sample_ser.cpp.i

CMakeFiles/server.dir/src/sample_ser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/sample_ser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/sample_ser.cpp -o CMakeFiles/server.dir/src/sample_ser.cpp.s

CMakeFiles/server.dir/src/util.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/util.cpp.o: ../src/util.cpp
CMakeFiles/server.dir/src/util.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/server.dir/src/util.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/src/util.cpp.o -MF CMakeFiles/server.dir/src/util.cpp.o.d -o CMakeFiles/server.dir/src/util.cpp.o -c /home/luo/code/sample_server/src/util.cpp

CMakeFiles/server.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luo/code/sample_server/src/util.cpp > CMakeFiles/server.dir/src/util.cpp.i

CMakeFiles/server.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luo/code/sample_server/src/util.cpp -o CMakeFiles/server.dir/src/util.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/src/Accept.cpp.o" \
"CMakeFiles/server.dir/src/Channel.cpp.o" \
"CMakeFiles/server.dir/src/Epolls.cpp.o" \
"CMakeFiles/server.dir/src/Eventloop.cpp.o" \
"CMakeFiles/server.dir/src/Inet_Addr.cpp.o" \
"CMakeFiles/server.dir/src/Server.cpp.o" \
"CMakeFiles/server.dir/src/Sock.cpp.o" \
"CMakeFiles/server.dir/src/sample_ser.cpp.o" \
"CMakeFiles/server.dir/src/util.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

../server: CMakeFiles/server.dir/src/Accept.cpp.o
../server: CMakeFiles/server.dir/src/Channel.cpp.o
../server: CMakeFiles/server.dir/src/Epolls.cpp.o
../server: CMakeFiles/server.dir/src/Eventloop.cpp.o
../server: CMakeFiles/server.dir/src/Inet_Addr.cpp.o
../server: CMakeFiles/server.dir/src/Server.cpp.o
../server: CMakeFiles/server.dir/src/Sock.cpp.o
../server: CMakeFiles/server.dir/src/sample_ser.cpp.o
../server: CMakeFiles/server.dir/src/util.cpp.o
../server: CMakeFiles/server.dir/build.make
../server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luo/code/sample_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: ../server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/luo/code/sample_server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luo/code/sample_server /home/luo/code/sample_server /home/luo/code/sample_server/build /home/luo/code/sample_server/build /home/luo/code/sample_server/build/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

