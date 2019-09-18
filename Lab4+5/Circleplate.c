//Include C libraries
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Declaration of variables
float r, pi, area_s, cost, refund, area_c, cost_c, cost_s;

//Main function scans values and outputs cost of the square and circular sheets along with refund value
int main()
{
	printf("Welcome! Today I will be calculating the cost of the steel you will need to make a circular plate of radius r!\n");
	printf("Enter the length of the radius (in cm) on the circle\n");
	scanf("%f", &r);
	printf("Enter the cost of steel per square cetimeter\n");
	scanf("%f", &cost);
	//Value of pi is defined
	pi = 3.1415;
	//expressions calculate the area of the square and circular sheets and their costs
	area_c = pi*(r)*(r);
	cost_c = area_c*cost;
	area_s = (2*r)*(2*r);
	cost_s = area_s*cost;
	refund = (area_s-area_c)*(cost*0.20);
	printf("The cost of the square steel plate will be %.2f, and the circular steel plate will be %.2f, with a refund available of %.2f\n", cost_s, cost_c, refund);
	return(EXIT_SUCCESS);
}

