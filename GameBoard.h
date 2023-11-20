//
// Created by igorz on 11/5/2023.
//

#ifndef PENGUINS2_GAMEBOARD_H
#define PENGUINS2_GAMEBOARD_H
#pragma once

#include <vector>
#include "Tile.h"


#include <random>
#include <ctime>
//#include <iostream>
//using namespace std;
//class GameBoard {
//public:
//    GameBoard(int size);
//    void draw();
//    void randomizeField();
//    std::vector<std::vector<Tile>> getBoard();
//private:
//    int size;
//    std::vector<std::vector<Tile>> tiles;
//};


struct Tile {
    int fishCount;
    int x;
    int y;
};

typedef struct Tile Tile;

struct GameBoard {
    int size;
    Tile** tiles;
};

struct Pair {
    int x;
    int y;
};

typedef struct GameBoard GameBoard;


double generateRandomNumber();

int createRandomFishAmount();

double gaussian2D(double x, double y, double centerX, double centerY, double stddevX, double stddevY);

void randomizeField(GameBoard* gameBoard);
void freeGameBoard(GameBoard* gameBoard);

#endif //PENGUINS2_GAMEBOARD_H
