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
CMAKE_SOURCE_DIR = /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build

# Include any dependencies generated for this target.
include CMakeFiles/3Dlib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3Dlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3Dlib.dir/flags.make

CMakeFiles/3Dlib.dir/src/main.cpp.o: CMakeFiles/3Dlib.dir/flags.make
CMakeFiles/3Dlib.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3Dlib.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3Dlib.dir/src/main.cpp.o -c /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/main.cpp

CMakeFiles/3Dlib.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3Dlib.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/main.cpp > CMakeFiles/3Dlib.dir/src/main.cpp.i

CMakeFiles/3Dlib.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3Dlib.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/main.cpp -o CMakeFiles/3Dlib.dir/src/main.cpp.s

CMakeFiles/3Dlib.dir/src/core/core.cpp.o: CMakeFiles/3Dlib.dir/flags.make
CMakeFiles/3Dlib.dir/src/core/core.cpp.o: ../src/core/core.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/3Dlib.dir/src/core/core.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3Dlib.dir/src/core/core.cpp.o -c /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/core/core.cpp

CMakeFiles/3Dlib.dir/src/core/core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3Dlib.dir/src/core/core.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/core/core.cpp > CMakeFiles/3Dlib.dir/src/core/core.cpp.i

CMakeFiles/3Dlib.dir/src/core/core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3Dlib.dir/src/core/core.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/core/core.cpp -o CMakeFiles/3Dlib.dir/src/core/core.cpp.s

CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.o: CMakeFiles/3Dlib.dir/flags.make
CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.o: ../src/render3D/render3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.o -c /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/render3D/render3D.cpp

CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/render3D/render3D.cpp > CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.i

CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/src/render3D/render3D.cpp -o CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.s

# Object files for target 3Dlib
3Dlib_OBJECTS = \
"CMakeFiles/3Dlib.dir/src/main.cpp.o" \
"CMakeFiles/3Dlib.dir/src/core/core.cpp.o" \
"CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.o"

# External object files for target 3Dlib
3Dlib_EXTERNAL_OBJECTS =

3Dlib: CMakeFiles/3Dlib.dir/src/main.cpp.o
3Dlib: CMakeFiles/3Dlib.dir/src/core/core.cpp.o
3Dlib: CMakeFiles/3Dlib.dir/src/render3D/render3D.cpp.o
3Dlib: CMakeFiles/3Dlib.dir/build.make
3Dlib: CMakeFiles/3Dlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable 3Dlib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3Dlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3Dlib.dir/build: 3Dlib

.PHONY : CMakeFiles/3Dlib.dir/build

CMakeFiles/3Dlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3Dlib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3Dlib.dir/clean

CMakeFiles/3Dlib.dir/depend:
	cd /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build /mnt/c/Users/mano/ubuntu/perso/PRS_2021_cpp_3DSFML/build/CMakeFiles/3Dlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3Dlib.dir/depend

