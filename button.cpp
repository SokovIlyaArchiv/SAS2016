#include "button.h"
#include <iostream>

using namespace std;
Button::Button(Vector2f pos, Font& font) :
    Widget(){
    text = std::make_shared<Text>("SOME", font);
    text->setCharacterSize(50);
    text->setColor(Color::Red);
    background.setFillColor(Color::Black);
    FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.width / 2.f + textRect.left,
                    textRect.height / 2.f + textRect.top);
    background.setOrigin({textRect.width / 2.f, textRect.height / 2.f});
    text->setPosition(pos);
    background.setSize({textRect.width + 20, textRect.height + 20});
    background.setPosition(pos - Vector2f{10, 10});
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

bool Button::contains(const Vector2i point) const {
    IntRect boundary {
                 text->getPosition().x - (int)background.getSize().x / 2,
                 text->getPosition().y - (int)background.getSize().y / 2,
                 background.getSize().x,
                 background.getSize().y
             };
    return boundary.contains(point);
}

Button::~Button() {
}
