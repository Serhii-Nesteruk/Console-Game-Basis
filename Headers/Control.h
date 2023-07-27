#pragma once

#include "Map.h"

namespace CGB {

    class ControlPlayer final {
    public:
        enum ControlMode {
            KEYS_STICKING,
            DEFAULT
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

        ControlPlayer() = delete;

        explicit ControlPlayer(Map& map) : map(map) {}

        ~ControlPlayer() = default;

        void connectToMap(Map& map);
        void pressKey();

        void move(const Direction &direction, const std::string &personalCode);

        inline void setPlayerControlMode(const ControlMode& controlMode) {
            this->playerControlMode = controlMode;
        }

        inline ControlMode getPlayerControlMode() const {
            return this->playerControlMode;
        }

        bool isKeyPressed(const Keyboard &key);
    private:
        void keyInterpretation(char input);
        void toUpperCase(char &ch);
        void checkControlMode();

    private:
        Keyboard activeKey = Keyboard::NONE;
        Map& map;
        ControlMode playerControlMode = ControlMode::DEFAULT;
    };

}