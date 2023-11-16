//
// Created by Tpshck on 11/16/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Penguin.h"


void setPenguinID(int ID) {
    penguinID = ID;
}

int getPenguinID() {
    return penguinID;
};


void setAmountOfPenguins() {
    int pengus;
        printf("Please, input the amount of penguins (at least 1, max 3): ");
        pengus = fixscanf();
        while (pengus < 1 || pengus > 3) {
            printf("ERROR: incorrect penguins amount. Please, type it again (at least 1, max 3): ");
            pengus = fixscanf();
        }
        amountOfPenguins = pengus;
    };