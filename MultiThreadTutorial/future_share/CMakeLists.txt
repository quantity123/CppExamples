cmake_minimum_required(VERSION 3.5)

project(future_share LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(future_share main.cpp)

find_package(Threads)
target_link_libraries(future_share ${CMAKE_THREAD_LIBS_INIT})
