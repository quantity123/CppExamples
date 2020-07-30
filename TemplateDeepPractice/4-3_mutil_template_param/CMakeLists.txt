cmake_minimum_required(VERSION 3.5)

project(4-3_mutil_template_param LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(4-3_mutil_template_param main.cpp MutilTemplate.hpp)
