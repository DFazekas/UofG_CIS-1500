/*
	This program ...

	Author: Laxmi Aryal
	Date: March 20, 2016
 */

#include <stdio.h>
#include <stdlib.h>
/** You're not using this library. **/ /// #include <ctype.h>

float grades [1001][101];

/** Include average array, by passing by reference. **/ /// void PrintData(int numStudents, int numAssignments);
/*NEW*/ void PrintData(int numStudents, int numAssignments, float *average);
/** You shouldn't make an entire function a pointer. **/ /// float *CalculateAverage(int numStudents, int numAssignments);
/*NEW*/ /** Include average array. **/ void CalculateAverage(int numStudents, int numAssignments, float *average);

int main (int argc, char *argv[]) {
    FILE *inputFile;
    int i = 0;
    int j = 0;
    int numStudents = 0;
    int numAssignments = 0;
    /** We're not taught static, so don't use it. Also, it doesn't need a pointer here. **/ /// static float *average[101];
    /*NEW*/ float average[101] = {0.0};

    /*NEW*/ if (argc != 3) {
        /*NEW*/ printf("usage: ./a.out num_students num_assignments\n");
        /** Returning 0 means no error. -1 means error **/ /// return(0);
        /*NEW*/ return -1;
    /*NEW*/ }

    /** You should validate the command line before opening the file. I fixed it for you. **/
    // Open the files for reading
    inputFile = fopen("grades.txt", "r");

    /** MOVED, line 26 **/ // Varifying the number of command line arguments
    /** MOVED **/ /// if (argc != 3) {
        /** MOVED **/ /// printf("usage: ./a.out num_students num_assignments\n");
        /** MOVED **/ /// return(0);
    /** MOVED **/ /// }

    /** This else isn't needed. Program either ends before this or does this regardless. **/ /// else {

        numStudents = atoi(argv[1]);
        numAssignments = atoi(argv[2]);
    /// }

    // Storing Data
    for (i = 1; i <= numStudents; ++i) {
        for (j = 1; j <= numAssignments; ++j) {
            fscanf(inputFile, "%f,", &grades[i][j]);
        }
    }
/** Why are you printing data before you've even calculated all of it, such as averages? This should be last, no? **/
    /** Send averages to print. But this is still a poor placement. **/ /// PrintData(numStudents, numAssignments);
    /*NEW*/ PrintData(numStudents, numAssignments, average);

    // Find Average
    for (i = 1; i <= numAssignments; ++i) {
        /** You can't return arrays. Pass by reference. **/ /// average[i] = CalculateAverage(numStudents, numAssignments);
        /*NEW*/ CalculateAverage(numStudents, numAssignments, average);
    }

    for (i = 1; i <= numAssignments; ++i) {
        printf("=============\n");
        printf("Ass # %d stats\n", i);
        printf("=============\n");

        printf("avg = %.1f\n", average[i]);
    }

    // Close the file
    fclose(inputFile);

    return(0);
}

/** You will need to print the averages, but you didn't include it here. **/ /// void PrintData(int numStudents, int numAssignments) {
void PrintData(int numStudents, int numAssignments, float *average) {
    int i, j;

    printf("==================================\n");
    printf("Student grades from the input file\n");
    printf("==================================\n");

    for (i = 1; i <= numStudents; ++i) {
        for (j = 1; j <= numAssignments; ++j) {
            if (j < numAssignments) {
                printf("%.1f, ", grades[i][j]);
            }
            else {
                printf("%.1f", grades[i][j]);
            }
        }
        printf("\n");
    }
    return;
}

/** This has to be exact same as your function prototype. **/ /// float *CalculateAverage(int numStudents, int numAssignments) {
/*NEW*/ /** I'm passing by reference here. **/ void CalculateAverage(int numStudents, int numAssignments, float *average){
    int i, j;
    /** This is the second instance of the same array. You only ever need one. Pass by reference. **/ /// float average[101];
    for (i = 1; i < numAssignments; ++i) {
        for (j = 1; j < numStudents; ++j) {
            average[i] += grades[j][i];
        }
        average[i] = average[i] / ((double)numStudents);
    }

    /** You can't return an array. There's nothing to return, set function to void. **/ /// return(average);
    return;
}
