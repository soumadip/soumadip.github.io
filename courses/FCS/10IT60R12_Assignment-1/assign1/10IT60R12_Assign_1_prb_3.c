#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int i,j,m,n,choice;
int **A;
char ch;
while(1){
lswitch:
printf("	1:lower triangular\n	2:upper Triangular\n	3:tri Diagonal\nAny Other Key:exit\n 	choice::");
scanf("%d",&choice);
switch(choice)
{
case 1:goto lebel1;break;
case 2:goto lebel2;break;
case 3:goto lebel3;break;
default:exit(0);
}
lebel1:
printf("size of matrix-->");
scanf("%d%d",&m,&n);
A=(int**)malloc(sizeof(int*)*m);
for(i=0;i<m;i++)
	A[i]=(int*)malloc(sizeof(int)*n);
printf("Enter element of lower triangular matrics--->\n");
for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{if(j<n-i){
	printf("\n[%d,%d]=",i,j);
	scanf("%d",&A[i][j]);
		}
	else
	A[i][j]=0;
	}
printf("DONE!!\nAccess...\n\n");
for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	printf("%4d",A[i][j]);
	printf("\n");
	}
/*l1:
printf("enter loc::");
scanf("%d%d",&i,&j);
printf("Ans-->%d\n",A[i][j]);
printf("again?<y/n>");
scanf("%c",&ch);
if(ch=='y') goto l1;
*/goto lswitch;

lebel2:
printf("size of matrix-->");
scanf("%d%d",&m,&n);
A=(int**)malloc(sizeof(int*)*m);
for(i=0;i<m;i++)
	A[i]=(int*)malloc(sizeof(int)*n);
printf("Enter element of upper triangular matrics--->\n");
for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{if(j>=(n-i-1)){
	printf("\n[%d,%d]=",i,j);
	scanf("%d",&A[i][j]);
		}
	else
	A[i][j]=0;
	}
printf("DONE!!\nAccess...\n\n");
for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	printf("%4d",A[i][j]);
	printf("\n");
	}
/*l2:
printf("enter loc::");
scanf("%d%d",&i,&j);
printf("Ans-->%d\n",A[i][j]);
printf("again?<y/n>");
scanf("%c",&ch);
if(ch=='y') goto l2;
*/goto lswitch;

lebel3:
printf("size of matrix-->");
scanf("%d%d",&m,&n);
A=(int**)malloc(sizeof(int*)*m);
for(i=0;i<m;i++)
	A[i]=(int*)malloc(sizeof(int)*n);
printf("Enter element of tri diagonal matrics--->\n");
for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{if(j>=n-i+1)
		A[i][j]=0;
	else if(j<n-i-2)
		A[i][j]=0;
else{		
	printf("\n[%d,%d]=",i,j);
	scanf("%d",&A[i][j]);}
	}
printf("DONE!!\nAccess...\n\n");
for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	printf("%4d",A[i][j]);
	printf("\n");
	}
/*l3:
printf("enter loc::");
scanf("%d%d",&i,&j);
printf("Ans-->%d\n",A[i][j]);
printf("again?<y/n>");
scanf("%c",&ch);
if(ch=='y') goto l3;
*/goto lswitch;
}}
