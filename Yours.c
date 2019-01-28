/***************************************************************************************

****************************************************************************************/

#include <stdio.h>
#include <string.h>

typedef struct player_struct {
    char firstName[11];
    char lastName[11];
    float data[8];
    char FAN[6];
} data;


int ReadFile(data player[], int *playerNum){
    FILE *inputFile = fopen("nba.txt", "r");
    char temp[10];
    int x;

    // MAKES SURE THERE IS A FILE TO READ:
    if (inputFile == NULL){
        printf("NO FILE FOUND");
        return (-1);
    }

    // STORE REDUNDANT INFORMATION:
    fscanf(inputFile, "%s %s %s %s %s %s", temp, temp, temp, temp, temp, temp);
    //printf("%s %s %s %s %s %s", temp, temp, temp, temp, temp, temp);

    // COLLECTS PLAYER DATA AND PLAYER NUMBER:
    while (!feof(inputFile)){
       fscanf(inputFile, "%s %s %f %f %f %f %f", player[x].firstName, player[x].lastName, &player[x].data[1], &player[x].data[2], &player[x].data[3], &player[x].data[4], &player[x].data[5]);
       //printf("(%d) %s %s %.1f %.1f %.1f %.1f %.1f\n", x, player[x].firstName, player[x].lastName, player[x].data[1], player[x].data[2], player[x].data[3], player[x].data[4], player[x].data[5]);
       x++;
    }
    *playerNum = x;

    fclose(inputFile);
    return 0;
}
void FANCalc(data player[], int playerNum) {
    int x;

    // CALCULATES THE VALUE OF FAN
    for (x = 0; x < playerNum; x++) {
        player[x].data[0] = 0.005 + player[x].data[1] + (1.5 * player[x].data[2]) + (1.5 * player[x].data[3]) + (3 * player[x].data[4]) + (2 * player[x].data[5]);
        //printf("%s %.1f\n", player[x].firstName, player[x].data[0]);
    }
    return;
}
void ConvertToString(data player[], int playerNum) {
    int x;

    // CONVERTS TO STRING:
    for (x = 0; x < playerNum; x++) {
        sprintf(player[x].FAN, "%.1f", player[x].data[0]);
        //puts(player[x].FAN);
    }
}
void Sorting (data player[], int playerNum) {

    int i;
    int z;
    int maxNum;
    int compare;
    data temp;

    // PUTS FAN SCORES IN ORDER:
    for (i = 0; i < playerNum; i++){
        maxNum = i;
        for (z = (i + 1); z < playerNum; z++) {
            compare = strcmp(player[maxNum].FAN, player[z].FAN);
            if (compare < 0) {
                maxNum = z;
            }
        }
        temp = player[maxNum];
        player[maxNum] = player[i];
        player[i] = temp;
    }


    return;
}
void PrintFunction (data player[], int playerNum) {

    int x;
    char fullName[23];
    int order;
    int rank;

    // PRINTS RESULTS:
    printf("        Player                FAN   PST    REB   AST   STL   BLK\n");
    printf("================================================================\n");
    for (x = 0; x < playerNum; x++) {
        if (strcmp(player[x].FAN, player[x-1].FAN) != 0){
            rank = (x + 1);
        }

        sprintf(fullName, "%s, %s", player[x].lastName, player[x].firstName);
        printf("  %-2d %-23s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f \n", rank, fullName, player[x].data[0], player[x].data[1], player[x].data[2], player[x].data[3], player[x].data[4], player[x].data[5]);
    }
    return;
}
int main (void){
    data player [1000];
    int playerNum = 0;


    ReadFile(player, &playerNum);
    FANCalc(player, playerNum);
    ConvertToString(player, playerNum);
    Sorting (player, playerNum);
    PrintFunction (player, playerNum);

    //printf("%d\n", playerNum);

    getchar();
    return 0;
}
