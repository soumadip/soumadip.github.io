#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int interpolation_search(int *data, int key,int low, int high)
{	
	int mid;
	if (key < data[low] || key > data[high])		//cheking if data is out of range
	return (-1);					//not found
	else
	{
		mid = low + ((key-data[low]) * (high-low)) / (data[high]-data[low]); //use interpolation formula
		if (key == data[mid])
		return (mid);
		else
		{	                        
			if (key < data[mid])			//if smaller
			return (interpolation_search(data,key, low, mid-1));   
			else					//if greater
			return (interpolation_search(data,key, mid+1, high));
		}
	}
}



int main()
{	
	int n,i,found,key,*a;
	int seq_rand;
	int choice=1;

	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));		//enter size 
 	
	seq_rand=rand()%10;
    	for(i=0;i<n;i++)			
	{
		a[i]=seq_rand;
		printf("pos: %d-->%2d\n",i,a[i]);
		seq_rand+=(int)rand()%10;
	}

while(choice==1){
	scanf("%d",&key);			//enter key
	found=interpolation_search(a,key,0,n-1);

	if(found != -1)
	printf("FOUND\n");
	else
	printf("NOT FOUND\n");

	printf("Again?<y=1/n=2>");
	scanf("%d",&choice);
	}
}
