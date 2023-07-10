#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int count, char* args[])
{
	int i;
	if (count == 1)
		printf ("No arguments supplied\n");
	else
	{
		for (i=0; i< count; i++)
		{
			if (strcmp("f", args[i]) == 0)
			{
				printf("%f\n", strtof(args[i+1], NULL));
				i++;
			}
			else if (strcmp("i", args[i]) == 0)
			{
				printf("%d\n", atoi(args[i+1]));
				i++;
			}
			else
				printf ("%s\n", args[i]);
		}
	}

	return 0;
}
