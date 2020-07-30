cmake_minimum_required(VERSION 3.5)

project(try_lock_for_until LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(try_lock_for_until main.cpp)

find_package(Threads)
target_link_libraries(try_lock_for_until ${CMAKE_THREAD_LIBS_INIT})
