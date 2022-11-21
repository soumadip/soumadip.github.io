#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

FILE *fp;
int main()
{
	int i,j,k,no,item;
	
	scanf("%d",&no);
	while(no)
	{
		scanf("%d",&item);
		t1=Insert(t1,item);
		no--;	
	}
	printf("\nPreOrder==> ");pre(t1);
	printf("\nInOrder==> ");in(t1);
	printf("\nPostOrder==> ");post(t1);
	printf("\nMax==> %d",max(t1));
	printf("\nMin==> %d",min(t1));
	printf("\nAverage==> %f",avg(t1));
	Display(t1);
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
		else 
			root->right=Insert(root->right,item);
	}
	return root;
}

void Display(tree *root)
{
	fp=fopen("output","w");
	fprintf(fp,"graph g {\nnode [shape=invtriangle,width=0.75,style=filled,fillcolor=lightgray];");
	disp(root);
	fprintf(fp,"\n}");
	fclose(fp);
	system("dotty output");
	
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