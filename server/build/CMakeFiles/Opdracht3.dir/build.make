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
CMAKE_SOURCE_DIR = /home/pi/embed2/Opdracht-3-MQTT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/embed2/Opdracht-3-MQTT/build

# Include any dependencies generated for this target.
include CMakeFiles/Opdracht3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Opdracht3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Opdracht3.dir/flags.make

CMakeFiles/Opdracht3.dir/sub.c.o: CMakeFiles/Opdracht3.dir/flags.make
CMakeFiles/Opdracht3.dir/sub.c.o: ../sub.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/embed2/Opdracht-3-MQTT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Opdracht3.dir/sub.c.o"
	/bin/gcc-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Opdracht3.dir/sub.c.o   -c /home/pi/embed2/Opdracht-3-MQTT/sub.c

CMakeFiles/Opdracht3.dir/sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Opdracht3.dir/sub.c.i"
	/bin/gcc-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/embed2/Opdracht-3-MQTT/sub.c > CMakeFiles/Opdracht3.dir/sub.c.i

CMakeFiles/Opdracht3.dir/sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Opdracht3.dir/sub.c.s"
	/bin/gcc-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/embed2/Opdracht-3-MQTT/sub.c -o CMakeFiles/Opdracht3.dir/sub.c.s

# Object files for target Opdracht3
Opdracht3_OBJECTS = \
"CMakeFiles/Opdracht3.dir/sub.c.o"

# External object files for target Opdracht3
Opdracht3_EXTERNAL_OBJECTS =

Opdracht3: CMakeFiles/Opdracht3.dir/sub.c.o
Opdracht3: CMakeFiles/Opdracht3.dir/build.make
Opdracht3: CMakeFiles/Opdracht3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/embed2/Opdracht-3-MQTT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Opdracht3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Opdracht3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Opdracht3.dir/build: Opdracht3

.PHONY : CMakeFiles/Opdracht3.dir/build

CMakeFiles/Opdracht3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Opdracht3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Opdracht3.dir/clean

CMakeFiles/Opdracht3.dir/depend:
	cd /home/pi/embed2/Opdracht-3-MQTT/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/embed2/Opdracht-3-MQTT /home/pi/embed2/Opdracht-3-MQTT /home/pi/embed2/Opdracht-3-MQTT/build /home/pi/embed2/Opdracht-3-MQTT/build /home/pi/embed2/Opdracht-3-MQTT/build/CMakeFiles/Opdracht3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Opdracht3.dir/depend

