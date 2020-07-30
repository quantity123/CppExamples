cmake_minimum_required(VERSION 3.5)

project(2-2_templateClass LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2-2_templateClass main.cpp stack.hpp classtemplate.hpp)
