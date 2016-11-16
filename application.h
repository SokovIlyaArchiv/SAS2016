#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;
using namespace sf;

#include "eventmanager.h"
#include "button.h"

class Application {
public:
    Application(int width = 800, int height = 600);
    void run();
private:
    shared_ptr<Font> buttonFont;
    shared_ptr<Button> button;
    shared_ptr<RenderWindow> window;
    shared_ptr<EventManager> eventManager;
};
