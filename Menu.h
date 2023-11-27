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

bool checkIntersection(int clickX, int clickY);

#endif //PENGUINS2_MENU_H


