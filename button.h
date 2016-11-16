#pragma once
#include <memory>

#include "widget.h"

class Button : public Widget {
public:
    Button(Vector2f pos, Font& font);
    void setSprite(std::shared_ptr<Sprite>& sprite);
    void setText(const std::string& text);
    virtual void draw(RenderTarget& target, RenderStates states) const;
    virtual ~Button();
private:
    std::shared_ptr<Text> text;
    std::shared_ptr<Sprite> sprite;
    RectangleShape background;
};
