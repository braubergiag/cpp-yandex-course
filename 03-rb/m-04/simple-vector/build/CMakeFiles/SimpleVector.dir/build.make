# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/cmake/852/bin/cmake

# The command to remove a file.
RM = /snap/cmake/852/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/build

# Include any dependencies generated for this target.
include CMakeFiles/SimpleVector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleVector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleVector.dir/flags.make

CMakeFiles/SimpleVector.dir/simple_vector.cpp.o: CMakeFiles/SimpleVector.dir/flags.make
CMakeFiles/SimpleVector.dir/simple_vector.cpp.o: ../simple_vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimpleVector.dir/simple_vector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleVector.dir/simple_vector.cpp.o -c /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/simple_vector.cpp

CMakeFiles/SimpleVector.dir/simple_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleVector.dir/simple_vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/simple_vector.cpp > CMakeFiles/SimpleVector.dir/simple_vector.cpp.i

CMakeFiles/SimpleVector.dir/simple_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleVector.dir/simple_vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/simple_vector.cpp -o CMakeFiles/SimpleVector.dir/simple_vector.cpp.s

# Object files for target SimpleVector
SimpleVector_OBJECTS = \
"CMakeFiles/SimpleVector.dir/simple_vector.cpp.o"

# External object files for target SimpleVector
SimpleVector_EXTERNAL_OBJECTS =

SimpleVector: CMakeFiles/SimpleVector.dir/simple_vector.cpp.o
SimpleVector: CMakeFiles/SimpleVector.dir/build.make
SimpleVector: CMakeFiles/SimpleVector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SimpleVector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleVector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleVector.dir/build: SimpleVector

.PHONY : CMakeFiles/SimpleVector.dir/build

CMakeFiles/SimpleVector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleVector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleVector.dir/clean

CMakeFiles/SimpleVector.dir/depend:
	cd /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/build /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/build /home/glushkov/projects/cpp-yandex-course/03-rb/m-04/simple-vector/build/CMakeFiles/SimpleVector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleVector.dir/depend

