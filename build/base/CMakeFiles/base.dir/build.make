# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/fellas/scratch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fellas/scratch/build

# Include any dependencies generated for this target.
include base/CMakeFiles/base.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include base/CMakeFiles/base.dir/compiler_depend.make

# Include the progress variables for this target.
include base/CMakeFiles/base.dir/progress.make

# Include the compile flags for this target's objects.
include base/CMakeFiles/base.dir/flags.make

base/CMakeFiles/base.dir/src/s8.c.o: base/CMakeFiles/base.dir/flags.make
base/CMakeFiles/base.dir/src/s8.c.o: /home/fellas/scratch/base/src/s8.c
base/CMakeFiles/base.dir/src/s8.c.o: base/CMakeFiles/base.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fellas/scratch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object base/CMakeFiles/base.dir/src/s8.c.o"
	cd /home/fellas/scratch/build/base && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT base/CMakeFiles/base.dir/src/s8.c.o -MF CMakeFiles/base.dir/src/s8.c.o.d -o CMakeFiles/base.dir/src/s8.c.o -c /home/fellas/scratch/base/src/s8.c

base/CMakeFiles/base.dir/src/s8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/base.dir/src/s8.c.i"
	cd /home/fellas/scratch/build/base && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fellas/scratch/base/src/s8.c > CMakeFiles/base.dir/src/s8.c.i

base/CMakeFiles/base.dir/src/s8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/base.dir/src/s8.c.s"
	cd /home/fellas/scratch/build/base && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fellas/scratch/base/src/s8.c -o CMakeFiles/base.dir/src/s8.c.s

# Object files for target base
base_OBJECTS = \
"CMakeFiles/base.dir/src/s8.c.o"

# External object files for target base
base_EXTERNAL_OBJECTS =

base/libbase.a: base/CMakeFiles/base.dir/src/s8.c.o
base/libbase.a: base/CMakeFiles/base.dir/build.make
base/libbase.a: base/CMakeFiles/base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fellas/scratch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libbase.a"
	cd /home/fellas/scratch/build/base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean_target.cmake
	cd /home/fellas/scratch/build/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/CMakeFiles/base.dir/build: base/libbase.a
.PHONY : base/CMakeFiles/base.dir/build

base/CMakeFiles/base.dir/clean:
	cd /home/fellas/scratch/build/base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean.cmake
.PHONY : base/CMakeFiles/base.dir/clean

base/CMakeFiles/base.dir/depend:
	cd /home/fellas/scratch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fellas/scratch /home/fellas/scratch/base /home/fellas/scratch/build /home/fellas/scratch/build/base /home/fellas/scratch/build/base/CMakeFiles/base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/CMakeFiles/base.dir/depend

