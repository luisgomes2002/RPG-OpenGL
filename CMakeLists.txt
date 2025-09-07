cmake_minimum_required(VERSION 3.10)

project(Game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
include_directories(dependencies)

add_executable(game
    src/Chest.cpp
    src/Inventory.cpp
    src/Item.cpp
    src/main.cpp
    src/Map.cpp
    src/Object.cpp
    src/Player.cpp
)