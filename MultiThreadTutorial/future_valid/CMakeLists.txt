cmake_minimum_required(VERSION 3.5)

project(future_valid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(future_valid main.cpp)

find_package(Threads)
target_link_libraries(future_valid ${CMAKE_THREAD_LIBS_INIT})
