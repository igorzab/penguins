#include <iostream>

#include "Game.h"

void validateData(int *x) {
    while (scanf("%d", x) != 1) {
        while (getchar() != '\n');

        printf("Invalid input. Please enter an integer: ");
    }
}

int main() {
    int numPlayers = -1;
    int size = -1;
    int numPenguins = -1;

    while(numPlayers < 0){
        printf("Enter the number of players: ");
        validateData(&numPlayers);
    }

    while(numPenguins < 0){
        printf("Enter the number of penguins: ");
        validateData(&numPenguins);
    }

    while(size < 5 || size < numPlayers * numPenguins){
        printf("Enter the field size: ");
        validateData(&size);
    }

    int windowSize = size > 20 ? size * 20 : size * 40;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Rybka");
    play(&window, numPlayers, numPenguins, size);


    return 0;
}