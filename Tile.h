#pragma once
#ifndef PENGUINS2_TILE_H
#define PENGUINS2_TILE_H

/**
 * @struct Tile
 * @brief Represents a tile on the game board.
 *
 * The Tile structure holds information about a game tile, including the number of fish on the tile,
 * its coordinates on the game board, and the player ID who owns the tile (if applicable).
 */
struct Tile {
    int fishCount;
    int x;
    int y;
    int owningPlayer;
};

typedef struct Tile Tile;
#endif //PENGUINS2_TILE_H
