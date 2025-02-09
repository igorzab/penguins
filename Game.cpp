//
// Created by igorz on 11/5/2023.
//
#include "Game.h"
#include "Colors.h"
#include "json.hpp"

float tileSize = 100.0f;

void drawGameBoard(struct GameBoard *board, int size, sf::RenderWindow *window, int numPenguins, int numPlayers) {

    sf::Color colors[] = {
            sf::Color::Red,
            sf::Color::Green,
            sf::Color::Blue,
            sf::Color::Yellow,
            sf::Color::Magenta,
            sf::Color::Cyan,
            sf::Color(255, 165, 0), // Orange
            sf::Color(128, 0, 128), // Purple
            sf::Color::White,
            sf::Color::Black
    };
    sf::Texture Dead_Penguin_Black;
    sf::Texture Dead_Penguin_Blue;
    sf::Texture Dead_Penguin_Cyan;
    sf::Texture Dead_Penguin_Green;
    sf::Texture Dead_Penguin_Magenta;
    sf::Texture Dead_Penguin_Purple;
    sf::Texture Dead_Penguin_White;
    sf::Texture Dead_Penguin_Red;
    sf::Texture Dead_Penguin_Orange;
    sf::Texture Dead_Penguin_Yellow;

    sf::Texture Penguin_Black;
    sf::Texture Penguin_Blue;
    sf::Texture Penguin_Cyan;
    sf::Texture Penguin_Green;
    sf::Texture Penguin_Purple;
    sf::Texture Penguin_Magenta;
    sf::Texture Penguin_White;
    sf::Texture Penguin_Red;
    sf::Texture Penguin_Orange;
    sf::Texture Penguin_Yellow;


    sf::Sprite sprite;
    sf::Texture oneFishtexture;
    sf::Texture twoFishtexture;
    sf::Texture threeFishtexture;
    sf::Texture waterTexture;
    sf::Texture penguinTexture;
    sf::Texture deadPenguinTexture;
    {
        if (!oneFishtexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/pen2_100.png"))
            cout << "error loading tile img\n";
        if (!twoFishtexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/pen1_100.png"))
            cout << "error loading tile img\n";
        if (!threeFishtexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/pen3_100.png"))
            cout << "error loading tile img\n";
        if (!waterTexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/water.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Black.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Black_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Blue.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Blue_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Cyan.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Cyan_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Green.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Green_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Purple.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Purple_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Magenta.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Magenta_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_White.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_White_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Red.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Red_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Orange.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Orange_100.png"))
            cout << "error loading tile img\n";
        if (!Dead_Penguin_Yellow.loadFromFile(
                "/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Dead_Penguin_Yellow_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Black.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Black_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Blue.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Blue_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Cyan.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Cyan_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Green.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Green_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Purple.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Purple_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Magenta.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Magenta_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_White.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_White_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Red.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Red_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Orange.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Orange_100.png"))
            cout << "error loading tile img\n";
        if (!Penguin_Yellow.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/tiles/Penguin_Yellow_100.png"))
            cout << "error loading tile img\n";
    }

    sf::Texture deadPenguins[] = {
            Dead_Penguin_Black,
            Dead_Penguin_Blue,
            Dead_Penguin_Cyan,
            Dead_Penguin_Green,
            Dead_Penguin_Purple,
            Dead_Penguin_Magenta,
            Dead_Penguin_White,
            Dead_Penguin_Red,
            Dead_Penguin_Orange,
            Dead_Penguin_Yellow

    };
    sf::Texture Penguins[] = {
            Penguin_Black,
            Penguin_Blue,
            Penguin_Cyan,
            Penguin_Green,
            Penguin_Purple,
            Penguin_Magenta,
            Penguin_White,
            Penguin_Red,
            Penguin_Orange,
            Penguin_Yellow

    };
    sprite.setTexture(waterTexture);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Tile tile = board->tiles[i][j];
            sprite.setPosition(tile.x * tileSize, tile.y * tileSize);
            sprite.setTexture(waterTexture);
            switch (tile.fishCount) {
                case -2:
                    Penguin penguin;
                    for (int k = 0; k < numPlayers; k++) {
                        bool found = false;
                        for (int l = 0; l < numPenguins; l++) {
//                            printf("trying to check penguin with playerId: %d, penguinId: %d, x: %d, y: %d. and check args are i: %d, j: %d... ",
//                                   k, l, board->players[k].penguins[l].x, board->players[k].penguins[l].y, i, j);
                            if (board->players[k].penguins[l].x == i && board->players[k].penguins[l].y == j) {
//                                printf("found!\n");
                                penguin = board->players[k].penguins[l];
                                found = true;
                                break;
                            }
//                            else { printf("\n"); }
                        }
                        if(found) { break; }
                    }
                    if (canMove(&penguin, board)) {
                        sprite.setTexture(Penguins[tile.owningPlayer - 1]);
                    } else {
                        sprite.setTexture(deadPenguins[tile.owningPlayer - 1]);
                    }
                    break;
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
            sprite.setScale(tileSize / 100, tileSize / 100);
            window->draw(sprite);
        }
    }
}

void drawAPenguin(int x, int y, GameBoard *gameBoard) {
    gameBoard->tiles[x][y].fishCount = -2; // penguin macros
}


Pair getPressedTile(int clickX, int clickY, GameBoard *gameBoard) {
    int xFound = -1, yFound = -1;

    xFound = clickX / tileSize;
    yFound = clickY / tileSize;

    if (xFound >= gameBoard->size || yFound >= gameBoard->size) {
        // error handling when clicked outside GameBoard
        return {-1, -1};
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
            gameBoard->players[i].penguins[j].x = 255;
            gameBoard->players[i].penguins[j].y = 255;
            gameBoard->players[i].penguins[j].playerID = i + 1;
            gameBoard->players[i].penguins[j].isActive = 1;
            printf("initializing penguin with playerIndex: %d, penguinIndex: %d\n", i, j);
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
    if (badTileOnWay(x, y, gameBoard)) {
        selected->isActive = false;
        return false;
    }
    if (penguinX == x) {
        if (abs(y - penguinY) == 1) {
            return true;
        }
    } else if (penguinY == y) {
        if (abs(x - penguinX) == 1) {
            return true;
        }
    }
    selected->isActive = false;
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

void parseGameBoard(GameBoard *gameBoard, nlohmann::json json) {
    gameBoard->size = json.at("size");
    const auto &jsonTiles = json.at("tiles");

    for (int i = 0; i < gameBoard->size; i++)
        for (int j = 0; j < gameBoard->size; j++) {
//            cout << "recieved i: " << i << " j: " << j << " x: " << jsonTiles[i][j].at("x") << " y: " <<  jsonTiles[i][j].at("y")<< " fishCount: " <<  jsonTiles[i][j].at("fishCount")<< endl;
            jsonTiles[j][i].at("fishCount").get_to(gameBoard->tiles[i][j].fishCount);
            jsonTiles[j][i].at("x").get_to(gameBoard->tiles[i][j].x);
            jsonTiles[j][i].at("y").get_to(gameBoard->tiles[i][j].y);
            jsonTiles[j][i].at("owningPlayer").get_to(gameBoard->tiles[i][j].owningPlayer);
        }
    const auto &jsonPlayers = json.at("players");
    for (size_t i = 0; i < jsonPlayers.size(); ++i) {
        const auto &jsonPlayer = jsonPlayers[i];

        jsonPlayer.at("playerID").get_to(gameBoard->players[i].playerID);
        jsonPlayer.at("score").get_to(gameBoard->players[i].score);
        jsonPlayer.at("numPenguins").get_to(gameBoard->players[i].numPenguins);

        const auto &jsonPenguins = jsonPlayer.at("penguins");
        for (size_t j = 0; j < jsonPenguins.size(); ++j) {
            const auto &jsonPenguin = jsonPenguins[j];

            jsonPenguin.at("isActive").get_to(gameBoard->players[i].penguins[j].isActive);
            jsonPenguin.at("playerID").get_to(gameBoard->players[i].penguins[j].playerID);
            jsonPenguin.at("x").get_to(gameBoard->players[i].penguins[j].x);
            jsonPenguin.at("y").get_to(gameBoard->players[i].penguins[j].y);
        }
    }
}

void recieveData(sf::TcpSocket *socket, sf::RenderWindow *window, GameBoard *gameBoard, int *currentPlayer,
                 int *currentPhase) {
    sf::Packet packet;
    while (window->isOpen()) {
        char buffer[100000];
        string recievedData;
        std::size_t received;
//        if (socket->receive(packet) == sf::Socket::Done) {
//            packet >> recievedData;
//            cout << "recieved buffer: "<< endl;
//
//        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
}


void play(sf::RenderWindow *window, int inputPhase, int useFiles, char *inputboardfile, char *outputboardfile){
    srand(time(NULL));
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("/Users/igorzab/CLionProjects/epfu/audio/move.wav")) std::cout << "error";
    // sound.setBuffer(buffer);
    bool gameOver = false;
    bool penguinsPlaced = false;
    if(inputPhase && useFiles){
        printf("penguins placed\n");
        penguinsPlaced = true;
    }
    bool penguinSelected = false;
    Penguin *selectedPenguin;
    int currentPlacingPlayer = 0;
    struct GameBoard gameboard;

    sf::Clock clock;
    sf::Clock introClock;
    sf::Texture penguinBackgroundTexture;
    sf::Vector2u windowSizeVector = window->getSize();

    unsigned int xSize = windowSizeVector.x;
    unsigned int ySize = windowSizeVector.y;

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/4k.jpg")) {
        cout << "error loading image \n";
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2f gameFieldSize(5472, 3648);

    int numPenguins = 3;
    int numPlayers = 2;
    int currentPhase = 0;
    sound.play();
    int positionCounter = 0;
    float animationSpeed = 0.03f;
    float introAnimationSpeed = 0.05f;
    sf::Clock snowClock;
    sf::IntRect snowRect(0, 0, 216, 160);


    sf::View view(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(view);

//    std::thread networkingThread(recieveData, socket, window, &gameboard, &currentPhase, &currentPlacingPlayer);

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
//                socket->disconnect();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (currentPhase <= 2) {
                    modifyValues(&numPenguins, &numPlayers, &currentPhase, event.mouseButton.x, event.mouseButton.y);
                    if (currentPhase == 3) {
//                        cout << "sending numPlayers";
//                        string stringPacket = to_string(numPlayers);
//                        sf::Packet packet;
//                        packet << stringPacket;
//
//                        if (socket->send(packet) == sf::Socket::Done) {
//                            cout << "packet sent" << endl;
//
//                        }

                        initializePlayers(&gameboard, numPlayers, numPenguins);
                        initializePenguins(&gameboard, numPlayers, numPenguins);
                        gameboard.size = (numPenguins * numPlayers + 20) / 1.5;
                        if (gameboard.size < 20) gameboard.size = 20;
                        gameboard.tiles = (Tile **) malloc(gameboard.size * sizeof(Tile *));

                        for (int i = 0; i < gameboard.size; i++) {
                            gameboard.tiles[i] = (Tile *) malloc(gameboard.size * sizeof(Tile));
                        }
                        if (useFiles == 0) {
                            randomizeField(&gameboard);
                        } else {
                            readGameData(&gameboard, &numPlayers, &numPenguins, inputboardfile);
                        }
                    }
                } else {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

                    // Convert screen coordinates to world coordinates (considering the view)
                    sf::Vector2f worldMousePosition = window->mapPixelToCoords(mousePosition, view);
                    Pair pressedTile = getPressedTile(worldMousePosition.x, worldMousePosition.y, &gameboard);
                    if (!penguinsPlaced) {
                        cout << "attempt to place.. pressedX: " << pressedTile.x << " PressedY: " << pressedTile.y << endl;
                        Player currentPlayer = gameboard.players[currentPlacingPlayer];
                        int counter = 0;
                        cout <<"numPenguins: " << numPenguins << endl;
                        while (counter < numPenguins) {
                            cout << "currentPlacing x: " <<  currentPlayer.penguins[counter].x << endl;
                            if ((currentPlayer.penguins[counter].x > gameboard.size * 100 + gameboard.size ||
                                 currentPlayer.penguins[counter].x == 0 ||   currentPlayer.penguins[counter].x == 255) &&
                                !badTileOnWay(pressedTile.x, pressedTile.y, &gameboard) &&
                                gameboard.tiles[pressedTile.x][pressedTile.y].fishCount == 1) {

                                cout << "placing";
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
                                        gameboard.tiles[pressedTile.x][pressedTile.y].owningPlayer = 0;
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

                                    gameboard.tiles[pressedTile.x][pressedTile.y].owningPlayer =
                                            currentPlacingPlayer + 1;
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
                            for (int i = 0; i < numPlayers; i++) {
                                if (gameboard.players[i].score > totalScore) {
                                    totalScore = gameboard.players[i].score;
                                    winnerId = i + 1;
                                }
                            }
                            std::cout << "Winner - player #" << winnerId << " with score = " << totalScore;
                        }

                    }
                }
            }
        }
        // Handle camera movement
        float cameraSpeed = 10.0f; // Adjust as needed
        sf::FloatRect viewBounds(0, 0, gameboard.size * tileSize, gameboard.size *
                                                                  tileSize); // Adjust mapWidth and mapHeight according to your game world
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            view.move(-cameraSpeed, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            view.move(cameraSpeed, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            view.move(0, -cameraSpeed);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            view.move(0, cameraSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            view.zoom(0.9f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
            view.zoom(1.1f);
        }
        sf::Vector2f viewCenter = view.getCenter();
        sf::Vector2f viewSize = view.getSize();

        float halfWidth = viewSize.x / 2.0f;
        float halfHeight = viewSize.y / 2.0f;

        if (viewCenter.x - halfWidth < viewBounds.left) {
            view.setCenter(halfWidth, viewCenter.y);
        }

        if (viewCenter.x + halfWidth > viewBounds.left + viewBounds.width) {
            view.setCenter(viewBounds.left + viewBounds.width - halfWidth, viewCenter.y);
        }

        if (viewCenter.y - halfHeight < viewBounds.top) {
            view.setCenter(viewCenter.x, halfHeight);
        }

        if (viewCenter.y + halfHeight > viewBounds.top + viewBounds.height) {
            view.setCenter(viewCenter.x, viewBounds.top + viewBounds.height - halfHeight);
        }
        window->clear(sf::Color::White);

        window->setView(view);
        if (currentPhase == -2) {
            window->draw(backgroundSprite);
        } else if (currentPhase == -1) {
            drawIntro(window, &introClock, introAnimationSpeed, &positionCounter, &currentPhase);
        } else if (currentPhase == 0) {
            drawFirstPage(window, &snowClock, &snowRect);
        } else if (currentPhase == 1) {
            drawSecondPage(window, &numPenguins, &numPlayers);
        } else if (currentPhase == 2) {
            drawThirdPage(window);
        } else if (currentPhase == 3) {
            if(useFiles == 1){
                writeGameState(&gameboard, numPlayers, outputboardfile);
            }
            drawGameBoard(&gameboard, gameboard.size, window, numPenguins, numPlayers);
        }
        window->display();
    }
//    networkingThread.join();

    // Close the connection
//    socket->disconnect();

}