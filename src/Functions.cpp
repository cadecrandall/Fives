//
// Created by Cade Crandall on 12/3/19.
//

#include "Functions.h"
#include "Gameboard.h"
#include <iostream>

using namespace std;

int getBestScore(std::vector<int> scores) {
    int bestIdx = 0;
    for (int i = 0; i < scores.size(); i++) {
        bestIdx = (scores.at(i) > scores.at(bestIdx) ? i : bestIdx);
    }
    return scores.at(bestIdx);
}

void makePlayerMove(Gameboard &gb, char move) {
    switch (move) {
        case 'W':
        case 'w':
            gb.moveUp();
            break;
        case 'A':
        case 'a':
            gb.moveLeft();
            break;
        case 'S':
        case 's':
            gb.moveDown();
            break;
        case 'D':
        case 'd':
            gb.moveRight();
            break;
        default:
            cerr << "Invalid move. Use WASD to move the board" << endl;
            return;
    }
    gb.newTile();
}