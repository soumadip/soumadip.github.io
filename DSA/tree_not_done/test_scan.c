#include<stdio.h>
#include <stdlib.h>

void  cs ()
{
	char ch;
	while (ch = getchar ())
		if (ch == '\n')
			break;
}
int main ()
{
	int a;
	char b,c;

	do 
	{
		printf ("choice--> ");
		scanf ("%c", &b);

		switch (b)
		{
			case 'a':
				printf ("case a [%d]\n", b);
				printf ("enter int :: ");
				scanf ("%d", &a);
				break;
			case 'b':
				printf ("case b [%d]\n", b);
				break;
			default :
				printf ("[%d] confirm (y)--> ", b);
				cs();
				scanf ("%c", &c);
				if (c == 'y')
					exit(0);
		}
		cs();

	}
	while (1);

}

