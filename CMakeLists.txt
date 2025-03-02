cmake_minimum_required(VERSION 3.10) 
project(bounce-ingress-server) 

# Ensure we use build directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Add debug symbols
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

set(CMAKE_CXX_STANDARD 11) 
find_package(Boost REQUIRED COMPONENTS system) 

add_executable(ingress_server src/main.cpp)

# Add include directories for Boost
include_directories(${Boost_INCLUDE_DIRS})

# Link Boost libraries to your executable
target_link_libraries(ingress_server ${Boost_LIBRARIES})