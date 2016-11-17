#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "button.h"

using namespace std;
using namespace sf;

enum class APP_STATE{PLAY, MENU, QUIT};
class EventManager {
public:
    EventManager();
    void processEvents(shared_ptr<RenderWindow>& window);
    void connect(shared_ptr<Button> widget);
    APP_STATE getAppState() const;
private:
    Event event;
    APP_STATE currentAppState,
              lastAppState;
    Vector2i lastPosPressed,
             lastPosReleased;
    unsigned maxId;
    vector<shared_ptr<Button>> widgets;
};
