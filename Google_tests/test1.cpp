//
// Created by Cade Crandall on 8/11/20.
//

#include "../src/Functions.h"
#include "../src/Gameboard.h"

// include this on all test features
#include "gtest/gtest.h"

TEST(GameboardSuite, gameOver) {
    int board[4][4] = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };
    Gameboard gb(board);
    ASSERT_EQ(gb.isGameOver(), true);
}