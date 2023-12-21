//
// Created by igorz on 11/5/2023.
//
#pragma once
#ifndef PENGUINS2_GAME_H
#define PENGUINS2_GAME_H

#include "Menu.h"



/**
 * @file Game.h
 *
 * @brief Header file for the functions related to the game logic and drawing.
 */

/**
 * @brief Draws a penguin tile on the game board.
 *
 * This function draws a penguin-shaped object on a specified tile of the game board using SFML graphics.
 * The tile background color, owning player, and position are taken into account when rendering the penguin.
 *
 * @param board A pointer to the GameBoard structure representing the game state.
 * @param size The size of the game board.
 * @param tileBackgroundColor The background color of the tile.
 * @param tileRect The SFML RectangleShape representing the tile.
 * @param window A pointer to the SFML RenderWindow used for drawing.
 * @param i The row index of the tile.
 * @param j The column index of the tile.
 * @param fishSize The size of the fish (penguin).
 * @param tileSize The size of the tile.
 */
void drawPenguinTile(struct GameBoard *board, int size, sf::Color tileBackgroundColor, sf::RectangleShape tileRect,
                     sf::RenderWindow *window, int i, int j, int fishSize, int tileSize);

/**
 * @brief Draws the game board on the provided SFML RenderWindow.
 *
 * This function takes a GameBoard structure, its size, and an SFML RenderWindow as parameters. It uses SFML graphics
 * to draw the tiles, fish, penguins, and grid lines on the window. The function also adjusts the size of tiles and fish
 * based on the given size parameter.
 *
 * @param board A pointer to the GameBoard structure representing the game state.
 * @param size The size of the game board.
 * @param window A pointer to the SFML RenderWindow used for drawing.
 */
void drawGameBoard(struct GameBoard *board, int size, sf::RenderWindow *window, int numPenguins, int numPlayers);

/**
 * @brief Places a penguin on the game board at the specified position.
 *
 * This function is responsible for placing a penguin on the game board by updating the corresponding fish count value.
 *
 * @param x The x-coordinate of the penguin's position on the game board.
 * @param y The y-coordinate of the penguin's position on the game board.
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 */
void drawAPenguin(int x, int y, GameBoard *gameBoard);

/**
 * @brief Determines the tile that was pressed based on mouse coordinates.
 *
 * Given the mouse click coordinates, this function calculates and returns the corresponding tile on the game board.
 *
 * @param clickX The x-coordinate of the mouse click.
 * @param clickY The y-coordinate of the mouse click.
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 * @return A Pair structure containing the coordinates (row and column) of the pressed tile.
 */
Pair getPressedTile(int clickX, int clickY, GameBoard *gameBoard);

/**
 * @brief Initializes player data in the game board structure.
 *
 * This function allocates memory for players and their penguins, initializing their IDs, scores, and positions.
 *
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 * @param numPlayers The number of players in the game.
 * @param numPenguins The number of penguins each player has.
 */
void initializePlayers(GameBoard *gameBoard, int numPlayers, int numPenguins);

/**
 * @brief Initializes penguin positions for each player in the game board structure.
 *
 * This function sets the initial positions and status of penguins for each player in the game.
 *
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 * @param numPlayers The number of players in the game.
 * @param numPenguins The number of penguins each player has.
 */
void initializePenguins(GameBoard *gameBoard, int numPlayers, int numPenguins);

/**
 * @brief Checks if a given tile is obstructed by water or another penguin.
 *
 * This function determines if the specified tile is obstructed by checking its fish count value.
 * A tile is considered obstructed if it represents water (-1) or contains a penguin (-2).
 *
 * @param x The x-coordinate of the tile.
 * @param y The y-coordinate of the tile.
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 * @return True if the tile is obstructed, false otherwise.
 */
bool badTileOnWay(int x, int y, GameBoard *gameBoard);

/**
 * @brief Checks if a given tile is a valid move for a penguin.
 *
 * This function verifies whether the specified move is legal based on the current position of the selected penguin.
 *
 * @param x The x-coordinate of the target tile.
 * @param y The y-coordinate of the target tile.
 * @param selected A pointer to the selected penguin.
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 * @return True if the move is legal, false otherwise.
 */
bool checkLegalMove(int x, int y, Penguin *selected, GameBoard *gameBoard);

/**
 * @brief Checks if a penguin has valid moves available.
 *
 * This function determines whether the selected penguin has legal moves in any direction on the game board.
 *
 * @param penguin A pointer to the penguin to be checked.
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 * @return True if the penguin can move, false otherwise.
 */
bool canMove(Penguin *penguin, GameBoard *gameBoard);

/**
 * @brief Checks if any of the player's penguins have valid moves.
 *
 * This function iterates through a player's penguins to check if any of them can make legal moves on the game board.
 *
 * @param player A pointer to the player to be checked.
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 * @param numPenguins The number of penguins each player has.
 * @return True if any penguin can move, false otherwise.
 */
bool movesExist(Player *player, GameBoard *gameBoard, int numPenguins);

/**
 * @brief Checks if there are valid moves available for any player.
 *
 * This function determines if any player in the game has penguins that can make legal moves on the game board.
 *
 * @param gameBoard A pointer to the GameBoard structure representing the game state.
 * @param numPlayers The number of players in the game.
 * @param numPenguins The number of penguins each player has.
 * @return True if any player has valid moves, false otherwise.
 */
bool totalMovesExist(GameBoard *gameBoard, int numPlayers, int numPenguins);

void playAnimation(sf::Sprite *animatedSprite, sf::IntRect *rectSource, float animationSpeed, sf::Clock *clock);


void recieveData(sf::TcpSocket *socket, sf::RenderWindow *window, GameBoard *gameBoard, int *currentPlayer, int *currentPhase);
/**
 * @brief Main function to play the game.
 *
 * This function handles the main game loop, including placing penguins on the board, selecting penguins, and making moves.
 * It uses SFML to create a window and handle user input for gameplay.
 *
 * @param window A pointer to the SFML RenderWindow used for displaying the game.
 * @param numPlayers The number of players in the game.
 * @param numPenguins The number of penguins each player has.
 * @param size The size of the game board.
 */
void play(sf::RenderWindow *window, sf::TcpSocket *socket);

#endif