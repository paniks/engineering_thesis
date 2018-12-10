project(arduino-anfis)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

include_directories(
        include
        third_party/due_timer
        third_party/uno_timer
)

add_executable(arduino-anfis main.cpp)

add_subdirectory(third_party/due_timer)
add_subdirectory(third_party/uno_timer)