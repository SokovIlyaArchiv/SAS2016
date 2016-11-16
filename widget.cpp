#include "widget.h"

Widget::Widget(unsigned id) :
    id(id) {
    setPosition({0, 0});
}

void Widget::setPosition(const Vector2f newPos) {
    position = newPos;
}

unsigned Widget::getId() const {
    return id;
}

Vector2f Widget::getPosition() const {
    return position;
}

Widget::~Widget() {
}
