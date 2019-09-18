#include <stdio.h>
#include <stdlib.h>

float sales, com, b1, b2, b3;

int main()
{
	printf("Welcome. Please enter your sales figures (in euros):\n");
	scanf("%f\n", &sales);
	if(sales>=10000)
		{com = sales*05;
		 printf("Your commission is €%.02f.\n", com);}
	else
		printf("You have not ade enough sales to earn commission.\n");
	return(EXIT_SUCCESS);
}
