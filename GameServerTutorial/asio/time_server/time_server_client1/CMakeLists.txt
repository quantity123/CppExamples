cmake_minimum_required(VERSION 3.5)

project(time_server_client1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#导入需要的库
find_package(Boost REQUIRED COMPONENTS regex filesystem thread)
if (NOT Boost_FOUND)
    message("Not found Boost")
endif()

#导入头文件
include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")

#导入库文件
link_libraries(${Boost_LIBRARIES})
message("${Boost_LIBRARIES}")

add_executable(time_server_client1 main.cpp)
