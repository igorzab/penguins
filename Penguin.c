#include <stdio.h>
#include "Penguin.h"


void setActivePenguin(struct Penguin *penguin, int active) {
    penguin->isActive = active;
}