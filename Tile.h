//
// Created by Cade Crandall on 11/17/19.
//

#ifndef FIVES_TILE_H
#define FIVES_TILE_H


class Tile {
public:
    Tile();         // default constructor
    Tile(int val);
    void updateTileValue();     // updates tile value when merged
    void tileColor();           // updates tile color when merged
    bool setNeighborTiles();    // checks to see if tile can move after each move
    bool getNeighborTiles() const;
    void delTile();     // deletes tile when merged
    int getCurrentVal();
    void setCurrentVal(int newVal);
    void setCurrentVal();
private:
    int _currentValue = 0;
    int _color;
    int _rowNum;
    int _colNum;
    bool _neighborTiles[4];      // array of bools (Up, Right, Down, Left) that checks to see if neighbors are same val
};


#endif //FIVES_TILE_H
