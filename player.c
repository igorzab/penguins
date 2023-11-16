#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        printf("Player %d! Enter your name: ", i + 1);
        char *name = malloc(sizeof(char) * 20);
        name[strcspn(name, "\r\n")] = 0;

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

struct GameBoard getPossibleMoves(struct GameBoard *gameBoard, struct Player* current) {

    struct Board possibleMoves;

    possibleMoves.tiles = malloc(sizeof(*gameBoard->tiles) * gameBoard->size);
    for (int i = 0; i < gameBoard->size; i++)
        possibleMoves.tiles[i] = malloc(sizeof(**gameBoard->tiles) * gameBoard->size);

    for (int i = 0; i < gameBoard->size; i++) {
        for (int j = 0; j < gameBoard->size; j++)
            possibleMoves.tiles[i][j].fishCount = -1;
    }

    if (current->numberOfPenguins == 0) {
        return possibleMoves;
    }

    int pengID = getPenguinID();

    int x = current->penguins[pengID].xCoordinate;
    int y = current->penguins[pengID].yCoordinate;

    for (int i = x + 1; i < gameBoard->size; i++) {
        if (gameBoard->tiles[i][y].fishCount == -1 || gameBoard->tiles[i][y].fishCount == 4)
            break;
        possibleMoves.grid[i][y] = gameBoard->grid[i][y];
    }

    for (int i = x - 1; i >= 0; i--) {
        if (gameBoard->tiles[i][y].fishCount == -1 || gameBoard->tiles[i][y].fishCount == 4)
            break;
        possibleMoves.grid[i][y] = gameBoard->grid[i][y];
    }

    for (int j = y + 1; j < gameBoard->size; j++) {
        if (gameBoard->tiles[x][j].fishCount == -1 || gameBoard->tiles[x][j].fishCount == 4)
            break;
        possibleMoves.grid[x][j] = gameBoard->grid[x][j];
    }

    for (int j = y - 1; j >= 0; j--) {
        if (gameBoard->tiles[x][j].fishCount == -1 || gameBoard->tiles[x][j].fishCount == 4)
            break;
        possibleMoves.grid[x][j] = gameBoard->grid[x][j];
    }
    return possibleMoves;
}

int fixscanf() {
    int variable;
    int readNr = 0;
    while (readNr != 1) {

        readNr = scanf("%d", &variable);
        if (readNr != 1) {
            printf("ERROR: please input a number: \n");
        }
        scanf("%*[^\n]");
    }
    return variable;
}