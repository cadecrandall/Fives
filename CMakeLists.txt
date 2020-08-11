cmake_minimum_required(VERSION 3.15)
project(Fives)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fives src/main.cpp src/Tile.cpp src/Tile.h src/Gameboard.cpp src/Gameboard.h src/Functions.cpp src/Functions.h)
