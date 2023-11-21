#pragma once
//
// Created by igorz on 11/5/2023.
//

#ifndef PENGUINS2_PENGUIN_H
#define PENGUINS2_PENGUIN_H

struct Penguin {
    int isActive; // Flag to indicate is penguin active 0;1
    int playerID; //ID of player who has penguin
    int x;
    int y;
};

void setActivePenguin(struct Penguin *penguin, int active);

#endif // PENGUINS2_PENGUIN_H
