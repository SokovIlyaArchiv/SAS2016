#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Hello World - SFML");
    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                App.close();
            }
        }
        App.display();
    }
    return 0;
}
