/******************************************************************
Programmed by: Devon Fazekas-Thomas
Date: Feb. 24, 2016
Purpose: To read data from a file, complete dynamic number of
         computations from data, and write output to new file.
*******************************************************************/

#include <stdio.h>
#define NUM_ITEMS 7


void InputData    (int *numStudents, int itemWeights[NUM_ITEMS],    int stuGrades[100][NUM_ITEMS]);
void CompAverages (int numStudents,  int stuGrades[100][NUM_ITEMS], double avgMarks[NUM_ITEMS],     int itemWeights[NUM_ITEMS]);
void OutputData   (int numStudents,  double avgMarks[NUM_ITEMS]);


int main() {

    int    numStudents                   = 0;
    int    itemWeights [NUM_ITEMS]       = {0};
    int    stuGrades   [100][NUM_ITEMS]  = {{0}};
    double avgMarks    [NUM_ITEMS]       = {0.0};


    /// Get input from file.
    InputData (&numStudents, itemWeights, stuGrades);

    /// Compute averages.
    CompAverages (numStudents, stuGrades, avgMarks, itemWeights);

    /// Write output to file.
    OutputData (numStudents, avgMarks);

    getchar ();
    return 0;
}


void InputData (int *numStudents, int itemWeights[NUM_ITEMS], int stuGrades[100][NUM_ITEMS]) {

    FILE *inFile;
    int i = 0;
    int j = 0;


    inFile = fopen("grades.txt", "r");

    /// Get # of students.
    fscanf (inFile, "%d", numStudents);

    /// Get all weights for all items.
    for (i = 0; i < NUM_ITEMS; i++) {
        fscanf (inFile, "%d", &itemWeights[i]);
    }

    /// Get all of students' marks.
    for (i = 0; i < *numStudents; i++) {
        for (j = 0; j < NUM_ITEMS; j++) {
            fscanf (inFile, "%d", &stuGrades[i][j]);
        }
    }
    fclose (inFile);
}

void CompAverages (int numStudents, int stuGrades[100][NUM_ITEMS], double avgMarks[NUM_ITEMS], int itemWeights[NUM_ITEMS]){

    int i       = 0;
    int j       = 0;
    int sum[10] = {0};


    /// Summation of student marks on all items.
    for (i = 0; i < NUM_ITEMS; i++) {
        for (j = 0; j < numStudents; j++) {
            sum[i] += stuGrades[j][i];
        }
    }

    /// Computes averages of all items.
    for (i = 0; i < NUM_ITEMS; i++) {
        avgMarks[i] = (sum[i] / ((double) numStudents * itemWeights[i])) * 100;
    }
}

void OutputData (int numStudents, double avgMarks[NUM_ITEMS]) {

    FILE *outFile;
    int i = 0;


    outFile = fopen("averages.txt", "w+");

    /// Write # of students to file.
    fprintf (outFile, "There are %d students in this class.\n", numStudents);

    for (i = 0; i < NUM_ITEMS; i++) {

        /// Write assignment averages to file.
        if (i < (NUM_ITEMS - 2) ) {
            fprintf (outFile, "The average for assignment #%d is %.f%%\n", (i + 1), avgMarks[i]);
        }

        /// Write midterm average to file.
        else if (i == (NUM_ITEMS - 2) ) {
            fprintf (outFile, "The average for the midterm is %.f%%\n", avgMarks[i]);
        }

        /// Write final average to file.
        else {
            fprintf (outFile, "The average for the final is %.f%%\n", avgMarks[i]);
        }
    }
    fclose (outFile);
}
