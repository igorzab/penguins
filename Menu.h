//
// Created by igor zab on 27/11/2023.
//
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "Penguin.h"
#include <iostream>
//#include "File.h"
#include "json.hpp"
#include "GameBoard.h"
#include <chrono>
#include <thread>
#ifndef PENGUINS2_MENU_H
#define PENGUINS2_MENU_H
using namespace std;
/**
 * @brief Animates a logo sprite.
 *
 * This function animates the provided sprite by updating its position based on a counter,
 * creating a smooth animation effect. It takes parameters such as the sprite to be animated,
 * the current position counter, animation speed, a clock for timing, the y-coordinate for positioning,
 * the current phase of the animation, and the size along the x-axis.
 *
 * @param animatedSprite Pointer to the sprite to be animated.
 * @param positionCounter Pointer to the current position counter.
 * @param animationSpeed The speed of the animation.
 * @param clock Pointer to the SFML Clock for timing.
 * @param yCoordinate The y-coordinate for positioning the sprite.
 * @param currentFaze Pointer to the current phase of the animation.
 * @param xSize The size along the x-axis.
 */
void animateLogo(sf::Sprite *animatedSprite, int *positionCounter, float animationSpeed,
                 sf::Clock *clock, int yCoordinate, int *currentFaze, int xSize);

/**
 * @brief Draws the introductory scene.
 *
 * This function draws the introductory scene in the provided SFML window. It uses a clock for timing,
 * an animation speed parameter, a position counter, and the current phase of the animation.
 *
 * @param window Pointer to the SFML RenderWindow to draw the scene in.
 * @param clock Pointer to the SFML Clock for timing.
 * @param animationSpeed The speed of the animation.
 * @param positionCounter Pointer to the current position counter.
 * @param currentFaze Pointer to the current phase of the animation.
 */
void drawIntro(sf::RenderWindow *window, sf::Clock *clock, float animationSpeed,
               int *positionCounter, int *currentFaze);

/**
 * @brief Draws the first page with snow effects.
 *
 * This function draws the first page in the provided SFML window, including snow effects.
 * It utilizes a clock for timing and a rectangle to control the snow animation.
 *
 * @param window Pointer to the SFML RenderWindow to draw the first page in.
 * @param snowClock Pointer to the SFML Clock for timing the snow animation.
 * @param snowRect Pointer to the SFML IntRect controlling the snow animation area.
 */
void drawFirstPage(sf::RenderWindow *window, sf::Clock *snowClock, sf::IntRect *snowRect);

/**
 * @brief Generates a random pair of coordinates.
 *
 * This function generates a random pair of coordinates within the specified ranges
 * along the x and y axes and stores them in the provided Pair structure.
 *
 * @param pair Pointer to the Pair structure to store the generated coordinates.
 * @param rangeX The range for the x-coordinate.
 * @param rangeY The range for the y-coordinate.
 */
void generateRandomPair(Pair *pair, int rangeX, int rangeY);

/**
 * @brief Draws the background.
 *
 * This function draws the background in the provided SFML window.
 *
 * @param window Pointer to the SFML RenderWindow to draw the background in.
 */
void drawBackground(sf::RenderWindow *window);

/**
 * @brief Draws the second page with penguins and player information.
 *
 * This function draws the second page in the provided SFML window, including penguins
 * and player information. It takes parameters for the number of penguins and players.
 *
 * @param window Pointer to the SFML RenderWindow to draw the second page in.
 * @param numPenguins Pointer to the number of penguins.
 * @param numPlayers Pointer to the number of players.
 */
void drawSecondPage(sf::RenderWindow *window, int *numPenguins, int *numPlayers);

/**
 * @brief Draws the third page.
 *
 * This function draws the third page in the provided SFML window.
 *
 * @param window Pointer to the SFML RenderWindow to draw the third page in.
 */
void drawThirdPage(sf::RenderWindow *window);

void drawFinal(sf::RenderWindow *window, GameBoard *gameBoard);

/**
 * @brief Modifies various values based on user input.
 *
 * This function modifies values such as the number of penguins, number of players,
 * and the current phase of the animation based on user input coordinates.
 *
 * @param numPenguins Pointer to the number of penguins to be modified.
 * @param numPlayers Pointer to the number of players to be modified.
 * @param currentFaze Pointer to the current phase of the animation to be modified.
 * @param clickX X-coordinate of the user's click.
 * @param clickY Y-coordinate of the user's click.
 */
void modifyValues(int *numPenguins, int *numPlayers, int *currentFaze, int clickX, int clickY);

/**
 * @brief Checks for intersection with a point.
 *
 * This function checks if a given point (specified by coordinates) intersects with
 * a particular region or object in the application.
 *
 * @param clickX X-coordinate of the point to check.
 * @param clickY Y-coordinate of the point to check.
 * @return True if the point intersects with the specified region, false otherwise.
 */
bool checkIntersection(int clickX, int clickY);


#endif //PENGUINS2_MENU_H


