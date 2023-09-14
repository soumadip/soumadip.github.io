#include<stdio.h>

#define SIZE 10

int i;

print1 (int b[])
{
	printf ("\nSTART OF Print 1\n");
	printf ("printing b as int: %d\n", b);

	for (i = 0; i < SIZE; i++)
		printf ("%d  ", b[i]);
	printf ("\nEND OF Print 1\n");

}
print2 (int a[])
{
	printf ("\nSTART OF Print 2\n");
	printf ("sizeof (a) = %d\n",sizeof (a));
	printf ("printing a = %d (as int)\n", a);
	printf ("printing a = %p (as address)\n", a);
	printf ("\nEND OF Print 2\n");
}
print22 (int *a)
{
	printf ("\nSTART OF Print 22\n");
	printf ("sizeof (a) = %d\n",sizeof (a));
	printf ("printing a = %d (as int)\n", a);
	printf ("printing a = %p (as address)\n", a);
	printf ("\nEND OF Print 22\n");
}
print3 (int *a, int n)
{
	printf ("\nSTART OF Print 3\n");
	for (i = 0; i < n; i++)
		printf ("%d  ", a[i]);
	printf ("\nEND OF Print 3\n");
}
print4 (int *a, int n)
{
	printf ("\nSTART OF Print 4\n");
	for (i = 0; i < n; i++)
		printf ("%p --> %d (%p) \n", &a[i], a[i], a+i);
	printf ("\n\n");
	printf ("\nEND OF Print 4\n");
}
print5 (int *a, int n)
{
	printf ("\nSTART OF Print 5\n");
	for (i = 0; i < n; i++)
		printf ("%d  ", a[i]);
	printf ("\nEND OF Print 5\n");
}


int main ()
{
	int a[10] = {1,2,3};
	int b[SIZE] = {10,20,30};
	
	
	printf ("In main : values of array a\n");
	for (i = 0; i < 10; i++)
		printf ("%p --> %d (%p) \n", &a[i], a[i], a+i);
	printf ("\n\n");
	printf ("In main : values of array b\n");
	for (i = 0; i < 10; i++)
		printf ("%p --> %d (%p) \n", &a[i], a[i], a+i);
	printf ("\n\n");

	print1 (b);
	print2 (a);
	print22 (a);
	print3 (a, 10);
	print4 (a, 10);
	print5 (a, 10);
}
