//
// Created by Cade Crandall on 12/3/19.
//

#ifndef FIVES_FUNCTIONS_H
#define FIVES_FUNCTIONS_H

#include <vector>
#include <iostream>
#include "Gameboard.h"

using namespace std;

int getBestScore(std::vector<int> scores);
void makePlayerMove(Gameboard &gb, char move);

#endif //FIVES_FUNCTIONS_H
