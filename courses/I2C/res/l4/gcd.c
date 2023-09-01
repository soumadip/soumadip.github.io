#include<stdio.h>
int gcd (int, int);​

int main ()
{
	int a = 10, b = 7;

	printf("gcd of %d and %d is %d", a, b, gcd(a,b));
	return 0;
}


int gcd (int A, int B) ​
{ ​
	int temp; ​
	while ((B % A) != 0) ​
	{ ​
		temp = B % A; ​
		B = A; ​
		A = temp; ​
	} ​
return (A); ​
}​