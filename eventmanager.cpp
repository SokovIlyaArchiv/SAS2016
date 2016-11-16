#include "eventmanager.h"

EventManager::EventManager() {
    lastPosPressed = lastPosReleased = {0, 0};
    currentAppState = lastAppState = APP_STATE::MENU;
}

void EventManager::takeEvents(shared_ptr<RenderWindow>& window) {
    while(window->pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                swap(currentAppState, lastAppState);
                currentAppState = APP_STATE::QUIT;
                break;
            case Event::MouseButtonPressed:
                lastPosPressed = Mouse::getPosition(*window.get());
                break;
            case Event::MouseButtonReleased:
                lastPosReleased = Mouse::getPosition(*window.get());
                break;
            case Event::KeyPressed:
                if(event.key.code == Keyboard::Escape) {
                    if(currentAppState == APP_STATE::MENU) {
                        if(lastAppState == APP_STATE::MENU) {
                            currentAppState = APP_STATE::QUIT;
                        } else {
                            swap(currentAppState, lastAppState);
                        }
                    } else {
                        swap(currentAppState, lastAppState);
                        currentAppState = APP_STATE::MENU;
                    }
                }
                break;
            default:
                break;
        }
    }
}

APP_STATE EventManager::getAppState() const {
    return currentAppState;
}
