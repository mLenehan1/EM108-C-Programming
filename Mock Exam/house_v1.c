#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structured Type Definition

typedef struct house
{
	char houseID[20];
	char name[10];
	int waste;
	int water;
	int area;
	float tax;
} house_type;

// List of Functions

void print_menu(house_type house_info[],int norecs);
int read_records(FILE* fp, house_type house_info[]);
int compute_tax(house_type house_info[], int i);
void write_records(char* file_name, house_type house_info[], int i);
void print_results(house_type house_info[], int i);

//Main Function

int main()
{
	house_type house_info[20];
	int norecs;
	int i;
	FILE* fp;
	FILE* results;

	fp = fopen("inputdata.txt", "r");
	results=fopen("results.txt","w");

	printf("Welcome to the program!\n");
	norecs = read_records(&*fp, house_info);
	print_menu(house_info,norecs);
	return(EXIT_SUCCESS);
}

//Function to Run a user menu

void print_menu(house_type house_info[],int norecs)
{
	int i;
	int selection;
	while(selection != 3)
	{
	printf("MENU\n\n");
	printf("1. Run Program and Print Results to Screen.\n2. Run Program and Print Results to File.\n3. Exit Program\n");
	scanf("%d", &selection);

		switch(selection)
		{
		case 1:
			for(i=0;i<norecs;i++){
				compute_tax(house_info,i);
				//write_records("results.txt", house_info, i);
				print_results(house_info,i);
			}
			printf("\nChoose another option.\n");
			break;
		case 2:
			for(i=0;i<norecs;i++){
				compute_tax(house_info,i);
				write_records("results.txt", house_info, i);
				//print_results(house_info,i);
			}
			printf("\nChoose another option.\n");
			break;
		case 3:
			printf("\nExiting Program.\n");
			break;

		default:
			printf("\nInvalid Selection\n");
			break;
		}
	}
}


// Read records from file

int read_records(FILE* fp, house_type house_info[])
{
	int norecs = 0;
	char ch;

	while(!feof(fp))
	{
		fscanf(fp, "%s%c%s%c%d%c%d%c%d ", house_info[norecs].houseID, &ch, house_info[norecs].name, &ch, &house_info[norecs].waste,&ch, &house_info[norecs].water, &ch, &house_info[norecs].area);
		norecs=norecs+1;
	}
	fclose(fp);
	return norecs;
}

// Compute Tax of each read in value

int compute_tax(house_type house_info[], int i)
{
		if(house_info[i].area >= 200)
			house_info[i].tax = ((house_info[i].area) + 0.5*(house_info[i].waste) + 3*(house_info[i].water));
		else
			house_info[i].tax = (100 + house_info[i].waste + house_info[i].water);
		return house_info[i].tax;
}

// Write Records to file

void write_records(char* file_name, house_type house_info[], int i)
{
	FILE* fp;
	fp = fopen(file_name, "a");
	fprintf(fp, "%s %s %d %d %d %1.0f\n", house_info[i].houseID, house_info[i].name, house_info[i].waste, house_info[i].water, house_info[i].area, house_info[i].tax);
	fflush(fp);
	fclose(fp);
}

// Print Results to the Screen

void print_results(house_type house_info[], int i)
{
	printf("| houseID  | ownername | binwaste | waterused | surfacearea | Tax |\n");
	printf("|%10s|%10s |   %d    |     %d    |     %d     | %1.0f |\n", house_info[i].houseID, house_info[i].name, house_info[i].waste, house_info[i].water,house_info[i].area, house_info[i].tax);
}