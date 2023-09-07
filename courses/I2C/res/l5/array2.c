#include<stdio.h>

int main ()
{
	int n;

	scanf("%d", &n);

	int a[n];

	for (int i=0; i <n; i++)
	{
		printf ("[%p] %d --> %d\n", &a[i], i, a[i]);
	}
	printf ("\n");
	for (int i=0; i <n; i++)
	{
		printf ("Enter val for position %d ::", i);
		scanf ("%d", &a[i]);
	}
	for (int i=0; i <n; i++)
	{
		printf ("[%p] %d --> %d\n", &a[i], i, a[i]);
	}

	printf ("\n another way of accessing elements of an array\n");
	for (int i=0; i <n; i++)
	{
		printf ("[%p] %d --> %d\n", a+i, i, *(a+i));
	}
}
