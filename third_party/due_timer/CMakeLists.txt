project(due_timer)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Release)

set(due_timer_SOURCES ${due_timer_SOURCES}
        due_timer.cpp
        )

add_library(due_timer STATIC ${due_timer_SOURCES})