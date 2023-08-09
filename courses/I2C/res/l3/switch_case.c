#include<stdio.h>

int main ()
{
	int choice;

	printf ("Enter Choice (1-5):: ");
	scanf ("%d", &choice);

	switch (choice)
	{
		default:
			printf ("You chose outside 1-5");
		case 1:
			printf ("you chose 1");
			break;
		case 2:
			printf ("you chose 2");
		case 3:
			printf ("you chose 3");
		case 4:
			printf ("you chose 4");
			break;
		case 5:
			printf ("you chose 5");
			break;
	}

	return 0;
}
