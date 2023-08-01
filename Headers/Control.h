#pragma once

#include "Map.h"

namespace CGB {

    class Control final {
    public:
        enum ControlMode {
            KEYS_STICKING,
            DEFAULT,
            SOLID_WALL
          //  SNAKE_MODE
        };

        enum Direction {
            LEFT,
            RIGHT,
            UP,
            DOWN
        };

        enum Keyboard {
            Q,W,E,R,T,Y,U,I,O,P,A,S,D,F,G,H,J,K,L,Z,X,C,V,B,N,M,
            SPACE, ESC, CTRL, FN, ALT, NONE
        };

        Control() = delete;

        explicit Control(Map& map) : map(map) {}

        ~Control() = default;

        void connectToMap(Map& map);
        void pressKey();

        void move(const Direction &direction, WorldObject& obj,
                  const std::string &personalCode);

        inline void setPlayerControlMode(const ControlMode& controlMode) {
            this->playerControlMode = controlMode;
        }

        inline ControlMode getPlayerControlMode() const {
            return this->playerControlMode;
        }

        void checkWall(WorldObject &player, const ControlMode &wallCondition);
        bool isKeyPressed(const Keyboard &key);
    private:
        void keyInterpretation(char input);
        void toUpperCase(char &ch);
        void checkControlMode();

    private:
        Keyboard activeKey = Keyboard::NONE;
        Map& map;
        ControlMode playerControlMode = ControlMode::DEFAULT;
        ControlMode wallCondition = ControlMode::SOLID_WALL;
    };

}