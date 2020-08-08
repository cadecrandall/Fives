cmake_minimum_required(VERSION 3.12)
project(Fives)

include_directories(include)
link_directories(lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(Fives src/main.cpp src/Tile.cpp src/Tile.h src/Gameboard.cpp src/Gameboard.h src/Functions.cpp src/Functions.h src/Leaderboard.cpp src/Leaderboard.h)

