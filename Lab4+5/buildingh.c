//C libraries included
#include <stdlib.h>
#include <stdio.h>

//Variables declared
float h, g, t1, t2, t3, tav;

//main function scans inputs and computes value for h
int main()
{
	printf("Today i will be helping you to measure the height of a building. Drop a stone from the top floor three times and measure the time taken (in seconds) for it to reach the ground each time.\n");
	printf("Enter the time value for time one:");
	scanf("%f", &t1);
	printf("Enter the time value for time two:");
	scanf("%f", &t2);
	printf("Enter the time value for time three:");
	scanf("%f", &t3);
	//compute average time using inputs
	tav = (t1+t2+t3)/3;
	//define value for g and compute value for h
	g = 9.81;
	h = (g*tav*tav)/2;
	printf("The height of the building is %.02f metres.\n", h);
	return(EXIT_SUCCESS);
}