cmake_minimum_required(VERSION 3.5)

project(future_promise_set_exception LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(future_promise_set_exception main.cpp)

find_package(Threads)
target_link_libraries(future_promise_set_exception ${CMAKE_THREAD_LIBS_INIT})
