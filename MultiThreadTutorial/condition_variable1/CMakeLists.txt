cmake_minimum_required(VERSION 3.5)

project(condition_variable1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(condition_variable1 main.cpp)

find_package(Threads)
target_link_libraries(condition_variable1 ${CMAKE_THREAD_LIBS_INIT})
