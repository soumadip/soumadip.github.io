#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sparse_node{
int inf;
int row,col;
struct sparse_node *nxt;
}sparse;
int main()
{
int i,j,m,n,temp;
sparse *node,*head,*ptr;
head=(sparse*)malloc(sizeof(sparse));
head->inf=0;
head->row=-1;
head->col=-1;
head->nxt=NULL;
printf("enter size-->");
scanf("%d%d",&m,&n);
printf("Enter element of sparce matrics--->\n");
for(i=0;i<m;i++) 
	for(j=0;j<n;j++)
	{
	printf("\n[%d,%d]=",i,j);
	scanf("%d",&temp);
	if(temp!=0)
	{
		node=(sparse*)malloc(sizeof(sparse));
		node->inf=temp;
		node->row=i;
		node->col=j;
		node->nxt=NULL;
	if(head->nxt==NULL) {head->nxt=node;ptr=node;}
	else	{ptr->nxt=node;ptr=ptr->nxt;}
	}	
	}	
ptr=head->nxt;
for(i=0;i<m;i++) 
{	for(j=0;j<n;j++)
	{if(i==ptr->row && j==ptr->col){
	printf("%4d",ptr->inf);
	ptr=ptr->nxt;
	}
	else
	printf("   0");
	}
printf("\n");
}}
