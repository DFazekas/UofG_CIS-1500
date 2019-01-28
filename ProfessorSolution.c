//-----------------------------------------------------------
// Programmed by Joe Sawada for CIS 1500
// Assignment 5: Read in NBA player data and output sorted
// by FAN statistic
//-----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
//--------------------------------------------------
void Swap(int i, int j, int a[]) {
    int temp = a[i];
    a[i] =a[j];
    a[j] =temp;
}
void SwapString(int i, int j, char w[][6]) {
    char temp[15];
    
    strcpy(temp, w[i]);
    strcpy(w[i], w[j]);
    strcpy(w[j], temp);
}
void BubbleSort(int n, char w[][6], int sorted_index[]) {
    int i, j;
    
    for (i=1; i<n; i++) {
        for (j=0; j<n-i; j++) {
            if (strcmp(w[j+1], w[j]) > 0) {
                SwapString(j,j+1,w);
                Swap(j,j+1, sorted_index);
            }
        }
    }
}
//----------------------------------------------------------
int main(int argc, char *argv[]) {
    
    FILE *input_file;
    char name[40], h[7][10], first[MAX][11], last[MAX][11], fan[MAX][6];
    int i, j, rank, num_players, sorted_index[MAX];
    float ppg[MAX], reb[MAX], ast[MAX], stl[MAX], block[MAX];
    
    //----------------------
    // READ IN PLAYER DATA
    //----------------------
    input_file = fopen("nba_short.txt","r");
    
    // Reader the header data
    fscanf(input_file, "%s %s %s %s %s %s", h[0], h[1], h[2], h[3], h[4], h[5]);
    
    // Read the player data line by line until no data left
    i = 0;
    while ( fscanf(input_file, "%s %s %f %f %f %f %f", first[i], last[i], &ppg[i], &reb[i], &ast[i], &stl[i], &block[i]) == 7 ) i++;
    num_players = i;
    
    fclose(input_file);
    
    //--------------------------------------------------------------
    // COMPUTE FAN STATISTIC (adding 0.01 to handle rounding issues)
    //--------------------------------------------------------------
    for (i=0; i< num_players; i++) sprintf(fan[i], "%.1lf", (float) ppg[i] + 1.5*reb[i] + 1.5*ast[i] + 3*stl[i] + 2*block[i] + 0.01);
    
    //-----------------------------------------------
    // SORT FAN -- ALSO SORTING THE INDEX
    //-----------------------------------------------
    for (i=0; i< num_players; i++) sorted_index[i] = i;
    BubbleSort(num_players, fan, sorted_index);
    
    //-----------------------------
    // OUTPUT PLAYERS SORTED BY PPG
    //-----------------------------
    printf("    %-22s  FAN   %3s  %3s  %3s  %3s  %3s \n", h[0], h[1], h[2], h[3], h[4], h[5]);
    for (i=0; i<57; i++) printf("=");
    printf("\n");
    
    for (i=0; i< num_players; i++) {
        j = sorted_index[i];
        sprintf(name, "%s, %s", last[j], first[j]);
        
        // Update the current rank
        if (i == 0) rank = 1;
        else if (strcmp(fan[i], fan[i-1]) < 0) rank = i+1;
        
        printf("%3d %-22s %-5s %4.1f %4.1f %4.1f %4.1f %4.1f\n", rank, name, fan[i], ppg[j], reb[j], ast[j], stl[j], block[j]);
    }
}
