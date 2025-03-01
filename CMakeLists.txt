cmake_minimum_required(VERSION 3.10) 
project(bounce-ingress-server) 

set(CMAKE_CXX_STANDARD 11) 

add_executable(ingress_server src/main.cpp)
