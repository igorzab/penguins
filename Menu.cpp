//
// Created by igor zab on 27/11/2023.
//
#include "Menu.h"

sf::Sprite startButtonSprite;

sf::Sprite plusButtonPenguin;

sf::Sprite minusButtonPenguin;

sf::Sprite plusButtonPlayer;

sf::Sprite minusButtonPlayer;

void drawFirstPage(sf::RenderWindow *window) {
    sf::Vector2u windowSizeVector = window->getSize();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    unsigned int xSize = windowSizeVector.x;
    unsigned int ySize = windowSizeVector.y;

    sf::Texture background;
    sf::Texture startButton;
    sf::Texture title;
    sf::Texture startButtonWhite;
    sf::Font font;
    if (!background.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/background1.jpg",
                                 sf::IntRect(0, 0, windowSizeVector.x, windowSizeVector.y)))
        cout << "ERROR loading bg image.\n";
    if (!startButton.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/startButton.png"))
        cout << "ERROR loading button image.\n";
    if (!title.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/title.png"))
        cout << "ERROR loading button image.\n";
    if (!startButtonWhite.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/startButtonWhite.png"))
        cout << "ERROR loading button image.\n";
    if (!font.loadFromFile("/Users/igorzab/CLionProjects/epfu/fonts/arial.ttf")) cout << "Error loading font\n";

    sf::Sprite titleSprite;
    titleSprite.setTexture(title);
    titleSprite.setPosition((xSize - titleSprite.getGlobalBounds().width) / 2, 250);
    sf::Sprite bgsprite;

    bgsprite.setTexture(background);
    startButtonSprite.setTexture(startButtonWhite);
    bgsprite.setScale(static_cast<float>(windowSizeVector.x) / background.getSize().x,
                      static_cast<float>(windowSizeVector.y) / background.getSize().y);
    sf::FloatRect spriteBounds = startButtonSprite.getGlobalBounds();
    startButtonSprite.setPosition((xSize - spriteBounds.width) / 2, (ySize) / 2);
    if (startButtonSprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                     static_cast<float>(mousePosition.y))) {
        startButtonSprite.setTexture(startButton);
    }

    window->draw(bgsprite);
    window->draw(startButtonSprite);
    window->draw(titleSprite);


}

void drawSecondPage(sf::RenderWindow *window, int *numPenguins, int* numPlayers) {
    sf::Vector2u windowSizeVector = window->getSize();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    unsigned int xSize = windowSizeVector.x;
    unsigned int ySize = windowSizeVector.y;
    sf::Texture inputField;
    sf::Texture inputFieldSmall;
    sf::Texture plusButton;
    sf::Texture minusButton;
    sf::Texture background;
    if (!background.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/background1.jpg",
                                 sf::IntRect(0, 0, windowSizeVector.x, windowSizeVector.y)))
        cout << "ERROR loading bg image.\n";
    if (!inputField.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/inputField.png"))
        cout << "ERROR loading inputField image.\n";
    if (!inputFieldSmall.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/inputFieldSmall.png"))
        cout << "ERROR loading inputField image.\n";
    if (!plusButton.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/plusButton.png"))
        cout << "ERROR loading plusButton image.\n";
    if (!minusButton.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/minusButton.png"))
        cout << "ERROR loading minusButton image.\n";
    sf::Font font;
    if (!font.loadFromFile("/Users/igorzab/CLionProjects/epfu/fonts/arial.ttf")) cout << "ERROR loading font.\n";
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(static_cast<float>(windowSizeVector.x) / background.getSize().x,
                              static_cast<float>(windowSizeVector.y) / background.getSize().y);

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


    window->draw(backgroundSprite);
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
    window->draw(textPlayer);
}

bool checkIntersection(int clickX, int clickY) {
    if (startButtonSprite.getGlobalBounds().contains(clickX, clickY)) {
        return true;
    }
    return false;
}

void modifyValues(int *numPenguins, int *numPlayers, int clickX, int clickY) {
    if (plusButtonPenguin.getGlobalBounds().contains(clickX, clickY)) *numPenguins = *numPenguins+1;
    if (minusButtonPenguin.getGlobalBounds().contains(clickX, clickY)) *numPenguins = *numPenguins-1;
    if (plusButtonPlayer.getGlobalBounds().contains(clickX, clickY)) *numPlayers = *numPlayers+1;
    if (minusButtonPlayer.getGlobalBounds().contains(clickX, clickY)) *numPlayers = *numPlayers-1;
}
