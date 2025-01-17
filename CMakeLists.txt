cmake_minimum_required(VERSION 3.29)
project(lab3)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(lib/config_parser)

add_subdirectory(lib/sound_processor)

add_subdirectory(lib/WAV)

add_subdirectory(lib/converter)

include_directories(lib/config_parser/include)

include_directories(lib/sound_processor/include)

include_directories(lib/WAV/include)

include_directories(lib/converter/include)

add_executable(my_executable src/main.cpp)

target_link_libraries(my_executable config_parser sound_processor WAV converter)