#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *strct(char *dest,char *src)
{
	int i,j;
	for (i = 0; dest[i] != '\0'; i++){}
	for (j = 0; src[j] != '\0'; j++)
		dest[i+j] = src[j];
	dest[i+j] = '\0';
return dest;
}
int main()
{
	int i,j,testcase;
	char str1[20]="./tree_asc<",str2[20]="./tree<",*str;
	scanf("%d",&testcase);

	i=0;
	system("gcc tree_asc.c -o tree_asc");
	system("gcc tree.c -o tree");
	str=(char*)malloc(sizeof(char)*20);
	while(i<testcase)
	{
		for(j=0;j<3;j++)
		{
			scanf("%s",str);
			if(j==0)
			{
				strcpy(str,strct(str1,str));
				system(str);
				strcpy(str1,"./tree_asc<\0");
			}
			else 
			{
				strcpy(str,strct(str2,str));
				system(str);
				strcpy(str2,"./tree<\0");
			}
		}
		i++;
	}
printf("\n");
return 0;
}


