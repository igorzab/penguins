#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "player.h"
#include "Penguin.h"
#include "colors.h"


#define MOVE_IS_NOT_POSSIBLE 0
#define MOVE_IS_POSSIBLE 1



void makeAMove(/*структура игрового поля*/){


    struct Player* current = getCurrentPlayer();
    int ID = getPenguidID();

    int currentX = current->penguins[ID].xCoordinate-1;
    int currentY = current->penguins[ID].yCoordinate-1;

    struct Board possibleMoves = getPossibleMoves(gameBoard, current);

    int X;
    int Y;

    do {
        printf("\nInput number of the row to move (ex. 1): ");
        X = fixscanf();
        X--;
        printf("Input number of the column to move (ex. A): ");
        Y = fixscanf();
        Y--;
    } while (gameBoard->grid[X][Y] != possibleMoves.grid[X][Y]);
    board->grid[currentX][currentY] = '_';


    board->grid[X][Y] = 'P';

    current->penguins[ID].coordinateX = X + 1;
    current->penguins[ID].coordinateY = (char)('A' + Y);


    if ('1' == possibleMoves.grid[X][Y]) {
        current->points += 1;
    }

    if ('2' == possibleMoves.grid[X][Y]) {
        current->points += 2;
    }

    if ('3' == possibleMoves.grid[X][Y]) {
        current->points += 3;
    }

};
