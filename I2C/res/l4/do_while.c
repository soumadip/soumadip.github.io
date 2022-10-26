#include<stdio.h>

int main ()
{
	//this is a comment
	char x = 'l';

	do
	{
		printf ("Enter choice y/x --> ");
		scanf("%c", &x);
		switch (x)
		{
			case 'y':
				printf ("Yes\n");
				break;
			case 'n':
				printf ("No\n");
				break;
			default:
				printf ("Invalid\n");
				return 0;
		}
		getchar ();
	}
	while (1);

	return 0;
}
