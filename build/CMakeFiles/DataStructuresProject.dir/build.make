# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build

# Include any dependencies generated for this target.
include CMakeFiles/DataStructuresProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DataStructuresProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructuresProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructuresProject.dir/flags.make

CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o: CMakeFiles/DataStructuresProject.dir/flags.make
CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o: /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/BST.cpp
CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o: CMakeFiles/DataStructuresProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o -MF CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o.d -o CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o -c /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/BST.cpp

CMakeFiles/DataStructuresProject.dir/src/BST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DataStructuresProject.dir/src/BST.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/BST.cpp > CMakeFiles/DataStructuresProject.dir/src/BST.cpp.i

CMakeFiles/DataStructuresProject.dir/src/BST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DataStructuresProject.dir/src/BST.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/BST.cpp -o CMakeFiles/DataStructuresProject.dir/src/BST.cpp.s

CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o: CMakeFiles/DataStructuresProject.dir/flags.make
CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o: /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/GUIManager.cpp
CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o: CMakeFiles/DataStructuresProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o -MF CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o.d -o CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o -c /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/GUIManager.cpp

CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/GUIManager.cpp > CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.i

CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/GUIManager.cpp -o CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.s

CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o: CMakeFiles/DataStructuresProject.dir/flags.make
CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o: /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/Heap.cpp
CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o: CMakeFiles/DataStructuresProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o -MF CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o.d -o CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o -c /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/Heap.cpp

CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/Heap.cpp > CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.i

CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/Heap.cpp -o CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.s

CMakeFiles/DataStructuresProject.dir/src/main.cpp.o: CMakeFiles/DataStructuresProject.dir/flags.make
CMakeFiles/DataStructuresProject.dir/src/main.cpp.o: /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/main.cpp
CMakeFiles/DataStructuresProject.dir/src/main.cpp.o: CMakeFiles/DataStructuresProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DataStructuresProject.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DataStructuresProject.dir/src/main.cpp.o -MF CMakeFiles/DataStructuresProject.dir/src/main.cpp.o.d -o CMakeFiles/DataStructuresProject.dir/src/main.cpp.o -c /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/main.cpp

CMakeFiles/DataStructuresProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DataStructuresProject.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/main.cpp > CMakeFiles/DataStructuresProject.dir/src/main.cpp.i

CMakeFiles/DataStructuresProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DataStructuresProject.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/src/main.cpp -o CMakeFiles/DataStructuresProject.dir/src/main.cpp.s

# Object files for target DataStructuresProject
DataStructuresProject_OBJECTS = \
"CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o" \
"CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o" \
"CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o" \
"CMakeFiles/DataStructuresProject.dir/src/main.cpp.o"

# External object files for target DataStructuresProject
DataStructuresProject_EXTERNAL_OBJECTS =

DataStructuresProject: CMakeFiles/DataStructuresProject.dir/src/BST.cpp.o
DataStructuresProject: CMakeFiles/DataStructuresProject.dir/src/GUIManager.cpp.o
DataStructuresProject: CMakeFiles/DataStructuresProject.dir/src/Heap.cpp.o
DataStructuresProject: CMakeFiles/DataStructuresProject.dir/src/main.cpp.o
DataStructuresProject: CMakeFiles/DataStructuresProject.dir/build.make
DataStructuresProject: /usr/local/lib/libsfml-graphics.2.6.2.dylib
DataStructuresProject: /usr/local/lib/libsfml-window.2.6.2.dylib
DataStructuresProject: /usr/local/lib/libsfml-system.2.6.2.dylib
DataStructuresProject: CMakeFiles/DataStructuresProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DataStructuresProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructuresProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructuresProject.dir/build: DataStructuresProject
.PHONY : CMakeFiles/DataStructuresProject.dir/build

CMakeFiles/DataStructuresProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataStructuresProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataStructuresProject.dir/clean

CMakeFiles/DataStructuresProject.dir/depend:
	cd /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build /Users/omariwhiting/Desktop/Final_Project_SFML/DataStructuresProject/build/CMakeFiles/DataStructuresProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DataStructuresProject.dir/depend

