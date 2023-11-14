#ifndef PENGUINS2_COLORS_H
#define PENGUINS2_COLORS_H

#endif //PENGUINS2_COLORS_H

#pragma once
#define LIGHT_GRAY 7
#define LIGHT_GREEN 10
#define LIGHT_RED 12

enum PlayerColor{
    NO_COLOR = -1,
    BLUE = 0,
    RED = 1,
    CYAN = 2,
    MAGENTA = 3,
    YELLOW = 4
};

void setColor(int color);
enum PlayerColor getPlayerColor(void);
void initColorsList(void);
int fixscanf(void);