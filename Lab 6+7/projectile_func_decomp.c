#include <stdlib.h>
#include <stdio.h>

int read_records(FILE* fp, float yo, float vx, float vy);
int compute_vals(float x[], float y[], float yo, float vx, float vy, int t, float g);
void write_records(char* file_name, float x[], float y[], int t);
void print_results(float x[], float y[], int t);

int main()
{
	float yo, vx, vy, x, y, t, g, i;
	int recs;
	FILE* fp;
	FILE* xyresults;

	fp = fopen("xydata.txt", "r");
	xyresults = fopen("xyresults.txt", "w");

	printf("Welcome to the Projectile Program!");
	recs = read_records(&*fp, yo, vx, vy);
	compute_vals(x, y, yo, vx, vy, t, g);
	write_records("xyresults.txt", x, y, t);
	print_results(x, y, i);

	return(EXIT_SUCCESS);
}

int read_records(FILE* fp, float yo, float vx, float vy)
{
		int recs = 0;
		char ch;

		while(!feof(fp))
		{
			fscanf(fp, "%f %f %f ", &yo, &vx, &vy);
			recs=recs+1;
		}
		fclose(fp);
		return recs;
}

int compute_vals(float x[], float y[], float yo, float vx, float vy, int t, float g)
{
	g = 9.81;
		while(y[t]>=0)
		{
			x[t] = (vx*t);
			y[t] = yo +vy*t - (g*t*t);

			printf(" %1.2f		%1.2f\n", x[t], y[t]);
			t++;
		}
		return x[t], x[y];
}

void write_records(char* file_name, float x[], float y[], int t)
{
		FILE* fp;
		fp = fopen(file_name, "a");
		fprintf(fp, "%f %f %d\n", x[t], y[t]);
		fflush(fp);
		fclose(fp);
}

void print_results(float x[], float y[], int t)
{
	printf("|	x	|	y	|");
	printf("|	%f	|	%f	|", x[t], y[t]);
}
