#include<stdio.h>

int main ()
{
	FILE *fp;

	fp = fopen ("new_file.txt", "w");

	fprintf (fp, "Hello world");

	fclose (fp);
}
