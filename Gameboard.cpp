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
    for (int r = 0; r < 4; ++r) {   // creates an empty 2d vector
        vector<Tile> row;
        _board.push_back(row);
        for (int c = 0; c < 4; ++c) {
            Tile col;
            _board.at(r).push_back(col);
        }
    }
    for (int r = 0; r < 4; r++) {           // fills 2d vector with 0s
        for (int c = 0; c < 4; c++) {
            _board.at(r).at(c).setCurrentVal(0);
        }
    }
    newTile();      // creates two random tiles to start game
    newTile();
}

void Gameboard::merge() {

}

void Gameboard::moveUp() {
    /* 1. remove blanks from each column (so everything will be touching)
     * 2. merge tiles up (starting at the top)
     * 3. remove blanks from each column created from merge
     */
    for (int r = 3; r >= 0; r--) {
        for (int c = 0; c < 4; c++) {      // has to work from bottom to avoid double checking
            if (_board.at(r).at(c).getCurrentVal() == 0) {
                _board.at(r).erase(_board.at(r).begin() + c);       // erases Tiles that hold the value 0
                _board.at(r).push_back(Tile(0));
            }
        }
    }

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r+1).at(c).getCurrentVal()) {
                // if tiles are equal (vertically), merge
                _board.at(r).at(c).setCurrentVal(); // multiplies Tile by 5
                _board.at(r+1).at(c).setCurrentVal(0);  // sets lower tile to 0
            }
        }
    }

    for (int r = 3; r >= 0; r--) {
        for (int c = 0; c < 4; c++) {      // has to work from bottom to avoid double checking
            if (_board.at(r).at(c).getCurrentVal() == 0) {
                _board.at(r).erase(_board.at(r).begin() + c);       // erases Tiles that hold the value 0
                _board.at(r).push_back(Tile(0));
            }
        }
    }
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
            cout << "| " << _board.at(r).at(c).getCurrentVal() << ' ';
        } cout << '|' << endl;
    }

}

void Gameboard::newTile() {
    bool isFull = true;
    while (isFull) {
        int pos = rand() % 15;
        int rowNum = pos / 4; // change random int to row column form
        int colNum = pos % 4;
        if (_board.at(rowNum).at(colNum).getCurrentVal() == 0) {
            _board.at(rowNum).at(colNum).setCurrentVal(((rand() / static_cast<double>(RAND_MAX)) < 0.9 ? 5 : 25));
            // if we find an empty spot, set the tile's value to either 5 or 25
            isFull = false; // exit loop
        }
    }
}
