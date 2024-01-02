//
// Created by igor zab on 28/12/2023.
//
#include "File.h"

void writeGameState(GameBoard& game, int numPlayers){

    std::ofstream outFile("out.txt");

    if (!outFile) {
        std::cerr << "Error opening file: " << "out.txt" << std::endl;
        exit(1);
    }

    // Write the board size
    outFile << game.size << std::endl;

    // Write the board state

    //TODO: If a player steps on a tile, we remove it's fish. that way we don't remember the amount while encoding a file.
    for (int i = 0; i < game.size; ++i) {
        for (int j = 0; j < game.size; ++j) {
            int fishcount_converted = 0;
            if(game.tiles[i][j].fishCount == -1 || game.tiles[i][j].fishCount == -2){
                fishcount_converted = 0;
            }else {
                fishcount_converted = game.tiles[i][j].fishCount;
            }
            outFile << fishcount_converted << game.tiles[i][j].owningPlayer << " ";
        }
        outFile << std::endl;
    }

    for(int i = 0; i < numPlayers; i++){
        outFile << game.players[i].playerID << game.players[i].playerID << " " << game.players[i].score  << std::endl;
    }


    outFile << std::endl;

    outFile.close();

}

void readGameData(GameBoard* gameBoard, int numPlayers) {
    ifstream inFile("out.txt");
    if (!inFile) {
        std::cerr << "Error opening file: " << "out.txt" << std::endl;
        exit(1);
    }
    inFile >> gameBoard->size;
    cout << "\nsize: " << gameBoard->size << '\n';
    // Allocate memory for tiles
    gameBoard->tiles = (Tile **) malloc(gameBoard->size * sizeof(Tile *));

    for (int i = 0; i < gameBoard->size; i++) {
        gameBoard->tiles[i] = (Tile *) malloc(gameBoard->size * sizeof(Tile));
    }

    // Read the board state
    for (int i = 0; i < gameBoard->size; ++i) {
        for (int j = 0; j < gameBoard->size; ++j) {
            string recievedString;
            inFile >> recievedString;
            int converted_string = stoi(recievedString);
            int fishCount = floor(converted_string / 10);
            int owningPlayer = converted_string % 10;
            cout << "i: " << i << " j: " << j << " Parsed string: "<< " fishCount: " << fishCount << " Player: " << owningPlayer << '\n';
        }
    }

//    // Read player information
//    for(int i = 0; i < numPlayers; i++){
//        inFile >> gameBoard->players[i].playerID >> gameBoard->players[i].score;
//    }

    inFile.close();

}