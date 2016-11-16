#include "button.h"

Button::Button(Vector2f pos, Font& font, unsigned id) :
    Widget(id) {
    text = std::make_shared<Text>("1", font);
    text->setCharacterSize(500);
    text->setPosition(pos);
    text->setColor(Color::Black);
    background.setSize({text->getLocalBounds().width, text->getLocalBounds().height});
    background.setPosition({pos.x, pos.y});
    background.setFillColor(Color::White);
    background.setOutlineColor(Color::Black);
    background.setOutlineThickness(1);
}

void Button::setSprite(std::shared_ptr<Sprite> &sprite) {
    this->sprite = sprite;
}

void Button::setText(const std::string &text) {
    this->text->setString(text);
}

void Button::draw(RenderTarget &target, RenderStates states) const {
    target.draw(background);
    if(sprite != nullptr) {
        target.draw(*sprite);
    }
    target.draw(*text.get());
}

Button::~Button() {
}
