/***************************************************************************************
Programmed by: Devon A. Fazekas-Thomas
Date:          April 6, 2016.
Purpose:       To read data from file, compute a new statistic, reorder data based on
                 results, and print with specified formatting.
****************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLAYERS 1000
#define CHAR_PER_LINE 100
#define NUM_STATS 6
#define NAME_LEN 12
#define ROUND_ERROR 0.005

enum statType {
    FAN,
    PPG,
    REB,
    AST,
    STL,
    BLK,
};
typedef struct data_struct {
    char  Name[22];
    float data[8];
    int   order;
    char  charFAN[CHAR_PER_LINE];
} data;

int  ParseFileData (data allPlayers[], int *playerCount);
void ComputeFAN    (data allPlayers[], int playerCount);
void FANToString   (data allPlayers[], int playerCount);
void SortData      (data allPlayers[], int playerCount);
void PrintData     (data allPlayers[], int playerCount);


int  main          (void){
    data allPlayers[NUM_PLAYERS];
    int playerCount = 0;

    if (ParseFileData (allPlayers, &playerCount) == 0){
        ComputeFAN    (allPlayers, playerCount);
        FANToString   (allPlayers, playerCount);
        SortData      (allPlayers, playerCount);
        PrintData     (allPlayers, playerCount);
    }

    printf("\nPROGRAM ENDED. Press ENTER to QUIT.");
    getchar();
    return 0;
}
int  ParseFileData (data allPlayers[], int *playerCount){
    char firstName[NAME_LEN],    lastName[NAME_LEN],    fileLine[CHAR_PER_LINE];
    int numLen,    j,    k;
    FILE *inputFile;

    // OPENING-FILE VALIDATION:
    inputFile = fopen("nba.txt", "r");
    if (inputFile == NULL) {
        printf("FILE NOT FOUND!\n");
        return (-1);
    }

    // VALIDATES FOR AND REMOVES TITLES FROM DATA:
    fgets(fileLine, CHAR_PER_LINE, inputFile);
    if (fileLine[0] == '\n') {
        printf("NO DATA TITLES!\n");
        return (-1);
    }

    // PARSE PLAYER INFO:
    while (fgets(fileLine, CHAR_PER_LINE, inputFile) != NULL) {

        // STORE PLAYER'S NAME & COUNT # OF PLAYERS:
        sscanf(fileLine, "%s %s", firstName, lastName);

        // VALIDATES MISSING/INVALID PLAYER NAMES:
        if (!(isalpha(firstName[0]) && isalpha(lastName[0]))){
            printf("Player #%d's name \"%s, %s\" is invalid!\n", *playerCount, firstName, lastName);
            return (-1);
        }
        sprintf(allPlayers[*playerCount].Name, "%s, %s", lastName, firstName);

        // STORE PLAYER'S STATS:
        strcpy(fileLine, (fileLine + strlen(allPlayers[*playerCount].Name)));
        for (j = 1, numLen = 0; j <= (NUM_STATS - 1); j++){

            // COMPUTE LENGTH OF DIGITS:
            for (k = 0; fileLine[k] != ' '; k++) {
                numLen++;
            }

            // STORE STATISTIC; TRUNCATE REMAINING STRING
            sscanf(fileLine, "%f", &allPlayers[*playerCount].data[j]);
            strcpy(fileLine, fileLine + numLen + 1);
            numLen = 0;
        }
        // COUNT QUANTITY OF PLAYERS:
        *playerCount += 1;
    }
    // CLOSE FILE:
    fclose(inputFile);
    return 0;
}
void ComputeFAN    (data allPlayers[], int playerCount){
    float temp;
    int j;

    // COMPUTE FAN:
    for (j = 0; j < playerCount; j++){
        temp = allPlayers[j].data[PPG] + (1.5 * allPlayers[j].data[REB]) + (1.5 * allPlayers[j].data[AST]);
        allPlayers[j].data[FAN] =  ROUND_ERROR + temp + (3 * allPlayers[j].data[STL]) + (2 * allPlayers[j].data[BLK]);
    }
    return;
}
void FANToString   (data allPlayers[], int playerCount){
    int j;

    // DUPLICATE & CONVERT FAN - FLOAT TO STRING:
    for (j = 0; j < playerCount; j++) {
        sprintf(allPlayers[j].charFAN, "%.1f", allPlayers[j].data[0]);
    }
    return;
}
void SortData      (data allPlayers[], int playerCount){
    int j,    i,    sizeDiff,    tempSize,    tempOrder,    largestFAN;

    // REORGANIZE DATA:
    for (j = 0; j < playerCount; j++){

        // DETERMINE LARGEST VALUE:
        largestFAN = j;
        for (i = (j + 1); i < playerCount; i++){
            sizeDiff = strcmp(allPlayers[largestFAN].charFAN, allPlayers[i].charFAN);

            // COMPARE CURRENT VALUE TO LARGEST VALUE:
            if (sizeDiff < 0){
                largestFAN = i;
            }
        }

        // IF LARGEST VALUE CHANGES, SWAP THEM:
        if (largestFAN != j){
            data strTemp           = allPlayers[j];
            allPlayers[j]          = allPlayers[largestFAN];
            allPlayers[largestFAN] = strTemp;
        }
    }

    // RESET ORDERS, ACCOUNTING FOR TIES:
    for (j = 0; j < NUM_PLAYERS; j++){
        if (j == 0){
            allPlayers[j].order = (j + 1);
        } else{
            tempSize = strcmp(allPlayers[j-1].charFAN, allPlayers[j].charFAN);
            if (tempSize != 0){
                tempOrder = (j + 1);
                allPlayers[j].order = (j + 1);
            } else {
                allPlayers[j].order = tempOrder;
            }
        }
    }
    return;
}
void PrintData     (data allPlayers[], int playerCount){
    int j, k;

    // PRINT DATA TITLES:
    printf("%9s %17s %5s %5s %5s %5s %5s\n", "Player", "FAN", "PTS", "REB", "AST", "STL", "BLK");
    printf("=========================================================\n");

    // PRINT REORDERED FILE DATA:
    for (j = 0; j < playerCount; j++){
        printf("%2d %-18s ", allPlayers[j].order, allPlayers[j].Name);
        for (k = 0; k < NUM_STATS; k++){
            printf("%5.1f ", allPlayers[j].data[k]);
        }
        printf("\n");
    }
    return;
}
