////
//// Created by igor zab on 28/12/2023.
////
#include "File.h"


void writeGameState(GameBoard *game, int numPlayers, char *name) {
    FILE *outFile = fopen(name, "w");

    if (!outFile) {
        perror("Error opening file: out.txt");
        exit(1);
    }

    // Write the board size
    fprintf(outFile, "%d\n", game->size);

    // Write the board state
    for (int i = 0; i < game->size; ++i) {
        for (int j = 0; j < game->size; ++j) {
            int fishcount_converted = (game->tiles[i][j].fishCount == -1 || game->tiles[i][j].fishCount == -2) ? 0
                                                                                                               : game->tiles[i][j].fishCount;
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

void readGameData(GameBoard *gameBoard, int *numPlayers, int *numPenguins, char *name) {
    FILE *inFile = fopen(name, "r");

    if (!inFile) {
        perror("Error opening file: out.txt");
        exit(1);
    }

    fscanf(inFile, "%d", &gameBoard->size);
    printf("\nsize: %d\n", gameBoard->size);

    // Allocate memory for tiles
    gameBoard->tiles = (Tile **) malloc(gameBoard->size * sizeof(Tile *));
    for (int i = 0; i < gameBoard->size; i++) {
        gameBoard->tiles[i] = (Tile *) malloc(gameBoard->size * sizeof(Tile));
    }

    // Read the board state
    for (int i = 0; i < gameBoard->size; ++i) {
        for (int j = 0; j < gameBoard->size; ++j) {
            int converted_string;
            fscanf(inFile, "%d", &converted_string);
            int fishCount = converted_string / 10;
            int owningPlayer = converted_string % 10;
            if(owningPlayer > 0){
                fishCount = -2;
            }
            gameBoard->tiles[i][j] = Tile{fishCount, j, i, owningPlayer};
            printf("i: %d j: %d Parsed string: %d fishCount: %d Player: %d\n", i, j, converted_string, gameBoard->tiles[i][j].fishCount,
                   gameBoard->tiles[i][j].owningPlayer);
        }
    }
//    fscanf(inFile, "\n");
    for(int i = 0; i < *numPlayers; i++){
        fscanf(inFile, "%d%d %d\n", &gameBoard->players[i].playerID,&gameBoard->players[i].playerID, &gameBoard->players[i].score);
        printf("parsed player with index: %d, id: %d, score: %d\n", i, gameBoard->players[i].playerID, gameBoard->players[i].score);
    }

    for (int i = 0; i < gameBoard->size; ++i) {
        for (int j = 0; j < gameBoard->size; ++j) {
            printf("parsing penguins, i: %d j: %d\n", i,j);
            int playerIndex = gameBoard->tiles[i][j].owningPlayer - 1;
            if (playerIndex > -1) {
                printf("found tile with playerId: %d\n", playerIndex);
                for (int k = 0; k < *numPenguins; k++) {
                    printf("i'm in a loop: %d\n", k);
                    if (gameBoard->players[playerIndex].penguins[k].x == 255) {
                        printf("found blank penguin: %d\n", k);
                        gameBoard->players[playerIndex].penguins[k].isActive = 1;
                        gameBoard->players[playerIndex].penguins[k].x = i;
                        gameBoard->players[playerIndex].penguins[k].y = j;
                        gameBoard->players[playerIndex].penguins[k].playerID = playerIndex + 1;
                        break;
                    }
                }
            }
        }
    }

    fclose(inFile);
}
