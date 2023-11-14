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

/*
struct Penguin {
    int xCoordinate;
    int yCoordinate;
};

int penguinID;
int amountOfPenguins;

int getPenguinID();

void setPenguinID(int ID);

};
 penguin.c: всё что ниже
void setPenguinID(int ID) {
	penguinID = ID;

int getPenguinID() {
    return penguinID;
};
void setAmountOfPenguins() {
	int pengus;
	clear();
	printf("Please, input the amount of penguins (at least 1, max 3): ");
	pengus = fixscanf();
	while (pengus < 1 || pengus > 3) {
		clear();
		setColor(LIGHT_RED);
		printf("ERROR: incorrect penguins amount. Please, type it again (at least 1, max 3): ");
		setColor(LIGHT_GRAY);
		pengus = fixscanf();
	}
	clear();
	amountOfPenguins = pengus;
};
 */
