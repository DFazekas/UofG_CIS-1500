#include <stdio.h>

/*
    This program calculates the area and perimeter of a rectangle, given the length and width.

    Author: Devon Fazekas-Thomas (0879824)
    Date: January 28, 2016
*/

int main()
{

    // Declaring variables
    int rectLength    = 0;
    int rectWidth     = 0;
    int rectArea      = 0;
    int rectPerimeter = 0;


    // Gets length and width of rectangle
    printf("We're computing the area & perimeter of a rectangle. \n\tEnter the desired LENGTH, then WIDTH (#,#): ");
    scanf("%d,%d", &rectLength, &rectWidth);
    getchar();

    // Evaluates the area and perimeter of the rectangle
    rectArea      = rectLength * rectWidth;
    rectPerimeter = (2 * rectLength) + (2 * rectWidth);

    // Prints all inputs and outputs to user, illustrating all calculations
    printf("\nThe area of the rectangle is %d x %d = %d.\n", rectLength, rectWidth, rectArea);
    printf("The perimeter of the rectangle is equal to (2 x %d) + (2 x %d) = %d.\n", rectLength, rectWidth, rectPerimeter);

    // Concludes program
    printf("\nPress ENTER to close."); getchar();
    return 0;
}
