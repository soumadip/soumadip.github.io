#include<stdio.h>
#include<stdlib.h>
#define INF -1


int size;

/*
this function checkes whether a is less than b in this context
*/
int less(int a,int b)
{
	if(b==a)
		return 0;
	if(b==INF)
		return 1;
	if(a > b)
		return 0;
	else 
		return 1;
			
}


/*
this function finds the minimun next value to be considered and returns the index
*/
int findMin(int* final,int* checked)
{
	int index=INF,i;
	int returnindex=INF;

	for(i=0;i<size;i++)
	{
		if(checked[i]==INF)
		continue;

		else
		{
			if(less(final[i],index))
			{
				index=final[i];
				returnindex = i;
			}
		}
	}

	return returnindex;

}


/////////////////////
/////   MAIN  ///////
/////////////////////
void main()
{
	int i,j,temp,node;
	int index=INF;
	int **ptr,*final,*checked;

	scanf("%d",&size);					//enter the no of nodes

	ptr=(int**)calloc(size,sizeof(int*));			//allocate a 2D matrix

	for(i=0;i<size;i++)
	{
		ptr[i]=(int*)calloc(size,sizeof(int));
	}

	for(i=0;i<size;i++)					//assign value taken from user
		for(j=0;j<size;j++)				// this case takes input the distance matrix
		scanf("%d",&ptr[i][j]);

/*	for(i=0;i<size;i++)					//assign value taken from user
		for(j=i;j<size;j++)				//this case only takes node-wise diastance
		{
			if(i==j)
			{
				ptr[i][j]=0;
				ptr[j][i]=0;
			}
			else
			{
				printf("%4d-->%2d :: ",i,j);
				scanf("%d",&ptr[i][j]);
				ptr[j][i]=ptr[i][j];
			}
		}
*/

	final=(int*)calloc(size,sizeof(int));			//allocate memory
	checked=(int*)calloc(size,sizeof(int));			//allocate memory

	for(i=0;i<size;i++)
		checked[i]=i;					//indexes initialization to be checked

	scanf("%d",&node);

	for(i=0;i<size;i++)
		final[i]=ptr[node][i];
	checked[node]=INF;					//this node is checked

	for(i=0;i<size;i++)
	{
		index=findMin(final,checked);			//find next minimum

		if(index==INF)					//if all checked
		break;

		checked[index]=INF;				//mark as checked

		for(j=0;j<size;j++)
		{
			temp=ptr[index][j]+final[index];	//calculate distance

			if(checked[j]==INF||ptr[index][j]==INF)	//skip is chceked i.e. finalized
			continue;

			else
				if(less(temp,final[j]))
				final[j]=temp;			//save minimum value
		}
	}

	for(i=0;i<size;i++)
		printf("%3d-->%2d :: %d\n",node,i,final[i]);	//print distances

	printf("\n");
}

