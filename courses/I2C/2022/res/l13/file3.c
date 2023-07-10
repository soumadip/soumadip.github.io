#include<stdio.h>


int main ()
{
	char c, buf[256];

	FILE *fp = fopen("abc.txt", "r"); 
	if (fp != NULL) { 
		while (!feof(fp)) { 
			c = fgetc(fp); 
			if (c == 'a') 
				ungetc('b', fp); 
			fgets(buf, 255, fp); 
			printf("%s", buf); 
		} 
	}
}

