/*
Computing Systems Lab
IT69101
(Autumn 2010)
Assignment #2 28/07/2010
*/
//Priority queue implementation using 1D array


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *arr;
int *front,*rear;

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
	t2--;
	if(front[t2]==10*t2 && rear[t2]==10*t2+9)
	{
	printf("Overflow\n");exit(1);
	}
	else if(rear[t2]==-1)
	{front[t2]=10*t2;rear[t2]=10*t2;arr[rear[t2]]=t1;}
	else {
	rear[t2]++;arr[rear[t2]]=t1;
	}
}

/* Name: 
      Input: 
      Output: 
      Description: 
         
         
   */
void delete()
{
	int temp,flag=0,i;
	for(i=4;i>=0;i--)
	{
	if(front[i]!=-1){flag=0;break;}
	flag=1;
	}
	if(flag)
	{printf("Underflow\n");exit(1);}
	else {
		if(front[i]==rear[i])
		{
			printf("deleted --> %d(%d)\n",arr[front[i]],i+1);
			front[i]=-1;rear[i]=-1;}
		else{
		printf("deleted --> %d(%d)\n",arr[front[i]],i+1);
		
		front[i]++;
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
	int i,j,flag=0;
	printf("\n");
	for(i=4;i>=0;i--)
	{
	if(front[i]!=-1){flag=0;break;}
	flag=1;
	}
	
	if(flag)printf("\nNo elements...\n");
	else
	for(i=0;i<5;i++)
	{	
	printf("\n");
	for(j=front[i];j<=rear[i];j++)
	if(front[i]!=-1)printf("\t%d(%d)",arr[j],i+1);
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
	int choise,i;
	arr=(int*)malloc(sizeof(int)*50);
	front=(int*)malloc(sizeof(int)*5);
	rear=(int*)malloc(sizeof(int)*5);
	for(i=0;i<5;i++)
	{
		front[i]=-1;
		rear[i]=-1;
	}
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
