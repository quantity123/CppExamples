cmake_minimum_required(VERSION 3.5)

project(future_packaged_task_reset LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(future_packaged_task_reset main.cpp)

find_package(Threads)
target_link_libraries(future_packaged_task_reset ${CMAKE_THREAD_LIBS_INIT})
