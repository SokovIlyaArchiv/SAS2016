#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Widget : public Drawable {
public:
    Widget();
    void setId(const unsigned id);
    unsigned getId() const;
    Vector2i getPosition() const;
    virtual bool contains(const Vector2i point) const = 0;
protected:
    virtual void draw(RenderTarget& target, RenderStates states) const = 0;
    void setPosition(const Vector2i newPosition);
    virtual ~Widget();
private:
    unsigned id;
    bool visible;
    Vector2i position;
};
