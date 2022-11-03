#include<stdio.h>

int main ()
{

	int arr[10];
	int i, key;
	for (i=0; i< 10; i++)
		scanf("%d", &arr[i]);

	printf ("enter key :: "); scanf ("%d", &key);
	printf ("\n key entered is %d\n", key);

	for (i=0; i< 10;i++)
		if (key == arr[i])
		{
			printf ("Found");
			return 0;
		}
	printf ("Not found");
}
