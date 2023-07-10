#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
	//char ch;
	int size;
	char *str;

	str  = (char*)malloc(sizeof(char));
	size = 1;

	printf ("Enter string of any length \n");
	while ('\n' != (str[size++ - 1] = fgetc(stdin)))
		str = realloc(str, size*sizeof(char));
/*	while (1)
	{
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		else
			str[size-1] = ch;
		size++;
		str = realloc (str, size*sizeof(char));
	}	*/
	str [size] = '\0';

	printf ("%s\n", str);
	printf ("lenth of the input string: %ld", strlen (str));
	free(str);

	return 0;
}
