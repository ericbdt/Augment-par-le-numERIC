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
CMAKE_SOURCE_DIR = /home/ensta/IN204/Augment-par-le-numERIC/repository

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ensta/IN204/Augment-par-le-numERIC/build

# Include any dependencies generated for this target.
include CMakeFiles/sfml-app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml-app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml-app.dir/flags.make

CMakeFiles/sfml-app.dir/src/Enemy.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/Enemy.cpp.o: /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN204/Augment-par-le-numERIC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml-app.dir/src/Enemy.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/Enemy.cpp.o -c /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Enemy.cpp

CMakeFiles/sfml-app.dir/src/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/Enemy.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Enemy.cpp > CMakeFiles/sfml-app.dir/src/Enemy.cpp.i

CMakeFiles/sfml-app.dir/src/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/Enemy.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Enemy.cpp -o CMakeFiles/sfml-app.dir/src/Enemy.cpp.s

CMakeFiles/sfml-app.dir/src/Game.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/Game.cpp.o: /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN204/Augment-par-le-numERIC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfml-app.dir/src/Game.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/Game.cpp.o -c /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Game.cpp

CMakeFiles/sfml-app.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/Game.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Game.cpp > CMakeFiles/sfml-app.dir/src/Game.cpp.i

CMakeFiles/sfml-app.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/Game.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Game.cpp -o CMakeFiles/sfml-app.dir/src/Game.cpp.s

CMakeFiles/sfml-app.dir/src/Player.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/Player.cpp.o: /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN204/Augment-par-le-numERIC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfml-app.dir/src/Player.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/Player.cpp.o -c /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Player.cpp

CMakeFiles/sfml-app.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/Player.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Player.cpp > CMakeFiles/sfml-app.dir/src/Player.cpp.i

CMakeFiles/sfml-app.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/Player.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN204/Augment-par-le-numERIC/repository/src/Player.cpp -o CMakeFiles/sfml-app.dir/src/Player.cpp.s

CMakeFiles/sfml-app.dir/src/main.cpp.o: CMakeFiles/sfml-app.dir/flags.make
CMakeFiles/sfml-app.dir/src/main.cpp.o: /home/ensta/IN204/Augment-par-le-numERIC/repository/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensta/IN204/Augment-par-le-numERIC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sfml-app.dir/src/main.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-app.dir/src/main.cpp.o -c /home/ensta/IN204/Augment-par-le-numERIC/repository/src/main.cpp

CMakeFiles/sfml-app.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-app.dir/src/main.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ensta/IN204/Augment-par-le-numERIC/repository/src/main.cpp > CMakeFiles/sfml-app.dir/src/main.cpp.i

CMakeFiles/sfml-app.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-app.dir/src/main.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ensta/IN204/Augment-par-le-numERIC/repository/src/main.cpp -o CMakeFiles/sfml-app.dir/src/main.cpp.s

# Object files for target sfml-app
sfml__app_OBJECTS = \
"CMakeFiles/sfml-app.dir/src/Enemy.cpp.o" \
"CMakeFiles/sfml-app.dir/src/Game.cpp.o" \
"CMakeFiles/sfml-app.dir/src/Player.cpp.o" \
"CMakeFiles/sfml-app.dir/src/main.cpp.o"

# External object files for target sfml-app
sfml__app_EXTERNAL_OBJECTS =

sfml-app: CMakeFiles/sfml-app.dir/src/Enemy.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/Game.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/Player.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/src/main.cpp.o
sfml-app: CMakeFiles/sfml-app.dir/build.make
sfml-app: CMakeFiles/sfml-app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ensta/IN204/Augment-par-le-numERIC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sfml-app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml-app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml-app.dir/build: sfml-app

.PHONY : CMakeFiles/sfml-app.dir/build

CMakeFiles/sfml-app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml-app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml-app.dir/clean

CMakeFiles/sfml-app.dir/depend:
	cd /home/ensta/IN204/Augment-par-le-numERIC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ensta/IN204/Augment-par-le-numERIC/repository /home/ensta/IN204/Augment-par-le-numERIC/repository /home/ensta/IN204/Augment-par-le-numERIC/build /home/ensta/IN204/Augment-par-le-numERIC/build /home/ensta/IN204/Augment-par-le-numERIC/build/CMakeFiles/sfml-app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml-app.dir/depend

