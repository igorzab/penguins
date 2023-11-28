#include <iostream>
#include "Game.h"

// Function to get validated user input
int getUserInput(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        while (getchar() != '\n');
        printf("Invalid input. Please enter an integer: ");
    }
    return value;
}

int main() {
    // Loop until user enter valid number of players
    int numPlayers = 2;
//    do {
//        numPlayers = getUserInput("Enter the number of players: ");
//    } while(numPlayers < 0);
//
//    // Loop until user enter valid number of penguins
    int numPenguins = 2;
//    do {
//        numPenguins = getUserInput("Enter the number of penguins: ");
//    } while(numPenguins < 0);
//
//    // Loop until user enter valid field size
    int size = 20;
//    do {
//        size = getUserInput("Enter the field size: ");
//    } while(size < 5 || size < numPlayers*numPenguins);

    int windowSize = size > 20 ? size * 20 : size * 40;
    sf::VideoMode desktop = sf::VideoMode::getFullscreenModes()[0];
    sf::RenderWindow window(desktop, "Rybka"); // sf::Style::Fullscreen for fullscreen mode
//    window.setFramerateLimit(60);
    play(&window);

    return 0;
}