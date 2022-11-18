/*
Computing Systems Lab
IT69101
(Autumn 2010)
Assignment #2 28/07/2010
*/
//Priority queue implementation using linked list


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct queue
{
int val;
int pri;
struct queue *next;
}queue;

queue *f,*r;

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void insert()
{
	int t1,t2;
	queue *ptr;
	//printf("\nEnter no --> ");
	scanf("%d",&t1);
	printf("\nEntered no --> %d\n",t1);
l1:	//printf("\nEnter prioity --> ");
	scanf("%d",&t2);if(t2<1||t2>5){printf("Unacceptable...\n");goto l1;}
	printf("Entered prioity --> %d\n",t2);
	if(r==NULL)
	{
		r=(queue*)malloc(sizeof(queue));
		r->val=t1;r->pri=t2;r->next=NULL;f=r;
	}
	else
	{	

		r->next=(queue*)malloc(sizeof(queue));
		r=r->next;
		r->pri=t2;
		r->val=t1;
		r->next=NULL;
	}
}

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void delete()
{
	queue *it,*prev,*ptr;
	if(f==NULL)
	{printf("Underflow...\n");exit(1);}
	else if(f==r)
	{
	printf("deleted --> %d(%d)\n",f->val,f->pri);
	free(f);
	f=NULL;r=NULL;
	}
	else
	{	ptr=f;
		prev=NULL;
		it=f;
		while((ptr!=NULL) && (ptr->next!=NULL))
		if((ptr->pri)<((ptr->next)->pri))
		{
		prev=ptr;
		it=ptr->next;
		ptr=ptr->next;
		}
		else 
		ptr=ptr->next;
		printf("deleted --> %d(%d)\n",it->val,it->pri);
		if(prev==NULL)
		f=f->next;
		else
		prev->next=it->next;
		free(it);
	}
}

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void display()
{
	queue *ptr;
	printf("\n\n");
	if(f==NULL)printf("No Elements...\n");
	else
	{
	ptr=f;
		while(ptr)
		{
			printf("\t%d(%d)",ptr->val,ptr->pri);
			ptr=ptr->next;
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
	int choise;
	f=NULL;r=NULL;
	printf("\nMENU::\n\n\t1::Insert\n\t2::Delete\n\t3::Display\n\t4::Exit\n\n");
	while(1)
	{
		//printf("\nMENU::\n\n\t1::Insert\n\t2::Delete\n\t3::Display\n\t4::Exit\n\n\t\tchoise-->");
		scanf("%d",&choise);
		printf("choise --> %d\n",choise);
		switch(choise)
		{
			case 1: insert();break;
			case 2: delete();break;
			case 3: display();break;
			default:exit(0);
		}
	}
return 0;
}
