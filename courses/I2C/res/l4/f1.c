#include<stdio.h>

void print_line ()
{
	printf ("************************\n");
	printf ("************************\n");
	printf ("************************\n");
	return; //move this return around and see the difference in outputs
}

int main ()
{
	print_line ();
	printf("New\n");
	print_line ();
	print_line ();

	return 11;
}
