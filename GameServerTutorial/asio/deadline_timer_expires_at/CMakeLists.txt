cmake_minimum_required(VERSION 3.5)

project(deadline_timer_expires_at LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

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

add_executable(deadline_timer_expires_at main.cpp)
#target_link_libraries(deadline_timer_expires_at ${Boost_LIBRARIES})
