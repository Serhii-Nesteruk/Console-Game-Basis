/**
 * @file
 * @brief This file contains the declaration of the CGB::SizeMap struct, CGB::Symbol enum, and CGB::Map class.
 */

#pragma once

#include "ObjectList.h"
#include "Position.h"

#include <vector>

namespace CGB {
    /**
     * @brief The SizeMap struct represents the size of the game map.
     */
    struct SizeMap {
        /**
         * @brief Constructor. Creates a SizeMap with the given x and y dimensions.
         * @param x The width of the map.
         * @param y The height of the map.
         */
        SizeMap(int x, int y) : x(x), y(y) {
        }

        /**
         * @brief Copy assignment operator for the SizeMap struct.
         * @param other The other SizeMap to copy from.
         * @return A reference to this SizeMap after assignment.
         */
        SizeMap &operator=(const SizeMap &other) {
            this->x = other.x;
            this->y = other.y;
            return *this;
        }

        /**
         * @brief Copy constructor. Creates a copy of another SizeMap object.
         * @param other The other SizeMap object to copy from.
         */
        SizeMap(const SizeMap &other) {
            this->operator=(other);
        }

        /**
         * @brief Equality comparison operator for comparing a SizeMap with an integer value.
         * @param value The integer value to compare against.
         * @return True if both x and y dimensions of the SizeMap are equal to the value, otherwise false.
         */
        bool operator==(int value) const {
            return this->x == value && this->y == value;
        }

        /**
         * @brief Less than or equal to comparison operator for comparing a SizeMap with an integer value.
         * @param value The integer value to compare against.
         * @return True if both x and y dimensions of the SizeMap are less than or equal to the value, otherwise false.
         */
        bool operator<=(int value) const {
            return this->x <= value && this->y <= value;
        }

        /**
         * @brief Greater than or equal to comparison operator for comparing a SizeMap with an integer value.
         * @param value The integer value to compare against.
         * @return True if both x and y dimensions of the SizeMap are greater than or equal to the value, otherwise false.
         */
        bool operator>=(int value) const {
            return this->x >= value && this->y >= value;
        }

        int x = 0; ///< The width of the map.
        int y = 0; ///< The height of the map.
    };

    /**
     * @brief The Symbol enum represents different symbols used in the game map.
     */
    enum Symbol {
        WALL = '#',  ///< The symbol for walls.
        SPACE = ' ', ///< The symbol for empty spaces.
        PLAYER = '*',///< The symbol for the player.
        APPLE = '0'  ///< The symbol for apples.
    };

    /**
     * @brief The Map class represents the game map and manages the world objects.
     */
    class Map final {
    private:
        using mapType = std::vector<std::vector<WorldObject>>; ///< The type for the 2D map grid.
    public:
        /**
         * @brief Default constructor. Creates an empty Map.
         */
        Map() = default;

        /**
         * @brief Constructor. Creates a Map with the given size.
         * @param sizeMap The size of the map as a SizeMap object.
         */
        explicit Map(const SizeMap &sizeMap);

        /**
         * @brief Default destructor.
         */
        ~Map() = default;

        /**
         * @brief Sets up the Map with the specified size.
         * @param sizeMap The size of the map as a SizeMap object.
         */
        void setup(const SizeMap &sizeMap);

        /**
         * @brief Initializes the world objects on the map.
         */
        void initWorldObjects();

        /**
         * @brief Initializes the Map.
         */
        void init();

        /**
         * @brief Updates the Map and checks for object changes.
         */
        void update();

        /**
         * @brief Draws the Map on the console.
         */
        void draw();

        /**
         * @brief Resets the specified object at the given position with a new object.
         * @param position The position to reset the object.
         * @param newObject The new WorldObject to set at the position.
         * @param personalCode The personal code associated with the object (optional).
         */
        void objectReset(const Position &position, const WorldObject &newObject, const std::string &personalCode);

        /**
         * @brief Gets the size of the map.
         * @return The SizeMap representing the size of the map.
         */
        inline SizeMap getSizeMap() {
            return this->sizeMap;
        }

        /**
         * @brief Sets the size of the map.
         * @param sizeMap The SizeMap representing the new size of the map.
         */
        inline void setSizeMap(const SizeMap &sizeMap) {
            this->sizeMap = sizeMap;
        }

        /**
         * @brief Gets the position of the object with the specified personal code.
         * @param personalCode The personal code of the object.
         * @return The Position of the object with the specified personal code.
         */
        inline Position getObjPosition(const std::string &personalCode) {
            return this->objects.find(personalCode).obj.getPosition();
        }

        /**
         * @brief Gets the WorldObject with the specified personal code.
         * @param personalCode The personal code of the object.
         * @return The WorldObject with the specified personal code.
         */
        inline WorldObject &getObject(const std::string &personalCode) {
            return this->objects.find(personalCode).obj;
        }

        /**
         * @brief Sets the color of the object with the specified personal code.
         * @param color The new color to set for the object.
         * @param personalCode The personal code of the object.
         */
        inline void setObjectColor(const Color &color, const std::string &personalCode) {
            this->objects.find(personalCode).obj.setColor(color);
        }

        /**
         * @brief Sets the symbol of the object with the specified personal code.
         * @param symbol The new symbol to set for the object.
         * @param personalCode The personal code of the object.
         */
        inline void setObjectSymbol(char symbol, const std::string &personalCode) {
            this->objects.find(personalCode).obj.setSymbol(symbol);
        }

        /**
         * @brief Gets a copy of the list of WorldObjects in the map.
         * @return A copy of the ObjectsList containing all the WorldObjects in the map.
         */
        inline ObjectsList getObjectsList() const {
            return this->objects;
        }

        /**
         * @brief A string constant representing the personal code for walls in the map.
         */
        inline static const std::string &wallCode = "0";

        /**
         * @brief A string constant representing the personal code for empty spaces in the map.
         */
        inline static const std::string &spaceCode = "1";

    private:
        /**
         * @brief Resize the game map grid to the specified size.
         * */
        void resize();

        /**
         * @brief Checks for changes in the world objects and updates their colors accordingly.
         * @details This function iterates through each cell in the map grid and updates the colors of the objects
         * based on their personal codes. This function is called during the update() method to ensure that the colors
         * of the objects are updated correctly for rendering on the console.
         */
        void checkObjectsChanges();

        /**
         * @brief Checks if the object at the specified position is a wall.
         * @param x The x-coordinate of the position to check.
         * @param y The y-coordinate of the position to check.
         * @return True if the object at the specified position is a wall, otherwise false.
         */
        bool isWall(unsigned int x, unsigned int y);

        /**
         * @brief Checks if the object at the specified position is an empty space.
         * @param x The x-coordinate of the position to check.
         * @param y The y-coordinate of the position to check.
         * @return True if the object at the specified position is an empty space, otherwise false.
         */
        bool isSpace(unsigned int x, unsigned int y);

        /**
         * @brief Changes the color of the wall at the specified position in the map.
         * @param x The x-coordinate of the position of the wall to change color.
         * @param y The y-coordinate of the position of the wall to change color.
         */
        void changeColorWall(unsigned int x, unsigned int y);

        /**
         * @brief Changes the color of all the objects at the specified position in the map.
         * @param x The x-coordinate of the position of the objects to change color.
         * @param y The y-coordinate of the position of the objects to change color.
         */
        void changeColorAllObjects(unsigned int x, unsigned int y);

        /**
         * @brief Changes the color of all the objects at the specified position in the map.
         * @param x The x-coordinate of the position of the objects to change color.
         * @param y The y-coordinate of the position of the objects to change color.
         */
        void changeColor(unsigned int x, unsigned int y);

        /**
         * @brief Initializes the wall objects along the left and right edges of the map.
         * @param y The y-coordinate of the edge where the wall objects are initialized.
         */
        void initLeftAndRightEdge(int y);

        /**
         * @brief Initializes the wall objects along the upper and lower edges of the map.
         * @param y The y-coordinate of the edge where the wall objects are initialized.
         */
        void initUpperAndLowerEdge(int y);

        /**
         * @brief Initializes a wall objects.
         */
        void initWall();

        /**
         * @brief Initializes a wall object at the specified position in the map.
         */
        void initWallUnit(const Position &position);

        /**
         * @brief Initializes empty space objects in the map.
         */
        void initSpace();

        /**
         * @brief Initializes empty space object in the map for a specific row.
         */
        void initSpaceUnit(int y);

    private:
        mapType map {};
        SizeMap sizeMap = SizeMap(5, 5);
        ObjectsList objects;
        std::vector<std::string> objectsCodes{};
    };
}