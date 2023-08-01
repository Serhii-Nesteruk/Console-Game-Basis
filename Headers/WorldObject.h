/**
 * @file
 * @brief This file contains the declaration of the CGB::WorldObject class.
 */

#pragma once

#include "Color.h"
#include "Position.h"

namespace CGB {
    /**
     * @brief The WorldObject class represents an object in the game world.
     */
    class WorldObject {
    public:
        /**
         * @brief Default constructor. Creates a WorldObject with default values.
         */
        WorldObject() = default;

        /**
         * @brief Parameterized constructor. Creates a WorldObject with the given symbol, color, and position.
         * @param symbol The character symbol representing the object.
         * @param color The Color object representing the object's color.
         * @param position The Position object representing the object's position (default is (0, 0)).
         */
        WorldObject(char symbol, const Color& color, const Position &position = Position(0, 0))
                : symbol(symbol), color(color), position(position) {}

        /**
         * @brief Default destructor.
         */
        ~WorldObject() = default;

        /**
         * @brief Overloaded assignment operator. Assigns the properties of another WorldObject to this object.
         * @param other The other WorldObject to assign from.
         * @return A reference to this object after assignment.
         */
        WorldObject operator=(const WorldObject& other);

        /**
         * @brief Checks if the object touches a specific position in the game world.
         * @param pos The Position to check against.
         * @return True if the object touches the given position, otherwise false.
         */
        inline bool touchCheck(const Position &pos) const {
            return this->position == pos;
        }

        /**
         * @brief Checks if the object touches another WorldObject in the game world.
         * @param other The other WorldObject to check against.
         * @return True if the objects touch each other, otherwise false.
         */
        inline bool touchCheck(const WorldObject& other) const {
            return this->position == other.position;
        }

        /**
         * @brief Overloaded equality operator. Checks if two WorldObjects are equal.
         * @param other The other WorldObject to compare against.
         * @return True if the objects are equal, otherwise false.
         */
        inline bool operator==(const WorldObject& other) const {
            return this->symbol == other.symbol && this->color == other.color && this->position == other.position;
        }

        /**
         * @brief Draws the WorldObject by changing the color and printing the symbol.
         */
        void draw();

        /**
         * @brief Gets the current position of the WorldObject.
         * @return The Position object representing the current position.
         */
        inline Position getPosition() const {
            return this->position;
        }

        /**
         * @brief Sets the position of the WorldObject.
         * @param position The Position object representing the new position.
         */
        inline void setPosition(const Position &position) {
            this->position = position;
        }

        /**
         * @brief Sets the color of the WorldObject.
         * @param color The Color object representing the new color.
         */
        inline void setColor(const Color &color) {
            this->color = color;
        }

        /**
         * @brief Gets the current color of the WorldObject.
         * @return The Color object representing the current color.
         */
        inline Color getColor() const {
            return this->color;
        }

        /**
         * @brief Sets the symbol of the WorldObject.
         * @param symbol The character symbol representing the new symbol.
         */
        inline void setSymbol(char symbol) {
            this->symbol = symbol;
        }

        /**
         * @brief Gets the current symbol of the WorldObject.
         * @return The character symbol representing the current symbol.
         */
        inline char getSymbol() const {
            return this->symbol;
        }
    private:
        char symbol = ' ';      ///< The character symbol representing the WorldObject.
        Position position;      ///< The Position object representing the position of the WorldObject.
        Color color = Color::WHITE;   ///< The Color object representing the color of the WorldObject.
    };
}