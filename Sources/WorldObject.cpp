#include "WorldObject.h"

#include <iostream>

void CGB::WorldObject::draw() {
    changeColor(color);
    std::cout << symbol;
}

CGB::WorldObject CGB::WorldObject::operator=(const CGB::WorldObject &other){
    this->symbol = other.symbol;
    this->color = other.color;
    this->position = other.position;

    return *this;
}