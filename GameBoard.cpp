#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GameBoard.h"
#include <iostream>

double generateRandomNumber() {
    double randomized = (double)rand() / RAND_MAX;
    return randomized;
}

int createRandomFishAmount() {
    double randomNumber = generateRandomNumber();
    int fishAmount = 0;
    if (randomNumber < 0.5) {
        fishAmount = 1;
    } else if (randomNumber < 0.7) {
        fishAmount = 2;
    } else if (randomNumber <= 1) {
        fishAmount = 3;
    }
    return fishAmount;
}

double gaussian2D(double x, double y, double centerX, double centerY, double stddevX, double stddevY) {
    double exponent = -(pow((x - centerX), 2) / (2 * stddevX * stddevX) + pow((y - centerY), 2) / (2 * stddevY * stddevY));
    return exp(exponent) / (2 * M_PI * stddevX * stddevY);
}

void randomizeField(GameBoard* gameBoard) {
    srand((unsigned int)time(NULL));
    int size = gameBoard->size;
    double centerX = size / 2.0;
    double centerY = size / 2.0;
    double iceDensity = 1024 * size / 20;
    double stddevX = size / 5.0;
    double stddevY = size / 5.0;

    gameBoard->tiles = (Tile**)malloc(size * sizeof(Tile*));
    for (int i = 0; i < size; i++) {
        gameBoard->tiles[i] = (Tile*)malloc(size * sizeof(Tile));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double x = j + 0.5;
            double y = i + 0.5;

            double density = gaussian2D(x, y, centerX, centerY, stddevX, stddevY);
            int fishAmount = createRandomFishAmount();

            if (generateRandomNumber() < density * iceDensity) {
                gameBoard->tiles[i][j].fishCount = fishAmount;
            } else {
                gameBoard->tiles[i][j].fishCount = -1;
            }

            gameBoard->tiles[i][j].x = j;
            gameBoard->tiles[i][j].y = i;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (gameBoard->tiles[i][j].fishCount == -1) continue;
            bool waterOnWayX = false;
            bool waterOnWayY = false;
            if (j == size / 2) waterOnWayX;
            if (i == size / 2) waterOnWayY;
            for (int k = j + 1; k <= size / 2 + 1; k++) {
                if (gameBoard->tiles[i][k].fishCount == -1) {
                    waterOnWayX = true;
                    break;
                }
            }
            for (int k = j - 1; k >= size / 2 - 1; k--) {
                if (gameBoard->tiles[i][k].fishCount == -1) {
                    waterOnWayX = true;
                    break;
                }
            }
            for (int b = i + 1; b <= size / 2 + 1; b++) {
                if (gameBoard->tiles[b][j].fishCount == -1) {
                    waterOnWayY = true;
                    break;
                }
            }
            for (int b = i - 1; b >= size / 2 - 1; b--) {
                if (gameBoard->tiles[b][j].fishCount == -1) {
                    waterOnWayY = true;
                    break;
                }
            }
            if (waterOnWayX && waterOnWayY) gameBoard->tiles[i][j].fishCount = -1;
        }
    }
}

void freeGameBoard(GameBoard* gameBoard) {
    for (int i = 0; i < gameBoard->size; i++) {
        free(gameBoard->tiles[i]);
    }
    free(gameBoard->tiles);
}
