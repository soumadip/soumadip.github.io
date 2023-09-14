#include<stdio.h>

#define MAXSIZE 100

float mean (int arr[], int n)
{
	float result;
	int i, sum=0;
	printf ("in mean: size of array : %ld\n", sizeof (arr)); //important distinction
	for (i=0; i <n; i++)
		sum += arr[i];
	result = sum / n;
	return result;
}

float mean2 (int *arr, int n)
{
	float result;
	int i, sum=0;
	printf ("in mean2: size of array : %ld\n", sizeof (arr)); //important distinction
	for (i=0; i <n; i++)
		sum += arr[i];
	result = sum / n;
	return result;
}

int main ()
{
	int A[MAXSIZE], n, i;

	printf ("in main: size of array : %ld\n", sizeof (A)); //check the value here

	printf ("Enter number of elements: ");
	scanf ("%d", &n);

	for (i=0; i<n; i++)
		scanf("%d", &A[i]);

	printf ("Mean of the %d elements is: %f\n", n, mean (A, n));
}
