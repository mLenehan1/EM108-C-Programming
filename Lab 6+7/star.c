#include <stdlib.h>
#include <stdio.h>

int main()
{
	int star, line;
	for(line=5; line>=0; line--){
			printf("\n");
			for(star = 0; star <= 11; star ++){
				printf("*");
		}
	}

	printf("\n\n");

	for(line=11;line>=0; line --){
		for(star = 0; star<line; star++){
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

		for(line=1;line<=11; line ++){
			for(star = 1; star<line; star++){
				printf("*");
			}
			printf("\n");
	}
	return(EXIT_SUCCESS);
}
