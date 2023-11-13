//
// Created by igorz on 11/5/2023.
//

#ifndef PENGUINS2_PENGUIN_H
#define PENGUINS2_PENGUIN_H


#include "Tile.h"

class Penguin {
public:
    Penguin(int color, int x, int y);
    void move(int newX, int newY);
    void collectFish(Tile& tile);
private:
    bool isValidMove(int newX, int newY) const;
    int xCoordinate;
    int yCoordinate;
    int penguinColor;
    int score;
};


#endif //PENGUINS2_PENGUIN_H
