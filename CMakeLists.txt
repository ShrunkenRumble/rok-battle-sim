cmake_minimum_required(VERSION 3.10)

project(ROKC VERSION 0.1 LANGUAGES CXX)

#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INC_DIR include)
set(SRC_DIR src)
set(BIN_DIR bin)
set(LIB_DIR lib)
include_directories(${INC_DIR})

file(GLOB SRC "${SRC_DIR}/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../${BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../${LIB_DIR})

add_executable(ROKC ${SRC})