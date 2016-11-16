#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Widget : public Drawable {
public:
    unsigned getId() const;
    void setId(const unsigned id);
    Vector2f getPosition() const;
protected:
    virtual void draw(RenderTarget& target, RenderStates states) const = 0;
    void setPosition(const Vector2f newPos);
    virtual ~Widget();
private:
    unsigned id;
    Vector2f position;
};
