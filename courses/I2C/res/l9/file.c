#include<stdio.h>

int main()
{
	char c, buf[256]; int num;
	FILE *fp = fopen("abc.txt", "w"); 
	if (fp != NULL) { 
		fputc('a', fp); 
		fputs("cde", fp); 
		fprintf(fp, "%d, %c, %s", 25, 'I', "hello");
		fflush(fp); 
		fclose(fp); 
	}

	fp = fopen("abc.txt", "r"); 
	if (fp != NULL) { 
		c = fgetc(fp);     printf ("c = %c\n", c); 
		fgets(buf, 4, fp); printf ("buf = %s\n", buf);
		fscanf(fp, "%d, %c, %s", &num, &c, buf);
		printf ("num = %d c = %c buf = %s\n", num, c, buf);
		fclose(fp); 
	}

	fp = fopen("abc.txt", "r"); 

	if (fp != NULL) { 
		while (!feof(fp)) { 
			c = fgetc(fp); 
			if (c == 'a') 
				ungetc('b', fp); 
			fgets(buf, 255, fp); 
			printf("%s\n", buf); 
			} 
	}
	return 0;
}
