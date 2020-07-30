cmake_minimum_required(VERSION 3.5)

project(threadPool1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(threadPool1 main.cpp)

find_package(Threads)
target_link_libraries(threadPool1 ${CMAKE_THREAD_LIBS_INIT})
