#include <iostream>
#include "Game.h"

int main() {

    sf::VideoMode desktop = sf::VideoMode::getFullscreenModes()[0];
    sf::RenderWindow window(desktop, "Rybka"); // sf::Style::Fullscreen for fullscreen mode
    window.setFramerateLimit(60);
    sf::TcpSocket socket;
    sf::TcpListener listener;
    if (socket.connect("141.147.31.0", 3000) != sf::Socket::Done) {
        std::cerr << "Error connecting to the server" << std::endl;
    }
//    listener.listen(3000);
//    listener.accept(socket);
    socket.setBlocking(false);
    std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
    play(&window, &socket, &listener);

    return 0;
}