//
// Created by igorz on 11/5/2023.
//

#ifndef PENGUINS2_GAME_H
#define PENGUINS2_GAME_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Penguin.h"
#include "Tile.h"
#include "GameBoard.h"
using namespace std;
class Game {
public:
    Game(sf::RenderWindow *window, int numPlayers, int boardSize);
    void play();
    void makeMove();
private:
    void drawGameBoard();
    bool gameOver;
    int currentPhase;
    int currentColor;
    int numPlayers;
    int size;
    sf::RenderWindow  *window;
    GameBoard *gameBoard;
    std::vector<Penguin> Players;
};


#endif //PENGUINS2_GAME_H
