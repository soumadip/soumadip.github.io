#include<stdio.h>

int main ()
{
	int fn = 1, fn_1 = 0, tmp;

	int count, max = 20;

	printf ("FIBBONACCHI SERIES:: %5d", fn_1);
	count  = 1;
	while (1)
	{
		printf ("%5d", fn);
		count++;

		if (count == max)
			break;
		
		tmp = fn + fn_1;
		fn_1 = fn;
		fn = tmp;
		//fn = fn + fn_1;
		//fn_1 = fn - fn_1;
	}
}
