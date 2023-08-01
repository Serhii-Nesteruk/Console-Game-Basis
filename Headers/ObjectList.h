#pragma once

#include "WorldObject.h"

#include <string>
#include <vector>

namespace CGB {
    class ObjectsList final {
    public:
        struct Object {
            Object() = default;
            Object(const WorldObject& obj, const std::string &personalCode)//TODO: use std::move
                : obj(obj), personalCode(personalCode) {}
            Object& operator=(const Object& other);

            WorldObject obj;
            std::string personalCode {};
        };

        ObjectsList() = default;
        ~ObjectsList() = default;

        Object& find(const std::string& personalCode);
        void reset(const Position &where, const WorldObject &what, const std::string &personalCode);

        Object& operator[](unsigned int index);
        bool empty();
        unsigned int size();
        Object& front();
        Object& back();
        void resize(unsigned int size);
        Object &at(unsigned int index);

        void emplace_back(const WorldObject &worldObj, const std::string &personalCode);
        void push_back(const WorldObject &worldObj, const std::string &personalCode);

        void pop_back();
    private:
        std::vector<Object> objects {};
    };
}