#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROUND(x) (int)(x+0.5)
typedef struct Binary_tree
{
	unsigned char value[5];
	int weight;
	char code;
	int star;
	struct Binary_tree *left;
	struct Binary_tree *right;
}tree;


typedef struct queue
{
	unsigned char val[5];
	int pri; tree* lookup;
	struct queue *next;
}queue;

FILE *fp;
queue *f;
static int count,cntcode,codelen;

tree* getnode()
{
	tree *temp;
	temp=(tree*)malloc(sizeof(tree));
	temp->left=NULL;temp->right=NULL;temp->star=0;
	return temp;
}


tree* ins_tree(tree *node1,tree *node2)
{
	tree *temp;
	temp=getnode();
	temp->left=node1;
	temp->right=node2;
	temp->weight=node1->weight+node2->weight;
	temp->code='0';
	strcpy(temp->value,"STAR");
	temp->star=++count;
	return temp;
}

tree* cast(queue* q,char n)
{
	tree *ptr;
	ptr=getnode();
	strcpy(ptr->value,q->val);
	ptr->code=n;
	ptr->weight=q->pri;
	return ptr;
}

void disp(tree *root)
{
	if(root!=NULL)
	{
		disp(root->left);
		if(root->left!=NULL)
			{
			if (!strcmp("STAR",root->value) && !strcmp("STAR",root->left->value))
			fprintf(fp,"\n\"%s-%d | %d\" -- \"%s-%d | %d\"",root->value,root->star,root->weight,root->left->value,root->left->star,root->left->weight);
			else if(!strcmp("STAR",root->left->value))
				fprintf(fp,"\n\"%s | %d\" -- \"%s-%d | %d\"",root->value,root->weight,root->left->value,root->left->star,root->left->weight);
				else if(!strcmp("STAR",root->value))
					fprintf(fp,"\n\"%s-%d | %d\" -- \"%s | %d\"",root->value,root->star,root->weight,root->left->value,root->left->weight);
					else 
						fprintf(fp,"\n\"%s | %d\" -- \"%s | %d\"",root->value,root->weight,root->left->value,root->left->weight); 
		fprintf(fp,"[style=bold,label=\" 0\"];");
			}
		if(root->right!=NULL)
			{			
			if (!strcmp("STAR",root->value) && !strcmp("STAR",root->right->value))
			fprintf(fp,"\n\"%s-%d | %d\" -- \"%s-%d | %d\"",root->value,root->star,root->weight,root->right->value,root->right->star,root->right->weight);
			else if(!strcmp("STAR",root->right->value))
				fprintf(fp,"\n\"%s | %d\" -- \"%s-%d | %d\"",root->value,root->weight,root->right->value,root->right->star,root->right->weight);
				else if(!strcmp("STAR",root->value))
					fprintf(fp,"\n\"%s-%d | %d\" -- \"%s | %d\"",root->value,root->star,root->weight,root->right->value,root->right->weight);
					else 
						fprintf(fp,"\n\"%s | %d\" -- \"%s | %d\"",root->value,root->weight,root->right->value,root->right->weight);
		fprintf(fp,"[style=bold,label=\" 1\"];");
			}
		disp(root->right);
	}

}


void Display(tree *root)
{
	fp=fopen("output","w");
	fprintf(fp,"graph g {\nlabel = \"CONVENSION: NODENAME | WEIGHT || STAR-# NODES ARE AGGREGATED NODES || OTHER NODES ARE PRIMAY NODES || THE VALUE OF EACH EDGE ARE INDICATED BESIDE THE EDGE\";\nnode [shape=record,width=2.00,style=filled,fillcolor=lightgray];");
	disp(root);
	fprintf(fp,"\n}");
	fclose(fp);
	system("dotty output");
	system("dot -Tpng output -o output.png");
}


void insert(unsigned char t1[],int t2,tree *look)
{
	queue *ptr,*prev;
	ptr=f;
	prev=NULL;
	if(f==NULL)
	{
		f=(queue*)malloc(sizeof(queue));
		strcpy(f->val,t1);f->pri=t2;f->next=NULL;f->lookup=look;
	}
	else
	{	

		while(ptr!=NULL && (ptr->pri)<=t2)
		{	prev=ptr;ptr=ptr->next;}
		if(prev==NULL)
		{
			ptr=(queue*)malloc(sizeof(queue));
			ptr->next=f;
			f=ptr;
			strcpy(f->val,t1);
			f->pri=t2;
			f->lookup=look;
		}
		else if(ptr==NULL)
		{
		prev->next=(queue*)malloc(sizeof(queue));
		ptr=prev->next;
		ptr->pri=t2;
		strcpy(ptr->val,t1);
		ptr->lookup=look;
		ptr->next=NULL;
		}
		else {
		prev->next=(queue*)malloc(sizeof(queue));
		prev->next->next=ptr;
		ptr=prev->next;
		ptr->pri=t2;
		strcpy(ptr->val,t1);
		ptr->lookup=look;	
		}

	}
}


queue* delete()
{
	queue *temp;
	if(f==NULL)
		return NULL;
	else
	{	temp=f;
		f=f->next;
		return temp;
	}
}




int isEmpty()
{
	return f==NULL?1:0;
}


tree* create_tree()
{
	queue *m,*n;
	tree* temp;
	while(!isEmpty())
	{
		m=delete();n=delete();
		if(n!=NULL)
		{
			if(!strcmp(m->val,"STAR")&& !strcmp(n->val,"STAR")){m->lookup->code='0';n->lookup->code='1';temp=ins_tree(m->lookup,n->lookup);}
			else if(!strcmp(m->val,"STAR")){m->lookup->code='0';temp=ins_tree(m->lookup,cast(n,1));}
			else if(!strcmp(n->val,"STAR")){n->lookup->code='1';temp=ins_tree(cast(m,0),n->lookup);}
			else temp=ins_tree(cast(m,'0'),cast(n,'1'));
		}
		else break;
		insert("STAR",temp->weight,temp);
	}
	strcpy(temp->value,"STAR");
	return temp;
}

void d(tree *r)
{
	if(r!=NULL)
	{
		printf("node value::%3s_%d_(%d)",r->value,r->star,r->weight);	
		if(r->left!=NULL){printf("\nleft of (%s_%d_(%d)-->",r->value,r->star,r->weight);d(r->left);}
		if(r->right!=NULL){printf("\nright of (%s_%d_(%d)-->",r->value,r->star,r->weight);d(r->right);}
	}

}
char temporal[5];
char* tostring(char ch)
{
if(ch!='"'&& ch!='\\')
{
temporal[0]=ch;
temporal[1]='\0';
}
else
{
temporal[0]='\\';
temporal[1]=ch;
temporal[2]='\0';
}
return temporal;
}

power(int x,int y)
{
	if(y==0) return 1;
	else if(y==1) return x;
	else return x*power(x,y-1); 
}

int bintodec(char x[])
{
	int i,res=0,len;
	len=strlen(x)-1;
	for(i=0;i<=len;i++)
	{ 
		res+=((int)x[i]-48)*power(2,len-i);
	}
	return res;
}

void showcode(tree *r,char ch[],int index)
{
	char str[128];
	ch[index]=r->code;
	index++;cntcode++;
	ch[index]='\0';
	if(strcmp("STAR",r->value))printf("\ncode of %s%d_%d--->%s-->%d",r->value,r->star,r->weight,ch+1,bintodec(ch+1));
	codelen+=strlen(ch+1);
	strcpy(str,ch);
	if(r->left!=NULL) showcode(r->left,str,index);
	if(r->right!=NULL) showcode(r->right,ch,index);
}

int logBase2(int num) { 

      if ( num == 1 )
           return 0; 

      return 1 + logBase2(num/2);

}

int main()
{
	int i,j,fxdlen,fxdbyte,varbyte;
	tree *tr;
	int ascii[128]={0};
	FILE* fp;
	char code[128];
	code[0]='\0';
	unsigned char ch;
	fp=fopen("inputfile","r");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		j=(int)ch;
	if(j>32)
		ascii[j]++;
	}
	fclose(fp);
	for(i=0;i<128;i++)
	{
		if(ascii[i]!=0)
		insert(tostring(i),ascii[i],NULL);
	}
	tr=create_tree();
	//d(tr);
	//Display(tr);
	printf("\n\nShow codes...\n");
	cntcode=0;codelen=0;
	showcode(tr,code,0);
	printf("\n\n Average codelength[%f]--> %d\n",(float)codelen/cntcode,ROUND(((float)codelen/cntcode)));
	varbyte=ROUND(((float)codelen/8));
	printf(" Total Byte transferred for Huffman coding--> %d\n",varbyte);
	fxdlen=logBase2(cntcode);
	if(power(2,fxdlen)!=cntcode)fxdlen++;
	fxdbyte=ROUND(((float)fxdlen*cntcode)/8);
	printf(" Total Byte transferred if fixed lengthis used--> %d\n",fxdbyte);
	printf(" Percentage of saving--> %f%\n",(float)(fxdbyte-varbyte)/fxdbyte*100);
	Display(tr);
	printf("\n");
return 0;
}
