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
CMAKE_SOURCE_DIR = /home/sleiman/Projeto-CG-21-22/phase4.1/Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sleiman/Projeto-CG-21-22/phase4.1/Engine

# Include any dependencies generated for this target.
include CMakeFiles/engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine.dir/flags.make

CMakeFiles/engine.dir/src/main.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/engine.dir/src/main.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/main.cpp.o -MF CMakeFiles/engine.dir/src/main.cpp.o.d -o CMakeFiles/engine.dir/src/main.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/main.cpp

CMakeFiles/engine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/main.cpp > CMakeFiles/engine.dir/src/main.cpp.i

CMakeFiles/engine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/main.cpp -o CMakeFiles/engine.dir/src/main.cpp.s

CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o: /home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp
CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o -MF CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o.d -o CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp

CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp > CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.i

CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp -o CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.s

CMakeFiles/engine.dir/src/Group.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Group.cpp.o: src/Group.cpp
CMakeFiles/engine.dir/src/Group.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/src/Group.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Group.cpp.o -MF CMakeFiles/engine.dir/src/Group.cpp.o.d -o CMakeFiles/engine.dir/src/Group.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Group.cpp

CMakeFiles/engine.dir/src/Group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Group.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Group.cpp > CMakeFiles/engine.dir/src/Group.cpp.i

CMakeFiles/engine.dir/src/Group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Group.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Group.cpp -o CMakeFiles/engine.dir/src/Group.cpp.s

CMakeFiles/engine.dir/src/VBO.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/VBO.cpp.o: src/VBO.cpp
CMakeFiles/engine.dir/src/VBO.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine.dir/src/VBO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/VBO.cpp.o -MF CMakeFiles/engine.dir/src/VBO.cpp.o.d -o CMakeFiles/engine.dir/src/VBO.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/VBO.cpp

CMakeFiles/engine.dir/src/VBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/VBO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/VBO.cpp > CMakeFiles/engine.dir/src/VBO.cpp.i

CMakeFiles/engine.dir/src/VBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/VBO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/VBO.cpp -o CMakeFiles/engine.dir/src/VBO.cpp.s

CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o: src/Transformations/Rotation.cpp
CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o -MF CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o.d -o CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Rotation.cpp

CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Rotation.cpp > CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.i

CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Rotation.cpp -o CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.s

CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o: src/Transformations/Translation.cpp
CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o -MF CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o.d -o CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Translation.cpp

CMakeFiles/engine.dir/src/Transformations/Translation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Transformations/Translation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Translation.cpp > CMakeFiles/engine.dir/src/Transformations/Translation.cpp.i

CMakeFiles/engine.dir/src/Transformations/Translation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Transformations/Translation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Translation.cpp -o CMakeFiles/engine.dir/src/Transformations/Translation.cpp.s

CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o: src/Transformations/Scale.cpp
CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o -MF CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o.d -o CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Scale.cpp

CMakeFiles/engine.dir/src/Transformations/Scale.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Transformations/Scale.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Scale.cpp > CMakeFiles/engine.dir/src/Transformations/Scale.cpp.i

CMakeFiles/engine.dir/src/Transformations/Scale.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Transformations/Scale.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Transformations/Scale.cpp -o CMakeFiles/engine.dir/src/Transformations/Scale.cpp.s

CMakeFiles/engine.dir/src/Figure.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Figure.cpp.o: src/Figure.cpp
CMakeFiles/engine.dir/src/Figure.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/engine.dir/src/Figure.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Figure.cpp.o -MF CMakeFiles/engine.dir/src/Figure.cpp.o.d -o CMakeFiles/engine.dir/src/Figure.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Figure.cpp

CMakeFiles/engine.dir/src/Figure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Figure.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Figure.cpp > CMakeFiles/engine.dir/src/Figure.cpp.i

CMakeFiles/engine.dir/src/Figure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Figure.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Figure.cpp -o CMakeFiles/engine.dir/src/Figure.cpp.s

CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o: src/Lights/DirectionalLight.cpp
CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o -MF CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o.d -o CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/DirectionalLight.cpp

CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/DirectionalLight.cpp > CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.i

CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/DirectionalLight.cpp -o CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.s

CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o: src/Lights/PointLight.cpp
CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o -MF CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o.d -o CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/PointLight.cpp

CMakeFiles/engine.dir/src/Lights/PointLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Lights/PointLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/PointLight.cpp > CMakeFiles/engine.dir/src/Lights/PointLight.cpp.i

CMakeFiles/engine.dir/src/Lights/PointLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Lights/PointLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/PointLight.cpp -o CMakeFiles/engine.dir/src/Lights/PointLight.cpp.s

CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o: src/Lights/SpotLight.cpp
CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o -MF CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o.d -o CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/SpotLight.cpp

CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/SpotLight.cpp > CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.i

CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Lights/SpotLight.cpp -o CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.s

CMakeFiles/engine.dir/src/Plane.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Plane.cpp.o: src/Plane.cpp
CMakeFiles/engine.dir/src/Plane.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/engine.dir/src/Plane.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Plane.cpp.o -MF CMakeFiles/engine.dir/src/Plane.cpp.o.d -o CMakeFiles/engine.dir/src/Plane.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Plane.cpp

CMakeFiles/engine.dir/src/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Plane.cpp > CMakeFiles/engine.dir/src/Plane.cpp.i

CMakeFiles/engine.dir/src/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Plane.cpp -o CMakeFiles/engine.dir/src/Plane.cpp.s

CMakeFiles/engine.dir/src/Frustum.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Frustum.cpp.o: src/Frustum.cpp
CMakeFiles/engine.dir/src/Frustum.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/engine.dir/src/Frustum.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/src/Frustum.cpp.o -MF CMakeFiles/engine.dir/src/Frustum.cpp.o.d -o CMakeFiles/engine.dir/src/Frustum.cpp.o -c /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Frustum.cpp

CMakeFiles/engine.dir/src/Frustum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Frustum.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Frustum.cpp > CMakeFiles/engine.dir/src/Frustum.cpp.i

CMakeFiles/engine.dir/src/Frustum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Frustum.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/src/Frustum.cpp -o CMakeFiles/engine.dir/src/Frustum.cpp.s

# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/src/main.cpp.o" \
"CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o" \
"CMakeFiles/engine.dir/src/Group.cpp.o" \
"CMakeFiles/engine.dir/src/VBO.cpp.o" \
"CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o" \
"CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o" \
"CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o" \
"CMakeFiles/engine.dir/src/Figure.cpp.o" \
"CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o" \
"CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o" \
"CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o" \
"CMakeFiles/engine.dir/src/Plane.cpp.o" \
"CMakeFiles/engine.dir/src/Frustum.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

engine: CMakeFiles/engine.dir/src/main.cpp.o
engine: CMakeFiles/engine.dir/home/sleiman/Projeto-CG-21-22/phase4.1/Utils/Point3D.cpp.o
engine: CMakeFiles/engine.dir/src/Group.cpp.o
engine: CMakeFiles/engine.dir/src/VBO.cpp.o
engine: CMakeFiles/engine.dir/src/Transformations/Rotation.cpp.o
engine: CMakeFiles/engine.dir/src/Transformations/Translation.cpp.o
engine: CMakeFiles/engine.dir/src/Transformations/Scale.cpp.o
engine: CMakeFiles/engine.dir/src/Figure.cpp.o
engine: CMakeFiles/engine.dir/src/Lights/DirectionalLight.cpp.o
engine: CMakeFiles/engine.dir/src/Lights/PointLight.cpp.o
engine: CMakeFiles/engine.dir/src/Lights/SpotLight.cpp.o
engine: CMakeFiles/engine.dir/src/Plane.cpp.o
engine: CMakeFiles/engine.dir/src/Frustum.cpp.o
engine: CMakeFiles/engine.dir/build.make
engine: libxmlParser.a
engine: /usr/lib/x86_64-linux-gnu/libGL.so
engine: /usr/lib/x86_64-linux-gnu/libGLU.so
engine: /usr/lib/x86_64-linux-gnu/libglut.so
engine: /usr/lib/x86_64-linux-gnu/libGLEW.so
engine: /usr/lib/x86_64-linux-gnu/libIL.so
engine: CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engine.dir/build: engine
.PHONY : CMakeFiles/engine.dir/build

CMakeFiles/engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine.dir/clean

CMakeFiles/engine.dir/depend:
	cd /home/sleiman/Projeto-CG-21-22/phase4.1/Engine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sleiman/Projeto-CG-21-22/phase4.1/Engine /home/sleiman/Projeto-CG-21-22/phase4.1/Engine /home/sleiman/Projeto-CG-21-22/phase4.1/Engine /home/sleiman/Projeto-CG-21-22/phase4.1/Engine /home/sleiman/Projeto-CG-21-22/phase4.1/Engine/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine.dir/depend

