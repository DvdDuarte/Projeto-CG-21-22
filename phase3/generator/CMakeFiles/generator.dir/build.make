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
CMAKE_SOURCE_DIR = /home/sdaslira/Projeto-CG-21-22/phase3/generator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sdaslira/Projeto-CG-21-22/phase3/generator

# Include any dependencies generated for this target.
include CMakeFiles/generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generator.dir/flags.make

CMakeFiles/generator.dir/generator.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/generator.cpp.o: generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sdaslira/Projeto-CG-21-22/phase3/generator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/generator.dir/generator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/generator.cpp.o -c /home/sdaslira/Projeto-CG-21-22/phase3/generator/generator.cpp

CMakeFiles/generator.dir/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sdaslira/Projeto-CG-21-22/phase3/generator/generator.cpp > CMakeFiles/generator.dir/generator.cpp.i

CMakeFiles/generator.dir/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sdaslira/Projeto-CG-21-22/phase3/generator/generator.cpp -o CMakeFiles/generator.dir/generator.cpp.s

CMakeFiles/generator.dir/generator_aux.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/generator_aux.cpp.o: generator_aux.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sdaslira/Projeto-CG-21-22/phase3/generator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/generator.dir/generator_aux.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generator.dir/generator_aux.cpp.o -c /home/sdaslira/Projeto-CG-21-22/phase3/generator/generator_aux.cpp

CMakeFiles/generator.dir/generator_aux.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/generator_aux.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sdaslira/Projeto-CG-21-22/phase3/generator/generator_aux.cpp > CMakeFiles/generator.dir/generator_aux.cpp.i

CMakeFiles/generator.dir/generator_aux.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/generator_aux.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sdaslira/Projeto-CG-21-22/phase3/generator/generator_aux.cpp -o CMakeFiles/generator.dir/generator_aux.cpp.s

# Object files for target generator
generator_OBJECTS = \
"CMakeFiles/generator.dir/generator.cpp.o" \
"CMakeFiles/generator.dir/generator_aux.cpp.o"

# External object files for target generator
generator_EXTERNAL_OBJECTS =

generator: CMakeFiles/generator.dir/generator.cpp.o
generator: CMakeFiles/generator.dir/generator_aux.cpp.o
generator: CMakeFiles/generator.dir/build.make
generator: /usr/lib/x86_64-linux-gnu/libGL.so
generator: /usr/lib/x86_64-linux-gnu/libGLU.so
generator: /usr/lib/x86_64-linux-gnu/libglut.so
generator: /usr/lib/x86_64-linux-gnu/libXmu.so
generator: /usr/lib/x86_64-linux-gnu/libXi.so
generator: CMakeFiles/generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sdaslira/Projeto-CG-21-22/phase3/generator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generator.dir/build: generator

.PHONY : CMakeFiles/generator.dir/build

CMakeFiles/generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generator.dir/clean

CMakeFiles/generator.dir/depend:
	cd /home/sdaslira/Projeto-CG-21-22/phase3/generator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sdaslira/Projeto-CG-21-22/phase3/generator /home/sdaslira/Projeto-CG-21-22/phase3/generator /home/sdaslira/Projeto-CG-21-22/phase3/generator /home/sdaslira/Projeto-CG-21-22/phase3/generator /home/sdaslira/Projeto-CG-21-22/phase3/generator/CMakeFiles/generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/generator.dir/depend

