project(arduino-anfis)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

add_subdirectory(ANFISlib)

add_executable(arduino-anfis main.cpp)

target_link_libraries( ${PROJECT_NAME} anfis-lib )