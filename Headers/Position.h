/**
 * @file
 * @brief This file contains the declaration of the CGB::Position struct.
 */

#pragma once

namespace CGB {
    /**
     * @brief The Position struct represents a 2D position in the game world.
     */
    struct Position {
        /**
         * @brief Default constructor. Creates a Position with default values (0, 0).
         */
        Position() = default;

        /**
         * @brief Constructor. Creates a Position with the given x and y coordinates.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        Position(int x, int y) : x(x), y(y) {
        };

        /**
         * @brief Deleted move constructor. Position objects cannot be moved.
         */
        Position(Position &&) = delete;

        /**
         * @brief Deleted move assignment operator. Position objects cannot be moved.
         * @return A reference to this Position object after assignment.
         */
        Position &operator=(Position &&) = delete;

        /**
         * @brief Copy constructor. Creates a copy of another Position object.
         * @param other The other Position object to copy from.
         */
        Position(const Position &other) {
            this->operator=(other);
        }

        /**
         * @brief Copy assignment operator. Assigns the properties of another Position object to this object.
         * @param other The other Position object to assign from.
         * @return A reference to this Position object after assignment.
         */
        Position &operator=(const Position &other) {
            this->x = other.x;
            this->y = other.y;

            return *this;
        }

        /**
         * @brief Equality comparison operator for comparing a Position with an integer value.
         * @param value The integer value to compare against.
         * @return True if both x and y coordinates of the Position are equal to the value, otherwise false.
         */
        bool operator==(int value) const {
            return this->x == value && this->y == value;
        }

        /**
         * @brief Equality comparison operator for comparing two Position objects.
         * @param other The other Position object to compare against.
         * @return True if both x and y coordinates of both Position objects are equal, otherwise false.
         */
        bool operator==(const Position &other) const {
            return this->x == other.x && this->y == other.y;
        }

        int x; ///< The x-coordinate of the Position.
        int y; ///< The y-coordinate of the Position.
    };
}