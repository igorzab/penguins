//
// Created by igorz on 11/5/2023.
//

#include "Game.h"

Game::Game(sf::RenderWindow *window, int numPlayers, int boardSize) {
    this->numPlayers = numPlayers;
    this->size = boardSize;
    this->gameBoard = new GameBoard(size);
    this->gameOver = false;
    this->currentPhase = 0; // 0 -> Placing penguins; 1 -> playing; 2 -> gameOver;
    this->window = window;
}

void Game::play() {
    while (window->isOpen() || !gameOver) {

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear(sf::Color::White);

            drawGameBoard();
            makeMove();

    }

}

void Game::drawGameBoard() {
    const std::vector<std::vector<Tile>> &tiles = gameBoard->getBoard();
    const int tileSize = size > 20 ? 20 : 40; // Adjust this value to set the size of each tile.

    const int fishSize = tileSize / 6; // adjust this value to change a fishTile size;
    window->clear(); // Clear the window before drawing.

    // Iterate through tiles and draw them
    for (int i = 0; i < tiles.size(); i++) {
        for (int j = 0; j < tiles[i].size(); j++) {
            sf::RectangleShape tileRect(sf::Vector2f(tileSize, tileSize));
            tileRect.setPosition(j * tileSize, i * tileSize);

            if (tiles[i][j].getFishCount() == -1) { // Water
                tileRect.setFillColor(sf::Color::Blue);


                window->draw(tileRect);
            } else { // Fish
                tileRect.setFillColor(sf::Color::White); // Set the tile color


                window->draw(tileRect);
                // Draw fish as small squares inside the tile
                int fishCount = tiles[i][j].getFishCount();
                for (int k = 0; k < fishCount; k++) {
                    sf::RectangleShape fishRect(sf::Vector2f(fishSize, fishSize));
                    fishRect.setFillColor(sf::Color::Magenta); // Set fish color
                    fishRect.setPosition(1 + j * tileSize + k * (fishSize) + k*3, i * tileSize + tileSize/2);
                    window->draw(fishRect);
                }
            }
        }
    }
    // Draw the grid lines
    for (int i = 0; i <= tiles.size(); i++) {
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0, i * tileSize)),
                sf::Vertex(sf::Vector2f(tiles.size() * tileSize, i * tileSize))
        };
        line[0].color = sf::Color::Black;
        line[1].color = sf::Color::Black;
        window->draw(line, 2, sf::Lines); // Provide 2 as the number of vertices

        sf::Vertex line2[] = {
                sf::Vertex(sf::Vector2f(i * tileSize, 0)),
                sf::Vertex(sf::Vector2f(i * tileSize, tiles.size() * tileSize))
        };

        line2[0].color = sf::Color::Black;
        line2[1].color = sf::Color::Black;
        window->draw(line2, 2, sf::Lines); // Provide 2 as the number of vertices
    }


    window->display(); // Display the rendered frame.
}

void Game::makeMove() {
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
//            cout << gameBoard->getBoard()[i][j].getFishCount()+1 << "  ";
        }
//        cout << endl;
    }
//    gameOver = 1;
}