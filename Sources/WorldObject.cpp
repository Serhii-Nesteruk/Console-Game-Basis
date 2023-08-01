#include "../Headers/WorldObject.h"

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

//TODO: refactor, magic numbers
//bool CGB::WorldObject::touchCheck(const CGB::WorldObject &other) const {
//   Position temp = this->position;
//   temp.x++;
//   if (temp.x == position.x && temp.y == position.y)
//       return true;
//   temp.x -= 2;
//    if (temp.x == position.x && temp.y == position.y)
//        return true;
//    temp.x++;
//    temp.y++;
//    if (temp.x == position.x && temp.y == position.y)
//        return true;
//    temp.y -= 2;
//    if (temp.x == position.x && temp.y == position.y)
//        return true;
//    return false;
//}
