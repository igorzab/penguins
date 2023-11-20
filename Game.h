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
#include "Tile.h"
#include "GameBoard.h"
//using namespace std;
//class Game {
//public:
//    Game(sf::RenderWindow *window, int numPlayers, int boardSize);
//    void play();
//    void makeMove();
//private:
//    void drawGameBoard();
//    bool gameOver;
//    int currentPhase;
//    int currentColor;
//    int numPlayers;
//    int size;
//    sf::RenderWindow  *window;
//    GameBoard *gameBoard;
//    std::vector<Penguin> Players;
//};

//
// Created by igorz on 11/5/2023.
//
#include <chrono>
#include <thread>
#include "GameBoard.h"

void drawGameBoard(struct GameBoard* board, int size, sf::RenderWindow *window);

void makeMove(int size);

void play(sf::RenderWindow *window, bool gameOver, int size);

Pair getPressedTile(int x, int y, GameBoard *gameBoard);

#endif //PENGUINS2_GAME_H
