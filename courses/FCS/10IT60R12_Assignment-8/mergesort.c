#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<limits.h>

/*
 * func Merge()
 * param array a, start index p, middle index q, end index r
 * merges array p-q and q-r to p-r
 */
void Merge(int *a,int p,int q,int r)
{
	int n1,n2;
	int *L,*R; /*buffer arrays*/
	int i,j,k;

	n1=q-p+1;
	n2=r-q;
	L=(int*)malloc(sizeof(int)*(n1+1));
	R=(int*)malloc(sizeof(int)*(n2+1));
	if(L==NULL||R==NULL)
	{
		printf("\nError:Unable to allocate memory\n");
		exit(1);
	}
	
	for(i=1;i<=n1;i++)
		L[i]=a[p+i-1];
		
	for(j=1;j<=n2;j++)
		R[j]=a[q+j];
		
	L[n1+1]=INT_MAX;
	R[n2+1]=INT_MAX;
	
	i=1;
	j=1;
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
	}
}


/*
 * funct MergeSort
 * param array a, start index p, end index r
 * sorts array elements of a between p and r
 */
void MergeSort(int* a,int p, int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
}





//////////////
///  MAIN  ///
//////////////
int main()
{
 	int *arr;
 	int i,j;
	int no=0;

 	scanf("%d",&no);
	arr=(int*)calloc(no,sizeof(int));

    	for(i=0;i<no;i++)			
	arr[i]=rand()%1000;

 
 	MergeSort(arr,0,no-1);//dividing elements
 	for(j=1;j<i;j++)
		printf("%d ",arr[j]);
	printf("\n");
}
