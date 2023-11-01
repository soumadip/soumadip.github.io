#include <stdio.h>
#include<string.h>

// Driver code
int main()
{
char arr[3][10] = {"IACS", "UG", "2022"};

for (int i = 0; i < 3; i++)
{
	printf("%s --> ", arr[i]);
	printf("%ld, %ld\n", strlen(arr[i]), sizeof (arr[i]));
}
printf("%ld\n", sizeof arr);
return 0;
}

