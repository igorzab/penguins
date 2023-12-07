#include <iostream>
#include "Game.h"

int main() {

    sf::VideoMode desktop = sf::VideoMode::getFullscreenModes()[0];
    sf::RenderWindow window(desktop, "Rybka"); // sf::Style::Fullscreen for fullscreen mode
    window.setFramerateLimit(60);
    play(&window);

    return 0;
}