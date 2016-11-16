#include "button.h"

Button::Button(Vector2f pos, Font& font) :
    Widget(){
    text = std::make_shared<Text>("AAA", font);
    text->setCharacterSize(50);
    text->setColor(Color::Red);
    background.setFillColor(Color::Black);
    FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.width / 2.f + textRect.left,
                    textRect.height / 2.f + textRect.top);
    background.setOrigin({textRect.width / 2.f, textRect.height / 2.f});
    text->setPosition(pos);
    background.setSize({textRect.width, textRect.height});
    background.setPosition(pos);
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
