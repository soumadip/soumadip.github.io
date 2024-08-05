#include<stdio.h>

int main ()
{
	double *buf[3];

	double d0 = 8, d1[2] = {11, 12}, d2 = 10;
	buf[0] = &d0; buf[1] = &d1[0]; buf[2] = &d2;

	printf("%ld, %ld \n", sizeof(double*), sizeof(buf));
	//prints 8, 24

	printf("%p, %p, %p, %lf \n", buf, &buf[0], buf[1], *buf[1]);
	//prints 0xbfed51d4, 0xbfed51d4, 0xbfed51e0, 11.000000
	
	printf("%lf %lf\n", buf[1][0], buf[1][1]);

}
