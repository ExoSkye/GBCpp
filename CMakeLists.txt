cmake_minimum_required(VERSION 3.10)
project(GBCpp)
set(CMAKE_CXX_STANDARD 20)

set(PLATFORM "GBCpp" CACHE STRING "Platform selection (affects output executable name, used for CI artifacts)")

set(SOURCES src/main.cpp src/memory.hpp src/memory.cpp)
add_executable(GBCpp ${SOURCES})
set_target_properties(GBCpp PROPERTIES OUTPUT_NAME ${PLATFORM})