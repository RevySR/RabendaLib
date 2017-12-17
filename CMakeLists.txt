cmake_minimum_required(VERSION 3.9)
project(RabendaLib)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

include_directories(src)

add_executable(RabendaLib ${SOURCE_FILES})
