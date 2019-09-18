#include <stdio.h>
#include <stdlib.h>

int read_records(char* file_name, int studIDs[], int em108[], int em109[]);
void compute_average(int em108[], int em109[], int avg[], int size[]);
void write_records(char* file_name, int studIDs[], int em108[], int em109[], int avg[], int size);
void print_results(int studIDs[], int em108[], int em109[], int avg[], int size);

typedef struct_car
{
	int year;
	char number[9];
	char colour[10];
	float engine;
} 	car_type;

car_type car_info;

int main()
{
	/*int studentIDs[5000];
	int avgGrades[5000];
	int em108[5000];
	int em109[5000];
	int norecs = 0;*/

	car_type car_info;

	printf("welcome to the program!\n");
	norecs = read_records("indata.txt", studentIDs, em108, em109);
	compute average(em108, em109, avgGrades, norecs);
	write_records("results.txt", studentIDs, em108, em109, avgGrades, norecs);
	print_results(studentIDs, em108, em109, avgGrades, norecs);
	printf("Goodbye!\n");

	return(EXIT_SUCCESS);
}

int read_records(char* file_name, int studIDs[], int em108[], int em109[])
{
	FILE* fp;
	int norecs = 0;
	char ch;

	fp = fopen(file_name, "r");
	while(!feof(fp))
	{
		fscanf(fp, "%d%c%d%c%d%c", &studIDs[norecs], &ch, &em108[norecs], &ch, &em109[norecs], &ch);
		norecs++;
	}
	fclose(fp);

	return norecs;
}

void compute_average(int em108[], int em109[],int avg[], int size)
{
	int i;

	for(i=0; i < size; i++)
		avg[i] = (em108[i] + em109[i])/2;
}

void write_records(char* file_name, int studIDs[], int em108[], int em109[], int avg[], int size)
{
	FILE* fp;
	int i;
	fp = fopen(file_name, "w");
	for(i=0; i < size; i++)
		fprintf(fp, "%d %d %d %d\n", studIDs[i], em108[i], em109[i], avg[i]);

	fflush(fp);
	fclose(fp);
}

void print_results(int studIDs[], int em108[], int em109[], int avg[], int size)
{
	int i;
	printf("| StudID | em108 | em109 | AVG |\n");
	for(i=0; i < size; i++)
		printf("|%8d|%3d|%3d|%3d|\n", studIDs[i], em108[i], em109[i], avg[i]);
}
