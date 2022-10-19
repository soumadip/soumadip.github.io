#include<stdio.h>
#include<string.h>

#define SIZE 100

int main ()
{
	char arr[SIZE];
	char ch, tmp[SIZE];
	int coeff, expo, i, j, k=0;

	printf ("ENTER POLYNOMIAL IN the following format: \nAx^i + Bx^j + Cx^k + D\n\t--> ");
	scanf ("%[^\n]c", arr);
	i = strlen (arr);
	arr[i+1] = arr[i];
	arr[i] = '+';	
	printf ("%s\n", arr);

	i = 0;
	j = 0;
	coeff = 0;
	expo = 0;
	while ((ch = arr[i]) != '\0')
	{
		switch (ch)
		{
			case '+':
				k = 0;
				while (k < j)
				{
					if (tmp[k] == 'x')
						break;
					coeff *= 10;
					coeff += tmp [k] - '0';
					k++;
				}
				k+=2;
				while (k < j)
				{
					expo *= 10;
					expo += tmp [k] - '0';
					k++;
				}

				j=0;

				printf ("coeff-->%d expo-->%d\n", coeff, expo);
				coeff = 0;
				expo = 0;
			case ' ':
				i++;
				break;
			default:
				tmp[j++] = ch;
				i++;
		}
	}
}
