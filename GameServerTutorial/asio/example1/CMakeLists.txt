cmake_minimum_required(VERSION 3.5)

project(example1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

#导入需要的库
find_package(Boost REQUIRED COMPONENTS)
if (NOT Boost_FOUND)
    message("Not found Boost")
endif()

#导入头文件
include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")

#导入库文件
link_libraries(${Boost_LIBRARIES})
message("${Boost_LIBRARIES}")

add_executable(example1 main.cpp)
target_link_libraries(example1 ${Boost_LIBRARIES})

find_package(Threads)
target_link_libraries(example1 ${CMAKE_THREAD_LIBS_INIT})
