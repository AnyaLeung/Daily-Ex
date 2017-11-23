cmake_minimum_required(VERSION 3.6)
project(hairdressers_simulation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        hairdressers_simulation.cpp
        queue.h
        test.cpp)

add_executable(hairdressers_simulation ${SOURCE_FILES})