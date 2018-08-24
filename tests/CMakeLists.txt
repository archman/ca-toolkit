cmake_minimum_required(VERSION 3.5.0)
project(ca-tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RELEASE)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src)
include_directories(${SRC_DIR})

add_executable(test001
        test001.c
        ${SRC_DIR}/evolve.c)