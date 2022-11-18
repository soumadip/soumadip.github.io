#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct polynomial_node{
int cof;
int pow;
struct polynomial_node *nxt;
}poly;
/*void print(poly *link){
printf("(%2d",link->cof);
if(link->nxt){printf("+x*");print(link->nxt);}
printf(")");
}
int eval(poly *link,int x){

if(link->nxt){return(link->cof+x*eval(link->nxt,x));}
else return link->cof;
}*/
int main()
{
int i,m,n,temp,x,ans,counter=0;
poly *node,*head1,*head2,*head3,*ptr1,*ptr2,*ptr3;
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
printf("enter size poly#1--(highest power of x)>");
scanf("%d",&m);
printf("Enter element of polynomials...(jst the cofefficients)--->\n");
for(i=0;i<=m;i++) 
	{
	printf("co eff of x^%d--> ",i);
	scanf("%d",&temp);
		node=(poly*)malloc(sizeof(poly));
		node->cof=temp;
		node->pow=i;
		node->nxt=NULL;
	if(head1->nxt==NULL) {head1->nxt=node;ptr1=node;}
	else	{ptr1->nxt=node;ptr1=ptr1->nxt;}	
	}	
printf("enter size poly#2--(highest power of x)>");
scanf("%d",&n);
printf("Enter element of polynomials...(jst the cofefficients)--->\n");
for(i=0;i<=n;i++) 
	{
	printf("co eff of x^%d--> ",i);
	scanf("%d",&temp);
		node=(poly*)malloc(sizeof(poly));
		node->cof=temp;
		node->pow=i;
		node->nxt=NULL;
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
ptr1=head1->nxt;
ptr2=head2->nxt;
while(ptr1 && ptr2){
		node=(poly*)malloc(sizeof(poly));
		node->cof=ptr1->cof+ptr2->cof;
		node->pow=ptr1->pow;
		node->nxt=NULL;
	if(head3->nxt==NULL) {head3->nxt=node;ptr3=node;}
	else	{ptr3->nxt=node;ptr3=ptr3->nxt;}
counter++;
	ptr1=ptr1->nxt;
	ptr2=ptr2->nxt;
}
while(ptr1){
		node=(poly*)malloc(sizeof(poly));
		node->cof=ptr1->cof;
		node->pow=ptr1->pow;
		node->nxt=NULL;
		ptr3->nxt=node;ptr3=ptr3->nxt;
		ptr1=ptr1->nxt;
counter++;
}
while(ptr2){
		node=(poly*)malloc(sizeof(poly));
		node->cof=ptr2->cof;
		node->pow=ptr2->pow;
		node->nxt=NULL;
		ptr3->nxt=node;ptr3=ptr3->nxt;
		ptr2=ptr2->nxt;
counter++;
}
ptr3=head3->nxt;
printf("\n the resultant poly nomial is..\n");
for(i=0;i<counter;i++) 
{	if (i==0)
	printf("%d*(x^%d)",ptr3->cof,i);
	else
	printf("+%2d*(x^%d)",ptr3->cof,i);
	ptr3=ptr3->nxt;
}
printf("\n");
/*printf("\n horner\'s form...\n");
print(head->nxt);
printf("\n");
printf("Enter value of x-->");
scanf("%d",&x);
ans=eval(head->nxt,x);
printf("ans is=> %d\n",ans);*/
}
