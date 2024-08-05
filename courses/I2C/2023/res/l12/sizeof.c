#include<stdio.h>

int main ()
{
	int a[5];
	int *arr;
	arr = a;

	printf ("%d, %d, %d, %d", sizeof a, sizeof arr, sizeof a[1], sizeof(int));
}
