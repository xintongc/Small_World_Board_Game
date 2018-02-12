cmake_minimum_required(VERSION 3.6)
project(small_world)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Map.cpp Map.h Region.cpp Region.h Race.h Race.cpp dice.h dice.cpp Amazons.h Amazons.cpp Dwarves.h Dwarves.cpp twoPlayer.map)
add_executable(small_world ${SOURCE_FILES})

