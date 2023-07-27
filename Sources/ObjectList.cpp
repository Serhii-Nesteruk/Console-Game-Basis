#include "../Headers/ObjectList.h"

void CGB::ObjectsList::emplace_back(const WorldObject &worldObj, const std::string &personalCode) {
    Object object;
    object.obj = worldObj;
    object.personalCode = personalCode;

    objects.emplace_back(object);
}

void CGB::ObjectsList::push_back(const WorldObject &worldObj, const std::string &personalCode) {
    Object object;
    object.obj = worldObj;
    object.personalCode = personalCode;

    objects.push_back(object);
}

void CGB::ObjectsList::pop_back() {
    objects.pop_back();
}

CGB::ObjectsList::Object &CGB::ObjectsList::operator[](unsigned int index) {
    return objects[index];
}

CGB::ObjectsList::Object &CGB::ObjectsList::at(unsigned int index) {
    return objects.at(index);
}

bool CGB::ObjectsList::empty() {
    return objects.empty();
}

unsigned int CGB::ObjectsList::size() {
    return objects.size();
}

void CGB::ObjectsList::resize(unsigned int size) {
    if (size < objects.size())
        throw std::exception("Error:ObjectList: the new size is smaller");
    objects.resize(size);
}

CGB::ObjectsList::Object &CGB::ObjectsList::front() {
    return objects.front();
}

CGB::ObjectsList::Object &CGB::ObjectsList::back() {
    return objects.back();
}

CGB::ObjectsList::Object &CGB::ObjectsList::find(const std::string &personalCode) {
    for (auto &obj: objects)
        if (obj.personalCode == personalCode)
            return obj;
    throw std::exception("Error: ObjectsList: object not found!");
}