#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int i,j,k,m,p,n;
int **ptr1,**ptr2,**ptr3;
int ch;
FILE *fp1,*fp2;
char str[20]="";
//printf("Enterm,p.n-->");
//scanf("%d%d%d",&m,&P,&n);
m=3;p=4;n=2;
ptr1=(int**)malloc(sizeof(int*)*m);
for(i=0;i<m;i++)
	ptr1[i]=(int*)malloc(sizeof(int)*p);
fp1= fopen("data1.dat","r");
i=0;j=0;k=0;
while((ch=fgetc(fp1))!='#')
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
			ptr1[i][k]=atoi(str);
			if(k<p-1)	k++;
			else{
				i++;k=0;
				}
		
	}}
fclose(fp1);
ptr2=(int**)malloc(sizeof(int*)*p);
for(i=0;i<p;i++)
	ptr2[i]=(int*)malloc(sizeof(int)*n);

fp2= fopen("data2.dat","r");
i=0;j=0;k=0;
while((ch=fgetc(fp2))!='#')
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
			ptr2[i][k]=atoi(str);
			if(k<n-1)	k++;
			else{
				i++;k=0;
				}
						
	}}
fclose(fp2);
printf("\n A[%d*%d]\n",m,p);
for(i=0;i<m;i++)
{
	for(j=0;j<p;j++)printf("%4d",ptr1[i][j]);
printf("\n");
}
printf("\n B[%d*%d]\n",p,n);
for(i=0;i<p;i++)
{
	for(j=0;j<n;j++)printf("%4d",ptr2[i][j]);
printf("\n");
}
ptr3=(int**)malloc(sizeof(int*)*m);
for(i=0;i<m;i++)
	ptr3[i]=(int*)malloc(sizeof(int)*n);
for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
		ptr3[i][j]=0;
		for(k=0;k<p;k++)
			ptr3[i][j]=ptr3[i][j]+ptr1[i][k]*ptr2[k][j];
	}
printf("\n C[%d*%d]\n",m,n);
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)printf("%8d",ptr3[i][j]);
printf("\n");
}
}
