#pragma once

#include "ObjectList.h"
#include "Position.h"

#include <vector>

namespace CGB {

    struct SizeMap {
        SizeMap(SizeMap &&) = delete;

        SizeMap &operator=(SizeMap &&) = delete;

        SizeMap(int x, int y) : x(x), y(y) {
        }

        SizeMap &operator=(const SizeMap &other) {
            this->x = other.x;
            this->y = other.y;
            return *this;
        }

        SizeMap(const SizeMap &other) {
            this->operator=(other);
        }

        bool operator==(int value) const {
            return this->x == value && this->y == value;
        }

        bool operator<=(int value) const {
            return this->x <= value && this->y <= value;
        }

        bool operator>=(int value) const {
            return this->x >= value && this->y >= value;
        }

        int x = 0, y = 0;
    };

    enum Symbol {
        WALL = '#',
        SPACE = ' ',
        PLAYER = '*',
        APPLE = '0'
    };

    class Map final {
    private:
        using mapType = std::vector<std::vector<WorldObject>>;
    public:
        Map() = default;

        explicit Map(const SizeMap &sizeMap);

        ~Map() = default;

        void setup(const SizeMap &sizeMap);
        void initWorldObjects();

        void init();
        void update();
        void draw();
        void objectReset(const Position &position, const WorldObject &newObject,
                         const std::string &personalCode);

        inline SizeMap getSizeMap() {
            return this->sizeMap;
        }

        inline void setSizeMap(const SizeMap &sizeMap) {
            this->sizeMap = sizeMap;
        }

        inline Position getObjPosition(const std::string &personalCode) {
            return this->objects.find(personalCode).obj.getPosition();
        }

        inline WorldObject &getObject(const std::string &personalCode) {
            return this->objects.find(personalCode).obj;
        }

        inline void setObjectColor(const Color& color, const std::string &personalCode) {
            this->objects.find(personalCode).obj.setColor(color);
        }

        inline void setObjectSymbol(char symbol, const std::string& personalCode) {
            this->objects.find(personalCode).obj.setSymbol(symbol);
        }

        inline ObjectsList getObjectsList() const {
            return this->objects;
        }

        inline static const std::string & wallCode = "0";
        inline static const std::string & spaceCode = "1";

    private:
        void checkObjectsChanges();
        void resize();
        void initWall(const Position &position);
        void initSpace(int y);
        bool isWall(unsigned int x, unsigned int y);//TODO: change name
        bool isSpace(unsigned int x, unsigned int y);//TODO: change name

   /**/ void changeColorWall(unsigned int x, unsigned int y);
   /**/ void changeColorAllObjects(unsigned int x, unsigned int y);
   /**/ void changeColor(unsigned int x, unsigned int y);
        void initUpperAndLowerEdge(int y);//TODO: refactor
        void initLeftAndRightEdge(int y);//TODO: refactor

    private:
        mapType map {};
        SizeMap sizeMap = SizeMap(5, 5);
        ObjectsList objects;
        std::vector<std::string> objectsCodes{};
    };
}