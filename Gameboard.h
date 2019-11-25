//
// Created by Cade Crandall on 11/17/19.
//

#ifndef FIVES_GAMEBOARD_H
#define FIVES_GAMEBOARD_H


#include <vector>
#include "Tile.h"
using namespace std;

class Gameboard {
public:
    Gameboard();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    bool isGameOver();
    void displayGame();
    void newTile();
private:
    vector<vector<Tile>> _board; //make a vector of vectors of Tiles
    int _currentScore = 0;
    int _bestScore = -1;
    void rotateClockwise();
    void rotateAntiClock();
};


#endif //FIVES_GAMEBOARD_H
