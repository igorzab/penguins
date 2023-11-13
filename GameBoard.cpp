//
// Created by igorz on 11/5/2023.
//

#include <chrono>
#include "GameBoard.h"

std::random_device rd;
std::mt19937 gen(rd());

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

bool isCloserToZero(double distance) {
    cout << distance << endl;
    if (distance < 10) {
        int random = getRandomNumber(1, 10);
        if (random < 5) {
            return true;
        }
    }
    return false;
}


double generateRandomNumber() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0, 1);
    return dis(gen);
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
    //stddev - standard deviation.
    double exponent = -(pow((x-centerX), 2) / (2 * stddevX * stddevX) + (pow((y - centerY), 2)) / (2 * stddevY * stddevY));
    return exp(exponent) / (2 * M_PI * stddevX * stddevY);
}

void GameBoard::randomizeField() {

    double centerX = size / 2.0;
    double centerY = size / 2.0;

    double iceDensity = 1024 * size / 20; // Adjust as needed (1024 * size / 20 is the best variant among others tested.)
    double stddevX = size / 5.0;
    double stddevY = size / 5.0;
    std::vector<std::vector<Tile>> field;

    for (int i = 0; i < size; i++) {
        std::vector<Tile> row;
        for (int j = 0; j < size; j++) {
            double x = j + 0.5; // Adjust for center of each square
            double y = i + 0.5; // Adjust for center of each square

            double density = gaussian2D(x, y, centerX, centerY, stddevX, stddevY); // get density using gaussian distribution for 2 dimensions formula.
            int fishAmount = createRandomFishAmount();

            if (generateRandomNumber() < density * iceDensity) { // create ice tile
                Tile tile(fishAmount, j, i);
                row.push_back(tile);
            } else { // create water tile
                Tile tile(-1, j, i);
                row.push_back(tile);
            }
        }
        field.push_back(row);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (field[i][j].getFishCount() == -1) continue;
            bool waterOnWayX = false;
            bool waterOnWayY = false;
            if (j == size / 2) waterOnWayX;
            if (i == size / 2) waterOnWayY;
            for (int k = j + 1; k <= size / 2 + 1; k++) {
                if (field[i][k].getFishCount() == -1) {
                    waterOnWayX = true;
                    break;
                }
            }
            for (int k = j - 1; k >= size / 2 - 1; k--) {
                if (field[i][k].getFishCount() == -1) {
                    waterOnWayX = true;
                    break;
                }
            }
            for (int b = i + 1; b <= size / 2 + 1; b++) {
                if (field[b][j].getFishCount() == -1) {
                    waterOnWayY = true;
                    break;
                }
            }
            for (int b = i - 1; b >= size / 2 - 1; b--) {
                if (field[b][j].getFishCount() == -1) {
                    waterOnWayY = true;
                    break;
                }
            }
            if (waterOnWayX && waterOnWayY) field[i][j].setFishCount(-1);
        }
    }
    this->tiles = field;
}
