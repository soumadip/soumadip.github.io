#include<stdio.h>

int swap (int x, int y);
int main ()
{
	int a=100, b=200;

	printf ("[M]Values: a = %d, b = %d\n", a, b);
	swap (a, b);
	printf ("[M]Values: a = %d, b = %d\n", a, b);
}
int swap (int a, int b)
{
	int tmp;
	printf ("[F]Values: a = %d, b = %d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf ("[F]Values: a = %d, b = %d\n", a, b);
	return 0;
}
