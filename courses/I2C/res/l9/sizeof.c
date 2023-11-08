#include<stdio.h>

int main ()
{
	int a[5];
	int *arr;
	arr = a;

	printf ("%ld, %ld, %ld, %ld", sizeof a, sizeof arr, sizeof a[1], sizeof(int));
}
