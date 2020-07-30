cmake_minimum_required(VERSION 3.5)

project(atomic_int LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(atomic_int main.cpp)

find_package(Threads)
target_link_libraries(atomic_int ${CMAKE_THREAD_LIBS_INIT})
