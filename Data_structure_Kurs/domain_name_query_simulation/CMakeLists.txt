cmake_minimum_required(VERSION 3.6)
project(domain_name_query_simulation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        domain_name_query_simulation.cpp
        test.cpp
        Tree.h)

add_executable(domain_name_query_simulation ${SOURCE_FILES})