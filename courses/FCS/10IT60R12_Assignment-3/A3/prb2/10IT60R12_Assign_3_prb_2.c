#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int value;
	struct tree *left;
	struct tree *right;
}tree;

FILE* fp;
int *in,*pre;
int len;
static int pos;
int pos_in()
{
	int i=-1;
	while(in[++i]!=pre[pos]);
	return i;
}

tree* create_tree(int start, int end)
{
	int x;
	tree *root;
	root=(tree*)malloc(sizeof(tree));
	root->value=pre[pos];root->left=NULL;root->right=NULL;printf("rootvalue-->%d",root->value);
	if(start==end)
		return root;
	else
	{
		x=pos_in();
		if(x!=start)
		{
			pos++;	
			printf("\ngoto left(%d)-->",root->value);root->left=create_tree(start,x-1);
		}
		if(x!=end)
		{
			pos++;
			printf("\ngoto right(%d)-->",root->value);root->right=create_tree(x+1,end);
		}
	}
return root;
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

void display(tree *root)
{
	fp=fopen("output","w");
	fprintf(fp,"graph g {\nnode [shape=invtriangle,width=0.75,style=filled,fillcolor=lightgray];");
	disp(root);
	fprintf(fp,"\n}");
	fclose(fp);
	system("dotty output");
	
}
void post(tree* tr)
{
	if(tr==NULL)
	return;
	else
	{
		post(tr->left);
		post(tr->right);
		printf("%4d",tr->value);
	}

}

void destroy(tree *t1)
{
if(t1->left!=NULL)destroy(t1->left);
if(t1->right!=NULL)destroy(t1->right);
free(t1);
}

int main()
{
	tree *tr;
	int i,testcase;
	tr=NULL;
	scanf("%d",&testcase);
	while(testcase)
	{
		pos=0;
		scanf("%d",&len);
	//printf("in--> ");
		in=(int*)malloc(sizeof(int)*len);
		i=0;
		while(i<len)scanf("%d",&in[i++]);
	//printf("pre--> ");
		pre=(int*)malloc(sizeof(int)*len);
		i=0;
		while(i<len)scanf("%d",&pre[i++]);
		tr=create_tree(0,len-1);
		printf("\nPost Order==>");
		post(tr);
		printf("\n");
		display(tr);
		printf("\n");
		destroy(tr);tr=NULL;
		free(in);free(pre);
	testcase--;
	}
	return 0;
}
