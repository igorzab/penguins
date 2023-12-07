//
// Created by igor zab on 27/11/2023.
//
#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
//#include "json_struct.h"
#include "json.hpp"
#include "Penguin.h"
#include "GameBoard.h"
#include <chrono>
#include <thread>
#ifndef PENGUINS2_MENU_H
#define PENGUINS2_MENU_H

#define INTRO_PHASE  -1
#define HOME_SCREEN  0
#define MODE_SELECT 1
#define SETTINGS  2
#define GAME  3

using namespace std;
void animateLogo(sf::Sprite *animatedSprite ,int *positionCounter, float animationSpeed, sf::Clock *clock, int yCoordinate, int *currentFaze, int xSize);
void drawIntro(sf::RenderWindow *window, sf::Clock *clock, float animationSpeed, int *positionCounter, int *currentFaze);
void drawFirstPage(sf::RenderWindow *window, sf::Clock *snowClock, sf::IntRect *snowRect);
void generateRandomPair(Pair *pair, int rangeX, int rangeY);
void drawBackground(sf::RenderWindow *window);
void drawSecondPage(sf::RenderWindow *window, int *numPenguins, int *numPlayers);
void modifyValues(int* numPenguins, int* numPlayers, int *currentFaze, int clickX, int clickY);
bool checkIntersection(int clickX, int clickY);

#endif //PENGUINS2_MENU_H


