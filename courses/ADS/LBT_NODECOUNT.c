#include<stdio.h>
#include<stdlib.h>
#include<math.h>



typedef struct LBT
{
	struct LBT *link[2];
}tree;


void destroy(tree *root)
{
	if(root->link[0]!=NULL)destroy(root->link[0]);
	if(root->link[1]!=NULL)destroy(root->link[1]);
free(root);
}


tree* getnode()
{
	tree *temp;
	temp=(tree*)malloc(sizeof(tree));
	temp->link[0]=temp->link[1]=NULL;
	return temp;
}


int count;
tree* Insert(tree *root,int *item)
{
	int i;count=0;
	for(i=15;i>-1;i--)
	{//printf("%d",item[i]);
		if(root->link[item[i]]==NULL)
			root->link[item[i]]=getnode();
		root=root->link[item[i]];
	count++;
	}
//	printf("NO OF NODES TRAVERSED :: %d\n",count);
}


search(tree *root,int *key)
{
	int i;count=0;
	for(i=15;i>-1;i--)
	{		//printf("%d",key[i]);
		if(root->link[key[i]]==NULL)
		{
			//printf("NOT FOUND\n");
			break;
		}
		root=root->link[key[i]];
	count++;
	}
//if(i==-1)printf("FOUND\n");
//	printf("NO OF NODES TRAVERSED :: %d\n",count);
}



int powr(int base,int power)
{
	return power==0?1:base*powr(base,power-1);
}



void dectobin(int dec,int *arr)
{
	int i=15;
	int temp;
	while(i>-1)
	{
		temp=powr(2,i);//printf("%d\n",temp);
		if(dec>=temp)
		{
			arr[i]=1;
			dec=dec-temp;
		}
		else
			arr[i]=0;
	i--;
	}
	//for(i=15;i>=0;i--)
	//printf("%d",arr[i]);
	//printf("\n");
}







int main()
{
	int arr[16];//={1,1,0,0,1,0,0,0,0,0,1,1,0,1,0,0};
	int dec,key,n=0,m=0,no=30000;
	int i=15,temp;
	long alltotal=0;

	tree *rootreal;
	//scanf("%d",&no);
	rootreal=getnode();

	while(n<no)
	{
		dec=rand()%65536;
		//scanf("%d",&dec);
		//printf("\ninserted::%d\n",dec);
		i=15;
		dectobin(dec,arr);
		
		Insert(rootreal,arr);
	alltotal+=count;
		n++;
	}
printf("AVG NO OF NODES TRAVERSED PER INSERT:: %lf\n",(double)alltotal/no);

alltotal=0;
	while(m<1000)
	{
		key=rand()%65536;
		//scanf("%d",&key);
		//printf("\nsearched::%d :: ",key);
		dectobin(key,arr);
		
			search(rootreal,arr);
	alltotal+=count;
		m++;
		//for(i=15;i>=0;i--)
		//printf("%d",arr[i]);
	}

printf("AVG NO OF NODES TRAVERSED PER SEARCH:: %lf\n",(double)alltotal/1000);
destroy(rootreal);
}
