#include<stdio.h>
#include<stdlib.h>
#include<math.h>



typedef struct LBT
{
	struct LBT *link[4];
}tree;


void destroy(tree *root)
{
	int i;
	for(i=0;i<4;i++)
		if(root->link[i]!=NULL)destroy(root->link[i]);
	free(root);
}


tree* getnode()
{
	int i;
	tree *temp;
	temp=(tree*)malloc(sizeof(tree));
	for(i=0;i<4;i++)
	temp->link[i]=NULL;
	return temp;
}

/*
void Display(tree *root)
{
	fp=fopen("output_bst","w");
	fprintf(fp,"graph g {\nnode [shape=invtriangle,width=0.75,style=filled,fillcolor=lightgray];");
	disp(root);
	fprintf(fp,"\n}");
	fclose(fp);
	system("dotty output_bst");
	
}
void disp(tree *root)
{
	if(root!=NULL)
	{
		disp(root->link[0]);
		//if(root->link[0]!=NULL)fprintf(fp,"\n%d -- %d;",root->value,root->link[0]->value);
		//if(root->link[1]!=NULL)fprintf(fp,"\n%d -- %d;",root->value,root->link[1]->value);
		disp(root->link[1]);
	}
}

*/
int count;
tree* Insert(tree *root,int *item)
{
	int i;count=0;
	for(i=15;i>-1;i=i-2)
	{//printf("%d%d",item[i],item[i-1]);
		if(root->link[(item[i]*2+item[i-1])]==NULL)
			root->link[(item[i]*2+item[i-1])]=getnode();
		root=root->link[(item[i]*2+item[i-1])];
		count++;
	}
//printf("NO OF NODES TRAVERSED :: %d\n",count);
}


search(tree *root,int *key)
{
	int i;count=0;
	for(i=15;i>-1;i=i-2)
	{		//printf("%d%d",key[i],key[i-1]);
		if(root->link[(key[i]*2+key[i-1])]==NULL)
		{
			//printf("\tNOT FOUND\n");
			break;
		}
		root=root->link[(key[i]*2+key[i-1])];
		count++;
	}
//if(i==-1)printf("\tFOUND\n");
	//printf("NO OF NODES TRAVERSED :: %d\n",count);
}
/*
int bintodec(int decimal)
{
     int total = 0;
     int power = 1;
     

     
     while(decimal > 0)
     {
          total += decimal % 10 * power;
          decimal = decimal / 10;
          power = power * 2;
          }

     return total;
}
*/


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
