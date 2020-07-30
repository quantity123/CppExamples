cmake_minimum_required(VERSION 3.5)

project(chat_server_unblock_protobuf LANGUAGES CXX)

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
include_directories(${PROTOBUF_INCLUDE_DIRS})
#PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ../Protocal.proto)
#add_executable(chat_client_protobuf ${SRC_LIST} ${PROTO_SRCS} ${PROTO_HDRS} main.cpp)
set(SRC_LIST ../Protocal.pb.h ../Protocal.pb.cc main.cpp)
add_executable(chat_server_unblock_protobuf ${SRC_LIST})
target_link_libraries(chat_server_unblock_protobuf ${PROTOBUF_LIBRARIES})
