//
// Created by Cade Crandall on 11/17/19.
//

#include "Tile.h"
#include <cstdlib>

using namespace std;

Tile::Tile() {
    _currentValue = 0;
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

void Tile::increment() {
    _currentValue *= 2;
}

void Tile::setRandomValue() {
    _currentValue = ((rand() / static_cast<double>(RAND_MAX)) < 0.9 ? 2 : 4);
}
