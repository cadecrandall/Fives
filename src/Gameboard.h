//
// Created by Cade Crandall on 11/25/19.
//

#ifndef FIVES_GAMEBOARD_H
#define FIVES_GAMEBOARD_H

#include <vector>
#include "Tile.h"
#include "Leaderboard.h"

using namespace std;

class Gameboard {
public:
    Gameboard();

    Gameboard(int[4][4]);


    void moveUp();

    void moveDown();

    void moveRight();

    void moveLeft();

    void printGameState(Leaderboard&);

    bool canMoveVert();

    bool canMoveHorizontally();

    bool isGameOver();

    int countEmptyTiles();

    void newTile();

    int getScore();

private:
    vector<vector<Tile>> _board;

    int _currentScore = 0;

    void rotateClockwise();

    void rotateAntiClockwise();

    void collapseRight();

    void collapseLeft();

    bool isBoardFull();
};

#endif //FIVES_GAMEBOARD_H
