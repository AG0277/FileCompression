# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Artur\source\repos\FileCompression\FileCompression

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Artur\source\repos\FileCompression\build

# Include any dependencies generated for this target.
include _deps/fmt-build/CMakeFiles/fmt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/fmt-build/CMakeFiles/fmt.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/fmt-build/CMakeFiles/fmt.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/fmt-build/CMakeFiles/fmt.dir/flags.make

_deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.obj: _deps/fmt-build/CMakeFiles/fmt.dir/flags.make
_deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.obj: _deps/fmt-build/CMakeFiles/fmt.dir/includes_CXX.rsp
_deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.obj: C:/Users/Artur/source/repos/FileCompression/build/_deps/fmt-src/src/format.cc
_deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.obj: _deps/fmt-build/CMakeFiles/fmt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Artur\source\repos\FileCompression\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.obj"
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.obj -MF CMakeFiles\fmt.dir\src\format.cc.obj.d -o CMakeFiles\fmt.dir\src\format.cc.obj -c C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-src\src\format.cc

_deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fmt.dir/src/format.cc.i"
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-src\src\format.cc > CMakeFiles\fmt.dir\src\format.cc.i

_deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fmt.dir/src/format.cc.s"
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-src\src\format.cc -o CMakeFiles\fmt.dir\src\format.cc.s

_deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.obj: _deps/fmt-build/CMakeFiles/fmt.dir/flags.make
_deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.obj: _deps/fmt-build/CMakeFiles/fmt.dir/includes_CXX.rsp
_deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.obj: C:/Users/Artur/source/repos/FileCompression/build/_deps/fmt-src/src/os.cc
_deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.obj: _deps/fmt-build/CMakeFiles/fmt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Artur\source\repos\FileCompression\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.obj"
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.obj -MF CMakeFiles\fmt.dir\src\os.cc.obj.d -o CMakeFiles\fmt.dir\src\os.cc.obj -c C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-src\src\os.cc

_deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fmt.dir/src/os.cc.i"
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-src\src\os.cc > CMakeFiles\fmt.dir\src\os.cc.i

_deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fmt.dir/src/os.cc.s"
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-src\src\os.cc -o CMakeFiles\fmt.dir\src\os.cc.s

# Object files for target fmt
fmt_OBJECTS = \
"CMakeFiles/fmt.dir/src/format.cc.obj" \
"CMakeFiles/fmt.dir/src/os.cc.obj"

# External object files for target fmt
fmt_EXTERNAL_OBJECTS =

_deps/fmt-build/libfmtd.a: _deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.obj
_deps/fmt-build/libfmtd.a: _deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.obj
_deps/fmt-build/libfmtd.a: _deps/fmt-build/CMakeFiles/fmt.dir/build.make
_deps/fmt-build/libfmtd.a: _deps/fmt-build/CMakeFiles/fmt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Artur\source\repos\FileCompression\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libfmtd.a"
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && $(CMAKE_COMMAND) -P CMakeFiles\fmt.dir\cmake_clean_target.cmake
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fmt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/fmt-build/CMakeFiles/fmt.dir/build: _deps/fmt-build/libfmtd.a
.PHONY : _deps/fmt-build/CMakeFiles/fmt.dir/build

_deps/fmt-build/CMakeFiles/fmt.dir/clean:
	cd /d C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build && $(CMAKE_COMMAND) -P CMakeFiles\fmt.dir\cmake_clean.cmake
.PHONY : _deps/fmt-build/CMakeFiles/fmt.dir/clean

_deps/fmt-build/CMakeFiles/fmt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Artur\source\repos\FileCompression\FileCompression C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-src C:\Users\Artur\source\repos\FileCompression\build C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build C:\Users\Artur\source\repos\FileCompression\build\_deps\fmt-build\CMakeFiles\fmt.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/fmt-build/CMakeFiles/fmt.dir/depend

