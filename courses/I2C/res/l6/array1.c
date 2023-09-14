#include<stdio.h>
#include<limits.h>

#define SIZE 10

int main ()
{
	int arr[SIZE];
	int i, sum, max, min;

	printf ("Enter elements...\n");
	for (i = 0; i < SIZE; i++)
	{
		printf ("elem[%d]: ", i);
		scanf ("%d", &arr[i]);
	}

	//print all elements
	printf ("All elements\n");
	for (i = 0; i < SIZE; i++)
	{
		printf ("arr[%d] = %d\n", i, arr[i]);
	}

	//print all elements in reverse
	printf ("All elements in reverse order\n");
	for (i = SIZE-1; i >= 0; i--)
	{
		printf ("arr[%d] = %d\n", i, arr[i]);
	}

	//print all alternative elements
	printf ("All alternative elements\n");
	for (i = 0; i < SIZE; i+=2)
	{
		printf ("arr[%d] = %d\n", i, arr[i]);
	}

	//sum of  all elements
	sum = 0;
	for (i = 0; i <SIZE; i++)
		sum += arr[i];
	printf ("Sum of all elements:: %d\n", sum);
	printf ("Mean of all elements:: %d\n", sum/SIZE);
	printf ("Median of all elements:: %d\n", arr[SIZE/2]);

	//max and min of all elements
	max = INT_MIN;
	min = INT_MAX;
	for (i = 0; i <SIZE; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	printf ("Maximum of all elements:: %d\n", max);
	printf ("Minimum of all elements:: %d\n", min);
}
