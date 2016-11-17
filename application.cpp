#include <iostream>

#include "application.h"

Application::Application(int width, int height) {
    window = make_shared<RenderWindow>(sf::VideoMode(width, height), "Chekers");
    eventManager = make_shared<EventManager>();
    buttonFont = make_shared<Font>();
    buttonFont->loadFromFile("Data/Fonts/arial.ttf");
    button = make_shared<Button>(Vector2f{100, 100}, *buttonFont.get());
    eventManager->connect(button);
    window->setFramerateLimit(60);
}

void Application::run() {
    while(eventManager->getAppState() != APP_STATE::QUIT) {
        eventManager->processEvents(window);
        window->clear(Color(255, 255, 255, 255));
        window->draw(*button.get());
        window->display();
    }
    window->close();
}
