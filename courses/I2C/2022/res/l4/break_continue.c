#include<stdio.h>

int main ()
{
	int i, j, k;

	printf ("LOOP 1 using break\n");
	for (int i = 0; i <10; i++)
	{
		printf ("Line before break; this is iteration number %d\n", i);
		if (i == 6)
			break;
		printf ("Line after break; this is iteration number %d\n", i);
	}
	printf ("LOOP 2 using continue\n");
	for (int i = 0; i <10; i++)
	{
		printf ("Line before continue; this is iteration number %d\n", i);
		if (i >= 3)
			continue;
		printf ("Line after continue; this is iteration number %d\n", i);
	}
}

