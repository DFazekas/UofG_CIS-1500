/*********************************************************
Title: Assignment #04.
Programmed by: Devon Fazekas-Thomas
Date: March 11, 2016.
Purpose: To interpret data from both the command line and
         a CSV file, computing averages, maximum value, and
         the frequencies of failed students, given the quantity
         of students, assignments, and their respective
         grades, then printing data to the console window.
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float grades[1001][101] = {{0.0}};

int  DataValidation  (int argc, char *argv[]);
void ReadFile        (int numStudent, int numAssignment);
void ComputeAvgs     (int numStudent, int numAssignment, float *assAvgs);
void ComputeMaxs     (int numStudent, int numAssignment, float *assMaxs);
void ComputeNumFails (int numStudent, int numAssignment, int *assFails);
void PrintData       (int numStudent, int numAssignment, float *assAvgs, float *assMaxs, int *assFails);

int  DataValidation (int argc, char *argv[]) {
    /// Command-line length validation.
    if ( (argc != 3) || !(isdigit(*argv[1]) && isdigit(*argv[2])) ) {
	    printf ("usage: ./a.out num_students num_assignments\n");
	    return -1;
	}
    return 0;
}
void ReadFile (int numStudent, int numAssignment) {
    FILE *inputFile;
    int i = 0;
    int j = 0;

    inputFile = fopen ("grades.txt", "r");

    /// Store data from file.
    for (i = 0; i < numStudent; i++) {
        for (j = 0; j < numAssignment; j++) {
            fscanf (inputFile, "%f,", &grades[i][j]);
        }
    }
    fclose (inputFile);
    return;
}
void ComputeAvgs (int numStudent, int numAssignment, float *assAvgs) {
    int i = 0;
    int j = 0;
    float average = 0.0;

    /// Initialize array.
    for (i= 0; i < numAssignment; i++) {
        assAvgs[i] = 0.0;
    }

    /// Compute average per assignment.
    for (i = 0; i < numAssignment; i++) {
        average = 0.0;
        for (j = 0; j < numStudent; j++) {
            average += grades[j][i];
        }
        assAvgs[i] = (average / numStudent);
    }
    return;
}
void ComputeMaxs (int numStudent, int numAssignment, float *assMaxs) {
    int i = 0;
    int j = 0;
    float max = 0.0;

    /// Initialize array.
    for (i = 0; i < numAssignment; i++) {
        assMaxs[i] = 0.0;
    }

    /// Compute max value per assignment.
    for (i = 0; i < numAssignment; i++) {
        max = 0.0;
        for (j = 0; j < numStudent; j++) {
            if (max < grades[j][i]) {
                max = grades[j][i];
            }
        }
        assMaxs[i] = max;
    }
    return;
}
void ComputeNumFails (int numStudent, int numAssignment, int *assFails) {
    int i     = 0;
    int j     = 0;
    int fails = 0;

    /// Initialize array.
    for (i = 0; i < numAssignment; i++) {
        assFails[i] = 0;
    }

    /// Compute number of fails per assignment.
    for (i = 0; i < numAssignment; i++) {
        fails = 0;
        for (j = 0; j < numStudent; j++) {
            if (grades[j][i] < 50.0) {
                ++fails;
            }
        }
        assFails[i] = fails;
    }
    return;
}
void PrintData (int numStudent, int numAssignment, float *assAvgs, float *assMaxs, int *assFails) {
    int i = 0;
    int j = 0;

    /// Output aligned data.
    printf ("\n==================================\nStudent grades from the input file\n==================================\n");
    for (i = 0; i < numStudent; i++) {
        for (j = 0; j < numAssignment; j++) {
            if (j != (numAssignment - 1) ) {
                printf ("%5.1f,\t", grades[i][j]);
            } else {
                printf ("%5.1f\t", grades[i][j]);
            }
        }
        printf ("\n");
    }

    /// Output assignment stats.
    for (i = 0; i < numAssignment; i++) {
        printf ("\n==============\nAss # %d stats\n==============\n", (i+1));
        printf (" avg = %5.1f\n", assAvgs[i]);
        printf (" max = %5.1f\n", assMaxs[i]);
        printf ("fail = %5d\n", assFails[i]);
    }
    return;
}
int main (int argc, char *argv[]) {
    int   numStudent     = 0;
    int   numAssignment  = 0;
    float assAvgs[numAssignment];
    float assMaxs[numAssignment];
    int   assFails[numAssignment];

    /// Validate command line arguments.
    system ("clear");
    if (DataValidation (argc, argv) != 0) {
		return -1;
	}

	/// Read file / store data.
    numStudent     = atoi(argv[1]);
    numAssignment  = atoi(argv[2]);
    ReadFile (numStudent, numAssignment);

    /// Computations.
    ComputeAvgs     (numStudent, numAssignment, assAvgs);
    ComputeMaxs     (numStudent, numAssignment, assMaxs);
    ComputeNumFails (numStudent, numAssignment, assFails);

    /// Print final data.
    PrintData (numStudent, numAssignment, assAvgs, assMaxs, assFails);

    printf ("\nPress ENTER to end quit and clear screen.\n");
    getchar();
    system ("clear");
    return 0;
}
