#pragma once
//
// Created by igorz on 11/5/2023.
//

#ifndef PENGUINS2_PENGUIN_H
#define PENGUINS2_PENGUIN_H
#include <stdio.h>

/**
 * @struct Penguin
 * @brief Represents a penguin entity in the game.
 *
 * The Penguin structure holds information about a penguin, including its activity status, the player ID
 * who owns the penguin, and its coordinates on the game board.
 */
struct Penguin {
    int isActive;  ///< Flag to indicate whether the penguin is active (0 for inactive, 1 for active).
    int playerID;  ///< ID of the player who owns the penguin.
    int x;         ///< The x-coordinate of the penguin on the game board.
    int y;         ///< The y-coordinate of the penguin on the game board.
};
#endif // PENGUINS2_PENGUIN_H
