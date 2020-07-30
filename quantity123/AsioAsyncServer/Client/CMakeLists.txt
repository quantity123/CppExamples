cmake_minimum_required(VERSION 3.5)

project(Client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DBOOST_LOG_DYN_LINK)

#导入需要的boost库
find_package(Boost REQUIRED COMPONENTS regex filesystem thread log)
if (NOT Boost_FOUND)
    message("Not found Boost")
endif()
#导入boost头文件
include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")
#导入boost库文件
link_libraries(${Boost_LIBRARIES})
message("${Boost_LIBRARIES}")

#导入需要的Protobuf库
find_package(Protobuf REQUIRED)
if (NOT PROTOBUF_FOUND)
    message("Not found Boost")
endif()
#导入Protobuf
message(${PROJECT_SOURCE_DIR})
include_directories(${PROTOBUF_INCLUDE_DIRS})
set(
    ALL_INCLUDE_SOURCE_FILES
    ../DataPacket/DataPackageStruct/Protocal.pb.h
    ../DataPacket/DataPackageStruct/Protocal.pb.cc
    ../DataPacket/data_packet.h
    ../DataPacket/data_packet.cpp
    main.cpp
)
add_executable(Client ${ALL_INCLUDE_SOURCE_FILES})
target_link_libraries(Client ${PROTOBUF_LIBRARIES})
