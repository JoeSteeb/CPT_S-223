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
CMAKE_SOURCE_DIR = /home/j/code/CPT_S223/PA2/CPT_S-223

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/j/code/CPT_S223/PA2/CPT_S-223/build

# Include any dependencies generated for this target.
include CMakeFiles/CPTS_223_PA2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPTS_223_PA2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPTS_223_PA2.dir/flags.make

CMakeFiles/CPTS_223_PA2.dir/main.cpp.o: CMakeFiles/CPTS_223_PA2.dir/flags.make
CMakeFiles/CPTS_223_PA2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/j/code/CPT_S223/PA2/CPT_S-223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPTS_223_PA2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPTS_223_PA2.dir/main.cpp.o -c /home/j/code/CPT_S223/PA2/CPT_S-223/main.cpp

CMakeFiles/CPTS_223_PA2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPTS_223_PA2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/j/code/CPT_S223/PA2/CPT_S-223/main.cpp > CMakeFiles/CPTS_223_PA2.dir/main.cpp.i

CMakeFiles/CPTS_223_PA2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPTS_223_PA2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/j/code/CPT_S223/PA2/CPT_S-223/main.cpp -o CMakeFiles/CPTS_223_PA2.dir/main.cpp.s

# Object files for target CPTS_223_PA2
CPTS_223_PA2_OBJECTS = \
"CMakeFiles/CPTS_223_PA2.dir/main.cpp.o"

# External object files for target CPTS_223_PA2
CPTS_223_PA2_EXTERNAL_OBJECTS =

CPTS_223_PA2: CMakeFiles/CPTS_223_PA2.dir/main.cpp.o
CPTS_223_PA2: CMakeFiles/CPTS_223_PA2.dir/build.make
CPTS_223_PA2: CMakeFiles/CPTS_223_PA2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/j/code/CPT_S223/PA2/CPT_S-223/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPTS_223_PA2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPTS_223_PA2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPTS_223_PA2.dir/build: CPTS_223_PA2

.PHONY : CMakeFiles/CPTS_223_PA2.dir/build

CMakeFiles/CPTS_223_PA2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPTS_223_PA2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPTS_223_PA2.dir/clean

CMakeFiles/CPTS_223_PA2.dir/depend:
	cd /home/j/code/CPT_S223/PA2/CPT_S-223/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/j/code/CPT_S223/PA2/CPT_S-223 /home/j/code/CPT_S223/PA2/CPT_S-223 /home/j/code/CPT_S223/PA2/CPT_S-223/build /home/j/code/CPT_S223/PA2/CPT_S-223/build /home/j/code/CPT_S223/PA2/CPT_S-223/build/CMakeFiles/CPTS_223_PA2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPTS_223_PA2.dir/depend

