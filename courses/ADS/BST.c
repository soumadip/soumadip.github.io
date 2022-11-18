#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SEARCHSIZE 100


typedef struct Binary_tree
{
	int value;
	struct Binary_tree *left;
	struct Binary_tree *right;
}tree;
tree *t1=NULL;
void Display(tree*);
tree* Insert(tree*,int);
tree* getnode(void);
void disp(tree*);
void destroy(tree *t1)
{
if(t1->left!=NULL)destroy(t1->left);
if(t1->right!=NULL)destroy(t1->right);
free(t1);
}

int min(tree *tr)
{
	tree *tmp;
	tmp=tr;
	while(tmp->left!=NULL)
	tmp=tmp->left;
	return tmp->value;
}

int max(tree *tr)
{
	tree *tmp;
	tmp=tr;
	while(tmp->right!=NULL)
	tmp=tmp->right;
	return tmp->value;
}

void post(tree *tr)
{
	tree *tmp;
	tmp=tr;
	if(tmp!=NULL)
	{
		post(tmp->left);
		post(tmp->right);
		printf("%4d",tmp->value);
	}
}

void pre(tree *tr)
{
	tree *tmp;
	tmp=tr;
	if(tmp!=NULL)
	{
		printf("%4d",tmp->value);
		pre(tmp->left);
		pre(tmp->right);
	}
}

void in(tree *tr)
{
	tree *tmp;
	tmp=tr;
	if(tmp!=NULL)
	{
		in(tmp->left);
		printf("%4d",tmp->value);
		in(tmp->right);
	}
}

int cnt;
float avg(tree *tr)
{
	tree *tmp;
	int x;
	tmp=tr;
	cnt=0;
	x=total(tmp);
	return (float)x/cnt; 
}

int total(tree *tr)
{
	int totl;
	totl=tr->value;
	cnt++;
	if(tr->left!=NULL)totl+=total(tr->left);
	if(tr->right!=NULL)totl+=total(tr->right);
	return totl;
}


void search(tree* root,int key)
{
	if(root==NULL)
		{}//printf("NOT FOUND\n");
	else
	{
		if(key>root->value)
		search(root->right,key);
		else 	if(key<root->value)
			search(root->left,key);
			else
				{}//printf("FOUND\n");
	}
}

FILE *fp;
int main()
{
	int i,j,k,no=30000,nos;
	long item;
	struct timeval time_start,time_end;
	long total_time,alltime=0;
	//scanf("%d",&no);nos=no;
	//printf("No of nodes----->%d",no-1);
	//printf("\nSize-------case-this-------> %ld KBytes\n",(no-1)*sizeof(tree)/1024);

	while(no)
	{
		//scanf("%d",&item);
		item=rand()%65536;//printf("next item:: %ld\n",item);
	gettimeofday(&time_start, NULL);
		t1=Insert(t1,item);
	gettimeofday(&time_end, NULL);
	total_time=(time_end.tv_sec-time_start.tv_sec)*1000000+(time_end.tv_usec-time_start.tv_usec);
	alltime+=total_time;
		no--;	
	}
	
	printf("Total Time to insert ---> %ld microseconds with avg is %lf microseconds\n",alltime,(double)alltime/30000);
printf("SEARCH RANDOM 1000 NOS...\n");
	alltime=0;
for(i=0;i<1000;i++)
{
	item=rand()%65536;
	gettimeofday(&time_start, NULL);
search(t1,item);
	gettimeofday(&time_end, NULL);
	total_time=(time_end.tv_sec-time_start.tv_sec)*1000000+(time_end.tv_usec-time_start.tv_usec);
	//printf("Time to search #%d::%ld ----->is %ld microseconds\n",i+1,item,total_time);
	alltime+=total_time;
}
	printf("Avg time--->%lf microseconds\n",(double)alltime/1000);
	//printf("\nPreOrder==> ");pre(t1);
	//printf("\nInOrder==> ");in(t1);
	//printf("\nPostOrder==> ");post(t1);
	//printf("\nMax==> %d",max(t1));
	//printf("\nMin==> %d",min(t1));
	//printf("\nAverage==> %f",avg(t1));
	//Display(t1);
	destroy(t1);
	return 1;

}

tree* Insert(tree *root,int item)
{
	if(root==NULL)
	{
		root=getnode();
		root->value=item;
	}
	else 
	{
		if(item<root->value)
			root->left=Insert(root->left,item);
		else if(item>root->value)
			root->right=Insert(root->right,item);
	}
	return root;
}


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
		disp(root->left);
		if(root->left!=NULL)fprintf(fp,"\n%d -- %d;",root->value,root->left->value);
		if(root->right!=NULL)fprintf(fp,"\n%d -- %d;",root->value,root->right->value);
		disp(root->right);
	}
}
tree* getnode()
{
	tree *temp;
	temp=(tree*)malloc(sizeof(tree));
	temp->left=temp->right=NULL;
	return temp;
}
