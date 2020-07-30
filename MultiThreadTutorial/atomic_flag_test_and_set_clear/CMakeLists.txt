cmake_minimum_required(VERSION 3.5)

project(atomic_flag_test_and_set_clear LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(atomic_flag_test_and_set_clear main.cpp)

find_package(Threads)
target_link_libraries(atomic_flag_test_and_set_clear ${CMAKE_THREAD_LIBS_INIT})
