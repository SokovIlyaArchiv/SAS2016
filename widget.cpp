#include "widget.h"

void Widget::setPosition(const Vector2f newPos) {
    position = newPos;
}

void Widget::setId(const unsigned id) {
    this->id = id;
}

unsigned Widget::getId() const {
    return id;
}

Vector2f Widget::getPosition() const {
    return position;
}

Widget::~Widget() {
}
