//Include C libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Declare variables
float r1, r2, r3;
float rs;
float rp;

int main()
{
	//Define values of resistors, calculate values for series and parallel. Print to screen.
	r1 = 2000;
	r2 = 1500;
	r3 = 750;
	rs = r1 + r2 + r3;
	rp = 1/((1/r1) + (1/r2) + (1/r3));
	printf("Welcome to the resistor calculator. I have taken the values of three resistors: 2000ohms, 1500ohms, and 750 ohms, and calculated the value of these in series and in parallel.\n");
	printf("The value of these resistors in series is %.1f.\n", rs);
	printf("The value of these resistors in parallel is %.1f.\n", rp);
	return(EXIT_SUCCESS);
}
