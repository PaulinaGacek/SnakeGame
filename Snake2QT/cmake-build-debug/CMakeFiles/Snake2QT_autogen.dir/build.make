# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pauli\CLionProjects\Snake2QT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pauli\CLionProjects\Snake2QT\cmake-build-debug

# Utility rule file for Snake2QT_autogen.

# Include the progress variables for this target.
include CMakeFiles\Snake2QT_autogen.dir\progress.make

CMakeFiles\Snake2QT_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\pauli\CLionProjects\Snake2QT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Snake2QT"
	echo >nul && "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E cmake_autogen C:/Users/pauli/CLionProjects/Snake2QT/cmake-build-debug/CMakeFiles/Snake2QT_autogen.dir/AutogenInfo.json Debug

Snake2QT_autogen: CMakeFiles\Snake2QT_autogen
Snake2QT_autogen: CMakeFiles\Snake2QT_autogen.dir\build.make

.PHONY : Snake2QT_autogen

# Rule to build all files generated by this target.
CMakeFiles\Snake2QT_autogen.dir\build: Snake2QT_autogen

.PHONY : CMakeFiles\Snake2QT_autogen.dir\build

CMakeFiles\Snake2QT_autogen.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Snake2QT_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Snake2QT_autogen.dir\clean

CMakeFiles\Snake2QT_autogen.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\pauli\CLionProjects\Snake2QT C:\Users\pauli\CLionProjects\Snake2QT C:\Users\pauli\CLionProjects\Snake2QT\cmake-build-debug C:\Users\pauli\CLionProjects\Snake2QT\cmake-build-debug C:\Users\pauli\CLionProjects\Snake2QT\cmake-build-debug\CMakeFiles\Snake2QT_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Snake2QT_autogen.dir\depend

