#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void sortMLB(char **teams, double *winPerc, int numTeams);

void printMLB(char **teams, double *winPerc, int numTeams);

int main(int argc, char **argv)

{

int const maxSize = 50;

int const numTeams = 16;

char filePath[] = "mlb_nl_2011.txt";

char tempBuffer[100];

FILE *fptr;

char* token;

int i;

char line[BUFSIZ];

int win,loss,total;

double per;

char **teams = (char **)malloc(sizeof(char *) * numTeams);

double *winPercentages = (double *)malloc(sizeof(double) * numTeams);

for(i = 0; i < numTeams; i++)

{

teams[i] = (char *)malloc(sizeof(char) * maxSize);

}

// TODO: open the file, read it line by line, tokenize it to get the

// team name, wins, and losses, and store the results into

// teams[] and winPercentagesp[]

if ((fptr = fopen(filePath, "r")) == NULL)

{

printf("Error! opening file");

// Program exits if file pointer returns NULL.

exit(1);

}

i=0;

while (fgets(line, sizeof line, fptr) != NULL)

{

token = strtok(line, " ");

strcpy(teams[i], token);

token = strtok(NULL, " ");

win=atoi(token);

token = strtok(NULL, " ");

loss=atoi(token);

total=win+loss;

per=(double)win/(double)total;

winPercentages[i]=per;

i++;

}

// sort them

sortMLB(teams, winPercentages, numTeams);

// print them out

printMLB(teams, winPercentages, numTeams);

return 0;

}

void sortMLB(char **teams, double *winPerc, int numTeams)

{

int i, j, max_index;

char tmp_str[100];

double tmp_dbl;

// for each element i

for (i = 0; i < numTeams - 1; i++)

{

max_index = i;

// find the maximum element among elements i+1 thru n-2

for (j = i + 1; j < numTeams; j++)

{

if (winPerc[max_index] < winPerc[j])

{

max_index = j;

}

}

// swap the ith element and the maximum element

// in this case, elements from both arrays need to be swapped

// at the same time; forgo swapping if it is in-place

if(i != max_index)

{

tmp_dbl = winPerc[i];

winPerc[i] = winPerc[max_index];

winPerc[max_index] = tmp_dbl;

strcpy(tmp_str, teams[i]);

strcpy(teams[i], teams[max_index]);

strcpy(teams[max_index], tmp_str);

}

}

}

void printMLB(char **teams, double *winPerc, int numTeams)

{

int i = 0;

printf("%-12s %-10s\n", "TEAM", "WIN PERC");

for (i = 0; i < numTeams; i++)

{

printf("%-12s %.3f%%\n", teams[i], winPerc[i] * 100.0);

}

}