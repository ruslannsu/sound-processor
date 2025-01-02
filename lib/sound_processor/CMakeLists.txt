cmake_minimum_required(VERSION 3.29)
project(sound_processor)

set(CMAKE_CXX_STANDARD 17)


include_directories(include ../config_parser/include)

add_library(sound_processor src/sound_processor.cpp)

