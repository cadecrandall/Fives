//
// Created by Cade Crandall on 11/25/19.
//

#ifndef SFML_TEMPLATE_GAMEBOARD_H
#define SFML_TEMPLATE_GAMEBOARD_H

#include <vector>
#include "Tile.h"
using namespace std;

class Gameboard {
public:
    Gameboard();
    void moveUp();  // moves tiles on the gameboard up and returns TRUE if a move occurs
    void moveDown(); // moves tiles on the gameboard down and returns TRUE if a move occurs
    void moveRight(); // moves tiles on the gameboard right and returns TRUE if a move occurs
    void moveLeft(); // moves tiles on the gameboard left and returns TRUE if a move occurs

    bool canMoveVert();
    bool canMoveRight();
    bool canMoveLeft();
    bool isGameOver();
    int countZeroes();
    void newTile();
    int getScore();
    vector<vector<Tile>> getBoard();

private:
    vector<vector<Tile>> _board; //make a vector of vectors of Tiles
    int _currentScore = 0;
    void rotateClockwise();
    void rotateAntiClock();
};

#endif //SFML_TEMPLATE_GAMEBOARD_H
