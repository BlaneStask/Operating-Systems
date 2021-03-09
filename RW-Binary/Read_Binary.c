// Lab: Reading to a binary file

#include <stdio.h>
#include <stdbool.h>

struct st_NFL_QB
{
	char	lastName[15];
	int		jerseyNum;
	char	posn[2+1];
	double	speedTest;		// 40 yard dash.
	char 	team[12];
	bool	isActive;
};

int main()
{
	FILE *ptr_myfile;
	struct st_NFL_QB my_NFL_QB;

	ptr_myfile = fopen("CmpSc472_BinaryFile.bin","rb");
	if(!ptr_myfile)
	{
		printf("Unable to open file!");
		return 1;
	}
   	printf("\n");
	for(int i = 0; i < 5; i++)
	{
		fread(&my_NFL_QB, sizeof(struct st_NFL_QB), 1, ptr_myfile);
		printf("Last Name: %s\n", my_NFL_QB.lastName);
		printf("Jersey Number: %d\n", my_NFL_QB.jerseyNum);
		printf("Position: %s\n", my_NFL_QB.posn);
		printf("Speed Test: %0.2f\n", my_NFL_QB.speedTest);
		printf("Team: %s\n", my_NFL_QB.team);
		if(my_NFL_QB.isActive == 1){ printf("Active: True \n\n");}
		else{ printf("Active: False \n\n");}
	}

	fclose(ptr_myfile);
	return 0;
}
