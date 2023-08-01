#include "Map.h"

#include <iostream>

CGB::Map::Map(const SizeMap &sizeMap) : sizeMap(sizeMap) {
    setup(sizeMap);
}

void CGB::Map::setup(const SizeMap &sizeMap) {
    if (sizeMap <= 0)
        this->sizeMap = sizeMap;

    resize();
    initWorldObjects();
    init();
}

void CGB::Map::resize() {
    map.resize(sizeMap.y);
    for (auto &x: map)
        x.resize(sizeMap.x);
}

void CGB::Map::initWorldObjects() {
    initWall();
    initSpace();
}

void CGB::Map::initLeftAndRightEdge(int y) {
    for (int x = 0; x < sizeMap.x; x += (sizeMap.x - 1))//TODO:magic number
        initWallUnit(Position(x, y));
}

void CGB::Map::initUpperAndLowerEdge(int y) {
    for (int x = 0; x < sizeMap.x; ++x)
        initWallUnit(Position(x, y));
}

void CGB::Map::initWall() {
    for (int y = 0; y < sizeMap.y; ++y) //TODO:magic number
        if (y == 0 || y == sizeMap.y - 1)//TODO:magic number
            initUpperAndLowerEdge(y);
        else
            initLeftAndRightEdge(y);
}

void CGB::Map::initWallUnit(const Position &position) {
    WorldObject wall(Symbol::WALL, Color::BROWN, Position(position));
    objects.emplace_back(wall, wallCode);
}

void CGB::Map::initSpace() {
    for (int y = 1; y < sizeMap.y - 1; ++y)//TODO: magic number
        initSpaceUnit(y);
}

void CGB::Map::initSpaceUnit(int y) {
    for (int x = 1; x < sizeMap.x - 1; ++x) {  //TODO:magic number
        WorldObject space(Symbol::SPACE, Color::WHITE, Position(x, y));
        objects.emplace_back(space, spaceCode);
    }
}

void CGB::Map::update() {
    system("cls");
    checkObjectsChanges();
}

void CGB::Map::draw() {
    for (auto &y: map) {
        for (auto &x: y)
            x.draw();
        std::cout << std::endl;
    }
}

void CGB::Map::init() {
    int posY = 0, posX = 0;

    for (auto &obj: objects) {
        posY = obj.obj.getPosition().y;
        posX = obj.obj.getPosition().x;

        map.at(posY).at(posX) = obj.obj;
    }
}

void CGB::Map::objectReset(const Position &position, const WorldObject &newObject,
                           const std::string &personalCode) {
    objects.reset(position, newObject, personalCode);
    objectsCodes.emplace_back(personalCode);
    map.at(position.y).at(position.x) = newObject;
}

void CGB::Map::checkObjectsChanges() {
  for (unsigned int y = 0; y < sizeMap.y; ++y) {
      for (unsigned int x = 0; x < sizeMap.x; ++x)
          changeColorAllObjects(x, y);
  }
}

bool CGB::Map::isWall(unsigned int x, unsigned int y) {
    return map.at(y).at(x).getSymbol() == objects.find(wallCode).obj.getSymbol();
}

bool CGB::Map::isSpace(unsigned int x, unsigned int y) {
    return map.at(y).at(x).getSymbol() == objects.find(spaceCode).obj.getSymbol();
}

void CGB::Map::changeColorWall(unsigned int x, unsigned int y) {
    map.at(y).at(x).setColor(objects.find(wallCode).obj.getColor());
}

void CGB::Map::changeColorAllObjects(unsigned int x, unsigned int y) {
    if (isWall(x, y))
        changeColorWall(x, y);
    else
        if (!isSpace(x, y))
            changeColor(x, y);
}

void CGB::Map::changeColor(unsigned int x, unsigned int y) {
   for (auto &obj: objects)
       for (auto &code: objectsCodes)
           if (obj.personalCode == code && (y < sizeMap.y && x < sizeMap.x))
               map.at(y).at(x) = obj.obj;
}