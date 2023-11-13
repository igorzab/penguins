//
// Created by igorz on 11/5/2023.
//

#ifndef PENGUINS2_GAMEBOARD_H
#define PENGUINS2_GAMEBOARD_H


#include <vector>
#include "Tile.h"


#include <random>
#include <ctime>
#include <iostream>
using namespace std;
class GameBoard {
public:
    GameBoard(int size);
    void draw();
    void randomizeField();
    std::vector<std::vector<Tile>> getBoard();
private:
    int size;
    std::vector<std::vector<Tile>> tiles;
};


#endif //PENGUINS2_GAMEBOARD_H
