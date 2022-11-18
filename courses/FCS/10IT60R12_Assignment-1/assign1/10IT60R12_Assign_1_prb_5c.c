#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct polynomial_node{
int cof;
int pow;
struct polynomial_node *nxt;
}poly;
poly *head1,*head2,*head3,*node,*ptr1,*ptr2,*ptr3,*demy,*ans;
void add(poly*,poly*,poly*);
int main(){
int i,j,k,m,n,temp;
int **cache;
int *p1,*p2;

head1=(poly*)malloc(sizeof(poly));
head1->cof=0;
head1->pow=-1;
head1->nxt=NULL;
head2=(poly*)malloc(sizeof(poly));
head2->cof=0;
head2->pow=-1;
head2->nxt=NULL;
head3=(poly*)malloc(sizeof(poly));
head3->cof=0;
head3->pow=-1;
head3->nxt=NULL;
ans=(poly*)malloc(sizeof(poly));
ans->cof=0;
ans->pow=-1;
ans->nxt=NULL;
printf("enter size poly#1--(highest power of x)>");
scanf("%d",&m);
p1=(int*)malloc(sizeof(int)*(m+1));
printf("Enter element of polynomials...(jst the cofefficients)--->\n");
for(i=0;i<=m;i++) 
	{
	printf("co eff of x^%d--> ",i);
	scanf("%d",&temp);
		node=(poly*)malloc(sizeof(poly));
		node->cof=temp;
		node->pow=i;
		node->nxt=NULL;
		p1[i]=temp;
	if(head1->nxt==NULL) {head1->nxt=node;ptr1=node;}
	else	{ptr1->nxt=node;ptr1=ptr1->nxt;}	
	}	
printf("enter size poly#2--(highest power of x)>");
scanf("%d",&n);
p2=(int*)malloc(sizeof(int)*(n+1));
printf("Enter element of polynomials...(jst the cofefficients)--->\n");
for(i=0;i<=n;i++) 
	{
	printf("co eff of x^%d--> ",i);
	scanf("%d",&temp);
		node=(poly*)malloc(sizeof(poly));
		node->cof=temp;
		node->pow=i;
		node->nxt=NULL;
		p2[i]=temp;
	if(head2->nxt==NULL) {head2->nxt=node;ptr2=node;}
	else	{ptr2->nxt=node;ptr2=ptr2->nxt;}	
	}	
ptr1=head1->nxt;
printf("\n the poly nomial#1 is..\n");
for(i=0;i<=m;i++) 
{	if (i==0)
	printf("%d*(x^%d)",ptr1->cof,i);
	else
	printf("+%2d*(x^%d)",ptr1->cof,i);
	ptr1=ptr1->nxt;
}
ptr2=head2->nxt;
printf("\n the poly nomial#2 is..\n");
for(i=0;i<=n;i++) 
{	if (i==0)
	printf("%d*(x^%d)",ptr2->cof,i);
	else
	printf("+%2d*(x^%d)",ptr2->cof,i);
	ptr2=ptr2->nxt;
}
cache=(int**)malloc(sizeof(int*)*(m+1));
for(i=0;i<=m;i++)
{
	cache[i]=(int*)malloc(sizeof(int)*(n+1));
}
for(i=0;i<=m;i++)
for(j=0;j<=n;j++)
cache[i][j]=p1[i]*p2[j];

for(k=0;k<=(m+n);k++)
{
	temp=0;
	for(i=0;i<=k;i++)
	{
		j=k-i;
		if(j>n||i>m) continue;
		temp=temp+cache[i][j];
	}
		node=(poly*)malloc(sizeof(poly));
		node->cof=temp;
		node->pow=k;
		node->nxt=NULL;
	if(head3->nxt==NULL) {head3->nxt=node;ptr3=node;}
	else	{ptr3->nxt=node;ptr3=ptr3->nxt;}	
	}
	ptr3=head3->nxt;
	printf("\n the resultant poly nomial is..\n");
	for(i=0;i<=m+n;i++) 
	{	
	if (i==0)
	printf("%d*(x^%d)",ptr3->cof,i);
	else
	printf("+%2d*(x^%d)",ptr3->cof,i);
	ptr3=ptr3->nxt;
	}

}