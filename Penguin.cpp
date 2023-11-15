//
// Created by igorz on 11/5/2023.
//

#include "Penguin.h"
#include "cmath"
//Penguin::Penguin(int color, int x, int y) {
//    this->penguinColor = color;
//    this->xCoordinate = x;
//    this->yCoordinate = y;
//    this->score = 0;
//}
//
//void Penguin::move(int newX, int newY) {
//    if(isValidMove(newX, newY)){
//        this->xCoordinate = newX;
//        this->yCoordinate = newY;
//    }
//}
//
//bool Penguin::isValidMove(int newX, int newY) const {
//    return abs(newX-xCoordinate) < 2 && abs(newY-yCoordinate) < 2;
//}
//
//void Penguin::collectFish(Tile &tile) {
//    this->score += tile.getFishCount();
//    tile.setFishCount(0);
//}