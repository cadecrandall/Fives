//
// Created by Cade Crandall on 11/17/19.
//

#include "Gameboard.h"
#include "Tile.h"

#include <vector>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

Gameboard::Gameboard() {
    for (int r = 0; r < 4; ++r) {
        vector<Tile> row;
        _board.push_back(row);
        for (int c = 0; c < 4; ++c) {
            Tile tile;
            _board.at(r).push_back(tile);
        }
    }
    newTile();      // creates two random tiles to start game
    newTile();
}

void Gameboard::moveUp() {
    rotateClockwise();
    moveRight();
    rotateAntiClockwise();
}

void Gameboard::moveDown() {
    rotateClockwise();
    moveLeft();
    rotateAntiClockwise();
}

void Gameboard::rotateClockwise() {
    Gameboard newBoard;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            newBoard._board.at(c).at(3 - r).setCurrentVal(_board.at(r).at(c).getCurrentVal());
        }
    }
    _board = newBoard._board;
}

void Gameboard::rotateAntiClockwise() {
    Gameboard newBoard;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            newBoard._board.at(r).at(c).setCurrentVal(_board.at(c).at(3 - r).getCurrentVal());
        }
    }
    _board = newBoard._board;
}

void Gameboard::moveRight() {
    /*
     * 1. Collapse vector to the right (remove blanks)
     * 2. Merge tiles right
     * 3. Collapse vector to the right following merge
     */
    collapseRight();
    for (int r = 0; r < 4; r++) {
        for (int c = 3; c > 0; c--) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r).at(c - 1).getCurrentVal()) {
                // if tiles are equal (horizontally), merge
                _board.at(r).at(c).increment(); // multiplies Tile by 5
                _currentScore += _board.at(r).at(c).getCurrentVal();
                _board.at(r).at(c - 1).setCurrentVal(0);  // sets lower tile to 0
            }
        }
    }
    collapseRight();
}

void Gameboard::moveLeft() {
    /*
     * 1. Collapse vector to the left (remove blanks)
     * 2. Merge tiles left
     * 3. Collapse vector to the left following merge
     */

    collapseLeft();
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 3; c++) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r).at(c + 1).getCurrentVal()) {
                // if tiles are equal (horizontally), merge
                _board.at(r).at(c).increment();
                _currentScore += _board.at(r).at(c).getCurrentVal();
                _board.at(r).at(c + 1).setCurrentVal(0);  // sets lower tile to 0
            }
        }
    }
    collapseLeft();
}

void Gameboard::collapseRight() {
    /**
     * Removes blank spaces in each vector row to the right
     * e.g.:    [2, 0, 2, 0] --> [0, 0, 2, 2]
     */
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {      // has to work from left side to avoid double checking
            if (_board.at(r).at(c).getCurrentVal() == 0) {
                _board.at(r).erase(_board.at(r).begin() + c);       // erases Tiles that hold the value 0
                _board.at(r).insert(_board.at(r).begin(), Tile());
            }
        }
    }
}

void Gameboard::collapseLeft() {
    /**
     * Removes blank spaces in each vector row to the left
     * e.g.:    [2, 0, 2, 0] --> [2, 2, 0, 0]
     */
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
    for (int r = 1; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r + 1).at(c).getCurrentVal() ||
                _board.at(r).at(c).getCurrentVal() == _board.at(r - 1).at(c).getCurrentVal()) {
                return true;
            }
        }
    }
    return false;
}


bool Gameboard::canMoveHorizontally() {
    for (int r = 0; r < 4; r++) {
        for (int c = 3; c > 0; c--) {
            if (_board.at(r).at(c).getCurrentVal() == _board.at(r).at(c - 1).getCurrentVal()) {
                return true;
            }
        }
    }
    return false;
}

bool Gameboard::isGameOver() {
    // Gameboard must be full without a horizontal or vertical move
    return isBoardFull() && !(canMoveHorizontally() || canMoveVert());
}

int Gameboard::countEmptyTiles() {
    int numZeroes = 0;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (_board.at(r).at(c).getCurrentVal() == 0)
                numZeroes++;
        }
    }
    return numZeroes;
}

bool Gameboard::isBoardFull() {
    return countEmptyTiles() == 0;
}

void Gameboard::newTile() {
    bool foundEmpty = false;
    while (!foundEmpty && countEmptyTiles() != 0) {
        int pos = rand() % 16;
        int r = pos / 4;
        int c = pos % 4;
        if (_board.at(r).at(c).getCurrentVal() == 0) {
            _board.at(r).at(c).setRandomValue();
            foundEmpty = true;
        }
    }
}

int Gameboard::getScore() {
    return _currentScore;
}

void Gameboard::printGame() {
    for (int r = 0; r < 4; ++r) {
        cout << setfill('-') << setw(20) << '-' << endl;
        for (int c = 0; c < 4; ++c) {
            cout << "| " << _board.at(r).at(c).getCurrentVal() << ' ';
        }
        cout << '|' << endl;
    }
}