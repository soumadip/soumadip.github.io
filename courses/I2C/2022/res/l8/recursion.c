#include<stdio.h>


int fact (int n) // f(n) = n*f(n-1), f(0) = 1
{
	// assume that n is always valid, i.e. n>=0 , don't worry about checking validation for now.
	if ( n==0) //the base case condition
		return 1;
	else
		return n* fact(n-1); // call recursion
}

int fibbo (int n) // f (n) = f (n-1) + f(n-2), f(0) = 0, f(1) = 1
{
	// assume that n is always valid, i.e. n>=0 , don't worry about checking validation for now.
	if (n == 0 || n == 1) // base case
		return n;
	else
		return fibbo(n-1) + fibbo(n-2); //recursion
}


int power (int x, int y)
{
	return (y==0) ? 1 : x * power (x, y-1);
}

int main ()
{
	printf ("factorial of 5 = %d\n", fact (5));
	printf ("tenth fibbonacci number = %d\n", fibbo (10));
	printf ("11^7 = %d\n", power(11, 7));
}
