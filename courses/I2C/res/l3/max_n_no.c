#include<stdio.h>

int main ()
{
	int n, max=0, count = 0;

	printf ("Enter Positive integers one by one, this program will keep track of the maximum number. Enter 0 or negetive number to exit.\n");
	while (1)
	{
		printf ("enter no:: ");
		scanf ("%d", &n);
		if (n <= 0)
			break;

		count++;

		if (n>max)
			max = n;

		printf ("The current max is :: %d\n", max);
	}

	printf ("Final max value of total %d input numbers is %d", count, max);
}
