# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/145/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/145/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/camanem/CLionProjects/ADS2-PJ1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ADS2_PJ1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ADS2_PJ1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ADS2_PJ1.dir/flags.make

CMakeFiles/ADS2_PJ1.dir/main.cpp.o: CMakeFiles/ADS2_PJ1.dir/flags.make
CMakeFiles/ADS2_PJ1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ADS2_PJ1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ADS2_PJ1.dir/main.cpp.o -c /home/camanem/CLionProjects/ADS2-PJ1/main.cpp

CMakeFiles/ADS2_PJ1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ADS2_PJ1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/camanem/CLionProjects/ADS2-PJ1/main.cpp > CMakeFiles/ADS2_PJ1.dir/main.cpp.i

CMakeFiles/ADS2_PJ1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ADS2_PJ1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/camanem/CLionProjects/ADS2-PJ1/main.cpp -o CMakeFiles/ADS2_PJ1.dir/main.cpp.s

CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.o: CMakeFiles/ADS2_PJ1.dir/flags.make
CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.o: ../Gui/MainWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.o -c /home/camanem/CLionProjects/ADS2-PJ1/Gui/MainWindow.cpp

CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/camanem/CLionProjects/ADS2-PJ1/Gui/MainWindow.cpp > CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.i

CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/camanem/CLionProjects/ADS2-PJ1/Gui/MainWindow.cpp -o CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.s

CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.o: CMakeFiles/ADS2_PJ1.dir/flags.make
CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.o: ../logic/Syntax.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.o -c /home/camanem/CLionProjects/ADS2-PJ1/logic/Syntax.cpp

CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/camanem/CLionProjects/ADS2-PJ1/logic/Syntax.cpp > CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.i

CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/camanem/CLionProjects/ADS2-PJ1/logic/Syntax.cpp -o CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.s

# Object files for target ADS2_PJ1
ADS2_PJ1_OBJECTS = \
"CMakeFiles/ADS2_PJ1.dir/main.cpp.o" \
"CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.o" \
"CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.o"

# External object files for target ADS2_PJ1
ADS2_PJ1_EXTERNAL_OBJECTS =

ADS2_PJ1: CMakeFiles/ADS2_PJ1.dir/main.cpp.o
ADS2_PJ1: CMakeFiles/ADS2_PJ1.dir/Gui/MainWindow.cpp.o
ADS2_PJ1: CMakeFiles/ADS2_PJ1.dir/logic/Syntax.cpp.o
ADS2_PJ1: CMakeFiles/ADS2_PJ1.dir/build.make
ADS2_PJ1: CMakeFiles/ADS2_PJ1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ADS2_PJ1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ADS2_PJ1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ADS2_PJ1.dir/build: ADS2_PJ1

.PHONY : CMakeFiles/ADS2_PJ1.dir/build

CMakeFiles/ADS2_PJ1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ADS2_PJ1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ADS2_PJ1.dir/clean

CMakeFiles/ADS2_PJ1.dir/depend:
	cd /home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/camanem/CLionProjects/ADS2-PJ1 /home/camanem/CLionProjects/ADS2-PJ1 /home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug /home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug /home/camanem/CLionProjects/ADS2-PJ1/cmake-build-debug/CMakeFiles/ADS2_PJ1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ADS2_PJ1.dir/depend

