//
// Created by igor zab on 28/12/2023.
//
//#pragma once
#include <fstream>
#include <sstream>
#include "GameBoard.h"
using namespace std;
#ifndef PENGUINS2_FILE_H
#define PENGUINS2_FILE_H

void writeGameState(GameBoard& game, int numPlayers);
void readGameData(GameBoard* gameBoard, int numPlayers);

#endif //PENGUINS2_FILE_H
