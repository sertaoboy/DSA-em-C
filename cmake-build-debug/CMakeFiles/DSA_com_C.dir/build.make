# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = "/home/raul/Desktop/Projetos Github/DSA-em-C"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/raul/Desktop/Projetos Github/DSA-em-C/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DSA_com_C.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DSA_com_C.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DSA_com_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSA_com_C.dir/flags.make

CMakeFiles/DSA_com_C.dir/codegen:
.PHONY : CMakeFiles/DSA_com_C.dir/codegen

CMakeFiles/DSA_com_C.dir/main.c.o: CMakeFiles/DSA_com_C.dir/flags.make
CMakeFiles/DSA_com_C.dir/main.c.o: /home/raul/Desktop/Projetos\ Github/DSA-em-C/main.c
CMakeFiles/DSA_com_C.dir/main.c.o: CMakeFiles/DSA_com_C.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/raul/Desktop/Projetos Github/DSA-em-C/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DSA_com_C.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DSA_com_C.dir/main.c.o -MF CMakeFiles/DSA_com_C.dir/main.c.o.d -o CMakeFiles/DSA_com_C.dir/main.c.o -c "/home/raul/Desktop/Projetos Github/DSA-em-C/main.c"

CMakeFiles/DSA_com_C.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/DSA_com_C.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/Projetos Github/DSA-em-C/main.c" > CMakeFiles/DSA_com_C.dir/main.c.i

CMakeFiles/DSA_com_C.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/DSA_com_C.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/Projetos Github/DSA-em-C/main.c" -o CMakeFiles/DSA_com_C.dir/main.c.s

CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o: CMakeFiles/DSA_com_C.dir/flags.make
CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o: /home/raul/Desktop/Projetos\ Github/DSA-em-C/Aula2/Exemplos/exercicio.c
CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o: CMakeFiles/DSA_com_C.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/raul/Desktop/Projetos Github/DSA-em-C/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o -MF CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o.d -o CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o -c "/home/raul/Desktop/Projetos Github/DSA-em-C/Aula2/Exemplos/exercicio.c"

CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/Projetos Github/DSA-em-C/Aula2/Exemplos/exercicio.c" > CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.i

CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/Projetos Github/DSA-em-C/Aula2/Exemplos/exercicio.c" -o CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.s

# Object files for target DSA_com_C
DSA_com_C_OBJECTS = \
"CMakeFiles/DSA_com_C.dir/main.c.o" \
"CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o"

# External object files for target DSA_com_C
DSA_com_C_EXTERNAL_OBJECTS =

DSA_com_C: CMakeFiles/DSA_com_C.dir/main.c.o
DSA_com_C: CMakeFiles/DSA_com_C.dir/Aula2/Exemplos/exercicio.c.o
DSA_com_C: CMakeFiles/DSA_com_C.dir/build.make
DSA_com_C: CMakeFiles/DSA_com_C.dir/compiler_depend.ts
DSA_com_C: CMakeFiles/DSA_com_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/raul/Desktop/Projetos Github/DSA-em-C/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable DSA_com_C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DSA_com_C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSA_com_C.dir/build: DSA_com_C
.PHONY : CMakeFiles/DSA_com_C.dir/build

CMakeFiles/DSA_com_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DSA_com_C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DSA_com_C.dir/clean

CMakeFiles/DSA_com_C.dir/depend:
	cd "/home/raul/Desktop/Projetos Github/DSA-em-C/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/raul/Desktop/Projetos Github/DSA-em-C" "/home/raul/Desktop/Projetos Github/DSA-em-C" "/home/raul/Desktop/Projetos Github/DSA-em-C/cmake-build-debug" "/home/raul/Desktop/Projetos Github/DSA-em-C/cmake-build-debug" "/home/raul/Desktop/Projetos Github/DSA-em-C/cmake-build-debug/CMakeFiles/DSA_com_C.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/DSA_com_C.dir/depend

