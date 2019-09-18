//Include C libraries
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Declare Variables
float adj;
float opp;
float hyp;

//Main function scans for inputs and outputs hyp value
int main()
{
	printf("Welcome, today I will be helping you find the hypotenuse of a right angled triangle.\nPlease enter the length of the adjacent side: ");
	scanf("f\n", &adj);
	printf("Enter the length of the opposite side: ");
	scanf("%f\n", &opp);
	//compute hyp value
	hyp = sqrt(adj*adj) + (opp*opp);
	printf("The hypotenuse of this triangle is %.01f\n" ,hyp);

	return(EXIT_SUCCESS);
}
