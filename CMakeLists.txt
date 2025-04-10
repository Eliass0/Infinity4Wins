cmake_minimum_required(VERSION 3.30)
project(code)

set(CMAKE_CXX_STANDARD 20)

# Set additional GCC warning flags for C++ files
set(GCC_ENABLE_WARNINGS "-Wall -Werror")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_ENABLE_WARNINGS}")

add_executable(code main.cpp
        Gamestate.cpp
        Gamestate.h
        Point.cpp
        Point.h)
