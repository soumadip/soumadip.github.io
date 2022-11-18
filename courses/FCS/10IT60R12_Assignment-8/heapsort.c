#include<stdio.h>
#include<malloc.h>
void buildHeap(int*,int);
void adjustHeap(int*,int);

int main()
{
        int *a,i;
	int sizenow;
	int n=0;

	scanf("%d",&n);				//size of the input data set
	a=(int*)calloc(n,sizeof(int));

      	for(i=1;i<=n;i++)
	{
		a[i]=rand()%1000;		//insert a new data
		buildHeap(a,i);			//buildHeap
	}

	sizenow=n;			//size of array to heapify
	for(i=1;i<=n;i++)
        {
                int temp;		
                temp=a[1];		//delete top value
                a[1]=a[sizenow];	//put last one at top
                a[sizenow]=temp;	//put deleted value at end
                sizenow--;		//decrease size by 1 rest are placed at posision
                adjustHeap(a,sizenow);	//heapify the array to be sorted 
        }

        printf("Output\n");
	for(i=2;i<=n;i++)
		printf("%4d",a[i]);
	printf("\n");
}



void buildHeap(int *a,int i)
{
        int this=a[i];				//newly inserted value 

        while((i>1) && (a[i/2]<this))		//if position is not root and parent is less than this value
        {
                a[i]=a[i/2];			//put the value lower
                i=i/2;			
        }
        a[i]=this;			//replace at actual position
}


void adjustHeap(int *a,int n)
{
	int this=a[1];				//copy of root				
	int j=2,temp;				
	while(j<=n)
	{
		if((j<n)&&(a[j]<a[j+1]))	//check which child is large
		j++;
		if(a[j]<a[j/2])			//if value is less than root loop ends
		break;

		temp=a[j];			//swap
		a[j]=a[j/2];			//these 
		a[j/2]=temp;			//two
		j=j*2;					//goto child
	}
	a[j/2]=this;
}
