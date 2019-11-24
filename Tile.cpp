//
// Created by Cade Crandall on 11/17/19.
//

#include "Tile.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Tile::Tile() {      // tile default constructor
    // generate a random double between 0.0 and 1.0
    _currentValue = ((rand() / static_cast<double>(RAND_MAX)) < 0.9 ? 5 : 25);
}

Tile::Tile(int val) {       // tile constructor that can have a predetermined value (usually 0 for removing zeroes in merge moves)
    _currentValue = val;

}

void Tile::updateTileValue() {

}

void Tile::tileColor() {

}

bool Tile::setNeighborTiles() {
    return false;
}

bool Tile::getNeighborTiles() const {
    return false;
}

void Tile::delTile() {

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
