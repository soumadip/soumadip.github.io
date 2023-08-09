#include <stdio.h>

#define size 100

    void main()
    {
	//const int size = 100;
        int i, a[size], n, max;
	//printf("Enter no of elements (1-100)");
	//scanf ("%d", &n);

	for (i=0; i<size; i++)
		scanf ("%d", &a[i]);

	max = a[0];
	for (i = 0; i <size; i++)
	{
		if (a[i] >max)
			max = a[i];
	}
	printf ("The max value is %d\n", max);
	

    }
