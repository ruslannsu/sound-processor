cmake_minimum_required(VERSION 3.29)
project(converter)

set(CMAKE_CXX_STANDARD 17)


include_directories(include ../WAV/include ../config_parser/include)

add_library(converter src/converter_creator.cpp src/converters.cpp)

