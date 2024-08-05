#include<stdio.h>

//int make_half (int);
int make_half (int x);

int main ()
{
	int a = 100, b;
	
	b = make_half (a);

	printf ("Value of b is %d\n", b);
}


int make_half (int x)
{
	int result;
	printf ("Value of x as parameter is %d\n", x);
	result = x / 2;
	return result;
}


