# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\GitHub\MyLeetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\GitHub\MyLeetcode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MyLeetcode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyLeetcode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyLeetcode.dir/flags.make

CMakeFiles/MyLeetcode.dir/main.c.obj: CMakeFiles/MyLeetcode.dir/flags.make
CMakeFiles/MyLeetcode.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\GitHub\MyLeetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyLeetcode.dir/main.c.obj"
	"D:\Program Files\MinGW64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MyLeetcode.dir\main.c.obj   -c E:\GitHub\MyLeetcode\main.c

CMakeFiles/MyLeetcode.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyLeetcode.dir/main.c.i"
	"D:\Program Files\MinGW64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\GitHub\MyLeetcode\main.c > CMakeFiles\MyLeetcode.dir\main.c.i

CMakeFiles/MyLeetcode.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyLeetcode.dir/main.c.s"
	"D:\Program Files\MinGW64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\GitHub\MyLeetcode\main.c -o CMakeFiles\MyLeetcode.dir\main.c.s

# Object files for target MyLeetcode
MyLeetcode_OBJECTS = \
"CMakeFiles/MyLeetcode.dir/main.c.obj"

# External object files for target MyLeetcode
MyLeetcode_EXTERNAL_OBJECTS =

MyLeetcode.exe: CMakeFiles/MyLeetcode.dir/main.c.obj
MyLeetcode.exe: CMakeFiles/MyLeetcode.dir/build.make
MyLeetcode.exe: CMakeFiles/MyLeetcode.dir/linklibs.rsp
MyLeetcode.exe: CMakeFiles/MyLeetcode.dir/objects1.rsp
MyLeetcode.exe: CMakeFiles/MyLeetcode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\GitHub\MyLeetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable MyLeetcode.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyLeetcode.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyLeetcode.dir/build: MyLeetcode.exe

.PHONY : CMakeFiles/MyLeetcode.dir/build

CMakeFiles/MyLeetcode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyLeetcode.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyLeetcode.dir/clean

CMakeFiles/MyLeetcode.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GitHub\MyLeetcode E:\GitHub\MyLeetcode E:\GitHub\MyLeetcode\cmake-build-debug E:\GitHub\MyLeetcode\cmake-build-debug E:\GitHub\MyLeetcode\cmake-build-debug\CMakeFiles\MyLeetcode.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyLeetcode.dir/depend

