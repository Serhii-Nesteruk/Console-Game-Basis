/**
 * @file
 * @brief This file contains the declaration of the CGB::Control class and related enums.
 */

#pragma once

#include "Map.h"

namespace CGB {

    /**
     * @brief The Control class handles player input and controls the movement of WorldObjects.
     */
    class Control final {
    public:
        /**
         * @brief Enum representing different control modes for the player.
         */
        enum ControlMode {
            KEYS_STICKING, ///< Control mode where keys are sticky (held down).
            DEFAULT,       ///< Default control mode.
            SOLID_WALL     ///< Control mode with solid walls (collision stops movement).
            // SNAKE_MODE   ///< Potential future control mode (commented out for now).
        };

        /**
         * @brief Enum representing different directions.
         */
        enum Direction {
            LEFT,  ///< Left direction.
            RIGHT, ///< Right direction.
            UP,    ///< Up direction.
            DOWN   ///< Down direction.
        };

        /**
         * @brief Enum representing different keyboard keys.
         */
        enum Keyboard {
            Q, W, E, R, T, Y, U, I, O, P, A, S, D, F, G, H, J, K, L, Z, X, C, V, B, N, M,
            SPACE,  ///< Spacebar key.
            ESC,    ///< Escape key.
            CTRL,   ///< Control key.
            FN,     ///< Function key.
            ALT,    ///< Alt key.
            NONE    ///< No key (default value).
        };

        /**
         * @brief Deleted default constructor. There's no default instance of Control.
         */
        Control() = delete;

        /**
         * @brief Constructs a Control object and connects it to a map.
         * @param map The Map object to connect to.
         */
        explicit Control(Map& map) : map(map) {}

        /**
         * @brief Default destructor.
         */
        ~Control() = default;

        /**
         * @brief Connects the Control object to a Map.
         * @param map The Map object to connect to.
         */
        void connectToMap(Map& map);

        /**
         * @brief Handles the key press event.
         */
        void pressKey();

        /**
         * @brief Moves a WorldObject in the specified direction.
         * @param direction The direction in which to move the WorldObject.
         * @param obj The WorldObject to move.
         * @param personalCode A string representing a personal code for the movement (not used in the current implementation).
         */
        void move(const Direction &direction, WorldObject& obj, const std::string &personalCode);

        /**
         * @brief Sets the player control mode.
         * @param controlMode The ControlMode to set.
         */
        inline void setPlayerControlMode(const ControlMode& controlMode) {
            this->playerControlMode = controlMode;
        }

        /**
         * @brief Gets the current player control mode.
         * @return The current ControlMode.
         */
        inline ControlMode getPlayerControlMode() const {
            return this->playerControlMode;
        }

        /**
         * @brief Checks for collision with a wall based on the control mode.
         * @param player The WorldObject representing the player.
         * @param wallCondition The ControlMode to consider for the wall condition.
         */
        void checkWall(WorldObject &player, const ControlMode &wallCondition);

        /**
         * @brief Checks if a specific keyboard key is currently pressed.
         * @param key The Keyboard key to check.
         * @return True if the key is pressed, otherwise false.
         */
        bool isKeyPressed(const Keyboard &key);

    private:
        /**
         * @brief Interprets the pressed key and performs corresponding actions.
         * @param input The character representation of the pressed key.
         */
        void keyInterpretation(char input);

        /**
         * @brief Converts a character to its uppercase representation.
         * @param ch The character to convert to uppercase.
         */
        void toUpperCase(char &ch);

        /**
         * @brief Checks the current control mode and performs any necessary actions.
         */
        void checkControlMode();

    private:
        Keyboard activeKey = Keyboard::NONE;   ///< The currently active keyboard key.
        Map& map;                              ///< Reference to the connected Map object.
        ControlMode playerControlMode = ControlMode::DEFAULT;   ///< The current player control mode.
        ControlMode wallCondition = ControlMode::SOLID_WALL;    ///< The current wall collision condition.
    };

}