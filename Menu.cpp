//
// Created by igor zab on 27/11/2023.
//
#include "Menu.h"

sf::Sprite startButtonSprite;
void drawFirstPage(sf::RenderWindow *window){
    sf::Vector2u windowSizeVector = window->getSize();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    unsigned int xSize = windowSizeVector.x;
    unsigned int ySize = windowSizeVector.y;

    sf::Texture background;
    sf::Texture startButton;
    sf::Texture startButtonWhite;
    if(!background.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/background1.png", sf::IntRect(0, 0,windowSizeVector.x,windowSizeVector.y ) )) cout << "ERROR loading bg image.\n";
    if(!startButton.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/startButton.png")) cout << "ERROR loading button image.\n";
    if(!startButtonWhite.loadFromFile("/Users/igorzab/CLionProjects/epfu/assets/img/startButtonWhite.png")) cout << "ERROR loading button image.\n";
    sf::Sprite bgsprite;

    bgsprite.setTexture(background);
    startButtonSprite.setTexture(startButtonWhite);
    bgsprite.setScale(static_cast<float>(windowSizeVector.x) / background.getSize().x,
                    static_cast<float>(windowSizeVector.y) / background.getSize().y);
    window->draw(bgsprite);
    sf::FloatRect spriteBounds = startButtonSprite.getGlobalBounds();
    startButtonSprite.setPosition((xSize - spriteBounds.width)/2, (ySize)/2);
    sf::FloatRect buttonBounds = startButtonSprite.getGlobalBounds();
    if (startButtonSprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        startButtonSprite.setTexture(startButton);
    }

    window->draw(startButtonSprite);


}

bool checkIntersection(int clickX, int clickY){
    if (startButtonSprite.getGlobalBounds().contains(clickX, clickY)) {
        return true;
    }
    return false;
}



