#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structured Type Definition

typedef struct pet
{
	char category[20];
	char breed[20];
	int age;
	int price;
	char code[20];
} pet_type;

//Equipment Structure
typedef struct equip
{
	char code[20];
	char name[20];
	int price;
} equip_type;

// List of Functions

void print_menu(pet_type pet_info[],int norecs);
int read_pet(FILE* fp, pet_type pet_info[]);
int read_equip(FILE* fe, equip_type equip_info[]);
int compute_tax(car_type car_info[], int i);
void write_records(char* file_name,car_type car_info[], int i);
void print_results(car_type car_info[], int i);

// Main Function

int main()
{
	pet_type pet_info[20];
	equip_type equip_info[20];
	int norecs_pet, norecs_equip;
	int i;
	FILE* fp;
	FILE* fe;
	FILE* results;

	fp = fopen("pet.txt", "r");
	fe = fopen("equip.txt", "r");
	results=fopen("results.txt","w");

	printf("Welcome to the program!\n");
	norecs_pet = read_records(&*fp, pet_info);
	norecs_equip = read_equip(&*fe, equip_info);
	print_menu(pet_info,equip_info,norecs_pet,norecs_equip);
	return(EXIT_SUCCESS);
}

//Function to Run a user menu

void print_menu(pet_type pet_info[],int norecs)
{
	int i;
	int norecs_pet, norecs_equip;
	int selection;
	while(selection !=7)
	{
		printf("MENU\n\n");
		printf("1. Read Pet Records.\n2. Read Equipment Records.\n3. Search for Pets.\n4. Print Price.\n5. Write File.\n6. Print Table.\n7. Exit Program.");
		scanf("%d", &selection);

		switch(selection)
		{
		case 1:
			for(i=0;i<norecs;i++){
				norecs_pet = read_records(&*fp, pet_info);
			}
			printf("\nGoodbye!\n");
			break;
		case 2:
			for(i=0;i<norecs;i++){
				norecs_equip = read_equip(&*fe, equip_info);
			}
			break;
		case 3:
			for(i=0;i<norecs;i++){
			}
		case 4:
			for(i=0;i<norecs;i++){
				compute_total(pet_info,i);
			}
		case 5:
			for(i=0;i<norecs;i++){
				write_records("results.txt", car_info, i);
			}
		case 6:
			for(i=0;i<norecs;i++){
				print_results(pet_info.category[],pet_info.breed[],pet_info.age[],equip_info.name[],totalprice[],i);
			}
		case 7:
			printf("\nGoodbye!\n");
			break;

		default:
			printf("\nInvalid Selection\n");
			break;
		}
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