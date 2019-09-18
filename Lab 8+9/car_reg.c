#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structured Type Definition

typedef struct car
{
	int year;
	char number[9];
	char colour[10];
	float engine;
	int tax;
} car_type;

// List of Functions

void print_menu(car_type car_info[],int norecs);
int read_records(FILE* fp, car_type car_info[]);
int compute_tax(car_type car_info[], int i);
void write_records(char* file_name,car_type car_info[], int i);
void print_results(car_type car_info[], int i);

// Main Function

int main()
{
	car_type car_info[10];
	int norecs;
	int i;
	FILE* fp;
	FILE* results;

	fp = fopen("indata.txt", "r");
	results=fopen("results.txt","w");

	printf("Welcome to the program!\n");
	norecs = read_records(&*fp, car_info);
	print_menu(car_info,norecs);
	return(EXIT_SUCCESS);
}

//Function to Run a user menu

void print_menu(car_type car_info[],int norecs)
{
	int i;
	int selection;
	printf("MENU\n\n");
	printf("1. Run Program.\n2. Exit Program\n");
	scanf("%d", &selection);

	switch(selection)
	{
	case 1:
		for(i=0;i<norecs;i++){
			compute_tax(car_info,i);
			write_records("results.txt", car_info, i);
			print_results(car_info,i);
		}
		printf("\nGoodbye!\n");
		break;

	case 2:
		printf("\nGoodbye!\n");
		break;

	default:
		printf("\nInvalid Selection\n");
		break;
	}
}

// Read records from file

int read_records(FILE* fp, car_type car_info[])
{
	int norecs = 0;
	char ch;

	while(!feof(fp))
	{
		fscanf(fp, "%d%c%s%c%s%c%f ", &car_info[norecs].year, &ch, car_info[norecs].number, &ch, &car_info[norecs].colour,&ch, &car_info[norecs].engine);
		norecs=norecs+1;
	}
	fclose(fp);
	return norecs;
}

// Compute Tax of each read in value

int compute_tax(car_type car_info[], int i)
{
	int crnt_year;
	int age;
	crnt_year = 2016;

		age = crnt_year - car_info[i].year;
		if(age <5 && car_info[i].engine <= 1.6)
			car_info[i].tax = 150;
		if (age<5 && car_info[i].engine>1.6)
			car_info[i].tax = 300;
		if(age > 5 && car_info[i].engine < 1.4)
			car_info[i].tax = 200;
		if(age > 5 && car_info[i].engine >1.4 && car_info[i].engine < 1.6)
			car_info[i].tax = 400;
		if(age >5 && car_info[i].engine >= 1.6)
			car_info[i].tax = 600;
	return car_info[i].tax;
}

// Write Records to file

void write_records(char* file_name,car_type car_info[],int i)
{
	FILE* fp;
	fp = fopen(file_name, "a");
	fprintf(fp, "%d %s %s %1.1f %d\n", car_info[i].year, car_info[i].number, car_info[i].colour, car_info[i].engine, car_info[i].tax);
	fflush(fp);
	fclose(fp);
}

// Print Results to the Screen

void print_results(car_type car_info[], int i)
{
	printf("| Year   | Number | Colour | Engine | Tax |\n");
	printf("|%8d|%s |%s   |%1.2f    |%d  |\n", car_info[i].year, car_info[i].number, car_info[i].colour, car_info[i].engine, car_info[i].tax);
}
