//
// Created by igorz on 11/5/2023.
//
#pragma once
#ifndef PENGUINS2_GAMEBOARD_H
#define PENGUINS2_GAMEBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "iostream"
#include "Player.h"
#include "Tile.h"



struct GameBoard {
    int size;
    Tile **tiles;
    Player *players; // Array of players on the game board
};

struct Pair {
    int x;
    int y;
};

typedef struct GameBoard GameBoard;


double generateRandomNumber();

int createRandomFishAmount();

double gaussian2D(double x, double y, double centerX, double centerY, double stddevX, double stddevY);

void randomizeField(GameBoard *gameBoard);

#endif //PENGUINS2_GAMEBOARD_H
