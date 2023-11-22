//
// Created by Tpshck on 11/20/2023.
//
#pragma once
#include "Penguin.h"
#ifndef PENGUINS2_PLAYER_H
#define PENGUINS2_PLAYER_H
struct Player {
    int playerID;   // Unique ID for the player
    int score;
    struct Penguin* penguins; // Array of penguins belonging to the player
    int numPenguins;
};
#endif //PENGUINS2_PLAYER_H
