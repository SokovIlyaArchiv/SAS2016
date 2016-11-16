#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Widget : public Drawable {
protected:
    Widget(unsigned id);
    virtual void draw(RenderTarget& target, RenderStates states) const = 0;
    void setPosition(const Vector2f newPos);
    unsigned getId() const;
    Vector2f getPosition() const;
    virtual ~Widget();
private:
    const unsigned id;
    Vector2f position;
};
