#include <iostream>

#include "Game.h"
#include "Game.h"

int main() {
    int numPlayers = 0;
    int size = 0;

    std::cout << "Plz enter a desired num of players: ";
    std::cin >> numPlayers;
    std::cout << "\nPlz enter a desired field size: ";
    std::cin >> size;
    int windowSize = size > 20 ? size*20 : size*40;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Rybka");
    // Add your game logic here
    play(&window, numPlayers, size);


    return 0;
}