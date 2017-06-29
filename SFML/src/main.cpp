#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
 
    sf::Window App(sf::VideoMode(800, 600), "HelloSFML");
    while (App.isOpen()) {
        sf::Event myEvent;
        while (App.pollEvent(myEvent)) {
            if (myEvent.type == sf::Event::Closed) {
                App.close();
            }
            App.display();
        }
    }
}