#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define REL2(a,b) ((a)>((2*(a)*(b))/((a)+(b))))
#define REL2(a,b) (((a)+(b))%10)%3
#define REL1(a,b) ((a)>(b))
#define NOTEQUAL(a,b) ((a)!=(b))
#define SEARCHSIZE 1000

typedef struct TETRAX
{
	int value;
	struct TETRAX *_r1_r2;
	struct TETRAX *_r1r2;
	struct TETRAX *r1_r2;
	struct TETRAX *r1r2;
}tree;

tree *t1=NULL;
int count;
FILE *fp;


tree* getnode()
{
	tree *temp;
	temp=(tree*)malloc(sizeof(tree));
	temp->_r1_r2=temp->_r1r2=temp->r1_r2=temp->_r1_r2=NULL;
	return temp;
}


tree* Insert(tree *root,int item)
{
	if(root==NULL)
	{
		root=getnode();
		root->value=item;//printf("inserted item:: %d\n",item);
	}
	else 	if(NOTEQUAL(root->value,(-1)*item) && NOTEQUAL(root->value,item))
		{
			if(REL1(root->value,item))
			{
				if(REL2(root->value,item))
					//{
					root->r1r2=Insert(root->r1r2,item);
					//printf("called:: r1r2\n");}
				else 
					//{
					root->r1_r2=Insert(root->r1_r2,item);
					//printf("called:: r1_r2\n");}
			}
			else 	//if()
				{
					if(REL2(root->value,item))
						//{
						root->_r1r2=Insert(root->_r1r2,item);
						//printf("called:: _r1r2\n");}
					else 
						//{
						root->_r1_r2=Insert(root->_r1_r2,item);
						//printf("called:: _r1_r2\n");}
				}
		}
		else 
		{
			if(REL2(root->value,item))
				//{
					root->r1r2=Insert(root->r1r2,item);
					//printf("called:: r1r2\n");}
			else 
				//{
					root->r1_r2=Insert(root->r1_r2,item);
					//printf("called:: r1_r2\n");}
		}
	count++;
	return root;
}


void disp(tree *root)
{
	if(root!=NULL)
	{
		disp(root->r1r2);
		disp(root->r1_r2);
		if(root->r1r2!=NULL)fprintf(fp,"\n%d -- %d;",root->value,root->r1r2->value);
		if(root->r1_r2!=NULL)fprintf(fp,"\n%d -- %d;",root->value,root->r1_r2->value);
		if(root->_r1_r2!=NULL)fprintf(fp,"\n%d -- %d;",root->value,root->_r1_r2->value);
		if(root->_r1r2!=NULL)fprintf(fp,"\n%d -- %d;",root->value,root->_r1r2->value);
		disp(root->_r1r2);
		disp(root->_r1_r2);
	}
}

void Display(tree *root)
{
	fp=fopen("output_tetrax","w");
	fprintf(fp,"graph g {\nnode [shape=record,width=0.75,style=filled,fillcolor=lightgray];");
	disp(root);
	fprintf(fp,"\n}");
	fclose(fp);
	system("dotty output_tetrax");
	
}


void destroy(tree *t1)
{
if(t1->r1r2!=NULL)destroy(t1->r1r2);
if(t1->_r1r2!=NULL)destroy(t1->_r1r2);
if(t1->r1_r2!=NULL)destroy(t1->r1_r2);
if(t1->_r1_r2!=NULL)destroy(t1->_r1_r2);
free(t1);
}


void search(tree* root,int key)
{
	if(root==NULL)
		{}//printf("NOT FOUND\n");
	else
	{
		if(NOTEQUAL(root->value,(-1)*key) && NOTEQUAL(root->value,key))
		{
			if(REL1(root->value,key))
			{
				if(REL2(root->value,key))
					search(root->r1r2,key);
				else 
					search(root->r1_r2,key);
			}
			else 	//if(
				{
					if(REL2(root->value,key))
						search(root->_r1r2,key);
					else 
						search(root->_r1_r2,key);
				}
		}
		else if(NOTEQUAL(root->value,key))
		{
			if(REL2(root->value,key))
				search(root->r1r2,key);
			else 
				search(root->r1_r2,key);
		}
		else
			{}//printf("FOUND\n");
	}
	count++;
}







int main()
{
	int i,j,k,no=30000,nos;
	long item,alltotal=0;;
	
	//scanf("%d",&no);nos=no;


	while(no)
	{
		//scanf("%d",&item);
		item=rand()%65536;//printf("next item:: %ld\n",item);
	count=0;
		t1=Insert(t1,item);
	alltotal+=count;//printf("NO OF NODES TRAVERSED :: %d\n",count);
		no--;	
	}
printf("AVG NO OF NODES TRAVERSED PER INSERT:: %lf\n",(double)alltotal/30000);


	alltotal=0;
	no=SEARCHSIZE;
	printf("SEARCH RANDOM %d NOS...\n",no);
	for(i=0;i<SEARCHSIZE;i++)
	{
		item=rand()%65536;
	count=0;
		search(t1,item);
	alltotal+=count;//printf("NO OF NODES TRAVERSED :: %d\n",count);
		
	}	
printf("AVG NO OF NODES TRAVERSED PER SEARCH:: %lf\n",(double)alltotal/SEARCHSIZE);
	//Display(t1);
	destroy(t1);
	return 1;

}
