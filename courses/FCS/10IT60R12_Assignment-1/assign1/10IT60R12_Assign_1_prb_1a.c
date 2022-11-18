#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int i,j,k,n;
int *ptr;
int ch;
FILE* fp;
char str[20]="";
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
ptr=(int*)malloc(sizeof(int)*n);
fp= fopen("data.dat","r");
j=0;k=0;
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
			ptr[k]=atoi(str);
			k++;
		
	}}
fclose(fp);
printf("\n data from array");
for(i=0;i<n;i++)
{
	printf("%4d",ptr[i]);
}
printf("\n");
}
