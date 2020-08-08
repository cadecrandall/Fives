//
// Created by Cade Crandall on 12/3/19.
//

#ifndef SFML_TEMPLATE_FUNCTIONS_H
#define SFML_TEMPLATE_FUNCTIONS_H
#include <vector>
#include <iostream>
#include "Gameboard.h"

using namespace std;

int determineBestScore(std::vector<int> scores);        // returns the index of the best score in the leaderboard
void makePlayerMove(Gameboard &gb, char move);

#endif //SFML_TEMPLATE_FUNCTIONS_H
