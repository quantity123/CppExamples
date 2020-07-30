cmake_minimum_required(VERSION 3.5)

project(lock_guard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lock_guard main.cpp)

find_package(Threads)
target_link_libraries(lock_guard ${CMAKE_THREAD_LIBS_INIT})
