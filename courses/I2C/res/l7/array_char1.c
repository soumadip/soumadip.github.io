#include<stdio.h>

#define size 10

void print_decimals_of_array (char arr[])
{
	int i;
	for (i = 0; i<size; i ++)
	{
		printf ("[%3d] ",arr[i]);
	}
	printf ("\n");
	for (i = 0; i<size; i ++)
	{
		printf ("[%3d] ",i);
	}
	printf ("\n");
}

int main ()
{
	char name[size];

	print_decimals_of_array(name);

	scanf("%s", name);
	//scanf ("%[^ ]%*c", name);
	print_decimals_of_array(name);

	scanf("%s", name);
	print_decimals_of_array(name);
	
	scanf("%s", name);
	print_decimals_of_array(name);
	
	scanf("%s", name);
	print_decimals_of_array(name);
	
	scanf("%s", name);
	print_decimals_of_array(name);
	
	scanf("%s", name);
	print_decimals_of_array(name);
}
