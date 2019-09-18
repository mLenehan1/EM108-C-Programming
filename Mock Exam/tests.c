#include <stdio.h>
#include <stdlib.h>

/* structured type definition */
typedef struct fashion_type_tag
{
char name[20];
char brand[20];
int size;				
float price;
int discount;
}  fashion_type;


/* function that reads data from a file, stores it in an array and returns the number of records read*/
int read_records (char* file_name, fashion_type fash[]);

/* function that searches for an item */
void search_item (fashion_type fash[], int norecs, 
char brand[], int size);

/* function that applies discount to items */
void apply_discount (fashion_type fash[], int norecs);

/* function that writes the array data into a file */
void write_file (char* file_name, 
fashion_type fash[], int norecs);

/* function that prints the items given a brand */
void print_brand (fashion_type fash[], int norecs, 
char brand[]);

/* the main program */
void main ()
{
fashion_type fash[500];
int norecs;
int answer;
int size;
char brand [20];

/* welcome message */
	printf("Welcome to Fashion Shop!\n ");
	
/* initialisation */
answer = 0;

	/* loop */
	while(answer != 6)
{
/* print options */
printf("Here are some choices:\n");
printf("Read records! – press 1\n");
printf("Search for item!	– press 2\n");
printf("Apply discount!	– press 3\n");
printf("Write in file!	– press 4\n");
printf("Print brand to screen! – press 5\n");
printf("Exit! 	– press 6\n");

/* read choice */
printf("Enter your choice:\n");
	scanf("%d", &answer);

/* perform activity */
switch(answer)
{
	case 1: 	printf(“Read_records!\n”); 
 	norecs=read_records(“items.txt”,fash);
	printf(“Read %d records\n”, norecs);
break;
case 2: 	printf(“Search item!\n”); 
		printf(“Enter brand name\n”);
		scanf(“%s”, brand);
		printf(“Enter size!\n”);
		scanf(“%d”, &size);
search_item(fash,norecs,brand,size);
printf(“Search complete\n”);
break;
case 3: printf(“Discount!\n”); break;
case 4: printf(“Write!\n”); break;
case 5: printf(“Print!\n”); break;
case 6: printf(“Bye!!!!\n”); break;
}

return (EXIT_SUCCESS);
}



/* function that reads data from a file, stores it in an array and returns the number of records read*/
int read_records (char* file_name, fashion_type fash[])
{
FILE* fp;
int norecs = 0;
char ch;

/* open file */
fp = fopen(file_name, “r”);

while(!feof(fp))
{
/* read on record from file */
fscanf(fp, “%s%c%s%c%d%c%f%c%d%c”, 
fash[norecs].name, &ch, 
fash[norecs].brand, &ch, 
&fash[norecs].size, &ch, 
&fash[norecs].price, &ch, 
&fash[norecs].discount, &ch); 

/* increase the number of records read */
norecs++;
}

/* close file */
fclose(fp);

return norecs;

}

/* function that searches for an item */
void search_item (fashion_type fash[], int norecs, 
char brand[], int size)
{
	int i;
	float newprice;

	for (i=0; i<norecs; i++)
{
	if (strcmp(fash[i].brand, brand)==0 &&
			fash[i].size==size)
	{
		newprice = fash[i].price – 
(fash[i].discount* fash[i].price);
			printf(“Name %s brand %s Size %d Price %f\n”,
				fash[i].name, fash[i].brand, 
				fash[i].size, newprice);
}
}
}
