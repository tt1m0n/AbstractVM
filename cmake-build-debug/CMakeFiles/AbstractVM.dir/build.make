# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Volumes/CLion/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Volumes/CLion/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/developer/Desktop/avm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/developer/Desktop/avm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AbstractVM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AbstractVM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AbstractVM.dir/flags.make

CMakeFiles/AbstractVM.dir/main.cpp.o: CMakeFiles/AbstractVM.dir/flags.make
CMakeFiles/AbstractVM.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AbstractVM.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstractVM.dir/main.cpp.o -c /Users/developer/Desktop/avm/main.cpp

CMakeFiles/AbstractVM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstractVM.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/developer/Desktop/avm/main.cpp > CMakeFiles/AbstractVM.dir/main.cpp.i

CMakeFiles/AbstractVM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstractVM.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/developer/Desktop/avm/main.cpp -o CMakeFiles/AbstractVM.dir/main.cpp.s

CMakeFiles/AbstractVM.dir/Lexer.cpp.o: CMakeFiles/AbstractVM.dir/flags.make
CMakeFiles/AbstractVM.dir/Lexer.cpp.o: ../Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AbstractVM.dir/Lexer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstractVM.dir/Lexer.cpp.o -c /Users/developer/Desktop/avm/Lexer.cpp

CMakeFiles/AbstractVM.dir/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstractVM.dir/Lexer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/developer/Desktop/avm/Lexer.cpp > CMakeFiles/AbstractVM.dir/Lexer.cpp.i

CMakeFiles/AbstractVM.dir/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstractVM.dir/Lexer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/developer/Desktop/avm/Lexer.cpp -o CMakeFiles/AbstractVM.dir/Lexer.cpp.s

CMakeFiles/AbstractVM.dir/MyException.cpp.o: CMakeFiles/AbstractVM.dir/flags.make
CMakeFiles/AbstractVM.dir/MyException.cpp.o: ../MyException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AbstractVM.dir/MyException.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstractVM.dir/MyException.cpp.o -c /Users/developer/Desktop/avm/MyException.cpp

CMakeFiles/AbstractVM.dir/MyException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstractVM.dir/MyException.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/developer/Desktop/avm/MyException.cpp > CMakeFiles/AbstractVM.dir/MyException.cpp.i

CMakeFiles/AbstractVM.dir/MyException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstractVM.dir/MyException.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/developer/Desktop/avm/MyException.cpp -o CMakeFiles/AbstractVM.dir/MyException.cpp.s

CMakeFiles/AbstractVM.dir/Parser.cpp.o: CMakeFiles/AbstractVM.dir/flags.make
CMakeFiles/AbstractVM.dir/Parser.cpp.o: ../Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AbstractVM.dir/Parser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstractVM.dir/Parser.cpp.o -c /Users/developer/Desktop/avm/Parser.cpp

CMakeFiles/AbstractVM.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstractVM.dir/Parser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/developer/Desktop/avm/Parser.cpp > CMakeFiles/AbstractVM.dir/Parser.cpp.i

CMakeFiles/AbstractVM.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstractVM.dir/Parser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/developer/Desktop/avm/Parser.cpp -o CMakeFiles/AbstractVM.dir/Parser.cpp.s

CMakeFiles/AbstractVM.dir/OperandFactory.cpp.o: CMakeFiles/AbstractVM.dir/flags.make
CMakeFiles/AbstractVM.dir/OperandFactory.cpp.o: ../OperandFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AbstractVM.dir/OperandFactory.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstractVM.dir/OperandFactory.cpp.o -c /Users/developer/Desktop/avm/OperandFactory.cpp

CMakeFiles/AbstractVM.dir/OperandFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstractVM.dir/OperandFactory.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/developer/Desktop/avm/OperandFactory.cpp > CMakeFiles/AbstractVM.dir/OperandFactory.cpp.i

CMakeFiles/AbstractVM.dir/OperandFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstractVM.dir/OperandFactory.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/developer/Desktop/avm/OperandFactory.cpp -o CMakeFiles/AbstractVM.dir/OperandFactory.cpp.s

CMakeFiles/AbstractVM.dir/LexerException.cpp.o: CMakeFiles/AbstractVM.dir/flags.make
CMakeFiles/AbstractVM.dir/LexerException.cpp.o: ../LexerException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AbstractVM.dir/LexerException.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstractVM.dir/LexerException.cpp.o -c /Users/developer/Desktop/avm/LexerException.cpp

CMakeFiles/AbstractVM.dir/LexerException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstractVM.dir/LexerException.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/developer/Desktop/avm/LexerException.cpp > CMakeFiles/AbstractVM.dir/LexerException.cpp.i

CMakeFiles/AbstractVM.dir/LexerException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstractVM.dir/LexerException.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/developer/Desktop/avm/LexerException.cpp -o CMakeFiles/AbstractVM.dir/LexerException.cpp.s

CMakeFiles/AbstractVM.dir/ParserException.cpp.o: CMakeFiles/AbstractVM.dir/flags.make
CMakeFiles/AbstractVM.dir/ParserException.cpp.o: ../ParserException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AbstractVM.dir/ParserException.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstractVM.dir/ParserException.cpp.o -c /Users/developer/Desktop/avm/ParserException.cpp

CMakeFiles/AbstractVM.dir/ParserException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstractVM.dir/ParserException.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/developer/Desktop/avm/ParserException.cpp > CMakeFiles/AbstractVM.dir/ParserException.cpp.i

CMakeFiles/AbstractVM.dir/ParserException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstractVM.dir/ParserException.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/developer/Desktop/avm/ParserException.cpp -o CMakeFiles/AbstractVM.dir/ParserException.cpp.s

CMakeFiles/AbstractVM.dir/OperandException.cpp.o: CMakeFiles/AbstractVM.dir/flags.make
CMakeFiles/AbstractVM.dir/OperandException.cpp.o: ../OperandException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AbstractVM.dir/OperandException.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstractVM.dir/OperandException.cpp.o -c /Users/developer/Desktop/avm/OperandException.cpp

CMakeFiles/AbstractVM.dir/OperandException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstractVM.dir/OperandException.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/developer/Desktop/avm/OperandException.cpp > CMakeFiles/AbstractVM.dir/OperandException.cpp.i

CMakeFiles/AbstractVM.dir/OperandException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstractVM.dir/OperandException.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/developer/Desktop/avm/OperandException.cpp -o CMakeFiles/AbstractVM.dir/OperandException.cpp.s

# Object files for target AbstractVM
AbstractVM_OBJECTS = \
"CMakeFiles/AbstractVM.dir/main.cpp.o" \
"CMakeFiles/AbstractVM.dir/Lexer.cpp.o" \
"CMakeFiles/AbstractVM.dir/MyException.cpp.o" \
"CMakeFiles/AbstractVM.dir/Parser.cpp.o" \
"CMakeFiles/AbstractVM.dir/OperandFactory.cpp.o" \
"CMakeFiles/AbstractVM.dir/LexerException.cpp.o" \
"CMakeFiles/AbstractVM.dir/ParserException.cpp.o" \
"CMakeFiles/AbstractVM.dir/OperandException.cpp.o"

# External object files for target AbstractVM
AbstractVM_EXTERNAL_OBJECTS =

AbstractVM: CMakeFiles/AbstractVM.dir/main.cpp.o
AbstractVM: CMakeFiles/AbstractVM.dir/Lexer.cpp.o
AbstractVM: CMakeFiles/AbstractVM.dir/MyException.cpp.o
AbstractVM: CMakeFiles/AbstractVM.dir/Parser.cpp.o
AbstractVM: CMakeFiles/AbstractVM.dir/OperandFactory.cpp.o
AbstractVM: CMakeFiles/AbstractVM.dir/LexerException.cpp.o
AbstractVM: CMakeFiles/AbstractVM.dir/ParserException.cpp.o
AbstractVM: CMakeFiles/AbstractVM.dir/OperandException.cpp.o
AbstractVM: CMakeFiles/AbstractVM.dir/build.make
AbstractVM: CMakeFiles/AbstractVM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable AbstractVM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AbstractVM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AbstractVM.dir/build: AbstractVM

.PHONY : CMakeFiles/AbstractVM.dir/build

CMakeFiles/AbstractVM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AbstractVM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AbstractVM.dir/clean

CMakeFiles/AbstractVM.dir/depend:
	cd /Users/developer/Desktop/avm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/developer/Desktop/avm /Users/developer/Desktop/avm /Users/developer/Desktop/avm/cmake-build-debug /Users/developer/Desktop/avm/cmake-build-debug /Users/developer/Desktop/avm/cmake-build-debug/CMakeFiles/AbstractVM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AbstractVM.dir/depend

