cmake_minimum_required(VERSION 3.14)
project(TEST_LIB_PROJ)

add_library(TEST_LIB src/TestExecImpl.cpp)

target_include_directories(TEST_LIB PUBLIC include)

set_target_properties(TEST_LIB PROPERTIES 
                      CMAKE_CXX_STANDARD 23
                      CMAKE_CXX_STANDARD_REQUIRED ON
                      CMAKE_C_STANDARD 23
                      CMAKE_C_STANDARD_REQUIRED ON
                      )