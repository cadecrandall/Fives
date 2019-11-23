//
// Created by Cade Crandall on 11/17/19.
//

#include "Gameboard.h"
#include "Tile.h"

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

Gameboard::Gameboard() {
    // clear all the values on _board
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            _board[r][c].setCurrentVal(0);
        }
    }
    newTile();
    newTile();
}

void Gameboard::merge() {

}

void Gameboard::moveUp() {

}

void Gameboard::moveDown() {

}

void Gameboard::moveRight() {

}

void Gameboard::moveLeft() {

}

bool Gameboard::isMoveLegal() {
    return false;
}

bool Gameboard::isGameOver() {
    return false;
}

void Gameboard::updateScore() {

}

void Gameboard::displayGame() {
    cout << "CURRENT SCORE: " << _currentScore << '\t' << "BEST SCORE: " << _bestScore << endl;
    for (int r = 0; r < 4; ++r) {
        cout << setfill('-') << setw(20) << '-' << endl;
        for (int c = 0; c < 4; ++c) {
            cout << "| " << _board[r][c].getCurrentVal() << ' ';
        } cout << '|' << endl;
    }

}

void Gameboard::newTile() {
    bool isFull = true;
    while (isFull) {
        int pos = rand() % 15;
        int rowNum = pos / 4; // change random int to row column form
        int colNum = pos % 4;
        if (_board[rowNum][colNum].getCurrentVal() == 0) {
            _board[rowNum][colNum].setCurrentVal(((rand() / static_cast<double>(RAND_MAX)) < 0.9 ? 5 : 25));
            // if we find an empty spot, set the tile's value to either 5 or 25
            isFull = false; // exit loop
        }
    }
}
