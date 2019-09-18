#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a, b, i;
float square, root;

int main()
{

	a = 1;
	b = 10;
	i = a;
	do
	{
		square = i*i;
		root = sqrt(i);
		printf("The square of %d is %.0f, and the square root is %.02f.\n", i, square, root);
		i = i+1;
	} while(i<=b);

	printf("Enter a value for a:");
	scanf("%d", &a);
	printf("Enter a value for b greater than a:");
	scanf("%d", &b);
{
		i = a;
	do
	{
		square = i*i;
		root = sqrt(i);
		printf("The square of %d is %.0f, and the square root is %.02f.\n", i, square, root);
		i = i+1;
	} while(i<=b);
}
	return(EXIT_SUCCESS);
}