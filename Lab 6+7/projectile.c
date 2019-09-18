#include <stdio.h>
#include <stdlib.h>

int main()
{
	float x[100], vxo, t, y[100], yo, vyo, g;
	g = 9.81;
	yo = 0;
	t = 0;


	printf("Enter vertical height: \n");
	scanf("%f", &yo);
	printf("Enter horizontal velocity component: \n");
	scanf("%f", &vxo);
	printf("Enter vertical velocity component: \n");
	scanf("%f", &vyo);


	while(y[t]>=0){
		x[t] = (vxo*t);
		y[t] = yo +vyo*t - (g*t*t);

		printf(" %1.2f		%1.2f\n", x[t], y[t]);
		t++;
	}
	return(EXIT_SUCCESS);
}
