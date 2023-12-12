//
// Created by igorz on 11/5/2023.
//
#include "Game.h"
#include "Colors.h"
#include <regex>
float tileSize = 100.0f;

void drawGameBoard(struct GameBoard *board, int numPlayers, int numPenguins, int size, sf::RenderWindow *window) {

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
                    for(int k = 0; k < numPlayers; k++){
                        for(int l = 0; l < numPenguins; l++){
                            if(board->players[k].penguins[l].x == i && board->players[k].penguins[l].y == j) penguin = board->players[k].penguins[l];
                        }
                    }
                    if(canMove(&penguin, board)){
                        sprite.setTexture(Penguins[tile.owningPlayer-1]);
                    }else{
                        sprite.setTexture(deadPenguins[tile.owningPlayer-1]);
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
    gameBoard->tiles[x][y].fishCount = PENGUIN_STATE; // penguin macros
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
            Penguin currentPenguin = gameBoard->players[i].penguins[j];
            currentPenguin.x = 255;
            currentPenguin.y = 255;
            currentPenguin.playerID = i + 1;
            currentPenguin.isActive = 1;
        }
    }
}

bool badTileOnWay(int x, int y, GameBoard *gameBoard) {
    if (x < 0 || y < 0) return true;
    if (gameBoard->tiles[x][y].fishCount == WATER) return true;
    if (gameBoard->tiles[x][y].fishCount == PENGUIN_STATE) return true;
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
int counter = 0;
void sendData(GameBoard *gameBoard, int numPlayers, int numPenguins, sf::TcpSocket *socket, int currentPlayer, int currentPhase) {

    nlohmann::json jsonGameBoard;
    jsonGameBoard["currentPlayer"] = currentPlayer;
    jsonGameBoard["currentPhase"] = currentPhase;
    sf::Packet packet;
    for (int i = 0; i < gameBoard->size; i++) {
        nlohmann::json jsonRow;
        for (int j = 0; j < gameBoard->size; j++) {
            cout << "sending: "<< "i: " << i << " j: " << j << " x: " << gameBoard->tiles[j][i].x<< " y: " << gameBoard->tiles[j][i].y << endl;
            nlohmann::json jsonTile;
            jsonTile["fishCount"] = gameBoard->tiles[j][i].fishCount;
            jsonTile["x"] = gameBoard->tiles[j][i].x;
            jsonTile["y"] = gameBoard->tiles[j][i].y;
            jsonTile["owningPlayer"] = gameBoard->tiles[j][i].owningPlayer;
            jsonRow.push_back(jsonTile);
        }
        jsonGameBoard["tiles"].push_back(jsonRow);
        jsonRow = "";
    }

    // Convert the json object to a string
    std::string jsonString = jsonGameBoard.dump();

    // Print the JSON string
    std::cout << jsonString << std::endl;
    std::cout << std::endl;
    packet << jsonString;
    if (socket->send(packet) != sf::Socket::Done) {
        std::cerr << "Error sending game board data to the server" << std::endl;
    } else {

        std::cout << "sent successfully: " << counter << endl;
        counter++;
    }
    jsonString = "";
    jsonGameBoard = "";
}

std::string extractJsonFragment(const std::string& input) {
    // Define the regular expression pattern to match the desired structure
    std::regex pattern(R"("currentPhase":[^}]+)");

    // Search for the last occurrence of the pattern
    std::sregex_iterator iter(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    // Find the last match
    std::smatch lastMatch;
    while (iter != end) {
        lastMatch = *iter;
        ++iter;
    }

    // If a match is found, extract the substring before and including the last match
    if (!lastMatch.empty()) {
        return lastMatch.prefix().str() + lastMatch[0].str() + '}';
    } else {
        // Return the original string if the pattern is not found
        return input;
    }
}

void updateGameboard(GameBoard *gameBoard, nlohmann::json json){
    const auto& jsonTiles = json.at("tiles");
    for(int i = 0; i < gameBoard->size; i++){
        for (int j = 0; j < gameBoard->size; j++) {
            cout << "recieved i: " << i << " j: " << j << " x: " << jsonTiles[i][j].at("x") << " y: " <<  jsonTiles[i][j].at("y")<< endl;
            jsonTiles[j][i].at("fishCount").get_to(gameBoard->tiles[i][j].fishCount);
            jsonTiles[j][i].at("x").get_to(gameBoard->tiles[i][j].x);
            jsonTiles[j][i].at("y").get_to(gameBoard->tiles[i][j].y);
            jsonTiles[j][i].at("owningPlayer").get_to(gameBoard->tiles[i][j].owningPlayer);
        }
    }
}

string recievedData = "";
void recieveData(sf::TcpSocket *socket, sf::RenderWindow *window, GameBoard *gameBoard, int *currentPlayer, int *currentPhase){
    while (window->isOpen()){
        char buffer[100000];
        std::size_t received;
        if (socket->receive(buffer, sizeof(buffer), received) == sf::Socket::Done) {
            recievedData = recievedData + buffer;
            cout << "recieved buffer: " << buffer << endl;
            recievedData = extractJsonFragment(recievedData);
            cout << "generated String: " << recievedData << endl;
            if(nlohmann::json::accept(recievedData)){
                cout << "recieved correct string!" << endl;
                nlohmann::json json = nlohmann::json::parse(recievedData);
//                std::cout << "Received data from server:\n" <<json.dump(4) << std::endl;
                recievedData = "";
                cout << "currentPlayer: " << json.at("currentPlayer") << endl;
                cout << "currentPlayer: " << json.at("currentPhase") << endl;
//                *currentPhase = json.at("currentPhase");
//                *currentPlayer = json.at("currentPlayer");
                updateGameboard(gameBoard, json);
                recievedData = "";
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
}

void play(sf::RenderWindow *window, sf::TcpSocket *socket, sf::TcpListener *listener) {
    srand(time(NULL));
    sf::SoundBuffer buffer;
    sf::Sound intro;

    sf::Music background;
    if (!background.openFromFile("/Users/igorzab/CLionProjects/epfu/audio/background.wav")) {
        std::cerr << "Error loading audio file" << std::endl;
    }
    background.setLoop(true);

    if (!buffer.loadFromFile("/Users/igorzab/CLionProjects/epfu/audio/intro.wav")) std::cout << "error";
    intro.setBuffer(buffer);
    bool gameOver = false;
    bool isServer = false;
    bool isClient = false;
    bool penguinsPlaced = false;
    bool penguinSelected = false;
    Penguin *selectedPenguin;
    int currentPlacingPlayer = 0;
    int myId = 0;
    struct GameBoard gameboard;

    sf::Clock clock;
    sf::Clock introClock;
    sf::Texture penguinBackgroundTexture;
    sf::Vector2u windowSizeVector = window->getSize();

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/4k.jpg")) {
        cout << "error loading image \n";
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    int numPenguins = 1;
    int numPlayers = 2;
    int currentPhase = 0;
//    intro.play();

//    background.play();
    int positionCounter = 0;
    float animationSpeed = 0.03f;
    float introAnimationSpeed = 0.05f;
    sf::Clock snowClock;
    sf::IntRect snowRect(0, 0, 216, 160);


    sf::View view(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(view);
    std::thread networkingThread(recieveData, socket, window, &gameboard, &currentPhase, &currentPlacingPlayer);
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (currentPhase <= SETTINGS) {
                    modifyValues(&numPenguins, &numPlayers, &currentPhase, event.mouseButton.x, event.mouseButton.y,
                                 &isServer, &isClient);
                    if (currentPhase == GAME) {
                        gamePhase(&gameboard, numPlayers, numPenguins, socket, currentPlacingPlayer, currentPhase);
                    }
                } else {

                    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

                    // Convert screen coordinates to world coordinates (considering the view)
                    sf::Vector2f worldMousePosition = window->mapPixelToCoords(mousePosition, view);
                    Pair pressedTile = getPressedTile(worldMousePosition.x, worldMousePosition.y, &gameboard);
                    if (!penguinsPlaced) {
//                        if(currentPlacingPlayer == myId){
                            placementPhase(pressedTile, &gameboard, &currentPlacingPlayer, numPenguins, numPlayers, &penguinsPlaced);
                            sendData(&gameboard, numPlayers, numPlayers, socket, currentPlacingPlayer, currentPhase);
//                        }

                    } else if (!gameOver ) {
                        Player currentPlayer = gameboard.players[currentPlacingPlayer];
                        if (movesExist(&currentPlayer, &gameboard, numPenguins)) {

                            if (!penguinSelected) {
                                for (int i = 0; i < numPenguins; i++) {
                                    if (currentPlayer.penguins[i].x == pressedTile.x &&
                                        currentPlayer.penguins[i].y == pressedTile.y &&
                                        canMove(&currentPlayer.penguins[i], &gameboard)) {
                                        selectedPenguin = &currentPlayer.penguins[i];
                                        gameboard.tiles[pressedTile.x][pressedTile.y].fishCount = SELECTED_PENGUIN;
                                        penguinSelected = true;
                                        break;
                                    }
                                }
                            } else {
                                if (checkLegalMove(pressedTile.x, pressedTile.y, selectedPenguin, &gameboard)) {

                                    gameboard.tiles[selectedPenguin->x][selectedPenguin->y].fishCount = WATER;

                                    selectedPenguin->x = pressedTile.x;
                                    selectedPenguin->y = pressedTile.y;

                                    gameboard.players[currentPlacingPlayer].score += gameboard.tiles[pressedTile.x][pressedTile.y].fishCount;
                                    drawAPenguin(pressedTile.x, pressedTile.y, &gameboard);

                                    gameboard.tiles[pressedTile.x][pressedTile.y].owningPlayer =
                                            currentPlacingPlayer + 1;
                                    currentPlacingPlayer++;

                                    if (currentPlacingPlayer >= numPlayers) currentPlacingPlayer = 0;
                                    std::cout << "Player #" << currentPlacingPlayer + 1 << ", plz select a penguin.\n";
                                    sendData(&gameboard, numPlayers, numPlayers, socket, currentPlacingPlayer, currentPhase);

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//            sendData(&gameboard, numPlayers, numPenguins);
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
        } else if (currentPhase == INTRO_PHASE) {
            drawIntro(window, &introClock, introAnimationSpeed, &positionCounter, &currentPhase);
        } else if (currentPhase == HOME_SCREEN) {
            drawFirstPage(window, &snowClock, &snowRect);
        } else if (currentPhase == MODE_SELECT) {
            drawSecondPage(window);
        } else if (currentPhase == SETTINGS) {
            drawThirdPage(window, &numPenguins, &numPlayers);
        } else if (currentPhase == GAME) {
            drawGameBoard(&gameboard, numPlayers, numPenguins, gameboard.size, window);
        }
//        char buffer[4096];
//        std::size_t received = 0;
//        if (socket->receive(buffer, sizeof(buffer), received) == sf::Socket::Done) {
//
//            std::cout << "Received data from server:\n" <<buffer << std::endl;
//        }

        window->display();
    }
    // Stop the networking thread
    networkingThread.join();

    // Close the connection
    socket->disconnect();
}

void placementPhase(Pair pressedTile, GameBoard *gameboard, int *currentPlacingPlayer, int numPenguins, int numPlayers, bool *penguinsPlaced){
    Player currentPlayer = gameboard->players[*currentPlacingPlayer];
    int counter = 0;
    while (counter < numPenguins) {
        if ((currentPlayer.penguins[counter].x > gameboard->size * 100 + gameboard->size ||
             currentPlayer.penguins[counter].x == 0) &&
            !badTileOnWay(pressedTile.x, pressedTile.y, gameboard) &&
            gameboard->tiles[pressedTile.x][pressedTile.y].fishCount == ONE_FISH) {

            currentPlayer.penguins[counter].x = pressedTile.x;
            currentPlayer.penguins[counter].y = pressedTile.y;
            gameboard->players[*currentPlacingPlayer].score += gameboard->tiles[pressedTile.x][pressedTile.y].fishCount;
            drawAPenguin(pressedTile.x, pressedTile.y, gameboard);
            gameboard->tiles[pressedTile.x][pressedTile.y].owningPlayer = *currentPlacingPlayer + 1;
            if (*currentPlacingPlayer == numPlayers - 1 && counter == numPenguins - 1) {
                *penguinsPlaced = true;
                *currentPlacingPlayer = 0;
            } else {
                *currentPlacingPlayer = *currentPlacingPlayer + 1;
            }
            if (*currentPlacingPlayer >= numPlayers) *currentPlacingPlayer = 0;
            break;
        }
        counter++;
    }
}

void gamePhase(GameBoard *gameboard, int numPlayers, int numPenguins, sf::TcpSocket *socket, int currentPlayer, int currentPhase){
    initializePlayers(gameboard, numPlayers, numPenguins);
    initializePenguins(gameboard, numPlayers, numPenguins);
    gameboard->size = (numPenguins * numPlayers + 20) / 1.5;
    if (gameboard->size < 20) gameboard->size = 20;
    gameboard->tiles = (Tile **) malloc(gameboard->size * sizeof(Tile *));

    for (int i = 0; i < gameboard->size; i++) {
        gameboard->tiles[i] = (Tile *) malloc(gameboard->size * sizeof(Tile));
    }
    randomizeField(gameboard);
    sendData(gameboard, numPlayers, numPenguins, socket, currentPlayer, currentPhase);
}