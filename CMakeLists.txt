cmake_minimum_required(VERSION 3.6)
project(IT279GroupProject2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/ShellSort.cpp src/BottomUpMerge.cpp src/InsertionSort.cpp)
add_executable(IT279GroupProject2 ${SOURCE_FILES})