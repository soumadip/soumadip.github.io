#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct polynomial_node{
int cof;
int pow;
struct polynomial_node *nxt;
}poly;
void print(poly *link){
printf("(%2d",link->cof);
if(link->nxt){printf("+x*");print(link->nxt);}
printf(")");
}
int eval(poly *link,int x){

if(link->nxt){return(link->cof+x*eval(link->nxt,x));}
else return link->cof;
}
int main()
{
int i,n,temp,x,ans;
poly *node,*head,*ptr;
head=(poly*)malloc(sizeof(poly));
head->cof=0;
head->pow=-1;
head->nxt=NULL;
printf("enter size--(highest power of x)>");
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
	if(head->nxt==NULL) {head->nxt=node;ptr=node;}
	else	{ptr->nxt=node;ptr=ptr->nxt;}	
	}	
ptr=head->nxt;
printf("\n the poly nomial is..\n");
for(i=0;i<=n;i++) 
{	if (i==0)
	printf("%d*(x^%d)",ptr->cof,i);
	else
	printf("+%2d*(x^%d)",ptr->cof,i);
	ptr=ptr->nxt;
}
printf("\n horner\'s form...\n");
print(head->nxt);
printf("\n");
printf("Enter value of x-->");
scanf("%d",&x);
ans=eval(head->nxt,x);
printf("ans is=> %d\n",ans);
}
