#include<stdio.h>

int main (int count, char* args[])
{
	int i;
	if (count == 1)
		printf ("No arguments supplied\n");
	else
	{
		for (i=0; i< count; i++)
		{
			printf ("%s\n", args[i]);
			
		}
	}

	return 0;
}
