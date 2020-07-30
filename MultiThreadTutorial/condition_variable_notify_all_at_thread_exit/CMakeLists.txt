cmake_minimum_required(VERSION 3.5)

project(condition_variable_notify_all_at_thread_exit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(condition_variable_notify_all_at_thread_exit main.cpp)

find_package(Threads)
target_link_libraries(condition_variable_notify_all_at_thread_exit ${CMAKE_THREAD_LIBS_INIT})
