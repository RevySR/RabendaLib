cmake_minimum_required(VERSION 3.9)
project(RabendaLib)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD TRUE)
set(SOURCE_FILES main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
add_executable(RabendaLib ${SOURCE_FILES})
