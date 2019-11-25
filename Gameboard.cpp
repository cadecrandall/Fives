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
            col.setCurrentVal(0);
            _board.at(r).push_back(col);
        }
    }
    newTile();      // creates two random tiles to start game
    newTile();
}

void Gameboard::moveUp() { // moving up is the same as rotating clockwise and merging right, then rotating anticlockwise
    rotateClockwise();
    moveRight();
    rotateAntiClock();
}

void Gameboard::moveDown() { // moving down is the same as rotating clockwise, merging left, and rotating anticlockwise
    rotateClockwise();
    moveLeft();
    rotateAntiClock();
}

void Gameboard::rotateClockwise() {
    Gameboard newBoard; // create a temporary board
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            newBoard._board.at(c).at(3-r).setCurrentVal(_board.at(r).at(c).getCurrentVal());
            // rotates the board clockwise
        }
    }
    _board = newBoard._board; // sets the callee board to the newboard
}

void Gameboard::rotateAntiClock() {
    Gameboard newBoard; // create a temporary board
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            newBoard._board.at(r).at(c).setCurrentVal(_board.at(c).at(3-r).getCurrentVal());
            // rotates the board clockwise
        }
    }
    _board = newBoard._board; // sets the callee board to the newboard
}

void Gameboard::moveRight() {
    /* 1. remove blanks from each row (so everything will be touching)
     * 2. merge tiles right
     * 3. remove blanks from each row created from merge
     */

    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {      // has to work from left side to avoid double checking
            if (_board.at(r).at(c).getCurrentVal() == 0) {
                _board.at(r).erase(_board.at(r).begin() + c);       // erases Tiles that hold the value 0
                _board.at(r).insert(_board.at(r).begin(), Tile(0));
            }
        }
    }

    for (int r = 0; r < 4; r++) {
        for (int c = 3; c > 0; c--) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r).at(c-1).getCurrentVal()) {
                // if tiles are equal (horizontally), merge
                _board.at(r).at(c).setCurrentVal(); // multiplies Tile by 5
                _currentScore += _board.at(r).at(c).getCurrentVal();
                _board.at(r).at(c-1).setCurrentVal(0);  // sets lower tile to 0
            }
        }
    }

    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {      // has to work from left side to avoid double checking
            if (_board.at(r).at(c).getCurrentVal() == 0) {
                _board.at(r).erase(_board.at(r).begin() + c);       // erases Tiles that hold the value 0
                _board.at(r).insert(_board.at(r).begin(), Tile(0));
            }
        }
    }
}

void Gameboard::moveLeft() {
    /* 1. remove blanks from each row (so everything will be touching)
     * 2. merge tiles left
     * 3. remove blanks from each row created from merge
     */

    for (int r = 0; r < 4; r++) {
        for (int c = 3; c >= 0; c--) {      // has to work from right side to avoid double checking
            if (_board.at(r).at(c).getCurrentVal() == 0) {
                _board.at(r).erase(_board.at(r).begin() + c);       // erases Tiles that hold the value 0
                _board.at(r).push_back(Tile(0)); // inserts a new tile at the right side of value 0
            }
        }
    }

    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r).at(c+1).getCurrentVal()) {
                // if tiles are equal (horizontally), merge
                _board.at(r).at(c).setCurrentVal(); // multiplies Tile by 5
                _currentScore += _board.at(r).at(c).getCurrentVal();
                _board.at(r).at(c+1).setCurrentVal(0);  // sets lower tile to 0
            }
        }
    }

    for (int r = 0; r < 4; r++) {
        for (int c = 3; c >= 0; c--) {      // has to work from right side to avoid double checking
            if (_board.at(r).at(c).getCurrentVal() == 0) {
                _board.at(r).erase(_board.at(r).begin() + c);       // erases Tiles that hold the value 0
                _board.at(r).push_back(Tile(0));
            }
        }
    }
}

bool Gameboard::canMoveVert() {
    rotateClockwise();
    if (canMoveLeft() || canMoveRight()) {
        rotateAntiClock();
        return true;
    }
    return false;
}


bool Gameboard::canMoveRight() {
    // function checks to see if anything matches and is movable when the board is full
    for (int r = 0; r < 4; r++) {
        for (int c = 3; c > 0; c--) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r).at(c-1).getCurrentVal()) {
                return true;
            }
        }
    }
    return false;
}

bool Gameboard::canMoveLeft() {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r).at(c+1).getCurrentVal()) {
                // if tiles are equal (horizontally), return true
                return true;
            }
        }
    }
    return false;
}

bool Gameboard::isGameOver() {
    int countZeroes = 0;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (_board.at(r).at(c).getCurrentVal() == 0)
                countZeroes++;
        }
    }

    if (countZeroes == 0 && (canMoveLeft() || canMoveRight() || canMoveVert())) {
        return true;
    }
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
