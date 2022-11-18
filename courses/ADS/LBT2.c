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
tree* Insert(tree *root,int *item)
{
	int i;
	for(i=15;i>-1;i--)
	{//printf("%d",item[i]);
		if(root->link[item[i]]==NULL)
			root->link[item[i]]=getnode();
		root=root->link[item[i]];
	}
}


search(tree *root,int *key)
{
	int i;
	for(i=15;i>-1;i--)
	{		//printf("%d",key[i]);
		if(root->link[key[i]]==NULL)
		{
			//printf("NOT FOUND\n");
			break;
		}
		root=root->link[key[i]];
	}
//if(i==-1)printf("FOUND\n");
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
	int dec,key,n=0,m=0;
	int i=15,temp;
	struct timeval time_start,time_end;
	long total_time,alltime=0;
	tree *rootreal;

	rootreal=getnode();

	while(n<30000){
	dec=rand()%65536;
	//printf("\ninserted::%d\n",dec);
	i=15;
	dectobin(dec,arr);
		gettimeofday(&time_start, NULL);
	Insert(rootreal,arr);
		gettimeofday(&time_end, NULL);
	total_time=(time_end.tv_sec-time_start.tv_sec)*1000000+(time_end.tv_usec-time_start.tv_usec);
	alltime+=total_time;
	n++;
	}
	printf("Avg time INsert--->%lf microseconds\n",(double)alltime/30000);
alltime=0;
while(m<1000)
{
	key=rand()%65536;
	//scanf("%d",&key);
	//printf("\nsearched::%d :: ",key);
	dectobin(key,arr);
	
	gettimeofday(&time_start, NULL);
		search(rootreal,arr);
	gettimeofday(&time_end, NULL);
	total_time=(time_end.tv_sec-time_start.tv_sec)*1000000+(time_end.tv_usec-time_start.tv_usec);
	alltime+=total_time;//printf("Time to search ::%ld ----->is %ld microseconds\n",key,total_time);
	m++;
	//for(i=15;i>=0;i--)
	//printf("%d",arr[i]);
}

	printf("Avg time Search--->%lf microseconds\n",(double)alltime/1000);
destroy(rootreal);
}
