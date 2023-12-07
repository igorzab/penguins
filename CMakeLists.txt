cmake_minimum_required(VERSION 3.26)
project(penguins2)

set(CMAKE_CXX_STANDARD 17)

include_directories(C:/libs/SFML/include)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake_modules)

set(SFML_ROOT C:/libs/SFML)

find_package(SFML REQUIRED system window graphics audio network)
add_executable(penguins2 main.cpp
        Tile.cpp
        Tile.h
        Penguin.h
        GameBoard.cpp
        GameBoard.h
        Game.cpp
        Game.h
        Penguin.c
        Player.c
        Player.h
        Colors.h
        Menu.h
        Menu.cpp
)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(penguins2 ${SFML_LIBRARIES})
