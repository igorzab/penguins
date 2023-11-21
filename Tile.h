#pragma once
#ifndef PENGUINS2_TILE_H
#define PENGUINS2_TILE_H
struct Tile {
    int fishCount;
    int x;
    int y;
    int owningPlayer;
};

typedef struct Tile Tile;
#endif //PENGUINS2_TILE_H
