/*
 * 
 * Coin changing problem by Dynamic Programming */

#include<stdio.h>
#include<stdlib.h>

int **c;	/*memory of dyanamic programming*/
int *d;		/*maintains list of denominations*/
int n;		/*number of denominations*/

/*
 * fucn coinChange 
 * param int a - amount to be changed
 * returns int - no of coins required to change the amount a
 */
int coinChange(int a)
{
	int i,j,k;

	for(j=0;j<=a;j++)
		c[n-1][j]=j;

	for(i=n-2;i>=0;i--)
		for(j=0;j<=a;j++)
		{
			if(d[i]>j)
				c[i][j]=c[i+1][j];
			else	
				c[i][j]=c[i+1][j]<(1+c[i][j-d[i]]) ? c[i+1][j] : (1+c[i][j-d[i]]);
		}
	return c[0][a];
	
}	
/*
 * func insertionSort()
 * return- void
 * sorts array in descending order
 */
void insertionSort()
{
	int i,j;
	int key;
	for(j=1;j<n;j++)
	{
		key=d[j];
		i=j-1;
		while(i>=0&& d[i]<key)
		{
			d[i+1]=d[i];
			i--;
		}
		d[i+1]=key;
	}
}




int main()
{
	int a,i,j,noc;

	printf("Enter no of denominations(>0)  ");
	scanf("%d",&n);
	if(n>0)		//if denomination is not more than 0 then exits
	{
	
	d=(int*)malloc(sizeof(int)*n); 		//allocate memory 
	c=(int**)malloc(sizeof(int*)*n);	//allocate memory 
	
	printf("Enter denominations :at least one denomination should be 1\n");
	for(i=0;i<n;i++)
		scanf("%d",&d[i]);
	
	insertionSort();  
	
	if(d[n-1]!=1)
	{
		printf("No denomination found as 1..exiting\n");
		exit(1);
		
	}

	printf("Enter amount to be changed :: ");
	scanf("%d",&a);
	if(a==0)
	{
		printf("Coin needs to change is 0\n");
		exit(0);
	}

	for(i=0;i<n;i++)		//allocate memory for a row which contains numberofcolumn elements
	{
		c[i]=(int*)malloc(sizeof(int)*(a+1));
		for(j=0;j<n;j++)
			c[i][j]=0;
	}
	
	noc=coinChange(a);
	printf("\nNumber of coins required : %d \n",noc);
	
	}
	else
	printf("Cannot denominate\n");
}
	


