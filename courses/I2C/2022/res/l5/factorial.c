#include<stdio.h>

int fact (int n)
{
	int i, result = 1;
	if (n==0)
		return 1;
	for (i = 1; i < n; i++)
	{
		result *= i;
	}
	return result;
	
	//return n==0 ? 1 : n*fact(n-1);
}

int main ()
{
	int n;

	printf ("Enter number:: ");
	scanf ("%d", &n);
	printf ("%d! = %d\n", n, fact(n));
}
