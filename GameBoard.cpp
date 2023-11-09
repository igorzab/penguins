//
// Created by igorz on 11/5/2023.
//

#include <chrono>
#include "GameBoard.h"

GameBoard::GameBoard(int size) {
    this->size = size;
    this->tiles = {};
    randomizeField();
}

void GameBoard::draw() {
    //draw
}

std::vector<std::vector<Tile>> GameBoard::getBoard() {
    return this->tiles;
}

int getRandomNumber(int min, int max) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    int randomizedNumber = rand() % (max - min) + min; // ???
    return randomizedNumber;
}

void GameBoard::randomizeField() {

    std::vector<std::vector<Tile>> field;
    for (int i = 0; i < size; i++) {
        std::vector<Tile> row;
        for (int j = 0; j < size; j++) {
            int randomNumber = getRandomNumber(0, 10);
            int fishAmount = 0;
            if (randomNumber == 1) {
                fishAmount = -1;
            } else if (randomNumber < 4) {
                fishAmount = 0;
            } else if (randomNumber < 7) {
                fishAmount = 1;
            } else if (randomNumber < 9) {
                fishAmount = 2;
            } else if (randomNumber <= 10) {
                fishAmount = 3;
            }
            if(abs(i-size) < 3 && abs(j-size) < 5) fishAmount = -1; //TODO: water randomizing algorithm.
            cout << "fishCount: " << fishAmount << endl;
            Tile tile(fishAmount, i, j);
            row.push_back(tile);

        }
        field.push_back(row);
    }
    this->tiles = field;
}
