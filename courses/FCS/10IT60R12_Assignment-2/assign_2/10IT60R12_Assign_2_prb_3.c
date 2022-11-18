/*
Computing Systems Lab
IT69101
(Autumn 2010)
Assignment #2 28/07/2010
*/
//Circular queue implementation using array

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define X(x) (x%10)


typedef struct queue
{
int arr[10];
int front,rear;
}queue;
queue q;

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void insert(int n)
{
	if(q.front==-1 && q.rear==-1)
	{
		q.front=0;q.rear=0;
		q.arr[q.rear]=n;
	}
	else if(q.front==X(q.rear+1)) 
	{
		printf("\nOverflow...\n");
		exit(1);
	}
	else
	{
		q.rear++;q.rear=X(q.rear);
		q.arr[q.rear]=n;
	}
}

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
int delete()
{
	int temp;
	if(q.front==-1 && q.rear==-1)
	{
		printf("\nUnderflow\n");exit(1);
	}
	else if(q.front==q.rear)
	{
		temp=q.arr[q.front];q.rear=-1;q.front=-1;
	}
	else
	{
		temp=q.arr[q.front];q.front++;q.front=X(q.front);
	}
	return temp;
}

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void display()
{
	int i;
	i=q.front;
	if(q.front==-1)printf("No Elements...\n");
	else
	{
		printf("\n\n");
		if(q.front<=q.rear)
			for(i=q.front;i<=q.rear;i++)
			printf("\t%d",q.arr[i]);
		else
		{
			for(i=q.front;i<10;i++)
			printf("\t%d",q.arr[i]);
			for(i=0;i<=q.rear;i++)
			printf("\t%d",q.arr[i]);
		}
	}
	printf("\n");
}

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
int main()
{
int choise,n;
q.front=-1;q.rear=-1;
printf("\nMENU::\n\n\t1::Insert\n\t2::Delete\n\t3::Display\n\t4::Exit\n\n");
while(1)
{
//printf("\nMENU::\n\n\t1::Insert\n\t2::Delete\n\t3::Display\n\t4::Exit\n\n\t\tchoise-->");
scanf("%d",&choise);
printf("choise --> %d\n",choise);

	switch(choise)
	{
		case 1: scanf("%d",&n);printf("Entered no-->%d\n",n);insert(n);break;
		case 2: n=delete();printf("\nDeleted-->%d\n",n);break;
		case 3: display();break;
		default:exit(0);
	}
}
return 0;
}
