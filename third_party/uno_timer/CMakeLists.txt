project(uno_timer)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Release)

set(uno_timer_SOURCES ${uno_timer_SOURCES}
        uno_timer.cpp
        )

add_library(uno_timer STATIC ${uno_timer_SOURCES})