//-----------------------------------------------------------------------------------
// Programmed by Joe Sawada for CIS 1500
// Assignment 4: compute a number of statistics on a CSV grade file.
// Assumes that the correct number of students and assignments are given in the command
// line arguments.
//-----------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// GLOBAL VARIABLES
float grades[1001][101];

// ---------------------------------------------------------
// Compute the average for a given assignment
//----------------------------------------------------------
float Average(int ass, int num_students) {

	int i;
	float sum = 0;

	for (i=0; i<num_students; i++) sum += grades[i][ass];
	return sum/num_students;
}
// ---------------------------------------------------------
// Compute the number of students who failed
//----------------------------------------------------------
int NumFail(int ass, int num_students) {

	int i, fail=0;

	for (i=0; i<num_students; i++) {
        if (grades[i][ass] < 50) fail++;
	} 
	return fail;
}
// ---------------------------------------------------------
// Compute the maximum for a given assignment
//----------------------------------------------------------
float Max(int ass, int num_students) {

	int i;
	float max;

	max=grades[0][ass];
	for (i=1; i<num_students; i++) {
		if (grades[i][ass] > max) max = grades[i][ass];
	} 
	return max; 
}
//----------------------------------------------------------
int main(int argc, char *argv[]) {

	int i, j, num_students, num_assignments;
	char c;
	FILE *input_file;

	// USAGE
	if (argc != 3) {
		printf("Usage:  ./a.out num_students num_assignments\n");
		return 0;
	}

	// OBTAIN NUMBER OF STUDENTS FROM COMMAND LINE
	num_students = atoi(argv[1]);
	num_assignments = atoi(argv[2]);
		
	input_file = fopen("grades1.txt","r");

	// READ EACH STUDENT 
	for (i=0; i<num_students; i++) {
	
		// READ ONE LINE - THE ASSIGNMENT SCORES
		for (j=0; j<num_assignments; j++) {
			fscanf(input_file, "%f", &grades[i][j]);
			fgetc(input_file);  // READ COMMA or EOLN or EOF
		}
	}

	// OUTPUT GRADES
	printf("==================================\n");
	printf("Student grades from the input file\n");
	printf("==================================\n");
	for (i=0; i<num_students; i++) {
		for (j=0; j<num_assignments-1; j++) printf("%5.1f, ", grades[i][j]);
		printf("%5.1f\n", grades[i][j]);
	} 
	printf("\n");

	// OUTPUT STATS
	for (i=0; i<num_assignments; i++) {
		printf("==============\n");
 		printf("Ass #%2d stats\n", i+1);
		printf("==============\n");
		printf("  avg = %5.1f\n", Average(i,num_students));
		printf("  max = %5.1f\n", Max(i,num_students));
        printf(" fail = %5d\n", NumFail(i,num_students));
		printf("\n");
	}

	fclose(input_file);
}