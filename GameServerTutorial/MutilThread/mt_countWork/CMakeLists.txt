cmake_minimum_required(VERSION 3.5)

project(mt_countWork LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mt_countWork main.cpp)

find_package(Threads)
target_link_libraries(mt_countWork ${CMAKE_THREAD_LIBS_INIT})
