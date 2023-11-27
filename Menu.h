//
// Created by igor zab on 27/11/2023.
//
#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Penguin.h"
#include "GameBoard.h"
#include <chrono>
#include <thread>
#ifndef PENGUINS2_MENU_H
#define PENGUINS2_MENU_H
using namespace std;

void drawFirstPage(sf::RenderWindow *window);
void drawSecondPage(sf::RenderWindow *window, int *numPenguins, int *numPlayers);
void modifyValues(int* numPenguins, int* numPlayers, int clickX, int clickY);
bool checkIntersection(int clickX, int clickY);

#endif //PENGUINS2_MENU_H


