cmake_minimum_required(VERSION 3.5)

project(future_async_launch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(future_async_launch main.cpp)

find_package(Threads)
target_link_libraries(future_async_launch ${CMAKE_THREAD_LIBS_INIT})
