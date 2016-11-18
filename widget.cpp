#include "widget.h"

Widget::Widget() {
    visible = true;
}

void Widget::setPosition(const Vector2i newPosition) {
    position = newPosition;
}

void Widget::setId(const unsigned id) {
    this->id = id;
}

unsigned Widget::getId() const {
    return id;
}

Vector2i Widget::getPosition() const {
    return position;
}

Widget::~Widget() {
}
