# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/joel/Projects/FixedPoint

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joel/Projects/FixedPoint/build

# Include any dependencies generated for this target.
include Tests/CMakeFiles/Tests.dir/depend.make

# Include the progress variables for this target.
include Tests/CMakeFiles/Tests.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeFiles/Tests.dir/flags.make

Tests/CMakeFiles/Tests.dir/test.o: Tests/CMakeFiles/Tests.dir/flags.make
Tests/CMakeFiles/Tests.dir/test.o: ../Tests/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joel/Projects/FixedPoint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/CMakeFiles/Tests.dir/test.o"
	cd /home/joel/Projects/FixedPoint/build/Tests && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tests.dir/test.o -c /home/joel/Projects/FixedPoint/Tests/test.cpp

Tests/CMakeFiles/Tests.dir/test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/test.i"
	cd /home/joel/Projects/FixedPoint/build/Tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joel/Projects/FixedPoint/Tests/test.cpp > CMakeFiles/Tests.dir/test.i

Tests/CMakeFiles/Tests.dir/test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/test.s"
	cd /home/joel/Projects/FixedPoint/build/Tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joel/Projects/FixedPoint/Tests/test.cpp -o CMakeFiles/Tests.dir/test.s

# Object files for target Tests
Tests_OBJECTS = \
"CMakeFiles/Tests.dir/test.o"

# External object files for target Tests
Tests_EXTERNAL_OBJECTS =

Tests/Tests: Tests/CMakeFiles/Tests.dir/test.o
Tests/Tests: Tests/CMakeFiles/Tests.dir/build.make
Tests/Tests: Tests/CMakeFiles/Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joel/Projects/FixedPoint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tests"
	cd /home/joel/Projects/FixedPoint/build/Tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeFiles/Tests.dir/build: Tests/Tests

.PHONY : Tests/CMakeFiles/Tests.dir/build

Tests/CMakeFiles/Tests.dir/clean:
	cd /home/joel/Projects/FixedPoint/build/Tests && $(CMAKE_COMMAND) -P CMakeFiles/Tests.dir/cmake_clean.cmake
.PHONY : Tests/CMakeFiles/Tests.dir/clean

Tests/CMakeFiles/Tests.dir/depend:
	cd /home/joel/Projects/FixedPoint/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joel/Projects/FixedPoint /home/joel/Projects/FixedPoint/Tests /home/joel/Projects/FixedPoint/build /home/joel/Projects/FixedPoint/build/Tests /home/joel/Projects/FixedPoint/build/Tests/CMakeFiles/Tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/CMakeFiles/Tests.dir/depend
