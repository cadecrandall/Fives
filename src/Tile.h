//
// Created by Cade Crandall on 11/25/19.
//

#ifndef FIVES_TILE_H
#define FIVES_TILE_H


class Tile {
public:
    Tile();         // default constructor
    Tile(int val);

    int getCurrentVal();

    void setCurrentVal(int newVal);

    void increment();

    void setRandomValue();

private:
    int _currentValue = 0;
};

#endif //FIVES_TILE_H
