#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "widget.h"

using namespace std;
using namespace sf;

enum class APP_STATE{PLAY, MENU, QUIT};
class EventManager {
public:
    EventManager();
    void takeEvents(shared_ptr<RenderWindow>& window);
    APP_STATE getAppState() const;
private:
    Event event;
    APP_STATE currentAppState,
              lastAppState;
    Vector2i lastPosPressed,
             lastPosReleased;
    vector<Widget*> widgets;
};
