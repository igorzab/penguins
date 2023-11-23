#include <iostream>

#include "Game.h"

bool validateData(int *x) {
    while (scanf("%d", x) != 1) {
        while (getchar() != '\n');

        printf("Invalid input. Please enter an integer: ");
    }
}

int main() {
    int numPlayers = 3;
    int size = 15;
    int numPenguins = 1;

    printf("Enter the number of players: ");
    validateData(&numPlayers);

    printf("Enter the number of penguins: ");
    validateData(&numPenguins);

    printf("Enter the field size: ");
    validateData(&size);

    int windowSize = size > 20 ? size * 20 : size * 40;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Rybka");
    play(&window, numPlayers, numPenguins, size);


    return 0;
}