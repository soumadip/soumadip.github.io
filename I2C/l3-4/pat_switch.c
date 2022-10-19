#include<stdio.h>

int main ()
{
	int i, j;

	int n, ch;

	printf ("n = ");
	scanf ("%d", &n);

	printf ("switch_case_choice = ");
	scanf ("%d", &ch);
	switch (ch)
	{
		case 1:
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf ("* ");
			}
			printf ("\n");
		}
		break;
		
		case 2:
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf ("* ");
			}
			printf ("\n");
		}
		break;

		case 3:
		for (i = 0; i < n; i++)
		{
			for (j = i; j < n; j++)
			{
				printf ("* ");
			}
			printf ("\n");
		}
		break;
		
		case 4:
		for (i = 0; i < n; i++)
		{
			for (j = i; j < n; j++)
			{
				printf ("1");
			}
			for (j = 0; j <= i; j++)
			{
				printf ("0");
			}
			printf ("\n");
		}
		break;
		
		case 5:
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf (" ");
			}
			for (j = i; j < n; j++)
			{
				printf ("* ");
			}
			printf ("\n");
		}
		break;

		case 6:
		for (i = 0; i < n; i++)
		{
			for (j = i; j < n; j++)
			{
				printf ("  ");
			}
			for (j = 0; j < i; j++)
			{
				printf ("* ");
			}
			printf ("\n");
		}
		break;

		case 7:
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf ("* ");
			}
			for (j = 2; j < 2 * (n-i); j++)
			{
				printf ("  ");
			}
			for (j = 0; j <= i; j++)
			{
				printf ("* ");
			}
			printf ("\n");
		}
		break;

		case 8:
		for (i = 0; i < n; i++)
		{
			for (j = i; j < n; j++)
			{
				printf (" ");
			}
			for (j = 0; j <= i; j++)
			{
				printf ("* ");
			}
			printf ("\n");
		}
		for (i = 1; i < n; i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf (" ");
			}
			for (j = i; j < n; j++)
			{
				printf ("* ");
			}
			printf ("\n");
		}

		default:
	}
}
