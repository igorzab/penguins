//
// Created by igorz on 11/5/2023.
//
#include "Game.h"
#include <chrono>
#include <thread>

#define NUM_OF_PENGUINS 2

void drawGameBoard(struct GameBoard *board, int size, sf::RenderWindow *window) {
    const int tileSize = size > 20 ? 20 : 40; // Adjust this value to set the size of each tile.

    const int fishSize = tileSize / 6; // adjust this value to change a fishTile size;
    window->clear(); // Clear the window before drawing.

    // Iterate through tiles and draw them
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            sf::RectangleShape tileRect(sf::Vector2f(tileSize, tileSize));
            tileRect.setPosition(j * tileSize, i * tileSize);

            if (board->tiles[i][j].fishCount == -1) { // Water
                tileRect.setFillColor(sf::Color::Blue);

                window->draw(tileRect);
            } else if (board->tiles[i][j].fishCount == -2) { //Penguin

                tileRect.setFillColor(sf::Color::White);
                window->draw(tileRect);
                sf::Color fillColor = sf::Color::White;
                switch (board->tiles[i][j].owningPlayer) {
                    case 1:
                        fillColor = sf::Color::Red;
                        break;
                    case 2:
                        fillColor = sf::Color::Green;
                        break;
                }
                sf::CircleShape penguinShape(fishSize * 2);
                penguinShape.setFillColor(fillColor);
                penguinShape.setPosition(3.5 + j * tileSize, i * tileSize - 4 + tileSize / 2);
                window->draw(penguinShape);

            } else { // Fish
                tileRect.setFillColor(sf::Color::White); // Set the tile color


                window->draw(tileRect);
                // Draw fish as small squares inside the tile
                int fishCount = board->tiles[i][j].fishCount;
                for (int k = 0; k < fishCount; k++) {
                    sf::RectangleShape fishRect(sf::Vector2f(fishSize, fishSize));
                    fishRect.setFillColor(sf::Color::Magenta); // Set fish color
                    fishRect.setPosition(1 + j * tileSize + k * (fishSize) + k * 3, i * tileSize + tileSize / 2);
                    window->draw(fishRect);
                }
            }
        }
    }
    // Draw the grid lines
    for (int i = 0; i <= size; i++) {
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0, i * tileSize)),
                sf::Vertex(sf::Vector2f(size * tileSize, i * tileSize))
        };
        line[0].color = sf::Color::Black;
        line[1].color = sf::Color::Black;
        window->draw(line, 2, sf::Lines); // Provide 2 as the number of vertices

        sf::Vertex line2[] = {
                sf::Vertex(sf::Vector2f(i * tileSize, 0)),
                sf::Vertex(sf::Vector2f(i * tileSize, size * tileSize))
        };

        line2[0].color = sf::Color::Black;
        line2[1].color = sf::Color::Black;
        window->draw(line2, 2, sf::Lines); // Provide 2 as the number of vertices
    }


    window->display(); // Display the rendered frame.
}

void drawAPenguin(int x, int y, GameBoard *gameBoard) {

        gameBoard->tiles[x][y].fishCount = -2; // penguin macros

}

Pair getPressedTile(int clickX, int clickY, GameBoard *gameBoard) {
    const int tileSize = gameBoard->size > 20 ? 20 : 40;
    int xFound = 0, yFound = 0;
    for (int i = 0; i < gameBoard->size; i++) {
        int yModulus = (i + 1) * tileSize;
        int j = 0;
        while (!xFound && j < gameBoard->size) {
            int xModulus = (j + 1) * tileSize;
            if (clickX > xModulus - tileSize && clickX <= xModulus) {
                xFound = j;
                break;
            }
            j++;
        }
        if (clickY > yModulus - tileSize && clickY <= yModulus) {
            yFound = i;
            break;
        }
    }
    struct Pair pair = {yFound, xFound};
    return pair;
}

void initializePlayers(GameBoard *gameBoard, int numPlayers, int numPenguins) {
    gameBoard->players = (Player *) malloc(numPlayers * sizeof(Player));

    for (int i = 0; i < numPlayers; i++) {
        Player *currentPlayer = &gameBoard->players[i];
        currentPlayer->playerID = i + 1;
        currentPlayer->score = 0;
        currentPlayer->numPenguins = NUM_OF_PENGUINS;
        currentPlayer->penguins = (Penguin *) malloc(numPenguins * sizeof(Penguin));
    }
}

void initializePenguins(GameBoard *gameBoard, int numPlayers, int numPenguins) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < numPenguins; j++) {
            Penguin currentPenguin = gameBoard->players[i].penguins[j];
            currentPenguin.x = 255;
            currentPenguin.y = 255;
            currentPenguin.playerID = i + 1;
            currentPenguin.isActive = 0;
        }
    }
}

void play(sf::RenderWindow *window, int numPlayers, int numPenguins, int size) {
    bool gameOver = false;
    bool boardGenerated = false;
    bool penguinsInitialized = false;
    bool penguinsPlaced = false;
    int currentPlacingPlayer = 0;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    if (!buffer.loadFromFile("/Users/igorzab/CLionProjects/epfu/audio/move.wav")) std::cout << "error";
    sound.setBuffer(buffer);

    struct GameBoard gameboard;
    gameboard.size = size;
    gameboard.tiles = (Tile **) malloc(size * sizeof(Tile *));
    for (int i = 0; i < size; i++) {
        gameboard.tiles[i] = (Tile *) malloc(size * sizeof(Tile));
    }
    while (window->isOpen() || !gameOver) {
        if (!boardGenerated) {
            randomizeField(&gameboard);
            boardGenerated = true;
        }
        if (!penguinsInitialized) {
            initializePlayers(&gameboard, numPlayers, numPenguins);
            initializePenguins(&gameboard, numPlayers, numPenguins);
            penguinsInitialized = true;
        }

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sound.play();
                Pair pressedTile = getPressedTile(event.mouseButton.x, event.mouseButton.y, &gameboard);
                if (!penguinsPlaced) {
                    Player currentPlayer = gameboard.players[currentPlacingPlayer];
                    int counter = 0;
                    while (counter < numPenguins) {

                        if ((currentPlayer.penguins[counter].x > size || currentPlayer.penguins[counter].x == 0) && gameboard.tiles[pressedTile.x][pressedTile.y].fishCount != -1 && gameboard.tiles[pressedTile.x][pressedTile.y].fishCount != -2) {
                            currentPlayer.penguins[counter].x = pressedTile.x;
                            currentPlayer.penguins[counter].y = pressedTile.y;
                            gameboard.players[currentPlacingPlayer].score += gameboard.tiles[pressedTile.x][pressedTile.y].fishCount;
                            drawAPenguin(pressedTile.x, pressedTile.y, &gameboard);
                            gameboard.tiles[pressedTile.x][pressedTile.y].owningPlayer = currentPlacingPlayer + 1;
                            if (currentPlacingPlayer == numPlayers - 1 && counter == numPenguins - 1)
                                penguinsPlaced = true;
                            currentPlacingPlayer++;
                            if (currentPlacingPlayer >= numPlayers) currentPlacingPlayer = 0;
                            break;
                        }
                        counter++;
                    }

                }
            }
            window->clear(sf::Color::White);

            drawGameBoard(&gameboard, size, window);
        }

    }
/*
    while (window->isOpen() || !gameOver) {
        Pair pressedTile = {-1, -1};
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                //std::cout << "button pressed, playing sound...\n";
                //sound.play();

                pressedTile = getPressedTile(event.mouseButton.x, event.mouseButton.y, &gameboard);
                placementPhaseStart(&gameboard, numPlayers, numPenguins, pressedTile);
                drawAPenguin(pressedTile.x, pressedTile.y, &gameboard);
            }
            for (int i = 1; i <= NUM_OF_PLAYERS; i++){
                for (int j = 1; j <= NUM_OF_PENGUINS; j++ ){
                    Tile t = gameboard.tiles[i][j];
                    if (t.hasPenguin){
                        std::cout << t.x;
                    }
                }
            }
        }


        window->clear(sf::Color::White);

        drawGameBoard(&gameboard, size, window);

        if (pressedTile.x != -1 && pressedTile.y != -1) {
            placementPhaseStart(&gameboard, numPlayers, numPenguins, pressedTile);
            pressedTile = {-1, -1};
        }
    }
    */
}
