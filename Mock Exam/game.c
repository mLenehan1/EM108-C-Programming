#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structured Type Definition - Game

typedef struct game
{
	char cat[20];
	char name[10];
	int year;
	int price;
	char platform[20];
	char code[20];
} game_type;

// Structured Type Definition - Equip

typedef struct equipment
{
	char code[20];
	char name[10];
	int price;
} equipment_type;

// List of Functions
void print_menu(game_type game_info[],int norecs_game, equipment_type equipment_info[], int norecs_equip);
int read_rec_game(FILE* fp, game_type game_info[]);
int read_rec_equip(FILE* fq, equipment_type equipment_info[]);
void search_item(game_type game_info[], equipment_type equipment_info[], int norecs_game, int norecs_equipment, char cat[], char name[]);

//Main Function

int main()
{
	game_type game_info[20];
	equipment_type equipment_info[20];
	int norecs_game, norecs_equip;
	int i;
	FILE* fp;
	FILE* fq;
	FILE* results;

	fp = fopen("games.txt", "r");
	fq = fopen("equip.txt", "r");
	results=fopen("results.txt","w");

	printf("Welcome to the program!\n");
	norecs_game = read_rec_game(&*fp, game_info);
	norecs_equip = read_rec_equipent(&*fq, equipment_info);
	print_menu(game_info,equipment_info,norecs_game,norecs_equip);
	return(EXIT_SUCCESS);
}

//Function to Run a user menu

void print_menu(game_type game_info[], equipment_type equipment_info[], int norecs_game ,int norecs_equip)
{
	int i;
	char name, cat;
	int selection;
	while(selection != 3)
	{
	printf("MENU\n\n");
	printf("1. Run Program and Print Results to Screen.\n2. Run Program and Print Results to File.\n3. Exit Program\n");
	scanf("%d", &selection);

		switch(selection)
		{
		case 1:
			printf("Enter the category of the game");
			scanf("%s", cat);
			printf("Enter the name of the game");
			scanf("&s", name);
			search_item(game_info, equipment_info, norecs_game, norecs_equip, cat, name);
			/*for(i=0;i<norecs;i++){
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
			break;*/

		default:
			printf("\nInvalid Selection\n");
			break;
		}
	}
}

// Read game records from file

int read_rec_game(FILE* fp, game_type game_info[])
{
	int norecs_game = 0;
	char ch;

	while(!feof(fp))
	{
		fscanf(fp, "%s%c%s%c%d%c%d%c%s", game_info[norecs_game].cat, &ch, game_info[norecs_game].name, &ch, &game_info[norecs_game].year, &ch, &game_info[norecs_game].price, &ch, game_info[norecs_game].code);
		norecs_game=norecs_game+1;
	}
	fclose(fp);
	return norecs_game;
}

// Read equipment records from file

int read_rec_equipment(FILE* fq, equipment_type equipment_info[])
{
	int norecs_equip = 0;
	char ch;

	while(!feof(fq))
	{
		fscanf(fq, "%s%c%s%c%d ", equipment_info[norecs_equip].code, &ch, equipment_info[norecs_equip].name, &ch, &equipment_info[norecs_equip].price);
		norecs_equip=norecs_equip+1;
	}
	fclose(fq);
	return norecs_equip;
}
/* function that searches for an item */
void search_item (game_type game_info[], equipment_type equipment_info[], int norecs_game, int norecs_equip, char cat[], char name[])
{
	int i, j;
	float newprice;

	for (i=0; i<norecs_game; i++)
{
	if (strcmp(game_info[i].cat, cat)==0 && strcmp(game_info[i].name, name))
	{
		for(j=0; j<norecs_equip; j++)
		{
			if(strcmp(game_info[i].platform, equipment_info[j].name) ==0)
			printf("The Equipment to be bought is the %s.", equipment_info[j].name);
		}
}
}
}
