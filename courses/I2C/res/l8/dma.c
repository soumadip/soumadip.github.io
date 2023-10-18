#include<stdlib.h>
#include<stdio.h>


int main ()
{
	int *ptr = malloc(sizeof(int));

	*ptr = 100;

	printf("val : %d\n", *ptr);
	printf("address: %p\n", ptr);

	printf("Enter new value : ");
	scanf("%d", ptr);
	int *arr = malloc(*ptr * sizeof(int));

	for(int i=0; i <*ptr; i++)
		scanf("%d", &arr[i]);

	for(int i=0; i <*ptr; i++)
		printf("[%p] %d\n", arr+i, *(arr+i));

	free(ptr);
	free(arr);

}

