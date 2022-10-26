#include<stdio.h>

int main ()
{
	int i, j, k;

	printf ("LOOP 1\n");
	for (int i = 0; i <10; i++)
	{
		if (i == 6)
			break;
		printf ("this is iteration number %d\n", i);
	}
	printf ("LOOP 2\n");
	for (int i = 0; i <10; i++)
	{
		printf ("this is iteration number %d\n", i);
		if (i == 6)
			break;
	}
	printf ("LOOP 3\n");
	for (int i = 0; i <10; i++)
	{
		if (i >= 3)
			continue;
		printf ("this is iteration number %d\n", i);
	}
	printf ("LOOP 4\n");
	for (int i = 0; i <10; i++)
	{
		printf ("this is iteration number %d\n", i);
		if (i >= 3)
			continue;
	}
}

