#include <stdio.h>
#include<malloc.h>
 

int binary_search(int* a,int key, int beg,int end)
{
int mid;
mid=(end+beg)/2;
if (a[mid] == key)
	printf("\nFOUND");
else if(beg==end)
	printf("\nNOT FOUND");	
	else
	{
		
	if (key < a[mid])		// target in lower
		binary_search(a,key,beg,mid-1);
	else				// target in upper 
		binary_search(a,key,mid+1,end);
	}

}

int main()
{
	int *a;
	int n;
	int i,seq_rand,choice=1;
	int key;
		
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
     	seq_rand=rand()%10;
    	for(i=0;i<n;i++)			
	{
		a[i]=seq_rand;
		printf("pos: %d-->%2d\n",i,a[i]);
		seq_rand+=(int)rand()%10;
	}

		

while(choice==1)
{
	scanf("%d",&key);			//enter key
	binary_search(a,key,0,n-1);

	printf("\nAgain?<y=1/n=2>");
	scanf("%d",&choice);

}

}
