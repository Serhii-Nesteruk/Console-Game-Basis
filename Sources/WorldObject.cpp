#include "../Headers/WorldObject.h"

#include <iostream>

void CGB::WorldObject::draw() {
    changeColor(color);
    std::cout << symbol;
}