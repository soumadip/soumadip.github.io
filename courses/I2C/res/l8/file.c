#include<stdio.h>
#include<stdlib.h>

int main ()
{
	FILE *fp;

	fp = fopen ("new_file.txt", "w");
	//fp = fopen ("new_file.txt", "r");

	if(fp== NULL)
	{
		perror("fail\n");
		exit(-1);
	}

	fprintf (fp, "Hello world");

	fclose (fp);
}
