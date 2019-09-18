#include <stdio.h>
#include <stdlib.h>

float l, m, n, perim, area, paint;

int main()
{
	printf("Enter the length of sides l, m, and n in metres:\n");
	scanf("%f", &l);
	scanf("%f", &m);
	scanf("%f", &n);
	perim = l+m+n;
	if(l>m)
		if(m>n)
			area = (l/2)*m;
		else
			area = (l/2)*n;
	else
		area = (m/2)*n;
	paint = area/20;
	printf("The perimeter is %.2f, and the area is %.2f, and %.2f cans of paint are needed to paint it.", perim, area, paint);
	return(EXIT_SUCCESS);
}