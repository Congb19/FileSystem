cmake_minimum_required(VERSION 3.13)
project(FileSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(FileSystem main.cpp disk.h disk.cpp node.h node.cpp filesys.h filesys.cpp tree.h tree.cpp)