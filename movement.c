#include <stdio.h>
#include <stdlib.h>
#include "movement.h"


#define MOVE_IS_NOT_POSSIBLE 0
#define MOVE_IS_POSSIBLE 1



void makeAMove(struct GameBoard *gameBoard){


    struct Player* current = getCurrentPlayer();
    int ID = getPenguinID();

    int currentX = current->penguins[ID].xCoordinate;
    int currentY = current->penguins[ID].yCoordinate;

    struct GameBoard possibleMoves = getPossibleMoves(gameBoard, current);

    int X;
    int Y;

    printf("\nInput number of the row to move: ");
    X = fixscanf();
    printf("Input number of the column to move: ");
    Y = fixscanf();
    while (possibleMoves.tiles[X][Y].fishCount > -1){
        printf("\nInput number of the row to move: ");
        X = fixscanf();
        printf("Input number of the column to move: ");
        Y = fixscanf();
    }

    gameBoard->tiles[currentX][currentY].fishCount = -1;


    gameBoard->tiles[X][Y].fishCount = 4;

    current->penguins[ID].xCoordinate = X;
    current->penguins[ID].yCoordinate = Y;

    if(gameBoard->tiles[currentX][currentY].fishCount > 0 && gameBoard->tiles[currentX][currentY].fishCount !=4){
        current->points += gameBoard->tiles[currentX][currentY].fishCount;
    }

};
