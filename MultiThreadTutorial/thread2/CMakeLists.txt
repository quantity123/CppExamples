cmake_minimum_required(VERSION 3.5)

project(thread2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(thread2 main.cpp)

find_package(Threads)
target_link_libraries(thread2 ${CMAKE_THREAD_LIBS_INIT})
