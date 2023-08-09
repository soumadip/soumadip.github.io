#include <stdio.h>


struct my_type
{
	int i;
	float f;
};

typedef struct my_type mt;

int main ()
{
	struct my_type m1;
	mt m2;

	mt *ptr;

	m1.i = 10;
	m1.f = 3.14;

	m2.i = 100;
	m2.f = 31.4;

	printf ("Values of m1: %d %f\n", m1.i, m1.f);
	printf ("values of m2: %d %f\n", m2.i, m2.f);

	ptr = &m2;
	printf ("usign pointer, value of m2: %d %f\n", (*ptr).i, (*ptr).f);
	printf ("another way : %d %f\n", ptr->i, ptr->f);

	ptr->i = 1;
	ptr->f = .314;
	printf ("values of m2 :%d %f\n", ptr->i, ptr->f);

}
