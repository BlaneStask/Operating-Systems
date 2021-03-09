// Lab: Writing to a binary file

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char*   names[]  = {"Rogers",   "McNabb", "R.White", "S.Young", "Gronk"    };
const int     jerseys[]= { 12,        5,        92,        8,         84         };
const char*   posns[]  = { "QB",      "QB",     "DE",      "QB",      "TE"       };
const double  speeds[] = { 4.8,       4.78,     5.21,      4.99,      5.05       };
const char*   teams[]  = { "Packers", "Eagles", "Eagles",  "49ers",   "Patriots" };
const bool    active[] = { true,      false,    false,     false,     true       };

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

	ptr_myfile = fopen("CmpSc472_BinaryFile.bin","wb");
	if(!ptr_myfile)
	{
		printf("Unable to open file!");
		return 1;
	}
	for(int i = 0; i < 5; i++)
	{
		strcpy(my_NFL_QB.lastName, names[i]);
		my_NFL_QB.jerseyNum = jerseys[i];
		strcpy(my_NFL_QB.posn, posns[i]);
		my_NFL_QB.speedTest = speeds[i];
		strcpy(my_NFL_QB.team, teams[i]);
		my_NFL_QB.isActive = active[i];
			fwrite(&my_NFL_QB, sizeof(struct st_NFL_QB), 1, ptr_myfile);
	}
	fclose(ptr_myfile);
	return 0;
}
