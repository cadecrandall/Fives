//
// Created by Cade Crandall on 11/17/19.
//

#include "Tile.h"
#include <cstdlib>

using namespace std;

Tile::Tile() {
    _currentValue = ((rand() / static_cast<double>(RAND_MAX)) < 0.9 ? 5 : 25);
}

Tile::Tile(int val) {
    _currentValue = val;
}

int Tile::getCurrentVal() {
    return _currentValue;
}

void Tile::setCurrentVal(int newVal) {
    _currentValue = newVal;
}

void Tile::setCurrentVal() {        // if called without argument, multiplies current Tile value by 5
    _currentValue *= 5;
}
