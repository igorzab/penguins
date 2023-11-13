#include <iostream>

#include "Game.h"

int main() {
    int numPlayers = 0;
    int size = 0;

    cout << "Plz enter a desired num of players: ";
    cin >> numPlayers;
    cout << "\nPlz enter a desired field size: ";
    cin >> size;
    int windowSize = size > 20 ? size*20 : size*40;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Rybka");
    // Add your game logic here
    Game game(&window, numPlayers, size);
    game.play();


    return 0;
}