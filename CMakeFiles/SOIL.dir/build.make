# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /Data/Dropbox/Study/University/Машграф/projects/mashgraph3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Data/Dropbox/Study/University/Машграф/projects/mashgraph3

# Include any dependencies generated for this target.
include CMakeFiles/SOIL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SOIL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SOIL.dir/flags.make

CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o: CMakeFiles/SOIL.dir/flags.make
CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o: SOIL/src/image_DXT.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Data/Dropbox/Study/University/Машграф/projects/mashgraph3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o   -c /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/image_DXT.c

CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/image_DXT.c > CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.i

CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/image_DXT.c -o CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.s

CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o.requires:

.PHONY : CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o.requires

CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o.provides: CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o.requires
	$(MAKE) -f CMakeFiles/SOIL.dir/build.make CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o.provides.build
.PHONY : CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o.provides

CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o.provides.build: CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o


CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o: CMakeFiles/SOIL.dir/flags.make
CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o: SOIL/src/stb_image_aug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Data/Dropbox/Study/University/Машграф/projects/mashgraph3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o   -c /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/stb_image_aug.c

CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/stb_image_aug.c > CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.i

CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/stb_image_aug.c -o CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.s

CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o.requires:

.PHONY : CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o.requires

CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o.provides: CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o.requires
	$(MAKE) -f CMakeFiles/SOIL.dir/build.make CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o.provides.build
.PHONY : CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o.provides

CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o.provides.build: CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o


CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o: CMakeFiles/SOIL.dir/flags.make
CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o: SOIL/src/image_helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Data/Dropbox/Study/University/Машграф/projects/mashgraph3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o   -c /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/image_helper.c

CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/image_helper.c > CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.i

CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/image_helper.c -o CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.s

CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o.requires:

.PHONY : CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o.requires

CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o.provides: CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o.requires
	$(MAKE) -f CMakeFiles/SOIL.dir/build.make CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o.provides.build
.PHONY : CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o.provides

CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o.provides.build: CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o


CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o: CMakeFiles/SOIL.dir/flags.make
CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o: SOIL/src/SOIL.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Data/Dropbox/Study/University/Машграф/projects/mashgraph3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o   -c /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/SOIL.c

CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/SOIL.c > CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.i

CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/SOIL.c -o CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.s

CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o.requires:

.PHONY : CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o.requires

CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o.provides: CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o.requires
	$(MAKE) -f CMakeFiles/SOIL.dir/build.make CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o.provides.build
.PHONY : CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o.provides

CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o.provides.build: CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o


CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o: CMakeFiles/SOIL.dir/flags.make
CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o: SOIL/src/original/stb_image-1.09.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Data/Dropbox/Study/University/Машграф/projects/mashgraph3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o   -c /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/original/stb_image-1.09.c

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/original/stb_image-1.09.c > CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.i

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/original/stb_image-1.09.c -o CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.s

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o.requires:

.PHONY : CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o.requires

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o.provides: CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o.requires
	$(MAKE) -f CMakeFiles/SOIL.dir/build.make CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o.provides.build
.PHONY : CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o.provides

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o.provides.build: CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o


CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o: CMakeFiles/SOIL.dir/flags.make
CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o: SOIL/src/original/stb_image-1.16.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Data/Dropbox/Study/University/Машграф/projects/mashgraph3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o   -c /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/original/stb_image-1.16.c

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/original/stb_image-1.16.c > CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.i

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/SOIL/src/original/stb_image-1.16.c -o CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.s

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o.requires:

.PHONY : CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o.requires

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o.provides: CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o.requires
	$(MAKE) -f CMakeFiles/SOIL.dir/build.make CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o.provides.build
.PHONY : CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o.provides

CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o.provides.build: CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o


# Object files for target SOIL
SOIL_OBJECTS = \
"CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o" \
"CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o" \
"CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o" \
"CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o" \
"CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o" \
"CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o"

# External object files for target SOIL
SOIL_EXTERNAL_OBJECTS =

libSOIL.a: CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o
libSOIL.a: CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o
libSOIL.a: CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o
libSOIL.a: CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o
libSOIL.a: CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o
libSOIL.a: CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o
libSOIL.a: CMakeFiles/SOIL.dir/build.make
libSOIL.a: CMakeFiles/SOIL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Data/Dropbox/Study/University/Машграф/projects/mashgraph3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libSOIL.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SOIL.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SOIL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SOIL.dir/build: libSOIL.a

.PHONY : CMakeFiles/SOIL.dir/build

CMakeFiles/SOIL.dir/requires: CMakeFiles/SOIL.dir/SOIL/src/image_DXT.c.o.requires
CMakeFiles/SOIL.dir/requires: CMakeFiles/SOIL.dir/SOIL/src/stb_image_aug.c.o.requires
CMakeFiles/SOIL.dir/requires: CMakeFiles/SOIL.dir/SOIL/src/image_helper.c.o.requires
CMakeFiles/SOIL.dir/requires: CMakeFiles/SOIL.dir/SOIL/src/SOIL.c.o.requires
CMakeFiles/SOIL.dir/requires: CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.09.c.o.requires
CMakeFiles/SOIL.dir/requires: CMakeFiles/SOIL.dir/SOIL/src/original/stb_image-1.16.c.o.requires

.PHONY : CMakeFiles/SOIL.dir/requires

CMakeFiles/SOIL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SOIL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SOIL.dir/clean

CMakeFiles/SOIL.dir/depend:
	cd /Data/Dropbox/Study/University/Машграф/projects/mashgraph3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Data/Dropbox/Study/University/Машграф/projects/mashgraph3 /Data/Dropbox/Study/University/Машграф/projects/mashgraph3 /Data/Dropbox/Study/University/Машграф/projects/mashgraph3 /Data/Dropbox/Study/University/Машграф/projects/mashgraph3 /Data/Dropbox/Study/University/Машграф/projects/mashgraph3/CMakeFiles/SOIL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SOIL.dir/depend
