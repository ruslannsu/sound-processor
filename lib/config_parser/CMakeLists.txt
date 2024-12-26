cmake_minimum_required(VERSION 3.29)
project(config_parser)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)

add_library(config_parser src/config_parser.cpp)

