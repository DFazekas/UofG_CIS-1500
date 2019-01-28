/****************************************************
Date: February 11, 2016.

fazekasd_ass2.c must be compiled using the following flags:
	-lm -std=c99

The following piece of code was used to get a character from this user without pressing ENTER:
        system("/bin/stty raw");
        system("/bin/stty cooked");
username: udondan
*****************************************************/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 150
#define MAX_ENTRIES 100
#define TRUE 1

int userInput ();
void Calculations ();


int main () {
    char repeat = '0';

    while (TRUE) {
        system ("@cls||clear");
        userInput();
        printf ("\n\n");

        printf ("Press any key to continue, or 'q' to quit. ");
        system ("/bin/stty raw"); // Stack Overflow.
        repeat = getchar();
        system ("/bin/stty cooked"); // Stack Overflow.
		printf ("\n");

        if ( (repeat == 'q') || (repeat == 'Q') )
			break;
    }

    return 0;
}

int userInput () {
    char   userLine    [MAX_CHAR];
    char   userNumbers [MAX_ENTRIES][MAX_CHAR];
    int    i = 0;
    int    k = 0;
    int    j = 0;
    int    cmArray     [MAX_ENTRIES];
    double inchArray   [MAX_ENTRIES];

    /// Gets annual rainfall(s) [in cm].
    printf ("On a single line, enter, as integers, the annual rainfall(s) chronologically, separated by any means.\n");
    printf ("\tEx: (1 2.3/4n5%%6jj7) = (1 2 3 4 5 6 7)\n");
    printf ("Data: ");
    fgets (userLine, MAX_CHAR, stdin);
    printf("\n");

    /// Extrapolates numeric values from user's singular input.
    while (i < strlen (userLine)) {

        /// Stitches consecutive digits, forming numeric fragments.
        while (isdigit (userLine [i])) {
           userNumbers [k][j] = userLine [i];
           j++;
           i++;
        }

        userNumbers [k][j] = '\0';

        /// Starts new fragment, if needed.
        if (isdigit (userLine [i - 1])) {
            k++;
        }

        i++;
        j = 0;
    }

    /// Converts char fragments to int & double fragments.
    for (i = 0; i < k; i++) {
        cmArray [i] = atoi (userNumbers [i]);
        inchArray [i] = 0.3937 * (double)cmArray [i];
    }

    /// Sends refined input for computations.
    Calculations (inchArray, k);

    return 0;
}


void Calculations (double inchArray[], int arrayLen) {
    int    i           = 0;
    int    j           = 0;
    double avgRain     = 0.0;
    double stdRain     = 0.0;
    int    globWarming = 0;

    /// Detects strictly increasing/decreasing sequences, and computes average annual rainfall.
    for (i = 0; i < arrayLen; i++) {
        if ( (arrayLen > 1) && (i > 0) && (i < arrayLen - 1) ) {
            if ( ( (inchArray [i - 1] < inchArray [i]) && (inchArray [i] < inchArray [i + 1]) ) || ( (inchArray [i - 1] > inchArray [i]) && (inchArray [i] > inchArray [i + 1]))) {
                globWarming += 0;
            }

            else {
                globWarming = 1;
            }
        }

        if (arrayLen <= 1) {
        	globWarming = 1;
        }

        /// Computes the average annual rainfall.
        avgRain += inchArray [i];

        if (i == (arrayLen - 1)) {
        	(avgRain /= arrayLen);
        }
    }

    /// Computes standard deviation of rainfall.
    for (i = 0; i < arrayLen; i++) {
        stdRain += pow(inchArray [i] - avgRain, 2);

        if (i == (arrayLen - 1)) {
            stdRain = sqrt(0.2 * stdRain);
        }
    }

    for (i = (2016 - arrayLen), j = 0; i < 2016; i++, j++) {
        printf ("\tIn %d, there was %.1f inches of rainfall.\n", i, inchArray [j]);
    }

    printf ("\n\tThe average rainfall was %0.2f inches, with standard deviation %0.2f. ", avgRain, stdRain);

    if (globWarming == 0) {
    	printf ("\n\tBarrack - global warming is for real!\n");
    }

    else {
    	printf ("\n");
    }
}
