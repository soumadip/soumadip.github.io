#include<stdio.h>
#include<string.h>


int main ()
{
	char str1[30] = "A string";
	char str2[30] = "Another string";
	char str3[30];

	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	printf("length of str1 = %ld\n", strlen(str1));
	printf("length of str2 = %ld\n", strlen(str2));
	strcpy(str3, str1);
	printf("str3 after strcpy l= %s\n", str3);
	strcat(str1, str2);
	printf("str1 after strcat = %s\n", str1);
	printf("str2 after strcat = %s\n", str2);

	printf("occurance of 'A' in str1 from  %s\n", strchr(str1, 'A'));
	printf("occurance of 'a' in str1 from  %s\n", strchr(str1, 'a'));
	printf("occurance of 's' in str1 from  %s\n", strchr(str1, 's'));
	printf("occurance of 2nd 's' in str1 from  %s\n", strchr(strchr(str1, 's')+1, 's'));

	return 0;
}
