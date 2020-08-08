cmake_minimum_required(VERSION 3.12)
project(Fives)

include_directories(include)
link_directories(lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(Fives main.cpp Tile.cpp Tile.h Gameboard.cpp Gameboard.h Functions.cpp Functions.h)

