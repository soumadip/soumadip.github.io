#include<stdio.h>

int main ()
{
	int a, b, large;

	printf ("Enter value of a:: ");
	scanf ("%d", &a);
	printf ("Enter value of b:: ");
	scanf ("%d", &b);

	large = a>b ? a : b;
	printf ("The large value is %d", large);
}
