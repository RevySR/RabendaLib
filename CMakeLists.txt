cmake_minimum_required(VERSION 2.8)
project(RabendaLib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/stl/stl_uninitialized.hpp)
add_executable(RabendaLib ${SOURCE_FILES})