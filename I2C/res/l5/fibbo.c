#include<stdio.h>

int fib (int n)
{
	int fn_1 = 0, fn = 1, result;
	if (n == 0)
		return fn_1;
	else if (n == 1)
		return fn;
	else
	{
		while (n-- - 1)
		{
			result = fn + fn_1;
			fn_1 = fn;
			fn = result;
		}
		return result;
	}
}

int main ()
{
	int n;

	printf ("Enter number:: ");
	scanf ("%d", &n);

	printf ("%dth fibbonaci number is %d", n, fib(n));
}
