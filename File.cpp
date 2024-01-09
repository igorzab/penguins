////
//// Created by igor zab on 28/12/2023.
////
#include "File.h"



void writeGameState(GameBoard* game, int numPlayers) {
    FILE* outFile = fopen("out.txt", "w");

    if (!outFile) {
        perror("Error opening file: out.txt");
        exit(1);
    }

    // Write the board size
    fprintf(outFile, "%d\n", game->size);

    // Write the board state
    for (int i = 0; i < game->size; ++i) {
        for (int j = 0; j < game->size; ++j) {
            int fishcount_converted = (game->tiles[i][j].fishCount == -1 || game->tiles[i][j].fishCount == -2) ? 0 : game->tiles[i][j].fishCount;
            fprintf(outFile, "%d%d ", fishcount_converted, game->tiles[i][j].owningPlayer);
        }
        fprintf(outFile, "\n");
    }

    // Assuming Player structure (not provided in the original code)
    // You might need to loop through players and write their information
    for (int i = 0; i < numPlayers; i++) {
        fprintf(outFile, "%d%d %d \n", game->players[i].playerID, game->players[i].playerID, game->players[i].score);
    }

    fclose(outFile);
}

void readGameData(GameBoard* gameBoard, int numPlayers) {
    FILE* inFile = fopen("out.txt", "r");

    if (!inFile) {
        perror("Error opening file: out.txt");
        exit(1);
    }

    fscanf(inFile, "%d", &gameBoard->size);
    printf("\nsize: %d\n", gameBoard->size);

    // Allocate memory for tiles
    gameBoard->tiles = (Tile**)malloc(gameBoard->size * sizeof(Tile*));
    for (int i = 0; i < gameBoard->size; i++) {
        gameBoard->tiles[i] = (Tile*)malloc(gameBoard->size * sizeof(Tile));
    }

    // Read the board state
    for (int i = 0; i < gameBoard->size; ++i) {
        for (int j = 0; j < gameBoard->size; ++j) {
            int converted_string;
            fscanf(inFile, "%d", &converted_string);
            int fishCount = converted_string / 10;
            int owningPlayer = converted_string % 10;
            printf("i: %d j: %d Parsed string: %d fishCount: %d Player: %d\n", i, j, converted_string, fishCount, owningPlayer);
        }
    }

    // Assuming Player structure (not provided in the original code)
    // You might need to loop through players and read their information
    // fscanf(inFile, "%d%d %d\n", &gameBoard->players[i].playerID, &gameBoard->players[i].playerID, &gameBoard->players[i].score);

    fclose(inFile);
}
