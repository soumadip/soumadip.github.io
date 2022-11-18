/*
Computing Systems Lab
IT69101
(Autumn 2010)
Assignment #2 28/07/2010
*/
//towerof hannoi using my stack


#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
char start,end;
int disc;
struct node *next;
}node;

node *top,*temp;

/* Name: push
      Input: character start and end with the disc no
      Output: void
      Description: inserts values on top of the stack
         
         
   */
void push(char s,char e,int n)
{
	node *ptr;
	if(top==NULL)
			{
				top=(node*)malloc(sizeof(node));
				top->disc=n;top->start=s;top->end=e;top->next=NULL;
				}
			else
			{
				ptr=(node*)malloc(sizeof(node));
				ptr->next=top;
				ptr->disc=n;ptr->start=s;ptr->end=e;
				top=ptr;
				}
	}

/* Name: pop
      Input: void
      Output: popped node
      Description: pops the top value fron the stack
         
         
   */
node* pop()
	{
		node *ptr;
		if (top==NULL)
		{
			printf("Underflow");
			exit(1);
			}
			else
			{
				temp=(node*)malloc(sizeof(node));
				temp->disc=top-> disc;temp->start=top->start;temp->end=top->end;temp->next=NULL;
				ptr=top->next;
				free(top);
				top=ptr;
				return temp;
				}
		}

/* Name: toh
      Input: start intermediate end and no od disks
      Output: void
      Description: pushes alltoh calls to stack
         
         
   */
void toh(char s,char m,char e,int n)
{

	if(n==1)push(s,e,1);
	else{
		toh(m,s,e,n-1);
		push(s,e,n);
		toh(s,e,m,n-1);
		}
	}

/* Name: isempty
      Input: void
      Output: 1 or 0
      Description: checks if the stack is empty,then returns 1 otherwise 0
         
         
   */
int isempty()
{
return (top==NULL)?0:1;
}

/* Name: print
      Input: void
      Output: void
      Description: prints the stack
         
         
   */
void print()
{
node *x;
	while(isempty())
	{
		x=pop();
		printf("Disc-%d--%c-->%c\n",x->disc,x->start,x->end);
	}
}

/* Name: main method
      Input: void
      Output: success or failure
      Description: 
         
         
   */
int main()
{
	int testcase,no;
	//printf("testcase-->");
	scanf("%d",&testcase);                                 
	while(testcase)
	{
		//printf("enter no of disc-->");
		scanf("%d",&no);

		if(no>0){
		printf("\nNo of disc-->%d\n\n",no);
		toh('A','B','C',no);
		print();
		}
		else printf("\nNo of disc cannot be-->%d\n\n",no);
		testcase--;
	}
return 0;
}
