cmake_minimum_required(VERSION 3.25)
project(CGB)

set(CMAKE_CXX_STANDARD 20)

add_executable(CGB
        Sources/main.cpp
        Sources/Map.cpp
        Sources/WorldObject.cpp
        Sources/ObjectList.cpp
        Sources/Control.cpp
)

include_directories(CGB PUBLIC
        Headers/
)
