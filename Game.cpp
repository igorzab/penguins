//
// Created by igorz on 11/5/2023.
//

#include "Game.h"
#include <chrono>
#include <thread>
#include "Game.h"

void drawGameBoard(struct GameBoard *board, int size, sf::RenderWindow *window) {
    const int tileSize = size > 20 ? 20 : 40; // Adjust this value to set the size of each tile.

    const int fishSize = tileSize / 6; // adjust this value to change a fishTile size;
    window->clear(); // Clear the window before drawing.

    // Iterate through tiles and draw them
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sf::RectangleShape tileRect(sf::Vector2f(tileSize, tileSize));
            tileRect.setPosition(j * tileSize, i * tileSize);

            if (board->tiles[i][j].fishCount == -1) { // Water
                tileRect.setFillColor(sf::Color::Blue);


                window->draw(tileRect);
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

void makeMove(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
        }
    }
}



Pair getPressedTile(int clickX, int clickY, GameBoard *gameBoard){
    const int tileSize = gameBoard->size > 20 ? 20 : 40;
    int xFound = 0, yFound = 0;
    for (int i = 0; i < gameBoard->size; i++) {
        int yModulus = (i+1) * tileSize;
        int j = 0;
        while(!xFound && j < gameBoard->size){
            int xModulus = (j+1) * tileSize;
            if(clickX > xModulus - tileSize && clickX <= xModulus) {
                xFound = j;
                break;
            }
            j++;
        }
        if(clickY > yModulus - tileSize && clickY <= yModulus) {
            yFound = i;
            break;
        }
    }
    struct Pair pair = {xFound, yFound};
    return pair;
}

void play(sf::RenderWindow *window, bool gameOver, int size) {
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
    randomizeField(&gameboard);
    while (window->isOpen() || !gameOver) {

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonPressed){
                sound.play();
                getPressedTile(event.mouseButton.x, event.mouseButton.y, &gameboard); // returns pair structure. do whatever you want.
            }
        }
        window->clear(sf::Color::White);

        drawGameBoard(&gameboard, size, window);
        makeMove(size);
    }

}
