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
CMAKE_SOURCE_DIR = /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/build

# Include any dependencies generated for this target.
include CMakeFiles/StringSet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StringSet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StringSet.dir/flags.make

CMakeFiles/StringSet.dir/StringSet.cpp.o: CMakeFiles/StringSet.dir/flags.make
CMakeFiles/StringSet.dir/StringSet.cpp.o: ../StringSet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StringSet.dir/StringSet.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StringSet.dir/StringSet.cpp.o -c /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/StringSet.cpp

CMakeFiles/StringSet.dir/StringSet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringSet.dir/StringSet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/StringSet.cpp > CMakeFiles/StringSet.dir/StringSet.cpp.i

CMakeFiles/StringSet.dir/StringSet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringSet.dir/StringSet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/StringSet.cpp -o CMakeFiles/StringSet.dir/StringSet.cpp.s

# Object files for target StringSet
StringSet_OBJECTS = \
"CMakeFiles/StringSet.dir/StringSet.cpp.o"

# External object files for target StringSet
StringSet_EXTERNAL_OBJECTS =

StringSet: CMakeFiles/StringSet.dir/StringSet.cpp.o
StringSet: CMakeFiles/StringSet.dir/build.make
StringSet: CMakeFiles/StringSet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StringSet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StringSet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StringSet.dir/build: StringSet

.PHONY : CMakeFiles/StringSet.dir/build

CMakeFiles/StringSet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StringSet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StringSet.dir/clean

CMakeFiles/StringSet.dir/depend:
	cd /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/build /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/build /home/glushkov/projects/cpp-yandex-course/03-rb/m-05/StringSet/build/CMakeFiles/StringSet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StringSet.dir/depend

