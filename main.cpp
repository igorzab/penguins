#include <iostream>

#include "Game.h"

int main() {
    int numPlayers = 2;
    int size = 51;
    int numPenguins = 3;

//    std::cout << "Plz enter a desired num of players: ";
//    std::cin >> numPlayers;
//    std::cout << "\nPlz enter a desired field size: ";
//    std::cin >> size;
    int windowSize = size > 20 ? size*20 : size*40;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Rybka");
    play(&window, numPlayers,numPenguins, size);


    return 0;
}