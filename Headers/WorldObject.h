#pragma once

#include "Color.h"
#include "Position.h"

namespace CGB {
    class WorldObject {
    public:
        WorldObject() = default;
        WorldObject(char symbol, const Color& color, const Position &position = Position(0, 0))
            : symbol(symbol), color(color), position(position) {}

        ~WorldObject() = default;

        inline WorldObject operator=(const WorldObject& other) {
            this->symbol = other.symbol;
            this->color = other.color;
            this->position = other.position;

            return *this;
        }

        inline bool operator==(const WorldObject& other) const {
            return this->symbol == other.symbol && this->color == other.color;
        }

        void draw();

        inline Position getPosition() const {
            return this->position;
        }

        inline void setPosition(const Position &position) {
            this->position = position;
        }

        inline void setColor(const Color &color) {
            this->color = color;
        }

        inline Color getColor() const {
            return this->color;
        }

        inline void setSymbol(char symbol) {
            this->symbol = symbol;
        }

        inline char getSymbol() const {
            return this->symbol;
        }
    private:
        char symbol = ' ';
        Position position;
        Color color = Color::WHITE;
    };
}
