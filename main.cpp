#include <iostream>
#include "Game.h"

#include <stdio.h>
#include <string.h>

bool processParameters(char *phase, int penguins, char *inputboardfile, char *outputboardfile, char *name) {
    // Check phase
    if (strcmp(phase, "placement") == 0 || strcmp(phase, "movement") == 0) {
        printf("Phase: %s\n", phase);
    } else {
        printf("Invalid phase. It should be either 'placement' or 'movement'\n");
        return false;
    }

    // Check penguins when phase is 'placement'
    if (strcmp(phase, "placement") == 0) {
        if (penguins <= 0) {
            printf("Invalid number of penguins. It should be greater than 0 for placement phase.\n");
            return false;
        }
        printf("Number of Penguins: %d\n", penguins);
    }

    // Check input and output board files
    if (strcmp(inputboardfile, outputboardfile) == 0) {
        printf("Warning: Input and output board files are the same.\n");
    }

    printf("Input Board File: %s\n", inputboardfile);
    printf("Output Board File: %s\n", outputboardfile);

    // Check if 'name' is present
    if (strcmp(name, "") > 0) {
        printf("Player's name requested.\n");
    } else {
        printf("Error parsing player's name..\n");
    }
    return true;
}

int main(int argc, char *argv[]) {

    // Initialize variables
    char *phase = NULL;
    int penguins = 0;
    char *inputboardfile = NULL;
    char *outputboardfile = NULL;
    char *name = NULL;



    int useFiles = 1;
    if (argc != 6) {
        printf("Invalid params size. proceeding without params.\n");
        useFiles = 0;
    }else{
        // Parse arguments
        for (int i = 1; i < argc; i++) {
            char *param = strtok(argv[i], "=");
            char *value = strtok(NULL, "=");

            if (param && value) {
                if (strcmp(param, "phase") == 0) {
                    phase = value;
                } else if (strcmp(param, "penguins") == 0) {
                    penguins = atoi(value);
                } else if (strcmp(param, "inputboardfile") == 0) {
                    inputboardfile = value;
                } else if (strcmp(param, "outputboardfile") == 0) {
                    outputboardfile = value;
                } else if (strcmp(param, "name") == 0) {
                    name = value;
                }
            }
        }
        // Process parameters
        if(!processParameters(phase, penguins, inputboardfile, outputboardfile, name)){
            return 0;
        }
    }


    int size = 20;

    int windowSize = size > 20 ? size * 20 : size * 40;
    int inputPhase = strcmp(phase, "movement") == 0 ? 1 : 0;
    sf::TcpSocket socket;
    socket.connect("127.0.0.1", 12345);
    sf::VideoMode desktop = sf::VideoMode::getFullscreenModes()[0];
    sf::RenderWindow window(desktop, "Rybka"); // sf::Style::Fullscreen for fullscreen mode
    window.setFramerateLimit(60);
    play(&window, inputPhase, useFiles, inputboardfile, outputboardfile);

    return 0;
}