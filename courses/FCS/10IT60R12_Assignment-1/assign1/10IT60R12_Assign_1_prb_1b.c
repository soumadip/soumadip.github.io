#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int i,j,k,n;
char **ptr;
int ch;
FILE* fp;
char *str;
printf("Enter size of array: ");
scanf("%d",&n);
/*fp= fopen("data.dat","w");
printf("\nEnter data to store...<Use # as EOF>");
fflush(stdin);
printf("1");
		while((ch=getchar())!='#')
		{
			putc(ch,fp);
		}
putc('#',fp);
fclose(fp);*/
ptr=(char**)malloc(sizeof(char*)*n);
fp= fopen("data_str.dat","r");
j=0;k=0;
str=(char*)malloc(sizeof(char)*20);
while((ch=fgetc(fp))!='#')
	{
		if(ch!='\n' && ch!=' ')
		{
			str[j]=ch;
			j++;
		}
		else
		{
			str[j]='\0';
			j=0;
//printf("%s",str);
			ptr[k]=str;
printf("%s",ptr[k]);
	str=(char*)malloc(sizeof(char)*20);
			k++;
	
	}}
fclose(fp);
printf("\n data from array\n");
for(i=0;i<n;i++)
{
	printf("%4s",ptr[i]);
}
printf("\n");
}
