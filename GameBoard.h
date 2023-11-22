//
// Created by igorz on 11/5/2023.
//
#pragma once
#ifndef PENGUINS2_GAMEBOARD_H
#define PENGUINS2_GAMEBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "iostream"
#include "Player.h"
#include "Tile.h"


/**
 * @struct GameBoard
 * @brief Represents the game board state.
 *
 * The GameBoard structure holds information about the game board, including its size, an array of tiles,
 * and an array of players participating in the game.
 */
struct GameBoard {
    int size;        ///< The size of the game board.
    Tile **tiles;    ///< 2D array representing the tiles on the game board.
    Player *players; ///< Array of players on the game board.
};

/**
 * @struct Pair
 * @brief Represents a pair of integers.
 *
 * The Pair structure is a simple structure holding two integer values, typically used to represent
 * coordinates or indices in the context of the game.
 */
struct Pair {
    int x; ///< The first integer value in the pair.
    int y; ///< The second integer value in the pair.
};

typedef struct GameBoard GameBoard; ///< Typedef for the GameBoard structure.

/**
 * @brief Generates a random number between 0 and 1.
 *
 * This function utilizes the standard rand() function to generate a random double between 0 and 1.
 *
 * @return A random double between 0 and 1.
 */
double generateRandomNumber();

/**
 * @brief Creates a random fish amount based on a generated random number.
 *
 * The function generates a random number and assigns a fish amount based on specific probability thresholds.
 *
 * @return The randomly generated fish amount (1, 2, or 3).
 */
int createRandomFishAmount();

/**
 * @brief Calculates a 2D Gaussian distribution.
 *
 * This function calculates the value of a 2D Gaussian distribution at a given point (x, y) with specified parameters.
 *
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * @param centerX The x-coordinate of the center of the distribution.
 * @param centerY The y-coordinate of the center of the distribution.
 * @param stddevX The standard deviation along the x-axis.
 * @param stddevY The standard deviation along the y-axis.
 * @return The value of the 2D Gaussian distribution at the specified point.
 */
double gaussian2D(double x, double y, double centerX, double centerY, double stddevX, double stddevY);

/**
 * @brief Randomizes the game board by placing fish tiles based on a 2D Gaussian distribution.
 *
 * This function initializes the game board with fish and water tiles. It uses a 2D Gaussian distribution to determine
 * the density of fish at each position on the board. The randomization process includes considering a central point,
 * standard deviations, and creating random fish amounts.
 *
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 */
void randomizeField(GameBoard *gameBoard);

#endif //PENGUINS2_GAMEBOARD_H
