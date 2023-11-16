//
// Created by Tpshck on 11/13/2023.
//
#pragma once
#ifndef PENGUINS2_PLAYER_H
#define PENGUINS2_PLAYER_H

#endif //PENGUINS2_PLAYER_H

struct Player {
    char* name;
    int points;
    int id;
    struct Penguin* penguins;
    int numberOfPenguins;
    int color;
    int movementStatus;
};
extern struct Player* players;
int amountOfPlayers;
int amountOfPenguins;

extern struct Player* currentPlayer;
struct Player* getCurrentPlayer(void);
void setCurrentPlayer(struct Player* players);
struct GameBoard getPossibleMoves(struct GameBoard *gameBoard, struct Player* current);

struct Player* getPlayer(int playerID);
struct Player* setAllPlayers(void);

int fixscanf();