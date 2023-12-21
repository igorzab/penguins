//
// Created by igor zab on 27/11/2023.
//
#include "Menu.h"

sf::Sprite startButtonSprite;

sf::Sprite snow;

sf::Sprite plusButtonPenguin;

sf::Sprite minusButtonPenguin;

sf::Sprite textFieldClient;

sf::Sprite textFieldServer;

sf::Sprite plusButtonPlayer;

sf::Sprite minusButtonPlayer;

sf::Sprite menu2NextButton;

sf::Sprite introLogo;


void animateLogo(sf::Sprite *animatedSprite ,int *positionCounter, float animationSpeed, sf::Clock *clock, int yCoordinate, int *currentFaze, int xSize){

    if (clock->getElapsedTime().asSeconds() > animationSpeed) {
        animatedSprite->setPosition(*positionCounter * 5, yCoordinate);
        *positionCounter = *positionCounter + 5;
        if(*positionCounter >= xSize/5) *currentFaze = *currentFaze + 1;
        clock->restart();
    }
}

void drawIntro(sf::RenderWindow *window, sf::Clock *clock, float animationSpeed, int *positionCounter, int *currentFaze) {
    sf::Vector2u windowSizeVector = window->getSize();
    sf::Texture introLogoTexture;
    if (!introLogoTexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/logo.png"))
        cout << "ERROR loading introLogo image.\n";
    window->clear(sf::Color::Black);
    introLogo.setTexture(introLogoTexture);
    animateLogo(&introLogo, positionCounter, animationSpeed, clock, windowSizeVector.y/2, currentFaze, windowSizeVector.x);
    window->draw(introLogo);
}

void drawBackground(sf::RenderWindow *window) {
    sf::Vector2u windowSizeVector = window->getSize();
    sf::Texture background;
    if (!background.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/background1.jpg",
                                 sf::IntRect(0, 0, windowSizeVector.x, windowSizeVector.y)))
        cout << "ERROR loading bg image.\n";
    sf::Sprite bgsprite;

    bgsprite.setTexture(background);
    bgsprite.setScale(static_cast<float>(windowSizeVector.x) / background.getSize().x,
                      static_cast<float>(windowSizeVector.y) / background.getSize().y);
    window->draw(bgsprite);
}

void generateRandomPair(Pair *pair, int rangeX, int rangeY){
    pair->x = rand()%rangeX;
    pair->y = rand()%rangeY;
}

void drawFirstPage(sf::RenderWindow *window, sf::Clock *snowClock, sf::IntRect *snowRect) {
    sf::Vector2u windowSizeVector = window->getSize();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    unsigned int xSize = windowSizeVector.x;
    unsigned int ySize = windowSizeVector.y;

    sf::Texture snowTexture;
    sf::Texture startButton;
    sf::Texture title;
    sf::Texture startButtonWhite;
    sf::Font font;

    if (!startButton.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/startButton.png"))
        cout << "ERROR loading button image.\n";
    if (!snowTexture.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/snow.png"))
        cout << "ERROR loading snow image.\n";
    if (!title.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/title.png"))
        cout << "ERROR loading title image.\n";
    if (!startButtonWhite.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/startButtonWhite.png"))
        cout << "ERROR loading startButtonWhite image.\n";
    if (!font.loadFromFile("/Users/igorzab/CLionProjects/epfu/fonts/arial.ttf")) cout << "Error loading font\n";
    drawBackground(window);

    snow.setTexture(snowTexture);
    sf::Sprite titleSprite;
    float snowAnimationSpeed = 0.1f;
    snow.setScale(window->getSize().x / static_cast<float>(snowRect->width),
                    window->getSize().y / static_cast<float>(snowRect->height));
    titleSprite.setTexture(title);
    titleSprite.setPosition((xSize - titleSprite.getGlobalBounds().width) / 2, 250);
    if(snowClock->getElapsedTime().asSeconds() >= snowAnimationSpeed){
        struct Pair snow[100];

        for(int i = 0; i < 100; i++){
            generateRandomPair(&snow[i], window->getSize().x, window->getSize().y);
        }
        for(int i = 0; i < 100; i++){
            sf::RectangleShape square;
            square.setSize(sf::Vector2f(4, 4));
            square.setPosition(snow[i].x, snow[i].y);
            square.setRotation(rand() % 90);
            square.setFillColor(sf::Color::White);
            window->draw(square);
        }
        snowClock->restart();
    }


    startButtonSprite.setTexture(startButtonWhite);
    startButtonSprite.setScale(0.6f,0.6f);
    sf::FloatRect spriteBounds = startButtonSprite.getGlobalBounds();
    startButtonSprite.setPosition((xSize - spriteBounds.width) / 2, (ySize) / 2);
    if (startButtonSprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                     static_cast<float>(mousePosition.y))) {
        startButtonSprite.setTexture(startButton);
    }

    window->draw(startButtonSprite);
    window->draw(titleSprite);


}

void drawSecondPage(sf::RenderWindow *window, int *numPenguins, int *numPlayers) {
    sf::Vector2u windowSizeVector = window->getSize();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    unsigned int xSize = windowSizeVector.x;
    unsigned int ySize = windowSizeVector.y;
    sf::Texture inputField;
    sf::Texture inputFieldSmall;
    sf::Texture plusButton;
    sf::Texture minusButton;
    sf::Texture nextButtonTxtr;
    if (!inputField.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/inputField.png"))
        cout << "ERROR loading inputField image.\n";
    if (!inputFieldSmall.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/inputFieldSmall.png"))
        cout << "ERROR loading inputField image.\n";
    if (!plusButton.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/plusButton.png"))
        cout << "ERROR loading plusButton image.\n";
    if (!minusButton.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/minusButton.png"))
        cout << "ERROR loading minusButton image.\n";
    if (!nextButtonTxtr.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/nextButton.png"))
        cout << "ERROR loading minusButton image.\n";
    sf::Font font;
    if (!font.loadFromFile("/Users/igorzab/CLionProjects/epfu/fonts/arial.ttf")) cout << "ERROR loading font.\n";
    drawBackground(window);

    sf::Sprite textPenguinField;
    textPenguinField.setTexture(inputField);
    textPenguinField.setPosition((xSize - textPenguinField.getGlobalBounds().width) / 2 - 120, ySize / 2 - 200);
    sf::Text textPenguin("Number of Penguins", font, 30);
    textPenguin.setPosition(textPenguinField.getPosition().x + 50,
                            textPenguinField.getPosition().y + textPenguinField.getGlobalBounds().height / 2 - 20);
    textPenguin.setFillColor(sf::Color::Black);

    sf::Sprite penguinAmountSprite;
    penguinAmountSprite.setTexture(inputFieldSmall);
    penguinAmountSprite.setPosition(textPenguinField.getGlobalBounds().width + textPenguinField.getPosition().x + 20,
                                    textPenguinField.getPosition().y);
    sf::Text textPenguinAmount(to_string(*numPenguins), font, 50);
    textPenguinAmount.setPosition(
            penguinAmountSprite.getPosition().x + penguinAmountSprite.getGlobalBounds().width / 2 - 15,
            penguinAmountSprite.getPosition().y + penguinAmountSprite.getGlobalBounds().height / 2 - 35);
    textPenguinAmount.setFillColor(sf::Color::Black);

    plusButtonPenguin.setTexture(plusButton);
    plusButtonPenguin.setPosition(
            penguinAmountSprite.getPosition().x + penguinAmountSprite.getGlobalBounds().width + 20,
            (penguinAmountSprite.getPosition().y + 20));

    minusButtonPenguin.setTexture(minusButton);
    minusButtonPenguin.setPosition(plusButtonPenguin.getPosition().x + plusButtonPenguin.getGlobalBounds().width + 20,
                                   (penguinAmountSprite.getPosition().y + 20));


    sf::Sprite textPlayerField;
    textPlayerField.setTexture(inputField);
    textPlayerField.setPosition((xSize - textPlayerField.getGlobalBounds().width) / 2 - 120,
                                ySize / 2 - 200 + textPenguinField.getGlobalBounds().height + 60);
    sf::Text textPlayer("Number of Players", font, 30);
    textPlayer.setPosition(textPlayerField.getPosition().x + 50,
                           textPlayerField.getPosition().y + textPlayerField.getGlobalBounds().height / 2 - 20);
    textPlayer.setFillColor(sf::Color::Black);

    sf::Sprite playerAmountSprite;
    playerAmountSprite.setTexture(inputFieldSmall);
    playerAmountSprite.setPosition(textPlayerField.getGlobalBounds().width + textPlayerField.getPosition().x + 20,
                                   textPlayerField.getPosition().y);
    sf::Text textPlayerAmount(to_string(*numPlayers), font, 50);
    textPlayerAmount.setPosition(
            playerAmountSprite.getPosition().x + playerAmountSprite.getGlobalBounds().width / 2 - 15,
            playerAmountSprite.getPosition().y + playerAmountSprite.getGlobalBounds().height / 2 - 35);
    textPlayerAmount.setFillColor(sf::Color::Black);

    plusButtonPlayer.setTexture(plusButton);
    plusButtonPlayer.setPosition(playerAmountSprite.getPosition().x + playerAmountSprite.getGlobalBounds().width + 20,
                                 (playerAmountSprite.getPosition().y + 20));

    minusButtonPlayer.setTexture(minusButton);
    minusButtonPlayer.setPosition(plusButtonPlayer.getPosition().x + plusButtonPlayer.getGlobalBounds().width + 20,
                                  (playerAmountSprite.getPosition().y + 20));

    menu2NextButton.setTexture(nextButtonTxtr);
    menu2NextButton.setPosition((xSize - menu2NextButton.getGlobalBounds().width) / 2, ySize - 300);


    window->draw(textPenguinField);
    window->draw(textPenguin);
    window->draw(textPlayerField);
    window->draw(penguinAmountSprite);
    window->draw(playerAmountSprite);
    window->draw(textPlayerAmount);
    window->draw(plusButtonPenguin);
    window->draw(minusButtonPenguin);
    window->draw(plusButtonPlayer);
    window->draw(minusButtonPlayer);
    window->draw(textPenguinAmount);
    window->draw(menu2NextButton);
    window->draw(textPlayer);
}

void drawThirdPage(sf::RenderWindow *window){

    sf::Vector2u windowSizeVector = window->getSize();

    unsigned int xSize = windowSizeVector.x;
    unsigned int ySize = windowSizeVector.y;

    sf::Texture inputField;
    sf::Font font;
    if (!inputField.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/inputField.png"))
        cout << "ERROR loading inputField image.\n";
    if (!font.loadFromFile("/Users/igorzab/CLionProjects/epfu/fonts/arial.ttf")) cout << "ERROR loading font.\n";
    drawBackground(window);


    textFieldClient.setTexture(inputField);
    textFieldServer.setTexture(inputField);
    textFieldClient.setPosition((xSize - textFieldClient.getGlobalBounds().width) / 2 - 120, ySize / 2 - 200);
    sf::Text textClient("PLAY AS CLIENT", font, 30);
    textClient.setPosition(textFieldClient.getPosition().x + 50,
                            textFieldClient.getPosition().y + textFieldClient.getGlobalBounds().height / 2 - 20);
    textClient.setFillColor(sf::Color::Black);

    textFieldServer.setPosition((xSize - textFieldServer.getGlobalBounds().width) / 2 - 120, ySize / 2 - 200 + textFieldServer.getGlobalBounds().height + 60);
    sf::Text textServer("PLAY AS SERVER", font, 30);
    textServer.setPosition(
            textFieldServer.getPosition().x + textFieldServer.getGlobalBounds().width / 2 - 120,
            textFieldServer.getPosition().y + textFieldServer.getGlobalBounds().height / 2 - 25);
    textServer.setFillColor(sf::Color::Black);

    window->draw(textFieldClient);
    window->draw(textFieldServer);
    window->draw(textClient);
    window->draw(textServer);
}

bool checkIntersection(int clickX, int clickY) {
    if (startButtonSprite.getGlobalBounds().contains(clickX, clickY)) {
        return true;
    }
    return false;
}

void modifyValues(int *numPenguins, int *numPlayers, int *currentFaze, int clickX, int clickY) {
    if (plusButtonPenguin.getGlobalBounds().contains(clickX, clickY)&& *numPenguins) *numPenguins = *numPenguins + 1;
    if (minusButtonPenguin.getGlobalBounds().contains(clickX, clickY) && *numPenguins > 0)
        *numPenguins = *numPenguins - 1;
    if (plusButtonPlayer.getGlobalBounds().contains(clickX, clickY)&& *numPlayers < 9) *numPlayers = *numPlayers + 1;
    if (minusButtonPlayer.getGlobalBounds().contains(clickX, clickY) && *numPlayers > 0) *numPlayers = *numPlayers - 1;
    if (menu2NextButton.getGlobalBounds().contains(clickX, clickY) && *currentFaze == 1) *currentFaze = *currentFaze + 1;
    if (startButtonSprite.getGlobalBounds().contains(clickX, clickY) && *currentFaze == 0) *currentFaze = *currentFaze + 1;

    if (textFieldClient.getGlobalBounds().contains(clickX, clickY) && *currentFaze == 2) *currentFaze = *currentFaze + 1;
    if (textFieldServer.getGlobalBounds().contains(clickX, clickY) && *currentFaze == 2) {
        *currentFaze = *currentFaze + 1;
    }
}
