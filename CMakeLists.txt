cmake_minimum_required(VERSION 3.13.4)

project(assignment1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} main.cpp node.h linkedList.h)
