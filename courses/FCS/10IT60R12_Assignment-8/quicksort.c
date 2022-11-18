#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>



 
void swap(int *x,int *y)			//swaps by address
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}


void quicksort(int *list, int s, int e)
{
int i,j,index=s;
printf("%4d-->%4d\n",s,e);
if(s!=e)
{
	for(i=s;i<=e;i++)
	{
		if(list[index]>list[i] && index<i)			//put all smaller on left
		{
			swap(list+index,list+i);
			index=i;
			i=s;
			
		}
		if(list[index]<list[i] && index>i)			//put all greater opn right
		{
			swap(list+index,list+i);
			index=i;
			i=s;
			
		}
	printf("\n");
	for(j=s;j<=e;j++)
	printf("%4d",list[j]);
	printf("%8d,%d\n",index,i);
	}
	if(index!=s)
		quicksort(list,s,index-1);			//recurse 
	if(index!=e)
		quicksort(list,index+1,e);			//recurse
}
}


int main()
{
	int no=0;
	int *list,i;

	scanf("%d",&no);
	list=(int*)calloc(no,sizeof(int));

    	for(i=0;i<no;i++)			
	list[i]=rand()%1000;

	quicksort(list,0,no-1);
 
	// print the result
	printf("Output:\n");
	for(i=0;i<no;i++)
	printf("%4d",list[i]);
	printf("\n");
}
