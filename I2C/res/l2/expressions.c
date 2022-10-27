#include<stdio.h>

int main ()
{
	int a, b, c, d;

	a = 20; b = 11;

	//arithmatic
	printf ("%d\n", a+b);
	printf ("%d\n", a-b);
	printf ("%d\n", a*b);
	printf ("%d\n", a/b);


	//logical
	printf ("%d\n", a && b);
	printf ("%d\n", a || b);
	printf ("%d\n", !b);

	//assignment
	c = a;
	printf ("%d\n", c);

	d = b + c;
	printf ("%d\n", d);

	d+=2;
	printf ("%d\n", d);

	c-=2;
	printf ("%d\n", c);

	c = c*2;
	printf ("%d\n", c);


}
