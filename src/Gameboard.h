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

    void moveUp();

    void moveDown();

    void moveRight();

    void moveLeft();

    void printGame();

    bool canMoveVert();

    bool canMoveRight();

    bool canMoveLeft();

    bool isGameOver();

    int countEmptyTiles();

    void newTile();

    int getScore();

private:
    vector<vector<Tile>> _board;

    int _currentScore = 0;

    void rotateClockwise();

    void rotateAntiClockwise();
};

#endif //SFML_TEMPLATE_GAMEBOARD_H
