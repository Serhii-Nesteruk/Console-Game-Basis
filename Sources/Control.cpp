#include "Control.h"

#include <conio.h>

void CGB::Control::pressKey() {
    char input = _getch();
    keyInterpretation(input);
}

bool CGB::Control::isKeyPressed(const Keyboard &key) {
    if (key == activeKey) {
        checkControlMode();
        return true;
    }
    return false;
}

void CGB::Control::keyInterpretation(char input) {
    toUpperCase(input);

    switch(input) {
        case 'Q':
            activeKey = Keyboard::Q;
            break;
        case 'W':
            activeKey = Keyboard::W;
            break;
        case 'E':
            activeKey = Keyboard::E;
            break;
        case 'R':
            activeKey = Keyboard::R;
            break;
        case 'T':
            activeKey = Keyboard::T;
            break;
        case 'Y':
            activeKey = Keyboard::Y;
            break;
        case 'U':
            activeKey = Keyboard::U;
            break;
        case 'I':
            activeKey = Keyboard::I;
            break;
        case 'P':
            activeKey = Keyboard::P;
            break;
        case 'A':
            activeKey = Keyboard::A;
            break;
        case 'S':
            activeKey = Keyboard::S;
            break;
        case 'D':
            activeKey = Keyboard::D;
            break;
        case 'F':
            activeKey = Keyboard::F;
        case 'G':
            activeKey = Keyboard::G;
            break;
        case 'H':
            activeKey = Keyboard::H;
            break;
        case 'J':
            activeKey = Keyboard::J;
            break;
        case 'K':
            activeKey = Keyboard::K;
            break;
        case 'L':
            activeKey = Keyboard::L;
            break;
        case 'Z':
            activeKey = Keyboard::Z;
            break;
        case 'X':
            activeKey = Keyboard::X;
            break;
        case 'C':
            activeKey = Keyboard::C;
            break;
        case 'V':
            activeKey = Keyboard::V;
            break;
        case 'B':
            activeKey = Keyboard::B;
            break;
        case 'N':
            activeKey = Keyboard::N;
            break;
        case 'M':
            activeKey = Keyboard::M;
            break;
    }

}

void CGB::Control::toUpperCase(char &ch) {
    if (std::isalpha(ch))
        ch = static_cast<char>(std::toupper(ch));
}

void CGB::Control::checkControlMode() {
    if (playerControlMode == ControlMode::KEYS_STICKING) {
        //We don't do anything here, we leave the if body empty;
    }
    if (playerControlMode == ControlMode::DEFAULT)
        activeKey = Keyboard::NONE;
}

//TODO: refactor, `move object`
void CGB::Control::move(const CGB::Control::Direction &direction, CGB::WorldObject &obj,
                              const std::string &personalCode) {
    int objX = obj.getPosition().x;
    int objY = obj.getPosition().y;

    //clear last position
    map.objectReset(Position(objX, objY), map.getObject(Map::spaceCode),
                    Map::spaceCode);

    if (direction == Direction::RIGHT)
        ++objX;
    if (direction == Direction::LEFT)
        --objX;
    if (direction == Direction::UP)
        --objY;
    if (direction == Direction::DOWN)
        ++objY;

    obj.setPosition(Position(objX, objY));
    map.objectReset(Position(objX, objY), obj, personalCode);
}

//TODO: this function is not working, to fix
void CGB::Control::checkWall(WorldObject &obj, const Position &lastPosition, const ControlMode &wallCondition_) {
    setWallCondition(wallCondition_);

    switch(wallCondition_) {
        case ControlMode::SOLID_WALL:
            setLastPositionIfTouchWall(obj, lastPosition);
            break;
        case ControlMode::SNAKE_MODE:
            //TODO: implement me
            break;
        case ControlMode::DEFAULT:
            throw std::exception("Error: the state of the wall cannot be ControlMode::DEFAULT");
            break;
        case ControlMode::KEYS_STICKING:
            throw std::exception("Error: the state of the wall cannot be ControlMode::KEYS_STICKING");
    }
}

void CGB::Control::setLastPositionIfTouchWall(CGB::WorldObject &object, const Position& lastPosition) {
    for (auto &obj: map.getObjectsList())
        if (obj.personalCode == Map::wallCode && object.touchCheck(obj.obj))
            object.setPosition(lastPosition);
}
