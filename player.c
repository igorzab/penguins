#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"
#include "player.h"
#define MOVE_IS_NOT_POSSIBLE 0
#define MOVE_IS_POSSIBLE 1



struct Player* currentPlayer;
struct Player* players = 0;
int amountOfPlayers;
int amountOfPenguins;


struct Player* getCurrentPlayer(){
    return currentPlayer;
}

void setCurrentPlayer(struct Player* player){
    currentPlayer = player;
}

struct Player* setAllPlayers(){
    for (int i = 0; i < amountOfPlayers; i++) {
        printf("Hi Player %d! How should I call you?: ", i + 1);
        char *name = malloc(sizeof(char) * 20);
        name[strcspn(name, "\r\n")] = 0;

        int color = getPlayerColor();
        while(color == NO_COLOR) {
            setColor(12);
            printf("ERROR: color was not found.\n");
            setColor(7);
            color = getPlayerColor();
        }
        players[i].color = color;
        players[i].name = name;
        players[i].id = i+1;
        players[i].points = 0;
        players[i].numberOfPenguins = 0;
        players[i].movementStatus = MOVE_IS_NOT_POSSIBLE;
    }

    return players;
}

struct Player* getPlayer(int playerID) {
    return &players[playerID];
}

struct Board getPossibleMoves(struct Board* gameBoard, struct Player* current) {

    struct Board possibleMoves;

    possibleMoves.grid = malloc(sizeof(*gameBoard->grid) * gameBoard->size);
    for (int i = 0; i < gameBoard->size; i++)
        possibleMoves.grid[i] = malloc(sizeof(**gameBoard->grid) * gameBoard->size);

    for (int i = 0; i < gameBoard->size; i++) {
        for (int j = 0; j < gameBoard->size; j++)
            possibleMoves.grid[i][j] = '0';
    }

    if (current->numberOfPenguins == 0) {
        return possibleMoves;
    }

    int pengID = getPenguinID();

    int x = current->penguins[pengID].xCoordinate - 1;
    int y = current->penguins[pengID].yCoordinate - 1;

    for (int i = x + 1; i < gameBoard->size; i++) {
        if (gameBoard->grid[i][y] == water || gameBoard->grid[i][y] == playerOnIceFloe)
            break;
        possibleMoves.grid[i][y] = gameBoard->grid[i][y];
    }

    for (int i = x - 1; i >= 0; i--) {
        if (gameBoard->grid[i][y] == water || gameBoard->grid[i][y] == playerOnIceFloe)
            break;
        possibleMoves.grid[i][y] = gameBoard->grid[i][y];
    }

    for (int j = y + 1; j < gameBoard->size; j++) {
        if (gameBoard->grid[x][j] == water || gameBoard->grid[x][j] == playerOnIceFloe)
            break;
        possibleMoves.grid[x][j] = gameBoard->grid[x][j];
    }

    for (int j = y - 1; j >= 0; j--) {
        if (gameBoard->grid[x][j] == water || gameBoard->grid[x][j] == playerOnIceFloe)
            break;
        possibleMoves.grid[x][j] = gameBoard->grid[x][j];
    }

    possibleMoves.grid[x][y] = water;
    return possibleMoves;
}