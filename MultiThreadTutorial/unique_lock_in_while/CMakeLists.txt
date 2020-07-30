cmake_minimum_required(VERSION 3.5)

project(unique_lock_in_while LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unique_lock_in_while main.cpp)

find_package(Threads)
target_link_libraries(unique_lock_in_while ${CMAKE_THREAD_LIBS_INIT})
