#include "eventmanager.h"

EventManager::EventManager() {
    lastPosPressed = lastPosReleased = {0, 0};
    currentAppState = lastAppState = APP_STATE::MENU;
    maxId = 0;
}

void EventManager::processEvents(shared_ptr<RenderWindow>& window) {
    while(window->pollEvent(event)) { // TAKE EVENTS
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
    for(auto pWidget : widgets) {
    }
}

void EventManager::connect(shared_ptr<Button> widget) {
    widget->setId(maxId);
    widgets.push_back(widget);
    maxId++;
}

APP_STATE EventManager::getAppState() const {
    return currentAppState;
}
