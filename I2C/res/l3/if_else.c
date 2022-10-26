#include<stdio.h>

int main ()
{
	int a, b, large;

	printf ("Enter value of a:: ");
	scanf ("%d", &a);
	printf ("Enter value of b:: ");
	scanf ("%d", &b);

	if (a>b)
		large = a;
	else
		large = b;
	printf ("The large value is %d", large);

	return 0;
}
