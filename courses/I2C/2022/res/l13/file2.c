#include<stdio.h>


int main ()
{
	FILE *fp = fopen("abc.txt", "r");
	char buf[10]; int num; char c;
	if (fp != NULL) {
		c = fgetc(fp);  
		printf ("%c", c);
		fgets(buf, 4, fp);  
		printf("%s", buf);
		fscanf(fp, "%d, %c, %s", &num, &c, buf);
		printf ("%d %c %s", num, c, buf);
		fclose(fp);
	}

}

