#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int client, client_num, tickets, index, sum;
float av;

int main()
{
	printf("Welcome!\nEnter the number of clients\n");
	scanf("%f", &client_num);
	client = 1;
	while(client<=client_num){
		printf("Enter the number of tickets for client %1.2f: ", client);
		scanf("%f", &tickets);
		client++;
	}
	return(EXIT_SUCCESS);

}
