//
// Created by igorz on 11/5/2023.
//
#pragma once
#ifndef PENGUINS2_GAME_H
#define PENGUINS2_GAME_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "Penguin.h"
#include "GameBoard.h"
#include <chrono>
#include <thread>

void drawGameBoard(struct GameBoard* board, int size, sf::RenderWindow *window);

void placePenguins(GameBoard* gameBoard, Player* player, int numPenguins, Pair pressedTile);

void initializePlayers(GameBoard* gameBoard, int numPlayers, int numPenguins, Pair pressedTile);

void drawAPenguin(int x, int y, GameBoard *gameBoard);

void initializePenguins(GameBoard* gameBoard, int numPlayers, int numPenguins);

void play(sf::RenderWindow *window, int numPlayers, int numPenguins, int size);

Pair getPressedTile(int x, int y, GameBoard *gameBoard);

#endif //PENGUINS2_GAME_H
