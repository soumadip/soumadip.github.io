#include<stdio.h>


int main ()
{
	FILE *fp = fopen("abc.txt", "w");

	if (fp != NULL) {
		fputc('a', fp);
		fputs("cde", fp);
		fprintf(fp, "%d, %c, %s", 25, 'I', "hello");
		fflush(fp);
		fclose(fp);
	}


}

