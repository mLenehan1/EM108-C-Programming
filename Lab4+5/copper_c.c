#include <stdio.h>
#include <stdlib.h>

float r, h, pi, c, area, cost;

int main()
{
	printf("Enter the radius of the cylinder in cm:");
	scanf("%f", &r);
	printf("Enter the height of the cylinder in cm:");
	scanf("%f", &h);
	printf("Enter the cost of the copper per square centimeter:");
	scanf("%f", &c);
	pi = 3.1416;
	area = 2*pi*r*h;
	cost = c*area;
	printf("The cost of the copper to build a cylinder of area %0.2f is %0.2f euro\n", area, cost);
	return(EXIT_SUCCESS);
}