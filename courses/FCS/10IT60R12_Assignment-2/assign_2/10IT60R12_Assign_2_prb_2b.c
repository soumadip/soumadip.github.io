/*
Computing Systems Lab
IT69101
(Autumn 2010)
Assignment #2 28/07/2010
*/
//n th fibbo using my stack


#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
int val;
struct node *next;
}node;

node *top;

/* Name: push
      Input: integer
      Output: void
      Description: inserts values on top of the stack
         
         
   */
void push(int n)
{
	node *ptr;
	if(top==NULL)
			{
				top=(node*)malloc(sizeof(node));
				top->val=n;top->next=NULL;
				}
			else
			{
				ptr=(node*)malloc(sizeof(node));
				ptr->next=top;
				ptr->val=n;
				top=ptr;
				}
	}
	
/* Name: pop
      Input: void
      Output: popped value
      Description: pops the top value fron the stack
         
         
   */	
int pop()
	{
		int temp;
		node *ptr;
		if (top==NULL)
		{
			printf("Underflow");
			exit(1);
			}
			else
			{
				temp=top->val;
				ptr=top->next;
				free(top);
				top=ptr;
				return temp;
				}
		}

/* Name: fibbo
      Input: integer n(no of fibbonachhi no)
      Output: nth fibbonachhi no
      Description: calculates fibbonachhi no by stack
         
         
   */
int fibbo(int n)
{
	push(1);
	push(1);
	if(n==1||n==2)return 1;
	while(n>2)
	{
		int t1,t2;
		t1=pop();
		t2=pop();
		push(t1);
		push(t1+t2);n--;
	}
	return pop();
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
		//printf("enter no -->");
		scanf("%d",&no);
		printf("Entered no -->%d\n",no);
		if(no<1) printf("can't calculate...\n\n");
		else
		printf("ans-->%d\n\n",fibbo(no));
		testcase--;
		}
return 0;
}
