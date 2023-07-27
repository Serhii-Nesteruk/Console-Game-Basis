#pragma once

namespace CGB {
    struct Position {
        Position() = default;
        Position(Position &&) = delete;

        Position &operator=(Position &&) = delete;

        Position(int x, int y) : x(x), y(y) {
        };

/**/    Position &operator=(const Position &other) {
/**/        this->x = other.x;
/**/        this->y = other.y;
/**/
/**/        return *this;
/**/    }
/**/
/**/    Position(const Position &other) {
/**/        this->operator=(other);
/**/    }
/**/
/**/    bool operator==(int value) const {
/**/        return this->x == value && this->y == value;
/**/    }

        bool operator==(const Position &other) const {
            return this->x == other.x && this->y == other.y;
        }

        int x, y;
    };

}