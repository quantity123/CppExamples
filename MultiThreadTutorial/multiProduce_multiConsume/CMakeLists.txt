cmake_minimum_required(VERSION 3.5)

project(multiProduce_multiConsume LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(multiProduce_multiConsume main.cpp)

find_package(Threads)
target_link_libraries(multiProduce_multiConsume ${CMAKE_THREAD_LIBS_INIT})
