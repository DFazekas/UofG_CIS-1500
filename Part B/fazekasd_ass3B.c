/**********************************************************
Programmed by: Devon Fazekas-Thomas
Date: Feb. 24, 2016
Purpose: To count the frequencies that each digit appears
         in a random text file, before the special phrase
         END appears as 3 consecutive characters.
***********************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 500


int fileInput (char randomText[MAX_LENGTH], int digFrequency[10]) {
    int i       = 0;
    int dataLen = 0;
    FILE *inFile;


    inFile = fopen ("data.txt", "r");

    /// Reports missing file.
    if (inFile == NULL) {
        perror("NO FILE!\n");
        return (-1);
    }

    /// Harvests file characters while counting digits, stopping upon SPECIAL sequence.
    while (fgets(randomText, MAX_LENGTH, inFile)) {
        dataLen = strlen(randomText);
        for (i = 0; i < dataLen; i++) {
            if (isdigit (randomText[i])) {
                digFrequency [randomText[i] - 48]++;
            }
            else if ( (randomText[i] == 'E') && (randomText[i+1] == 'N') && (randomText[i+2] == 'D') ) {
                return 0;
            }
        }
    }
    fclose(inFile);
    return 0;
}

void printDigits (int digFrequency[10]) {
    int i = 0;

    for (i = 0; i <= 9; i++) {
        printf ("Number of %d: %d\n", i, digFrequency[i]);
    }
}

int main () {
    char randomText[MAX_LENGTH];
    int digFrequency[10] = { 0 };

    /// Gets data from file.
    fileInput (randomText, digFrequency);

    /// Output frequencies.
    printDigits (digFrequency);

    printf ("\nPress ENTER to quit.");
    getchar ();
    return 0;
}
