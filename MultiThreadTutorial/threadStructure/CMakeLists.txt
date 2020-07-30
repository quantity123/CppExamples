cmake_minimum_required(VERSION 3.5)

project(threadStructure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(threadStructure main.cpp)

find_package(Threads)
target_link_libraries(threadStructure ${CMAKE_THREAD_LIBS_INIT})
