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
CMAKE_SOURCE_DIR = /home/neuralnuts/Projects/Nippy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neuralnuts/Projects/Nippy/build

# Include any dependencies generated for this target.
include CMakeFiles/nippy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/nippy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/nippy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nippy.dir/flags.make

CMakeFiles/nippy.dir/src/main.c.o: CMakeFiles/nippy.dir/flags.make
CMakeFiles/nippy.dir/src/main.c.o: ../src/main.c
CMakeFiles/nippy.dir/src/main.c.o: CMakeFiles/nippy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neuralnuts/Projects/Nippy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/nippy.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nippy.dir/src/main.c.o -MF CMakeFiles/nippy.dir/src/main.c.o.d -o CMakeFiles/nippy.dir/src/main.c.o -c /home/neuralnuts/Projects/Nippy/src/main.c

CMakeFiles/nippy.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nippy.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neuralnuts/Projects/Nippy/src/main.c > CMakeFiles/nippy.dir/src/main.c.i

CMakeFiles/nippy.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nippy.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neuralnuts/Projects/Nippy/src/main.c -o CMakeFiles/nippy.dir/src/main.c.s

CMakeFiles/nippy.dir/src/tokenizer.c.o: CMakeFiles/nippy.dir/flags.make
CMakeFiles/nippy.dir/src/tokenizer.c.o: ../src/tokenizer.c
CMakeFiles/nippy.dir/src/tokenizer.c.o: CMakeFiles/nippy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neuralnuts/Projects/Nippy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/nippy.dir/src/tokenizer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nippy.dir/src/tokenizer.c.o -MF CMakeFiles/nippy.dir/src/tokenizer.c.o.d -o CMakeFiles/nippy.dir/src/tokenizer.c.o -c /home/neuralnuts/Projects/Nippy/src/tokenizer.c

CMakeFiles/nippy.dir/src/tokenizer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nippy.dir/src/tokenizer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neuralnuts/Projects/Nippy/src/tokenizer.c > CMakeFiles/nippy.dir/src/tokenizer.c.i

CMakeFiles/nippy.dir/src/tokenizer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nippy.dir/src/tokenizer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neuralnuts/Projects/Nippy/src/tokenizer.c -o CMakeFiles/nippy.dir/src/tokenizer.c.s

CMakeFiles/nippy.dir/tests/lexer_tests.c.o: CMakeFiles/nippy.dir/flags.make
CMakeFiles/nippy.dir/tests/lexer_tests.c.o: ../tests/lexer_tests.c
CMakeFiles/nippy.dir/tests/lexer_tests.c.o: CMakeFiles/nippy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neuralnuts/Projects/Nippy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/nippy.dir/tests/lexer_tests.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nippy.dir/tests/lexer_tests.c.o -MF CMakeFiles/nippy.dir/tests/lexer_tests.c.o.d -o CMakeFiles/nippy.dir/tests/lexer_tests.c.o -c /home/neuralnuts/Projects/Nippy/tests/lexer_tests.c

CMakeFiles/nippy.dir/tests/lexer_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nippy.dir/tests/lexer_tests.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neuralnuts/Projects/Nippy/tests/lexer_tests.c > CMakeFiles/nippy.dir/tests/lexer_tests.c.i

CMakeFiles/nippy.dir/tests/lexer_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nippy.dir/tests/lexer_tests.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neuralnuts/Projects/Nippy/tests/lexer_tests.c -o CMakeFiles/nippy.dir/tests/lexer_tests.c.s

CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o: CMakeFiles/nippy.dir/flags.make
CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o: ../lib/file_functions_lib/src/file_functions.c
CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o: CMakeFiles/nippy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neuralnuts/Projects/Nippy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o -MF CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o.d -o CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o -c /home/neuralnuts/Projects/Nippy/lib/file_functions_lib/src/file_functions.c

CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neuralnuts/Projects/Nippy/lib/file_functions_lib/src/file_functions.c > CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.i

CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neuralnuts/Projects/Nippy/lib/file_functions_lib/src/file_functions.c -o CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.s

CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o: CMakeFiles/nippy.dir/flags.make
CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o: ../lib/color_printf_lib/src/color_print.c
CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o: CMakeFiles/nippy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neuralnuts/Projects/Nippy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o -MF CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o.d -o CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o -c /home/neuralnuts/Projects/Nippy/lib/color_printf_lib/src/color_print.c

CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neuralnuts/Projects/Nippy/lib/color_printf_lib/src/color_print.c > CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.i

CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neuralnuts/Projects/Nippy/lib/color_printf_lib/src/color_print.c -o CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.s

CMakeFiles/nippy.dir/src/variable_map.c.o: CMakeFiles/nippy.dir/flags.make
CMakeFiles/nippy.dir/src/variable_map.c.o: ../src/variable_map.c
CMakeFiles/nippy.dir/src/variable_map.c.o: CMakeFiles/nippy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neuralnuts/Projects/Nippy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/nippy.dir/src/variable_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nippy.dir/src/variable_map.c.o -MF CMakeFiles/nippy.dir/src/variable_map.c.o.d -o CMakeFiles/nippy.dir/src/variable_map.c.o -c /home/neuralnuts/Projects/Nippy/src/variable_map.c

CMakeFiles/nippy.dir/src/variable_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nippy.dir/src/variable_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neuralnuts/Projects/Nippy/src/variable_map.c > CMakeFiles/nippy.dir/src/variable_map.c.i

CMakeFiles/nippy.dir/src/variable_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nippy.dir/src/variable_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neuralnuts/Projects/Nippy/src/variable_map.c -o CMakeFiles/nippy.dir/src/variable_map.c.s

CMakeFiles/nippy.dir/src/ast.c.o: CMakeFiles/nippy.dir/flags.make
CMakeFiles/nippy.dir/src/ast.c.o: ../src/ast.c
CMakeFiles/nippy.dir/src/ast.c.o: CMakeFiles/nippy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neuralnuts/Projects/Nippy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/nippy.dir/src/ast.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/nippy.dir/src/ast.c.o -MF CMakeFiles/nippy.dir/src/ast.c.o.d -o CMakeFiles/nippy.dir/src/ast.c.o -c /home/neuralnuts/Projects/Nippy/src/ast.c

CMakeFiles/nippy.dir/src/ast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nippy.dir/src/ast.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/neuralnuts/Projects/Nippy/src/ast.c > CMakeFiles/nippy.dir/src/ast.c.i

CMakeFiles/nippy.dir/src/ast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nippy.dir/src/ast.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/neuralnuts/Projects/Nippy/src/ast.c -o CMakeFiles/nippy.dir/src/ast.c.s

# Object files for target nippy
nippy_OBJECTS = \
"CMakeFiles/nippy.dir/src/main.c.o" \
"CMakeFiles/nippy.dir/src/tokenizer.c.o" \
"CMakeFiles/nippy.dir/tests/lexer_tests.c.o" \
"CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o" \
"CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o" \
"CMakeFiles/nippy.dir/src/variable_map.c.o" \
"CMakeFiles/nippy.dir/src/ast.c.o"

# External object files for target nippy
nippy_EXTERNAL_OBJECTS =

nippy: CMakeFiles/nippy.dir/src/main.c.o
nippy: CMakeFiles/nippy.dir/src/tokenizer.c.o
nippy: CMakeFiles/nippy.dir/tests/lexer_tests.c.o
nippy: CMakeFiles/nippy.dir/lib/file_functions_lib/src/file_functions.c.o
nippy: CMakeFiles/nippy.dir/lib/color_printf_lib/src/color_print.c.o
nippy: CMakeFiles/nippy.dir/src/variable_map.c.o
nippy: CMakeFiles/nippy.dir/src/ast.c.o
nippy: CMakeFiles/nippy.dir/build.make
nippy: CMakeFiles/nippy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neuralnuts/Projects/Nippy/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable nippy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nippy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nippy.dir/build: nippy
.PHONY : CMakeFiles/nippy.dir/build

CMakeFiles/nippy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nippy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nippy.dir/clean

CMakeFiles/nippy.dir/depend:
	cd /home/neuralnuts/Projects/Nippy/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neuralnuts/Projects/Nippy /home/neuralnuts/Projects/Nippy /home/neuralnuts/Projects/Nippy/build /home/neuralnuts/Projects/Nippy/build /home/neuralnuts/Projects/Nippy/build/CMakeFiles/nippy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nippy.dir/depend
