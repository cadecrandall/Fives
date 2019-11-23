cmake_minimum_required(VERSION 3.15)
project(Fives)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fives main.cpp Tile.cpp Tile.h Gameboard.cpp Gameboard.h)