#include "../Headers/Map.h"

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

void CGB::Map::initWorldObjects() {//TODO: refactor

    for (int y = 0; y < sizeMap.y; ++y) {//TODO:magic number
        if (y == 0 || y == sizeMap.y - 1)//TODO:magic number
            initUpperAndLowerEdge(y);//TODO:
        else
            initLeftAndRightEdge(y);//TODO:
    }

    for (int y = 1; y < sizeMap.y - 1; ++y) {//TODO:magic number
            initSpace(y);
    }
}

void CGB::Map::initLeftAndRightEdge(int y) {
    for (int x = 0; x < sizeMap.x; x += (sizeMap.x - 1))//TODO:magic number
        initWall(Position(x, y));
}

void CGB::Map::initUpperAndLowerEdge(int y) {
    for (int x = 0; x < sizeMap.x; ++x)
        initWall(Position(x, y));
}

void CGB::Map::initWall(const Position &position) { //TODO:magic number
    WorldObject wall(Symbol::WALL, Color::BROWN, Position(position));
    objects.emplace_back(wall, wallCode);
}

void CGB::Map::initSpace(int y) {
    for (int x = 1; x < sizeMap.x - 1; ++x) {  //TODO:magic number
        WorldObject space(Symbol::SPACE, Color::WHITE, Position(x, y));
        objects.emplace_back(space, spaceCode);
    }
}

void CGB::Map::update() {//TODO: implement me!
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

    //TODO: use range-based for
    for (int i = 0; i < objects.size(); ++i) {
        posY = objects.at(i).obj.getPosition().y;
        posX = objects.at(i).obj.getPosition().x;

        map.at(posY).at(posX) = objects.at(i).obj;
    }
}

void CGB::Map::objectReset(const Position &position, const WorldObject &newObject,
                           const std::string &personalCode) {//TODO: improve
    objects.emplace_back(newObject, personalCode);
    objectsCodes.emplace_back(personalCode);
    map.at(position.y).at(position.x) = newObject;
}

void CGB::Map::checkObjectsChanges() {//TODO: refactor, improve
  for (unsigned int y = 0; y < sizeMap.y; ++y) {
      for (unsigned int x = 0; x < sizeMap.x; ++x)
          changeColorAllObjects(x, y);
  }
}

bool CGB::Map::isWall(unsigned int x, unsigned int y) {
    if (map.at(y).at(x).getSymbol() == objects.find(wallCode).obj.getSymbol())
        return true;
    return false;
}

bool CGB::Map::isSpace(unsigned int x, unsigned int y) {
    if (map.at(y).at(x).getSymbol() == objects.find(spaceCode).obj.getSymbol())
        return true;
    return false;
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
   //TODO: use a range-based for
   for (unsigned int i = 0; i < objects.size(); ++i) {
       for (unsigned int j = 0; j < objectsCodes.size(); ++j) {
           if (objects.at(i).personalCode == objectsCodes.at(j))
               if (y < sizeMap.y && x < sizeMap.x)
                   map.at(y).at(x) = objects.at(i).obj;
       }
   }
}