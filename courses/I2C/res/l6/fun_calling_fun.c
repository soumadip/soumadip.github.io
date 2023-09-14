#include<stdio.h>

void fun1 ();
void fun2 ();
void fun3 ();
void fun4 ();
void fun5 ();

int main ()
{
	printf("in main, Calling FUN 1\n");
	fun1 ();
	printf ("in main, FUN 1 returned\n\n");

	printf("in main, Calling FUN 2\n");
	fun2 ();
	printf ("in main, FUN 2 returned\n\n");

	printf("in main, Calling FUN 3\n");
	fun3 ();
	printf ("in main, FUN 3 returned\n\n");

	printf("in main, Calling FUN 4\n");
	fun4 ();
	printf ("in main, FUN 4 returned\n\n");
	
	printf("in main, Calling FUN 5\n");
	fun5 ();
	printf ("in main, FUN 5 returned\n\n");
}

void fun1 ()
{
	printf ("in fun1\n");
}


void fun2 ()
{
	printf("in fun2, Calling FUN 3\n");
	fun3();
	printf ("in fun2, FUN 3 returned\n\n");
}


void fun3 ()
{
	printf("in fun3, Calling FUN 4\n");
	fun4();
	printf ("in fun3, FUN 4 returned\n\n");
	
}


void fun4 ()
{
	printf ("in fun4\n");
}


void fun5 ()
{
	printf ("in fun5, doing something\n");

	printf("in fun5, Calling FUN 3\n");
	fun3();
	printf ("in fun5, FUN 3 returned\n\n");

	printf ("in fun5, doing something more\n");

	printf("in fun5, Calling FUN 4\n");
	fun4();
	printf ("in fun5, FUN 4 returned\n\n");
}


