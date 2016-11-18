#pragma once
#include <memory>

#include "widget.h"

class Button : public Widget {
public:
    Button(Vector2f pos, Font& font);
    void setSprite(std::shared_ptr<Sprite>& sprite);
    void setText(const std::string& text);
    virtual ~Button();
protected:
    virtual void draw(RenderTarget& target, RenderStates states) const;
    virtual bool contains(const Vector2i point) const;
private:
    std::shared_ptr<Text> text;
    std::shared_ptr<Sprite> sprite;
    RectangleShape background;
};
