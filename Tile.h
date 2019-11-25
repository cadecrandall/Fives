//
// Created by Cade Crandall on 11/17/19.
//

#ifndef FIVES_TILE_H
#define FIVES_TILE_H


class Tile {
public:
    Tile();         // default constructor
    Tile(int val);
    void tileColor();           // updates tile color when merged
    int getCurrentVal();
    void setCurrentVal(int newVal);
    void setCurrentVal();
private:
    int _currentValue = 0;
    int _color;
};


#endif //FIVES_TILE_H
