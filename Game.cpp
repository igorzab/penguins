//
// Created by igorz on 11/5/2023.
//
#include "Game.h"
#include "Colors.h"

void drawGameBoard(struct GameBoard *board, int size, sf::RenderWindow *window) {
    sf::Sprite sprite;
    sf::Texture oneFishtexture;
    sf::Texture twoFishtexture;
    sf::Texture threeFishtexture;
    sf::Texture waterTexture;
    if (!oneFishtexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/1fish.png"))
        cout << "error loading tile img\n";
    if (!twoFishtexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/2fish.png"))
        cout << "error loading tile img\n";
    if (!threeFishtexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/3fish.png"))
        cout << "error loading tile img\n";
    if (!waterTexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/water.png"))
        cout << "error loading tile img\n";
    sprite.setTexture(waterTexture);

    const int tileSize = 100;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Tile tile = board->tiles[i][j];
            sprite.setPosition(tile.x * tileSize, tile.y * tileSize);
            sprite.setTexture(waterTexture);
            switch (tile.fishCount) {
                case 1:
                    sprite.setTexture(oneFishtexture);
                    break;
                case 2:
                    sprite.setTexture(twoFishtexture);
                    break;
                case 3:
                    sprite.setTexture(threeFishtexture);
                    break;
            }
            window->draw(sprite);
        }
    }
}

/*
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

                drawPenguinTile(board, size, sf::Color::White, tileRect, window, i, j, fishSize, tileSize);

            } else if (board->tiles[i][j].fishCount == -3) { //selectedPenguin
                drawPenguinTile(board, size, sf::Color::Cyan, tileRect, window, i, j, fishSize, tileSize);

            } else { // Fish
                tileRect.setFillColor(sf::Color::White);


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
        window->draw(line, 2, sf::Lines);

        sf::Vertex line2[] = {
                sf::Vertex(sf::Vector2f(i * tileSize, 0)),
                sf::Vertex(sf::Vector2f(i * tileSize, size * tileSize))
        };

        line2[0].color = sf::Color::Black;
        line2[1].color = sf::Color::Black;
        window->draw(line2, 2, sf::Lines);
    }


    window->display();
}
*/
void drawAPenguin(int x, int y, GameBoard *gameBoard) {
    gameBoard->tiles[x][y].fishCount = -2; // penguin macros
}

void drawPenguinTile(struct GameBoard *board, int size, sf::Color tileBackgroundColor, sf::RectangleShape tileRect,
                     sf::RenderWindow *window, int i, int j, int fishSize, int tileSize) {

    tileRect.setFillColor(tileBackgroundColor);
    window->draw(tileRect);
    sf::Color fillColor = sf::Color::White;
    switch (board->tiles[i][j].owningPlayer) {
        case 1:
            fillColor = sf::Color::Red;
            break;
        case 2:
            fillColor = Orange;
            break;
        case 3:
            fillColor = LightGreen;
            break;
        case 4:
            fillColor = DarkGreen;
            break;
        case 5:
            fillColor = Gray;
            break;
        case 6:
            fillColor = Pink;
            break;
        case 7:
            fillColor = Brown;
            break;
        case 8:
            fillColor = Purple;
            break;
        case 9:
            fillColor = Sapphire;
            break;
    }
    sf::CircleShape penguinShape(fishSize * 2);
    penguinShape.setFillColor(fillColor);
    penguinShape.setPosition(3.5 + j * tileSize, i * tileSize - 4 + tileSize / 2);
    window->draw(penguinShape);

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
        currentPlayer->numPenguins = numPenguins;
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

bool badTileOnWay(int x, int y, GameBoard *gameBoard) {
    if (x < 0 || y < 0) return true;
    if (gameBoard->tiles[x][y].fishCount == -1) return true;
    if (gameBoard->tiles[x][y].fishCount == -2) return true;
    return false;
}

bool checkLegalMove(int x, int y, Penguin *selected, GameBoard *gameBoard) {
    int penguinX = selected->x;
    int penguinY = selected->y;
    if (badTileOnWay(x, y, gameBoard)) return false;
    if (penguinX == x) {
        if (abs(y - penguinY) == 1) {
            return true;
        }
    } else if (penguinY == y) {
        if (abs(x - penguinX) == 1) {
            return true;
        }
    }
    return false;
}

bool canMove(Penguin *penguin, GameBoard *gameBoard) {
    if (penguin->x != gameBoard->size - 1 && !badTileOnWay(penguin->x + 1, penguin->y, gameBoard)) return true;
    if (penguin->x != 0 && !badTileOnWay(penguin->x - 1, penguin->y, gameBoard)) return true;
    if (penguin->y != gameBoard->size - 1 && !badTileOnWay(penguin->x, penguin->y + 1, gameBoard)) return true;
    if (penguin->y != 0 && !badTileOnWay(penguin->x, penguin->y - 1, gameBoard)) return true;
    return false;
}

bool movesExist(Player *player, GameBoard *gameBoard, int numPenguins) {
    for (int i = 0; i < numPenguins; i++) {
        if (canMove(&player->penguins[i], gameBoard)) {
            return true;
        }
    }
    return false;
}

bool totalMovesExist(GameBoard *gameBoard, int numPlayers, int numPenguins) {
    for (int i = 0; i < numPlayers; i++) {
        if (movesExist(&gameBoard->players[i], gameBoard, numPenguins)) return true;
    }
    return false;
}


void playAnimation(sf::Sprite *animatedSprite, sf::IntRect *rectSource, float animationSpeed, sf::Clock *clock) {

    if (clock->getElapsedTime().asSeconds() > animationSpeed) {
        if (rectSource->left + rectSource->width >= 7080) {
            rectSource->left = 0;
        } else {
            rectSource->left = rectSource->left + rectSource->width;
        }
        animatedSprite->setTextureRect(*rectSource);
        clock->restart();
    }
}

void play(sf::RenderWindow *window) {

    struct GameBoard gameboard;
    gameboard.size = 20;
    gameboard.tiles = (Tile **) malloc(20 * sizeof(Tile *));

    for (int i = 0; i < 20; i++) {
        gameboard.tiles[i] = (Tile *) malloc(20 * sizeof(Tile));
    }
    randomizeField(&gameboard);
    initializePlayers(&gameboard, 2, 3);
    initializePenguins(&gameboard, 2, 3);

    sf::Clock clock;
    sf::Clock introClock;
    sf::Texture penguinBackgroundTexture;
    sf::Vector2u windowSizeVector = window->getSize();
    sf::IntRect rectPengBackground(0, 0, 120, 180);
    sf::Sprite backgroundPenguin(penguinBackgroundTexture, rectPengBackground);
    backgroundPenguin.setScale(2.0f, 2.0f);
    backgroundPenguin.setPosition(0, 0);

    unsigned int xSize = windowSizeVector.x;
    unsigned int ySize = windowSizeVector.y;

    if (!penguinBackgroundTexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/backgroundPenguin.png"))
        cout << "ERROR loading penguinBackgroundTexture image.\n";

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/4k.jpg")) {
        cout << "error loading image \n";
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2f gameFieldSize(5472, 3648);

    int numPenguins = 0;
    int numPlayers = 0;
    int currentFaze = 2;
    int positionCounter = 0;
    float animationSpeed = 0.03f;
    float introAnimationSpeed = 0.05f;

    sf::View view(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(view);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                modifyValues(&numPenguins, &numPlayers, &currentFaze, event.mouseButton.x, event.mouseButton.y);
//                if (currentFaze == 0) {
//                    bool check = checkIntersection(event.mouseButton.x, event.mouseButton.y);
//                    if (check) {
//                        currentFaze++;
//                    }
//                }else if(currentFaze == 1){
//                    cout << "Was at main currentfaze = 1\n";
//                    modifyValues(&numPenguins, &numPlayers, &currentFaze, event.mouseButton.x, event.mouseButton.y);
//                    cout << "faze: " << currentFaze << endl;
//                }
            }
        }
        // Handle camera movement
        float cameraSpeed = 3.0f; // Adjust as needed

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            view.move(-cameraSpeed, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            view.move(cameraSpeed, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            view.move(0, -cameraSpeed);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            view.move(0, cameraSpeed);
        }


//        playAnimation(&backgroundPenguin, &rectPengBackground, animationSpeed, &clock);
        window->clear(sf::Color::White);

        window->setView(view);
        if (currentFaze == -2) {
            window->draw(backgroundSprite);
        } else if (currentFaze == -1) {
            drawIntro(window, &introClock, introAnimationSpeed, &positionCounter, &currentFaze);
        } else if (currentFaze == 0) {
            drawFirstPage(window);
        } else if (currentFaze == 1) {

            drawSecondPage(window, &numPenguins, &numPlayers);
        } else if (currentFaze == 2) {

            drawGameBoard(&gameboard, 20, window);
        }
//        window->draw(backgroundPenguin);
        window->display();
    }
}


/*
void play(sf::RenderWindow *window, int numPlayers, int numPenguins, int size) {

    bool gameOver = false;
    bool penguinsPlaced = false;
    bool penguinSelected = false;
    Penguin *selectedPenguin;
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
    randomizeField(&gameboard);
    initializePlayers(&gameboard, numPlayers, numPenguins);
    initializePenguins(&gameboard, numPlayers, numPenguins);
    while (window->isOpen() || !gameOver) {

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
                        if ((currentPlayer.penguins[counter].x > size || currentPlayer.penguins[counter].x == 0) && !badTileOnWay(pressedTile.x, pressedTile.y, &gameboard) && gameboard.tiles[pressedTile.x][pressedTile.y].fishCount == 1) {
                            currentPlayer.penguins[counter].x = pressedTile.x;
                            currentPlayer.penguins[counter].y = pressedTile.y;
                            gameboard.players[currentPlacingPlayer].score += gameboard.tiles[pressedTile.x][pressedTile.y].fishCount;
                            drawAPenguin(pressedTile.x, pressedTile.y, &gameboard);
                            gameboard.tiles[pressedTile.x][pressedTile.y].owningPlayer = currentPlacingPlayer + 1;
                            if (currentPlacingPlayer == numPlayers - 1 && counter == numPenguins - 1) {
                                penguinsPlaced = true;
                                currentPlacingPlayer = 0;
                            } else {
                                std::cout << "Player #" << currentPlacingPlayer + 1 << ", plz place ur penguin.\n";
                                currentPlacingPlayer++;
                            }
                            if (currentPlacingPlayer >= numPlayers) currentPlacingPlayer = 0;
                            break;
                        }
                        counter++;
                    }

                } else if (!gameOver) {
                    Player currentPlayer = gameboard.players[currentPlacingPlayer];
                    if (movesExist(&currentPlayer, &gameboard, numPenguins)) {

                        if (!penguinSelected) {
                            for (int i = 0; i < numPenguins; i++) {
                                if (currentPlayer.penguins[i].x == pressedTile.x &&
                                    currentPlayer.penguins[i].y == pressedTile.y &&
                                    canMove(&currentPlayer.penguins[i], &gameboard)) {
                                    selectedPenguin = &currentPlayer.penguins[i];
                                    gameboard.tiles[pressedTile.x][pressedTile.y].fishCount = -3;
                                    penguinSelected = true;
                                    break;
                                }
                            }
                        } else {
                            if (checkLegalMove(pressedTile.x, pressedTile.y, selectedPenguin, &gameboard)) {

                                gameboard.tiles[selectedPenguin->x][selectedPenguin->y].fishCount = -1;

                                selectedPenguin->x = pressedTile.x;
                                selectedPenguin->y = pressedTile.y;

                                gameboard.players[currentPlacingPlayer].score += gameboard.tiles[pressedTile.x][pressedTile.y].fishCount;
                                drawAPenguin(pressedTile.x, pressedTile.y, &gameboard);

                                gameboard.tiles[pressedTile.x][pressedTile.y].owningPlayer = currentPlacingPlayer + 1;
                                currentPlacingPlayer++;
                                if (currentPlacingPlayer >= numPlayers) currentPlacingPlayer = 0;
                                std::cout << "Player #" << currentPlacingPlayer + 1 << ", plz select a penguin.\n";

                                penguinSelected = false;
                            }
                        }
                    } else {
                        currentPlacingPlayer++;
                        if (currentPlacingPlayer >= numPlayers) currentPlacingPlayer = 0;
                    }
                    if (!totalMovesExist(&gameboard, numPlayers, numPenguins)) {
                        gameOver = true;
                        int totalScore = 0;
                        int winnerId;
                        for(int i = 0; i < numPlayers; i++){
                            if(gameboard.players[i].score > totalScore) {
                                totalScore = gameboard.players[i].score;
                                winnerId = i+1;
                            }
                        }
                        std::cout << "Winner - player #" << winnerId << " with score = " << totalScore;
                    }
                }
            }
            window->clear(sf::Color::White);

            drawGameBoard(&gameboard, size, window);
        }
    }
}
*/