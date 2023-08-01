cmake_minimum_required(VERSION 3.25)
project(CGB)

set(CMAKE_CXX_STANDARD 20)

add_executable(CGB
        Sources/main.cpp
        Sources/Map.cpp
        Headers/Map.h
        Sources/WorldObject.cpp
        Headers/WorldObject.h
        Headers/Position.h
        Sources/ObjectList.cpp
        Headers/ObjectList.h
        Headers/Color.h
        Sources/Control.cpp
        Headers/Control.h
)

include_directories(CGB PUBLIC
        Headers/Control.h
)
