cmake_minimum_required(VERSION 3.29)
project(WAV)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)

add_library(WAV src/WAVReader.cpp src/WAVWriter.cpp)

