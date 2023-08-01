/**
 * @file
 * @brief This file contains the declaration of the CGB::ObjectsList class.
 */

#pragma once

#include "WorldObject.h"
#include <string>
#include <vector>

namespace CGB {
    /**
     * @brief The ObjectsList class represents a list of objects in the game world.
     */
    class ObjectsList final {
    public:
        /**
         * @brief The Object struct represents an object in the ObjectsList.
         */
        struct Object {
            /**
             * @brief Default constructor. Creates an Object with default values.
             */
            Object() = default;

            /**
             * @brief Constructor. Creates an Object with the given WorldObject and personal code.
             * @param obj The WorldObject to store in the Object.
             * @param personalCode The personal code associated with the object (default is an empty string).
             */
            Object(const WorldObject& obj, const std::string &personalCode)
                    : obj(obj), personalCode(personalCode) {}

            /**
             * @brief Copy assignment operator for the Object struct.
             * @param other The other Object to copy from.
             * @return A reference to this Object after assignment.
             */
            Object& operator=(const Object& other);

            WorldObject obj;         ///< The WorldObject stored in the Object.
            std::string personalCode;///< The personal code associated with the Object (optional).
        };

        /**
         * @brief Default constructor. Creates an empty ObjectsList.
         */
        ObjectsList() = default;

        /**
         * @brief Default destructor.
         */
        ~ObjectsList() = default;

        /**
         * @brief Finds an Object with the specified personal code in the ObjectsList.
         * @param personalCode The personal code to search for.
         * @return A reference to the Object with the matching personal code.
         * @throw std::exception If no Object with the specified personal code is found.
         */
        Object& find(const std::string& personalCode);

        /**
         * @brief Resets the Object at the specified position in the ObjectsList.
         * @param where The Position where the Object should be reset.
         * @param what The WorldObject to set at the specified position.
         * @param personalCode The personal code to set for the Object (optional).
         */
        void reset(const Position &where, const WorldObject &what, const std::string &personalCode);

        /**
         * @brief Overloaded subscript operator to access Objects in the ObjectsList by index.
         * @param index The index of the Object to access.
         * @return A reference to the Object at the specified index.
         */
        Object& operator[](unsigned int index);

        /**
         * @brief Accesses an Object in the ObjectsList at the specified index.
         * @param index The index of the Object to access.
         * @return A reference to the Object at the specified index.
         * @throw std::out_of_range If the index is out of range.
         */
        Object& at(unsigned int index);

        /**
         * @brief Returns an iterator pointing to the last element in the vector of objects
         * @return An iterator pointing to the last element in the vector.
         */
        inline std::vector<Object>::iterator end() {
            return objects.end();
        }

        /**
         * @brief Returns an iterator pointing to the first element in the vector of objects
         * @return An iterator pointing to the first element in the vector.
         */
        inline std::vector<Object>::iterator begin() {
            return objects.begin();
        }

        /**
         * @brief Checks if the ObjectsList is empty.
         * @return True if the ObjectsList is empty, otherwise false.
         */
        bool empty();

        /**
         * @brief Gets the number of Objects in the ObjectsList.
         * @return The number of Objects in the ObjectsList.
         */
        unsigned int size();

        /**
         * @brief Resizes the ObjectsList to the specified size.
         * @param size The new size of the ObjectsList.
         * @throw std::exception If the new size is smaller than the current size.
         */
        void resize(unsigned int size);

        /**
         * @brief Gets a reference to the first Object in the ObjectsList.
         * @return A reference to the first Object.
         */
        Object& front();

        /**
         * @brief Gets a reference to the last Object in the ObjectsList.
         * @return A reference to the last Object.
         */
        Object& back();

        /**
         * @brief Adds an Object to the end of the ObjectsList using emplace_back.
         * @param worldObj The WorldObject to add to the ObjectsList.
         * @param personalCode The personal code associated with the Object (optional).
         */
        void emplace_back(const WorldObject &worldObj, const std::string &personalCode);

        /**
         * @brief Adds an Object to the end of the ObjectsList using push_back.
         * @param worldObj The WorldObject to add to the ObjectsList.
         * @param personalCode The personal code associated with the Object (optional).
         */
        void push_back(const WorldObject &worldObj, const std::string &personalCode);

        /**
         * @brief Removes the last Object from the ObjectsList.
         */
        void pop_back();

    private:
        std::vector<Object> objects; ///< The vector that holds the Object instances.
    };
}