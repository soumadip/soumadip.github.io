/*
Computing Systems Lab
IT69101
(Autumn 2010)
Assignment #2 28/07/2010
*/
//Priority queue implementation using 2D matrix


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **arr;
int front,rear;

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void insert()
{
	int t1,t2;
	//printf("\nEnter no --> ");
	scanf("%d",&t1);
	printf("\nEntered no --> %d\n",t1);
l1:	//printf("\nEnter prioity --> ");
	scanf("%d",&t2);if(t2<1||t2>5){printf("Unacceptable...\n");goto l1;}
	printf("Entered prioity --> %d\n",t2);
	if(rear==19)
	{
	printf("Overflow...\n");exit(1);
	}
	else if(rear==-1)
	{front=0;rear=0;arr[0][rear]=t1;arr[1][rear]=t2;}
	else {
	rear++;arr[0][rear]=t1;arr[1][rear]=t2;
	}
}

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void delete()
{
	int temp,index,i;
	temp=arr[1][front];index=front;
	if(front==-1)
	{printf("Underflow...\n");exit(1);}
	else {
		if(front==rear)
		{
			printf("deleted --> %d(%d)\n",arr[0][front],arr[1][front]);
			front=-1;rear=-1;}
		else{
		for(i=front;i<=rear;i++)
		if(temp<arr[1][i])
		{
			temp=arr[1][i];
			index=i;
		}
		printf("deleted --> %d(%d)\n",arr[0][index],arr[1][index]);
		
		for(i=index;i>front;i--)
		{
		arr[0][i]=arr[0][i-1];
		arr[1][i]=arr[1][i-1];	
		}
		front++;
		}
	}
}

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void display()
{
	int i;
	printf("\n");
	if(front==-1)printf("\nNo elements...\n");
	else
	for(i=front;i<=rear;i++){
	printf("\t%d(%d)",arr[0][i],arr[1][i]);
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
	front=-1;rear=-1;
	arr=(int**)malloc(sizeof(int*)*2);
	arr[0]=(int*)malloc(sizeof(int)*2);
	arr[1]=(int*)malloc(sizeof(int)*2);
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
