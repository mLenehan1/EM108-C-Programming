//Include C libraries
#include <stdlib.h>
#include <stdio.h>

//Declare variables
float d, rolls_w, pi, circum, cost_w, cost_tot;

int main()
{
	//print message and scan diameter
	printf("What is the diameter of your field?\n");
	scanf("%f\n", &d);
	//print message and scan cost per roll
	printf("What is the cost of a 20 meter roll of wire?\n");
	scanf("%f\n", &cost_w);
	//Define pi and circumference expression, then print.
	pi = 3.1416;
	circum = 2*pi*(d/2);
	printf("The circumference is %f\n", circum);
	//Define the # of rolls needed and the total cost, then print.
	rolls_w = circum/20;
	cost_tot = cost_w*rolls_w;
	printf("The amount of rolls needed is %f, and the cost is %f\n", rolls_w, cost_tot);
	return(EXIT_SUCCESS);

}