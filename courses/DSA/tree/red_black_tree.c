#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>


/*//////////////////////////////////////////////*/
//		STRUCTURE DEFINITION		//	
/*//////////////////////////////////////////////*/

/* 
	Name:	Red_Black_tree
	Description:	This is the stricture of the tree 
*/
typedef struct Red_Black_tree
{
	int value;				//this is node value
	struct Red_Black_tree *left;		//this is left pointer
	struct Red_Black_tree *right;		//this is roght pointer
	struct Red_Black_tree *parent;		//this is pointer to parent
	char color[5];				//this is the color of the node
}rbt;

rbt *rootreal=NULL;


/*//////////////////////////////////////////////*/
//		FUNCTION DEFINITIONS		//
/*//////////////////////////////////////////////*/



/*
	Name:	toBlack
	Input:	node pointer
	Output:	void
	Description:	sets color of the node to Black
*/
void toBlack(rbt *root)
{
	if ( root!=NULL ) strcpy(root->color,"BLACK");
}


/*
	Name:	toRed
	Input:	node pointer
	Output:	void
	Description:	sets color of the node to Red
*/
void toRed(rbt *root)
{
	if ( root != NULL ) strcpy(root->color,"RED");
}


/*
	Name:	isBlack
	Input:	node pointer
	Output:	1 if Black oterwise 0
	Description:	checks color of the node is Black or not
*/
int isBlack(rbt *root)
{
	return root == NULL ? 1 : (strcmp(root->color,"BLACK") ? 0 : 1);
}


/*
	Name:	isRed
	Input:	node pointer
	Output:	1 if Red oterwise 0
	Description:	checks color of the node is Red or not
*/
int isRed(rbt *root)
{
	return strcmp(root->color,"RED") ? 0 : 1;
}


/*
	Name:	getnode
	Input:	value as integer
	Output:	a new initialized node
	Description:	this function creates a new node and initializes it and then returns
*/
rbt* getNode(int data)
{
	rbt *node;
	node=(rbt*)malloc(sizeof(rbt));		//creates new node
	node->value=data;			//initializes
	node->left=NULL;			//the 
	node->right=NULL;			//attributes
	node->parent=NULL;			//of the 
	toRed(node);				//node
	return node;				//returns the new node
}


/*
	Name:	destroy
	Input:	a node pointer
	Output:	void
	Description:	this function destroyes a tree pointed by node pointer
*/
void destroy(rbt *root)
{
	if(root!=NULL)
	{
		destroy(root->left);		//destroyes right sub-tree
		destroy(root->right);		//destroyes left sub-tree 
		free(root);					//frees itself
	}
}


/*
	Name:	L2L
	Input:	a pointer to a node
	Output:	a pointer to a node
	Description:	rotates left to left w.r.t. pivot and returns new node at that place
*/
rbt* L2L(rbt* pivot)
{
	rbt *temp;

	temp = pivot;

	if(pivot->parent != NULL)
	{
		if(pivot->parent->left == pivot)
			pivot->parent->left = temp->left;
		else 
			pivot->parent->right = temp->left;
	}

	pivot = temp->left;
	pivot->parent = temp->parent;

	temp->left = pivot->right;
	if(temp->left != NULL)temp->left->parent = temp;

	pivot->right = temp;
	pivot->right->parent = pivot;

	if(rootreal == temp)
	rootreal = pivot;

	return pivot;
}


/*
	Name:	R2R
	Input:	a pointer to a node
	Output:	a pointer to a node
	Description:	rotates right to right w.r.t. pivot and returns new node at that place
*/
rbt* R2R(rbt* pivot)
{
	rbt *temp;

	temp = pivot;

	if(pivot->parent != NULL)
	{
		if(pivot->parent->left == pivot)
			pivot->parent->left = temp->right;
		else 
			pivot->parent->right = temp->right;
	}

	pivot = temp->right;
	pivot->parent = temp->parent;

	temp->right = pivot->left;
	if(temp->right != NULL)temp->right->parent = temp;

	pivot->left = temp;
	pivot->left->parent = pivot;

	if(rootreal == temp)
	rootreal = pivot;

	return pivot;
}


/*
	Name:	insertCase1
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
void insertCase1(rbt *root,rbt *data)
{
	rootreal = data;
	toBlack(rootreal);
}


/*
	Name:	insertCase2
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
void insertCase2(rbt *root,rbt *data)
{
	if(root->value > data->value)
	{
		root->left = data;
		root->left->parent = root;
	}
	else
	{
		root->right = data;
		root->right->parent = root;
	}
}


/*
	Name:	insertCase3a
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
void insertCase3a(rbt *root,rbt *data)
{
	root->left = data;
	root->left->parent = root;
	toBlack(root->left);
	root = L2L(root->parent);
}


/*
	Name:	insertCase3b
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
void insertCase3b(rbt *root,rbt *data)
{
	root->right = data;
	root->right->parent = root;
	root = R2R(root);
	toBlack(root->left);
	root = L2L(root->parent);
}

/*
	Name:	insertCasec
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
void insertCase3c(rbt *root,rbt *data)
{
	root->left = data;
	root->left->parent = root;
	root = L2L(root);
	toBlack(root->right);
	root = R2R(root->parent);
}

/*
	Name:	insertCase3d
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
void insertCase3d(rbt *root,rbt *data)
{
	root->right = data;
	root->right->parent = root;
	toBlack(root->right);
	root = R2R(root->parent);
}


/*
	Name:	insert
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
void Insert(rbt *root,rbt *data)
{
	int flag;
	if (rootreal == data||root ==NULL)
	{
		insertCase1(root,data);
	}
	else if(root !=NULL && isBlack(root))
		{
			insertCase2(root,data);
		}
		else if(root != NULL)
		{
			if((root->parent == NULL && root->value > data->value) || (root->parent->left == root))
			{
				if(root->value > data->value)
				{
					insertCase3a(root,data);flag=1;
				}
				else
				{
					insertCase3b(root,data);
					flag=0;
				}
			}
			else 
			{
				if(root->value > data->value)
				{
					insertCase3c(root,data);flag=0;
				}
				else
				{
					insertCase3d(root,data);
					flag=1;
				}
			}
	if(root->parent != NULL) 
		{
			if (flag==0)Insert(root->parent->parent,root->parent);
			else Insert(root->parent,root);
		}
	else
		Insert(NULL,root);
	}
}


/*
	Name:	searchWhereToInsert
	Input:	a pointer to a node and a integer
	Output:	pointer to a node 
	Description:	this function searches the tree and finds the position where to insert the given value
*/
rbt* searchWhereToInsert(rbt *root,rbt *data)
{
	if ( root->value < data->value )
	{
		if(root->right != NULL)
			return searchWhereToInsert(root->right,data);
		else
			return root;
	}
	else if ( root->value > data->value )
		{
			if(root->left != NULL)
				return searchWhereToInsert(root->left,data);
			else
				return root;
		}
		else
			return NULL;
}


/* 
	Name: d
	Input: node pointer
	Output: void
	Description: test function:: prints to console file output format of graphviz
*/
void d(rbt *root)
{
	if(root!=NULL)
	{
		d(root->left);				//recursive call to left sub-tree
		if(root->left!=NULL)
			printf("\n%d <-left- %d;",root->left->value,root->value);
		if(root->right!=NULL)
			printf("\n\t%d -right-> %d;",root->value,root->right->value);
		d(root->right);				//recursive call to right sub-tree
	}
}


/*
	Name:	traverseAndWrite
	Input:	a pointer to a node and file pointer
	Output:	void
	Description:	writes description of all internal node
*/
void traverseAndWrite(rbt *root,FILE *fp)
{
	if(root!=NULL)
	{
		fprintf(fp,"\n%d [width=1.00,style=filled,fillcolor=%s];",root->value,root->color);
		traverseAndWrite(root->left,fp);				//recursive call to left sub-tree
		traverseAndWrite(root->right,fp);				//recursive call to right sub-tree
	}
}


int ext_count=0;
/*
	Name:	disp
	Input:	a pointer to the node and the file pointer 
	Output:	writes information to the file
	Description:	this function writes the information 
			required by software "GraphViz" 
			to display the graph which node is the pointer to node 
			to the file pointed by the file pointer
*/
void disp(rbt *root,FILE *fp)
{
	if(root!=NULL)
	{
		disp(root->left,fp);			//recursive call to the left node
		if(root->left!=NULL)
		{
			fprintf(fp,"\n%d -- %d",root->value,root->left->value);
			fprintf(fp,"[style=bold,label=\" L\"];");
		}
		else 
		{
			fprintf(fp,"\n%d -- \"ext-%d\"",root->value,++ext_count);
			fprintf(fp,"[style=bold,label=\" L\"];");
		}
		if(root->right!=NULL)
		{
			fprintf(fp,"\n%d -- %d",root->value,root->right->value);
			fprintf(fp,"[style=bold,label=\" R\"];");
		}
		else
		{
			fprintf(fp,"\n%d -- \"ext-%d\"",root->value,++ext_count);
			fprintf(fp,"[style=bold,label=\" R\"];");
		}
		disp(root->right,fp);			//recursive call to the right node
	}
}


/*
	Name:	writeExt
	Input:	file pointer
	Output:	void
	Description:	writes description of all external node
*/
void writeExt(FILE *fp)
{
	int i=0;
	while(i<ext_count)
	fprintf(fp,"\n\"ext-%d\" [shape=record,width=0.25,style=filled,fillcolor=BLACK];",++i);
}


/*
	Name:	Display
	Input:	a pointer to a node and a string
	Output:	creates a png file with name as the input string
	Description:	the output png display the graph pointed by the node 
*/
void display(rbt *root,char* outfilename)
{
	FILE *fp;char buffer[100]="";
	fp=fopen(outfilename,"w");			//opens a file named output in write mode to write the information about tree
	fprintf(fp,"graph g {\nlabel = \"By. Soumadip Biswas_10IT60R12\";\nnode [fontcolor=WHITE,fontstyle=bold];\n");
	ext_count=0;
	disp(root,fp);						//calls the disp function and passes the file pointer
	traverseAndWrite(root,fp);
	writeExt(fp);
	fprintf(fp,"\n}");
	fclose(fp);							//closes the file
	strcat(buffer,"dot -Tpng ");
	strcat(buffer,outfilename);
	strcat(buffer," -o ");
	strcat(buffer,outfilename);
	strcat(buffer,".png");
	system(buffer);						//creates the png file -- system call
}


/*//////////////////////////////////////////////*/
//		THE MAIN FUNCTION		//
/*//////////////////////////////////////////////*/

/* 
	Name: main
	Input: void
	Output: sucess or failure
	Description: test procedure
*/
int main()
{
	rbt *data,*node;
	int value,no_of_nodes,nodecount;
	int testcases;
	struct timeval time_start,time_end;
	long total_time,instance_time;
	char filename[50];
	char out[20]="./_/out____";char c='A';
	char final_output[20]="./_/final_output__";char ch='1';
	char command1[20]="mkdir _";
	char command2[20]="rm -rf _";
	FILE *log,*fcase;
	log=fopen("stat.rbt","w");
	scanf("%d",&testcases);
	while(testcases--)
	{
		scanf("%s",&filename);
		fcase=fopen(filename,"r");
		if(fcase==NULL)
		{
			printf("Error in opeing the file\n");
		fprintf(log,"\n--------------------------------------------------------------------------------------------------------------------------------------------");
		fprintf(log,"\n\nFILENAME:: %s\n",filename);
		fprintf(log,"ERROR_IN_OPENING_FILE\n");
		fprintf(log,"--------------------------------------------------------------------------------------------------------------------------------------------\n\nEXITING_PROGRAM");
		exit(0);
		}
		fscanf(fcase,"%d",&no_of_nodes);
		nodecount=0;	
		command2[7]=ch;
		system(command2);
		command1[6]=ch;
		system(command1);
	//	scanf("%d",&no_of_nodes);
		total_time=0;
		fprintf(log,"\n--------------------------------------------------------------------------------------------------------------------------------------------");
		fprintf(log,"\n\nFILENAME:: %s\n",filename);
		fprintf(log,"\nNO_OF_NODES(FROM_FILE):: %d\n\n",no_of_nodes);
		while(no_of_nodes)
		{
			gettimeofday(&time_start, NULL);
			fscanf(fcase,"%d",&value);//scanf("%d",&value);
			data = getNode(value);
			if ( rootreal == NULL ) 
			{
				rootreal = data;
				toBlack(rootreal);
			}
			node = searchWhereToInsert(rootreal,data);
			if(node != NULL)Insert(node,data);
			gettimeofday(&time_end, NULL);
			instance_time=(time_end.tv_sec-time_start.tv_sec)*1000000+(time_end.tv_usec-time_start.tv_usec);
			total_time+=instance_time;
			fprintf(log,"TIME_TAKEN_FOR_INSERTION_OF %4d:: %d microsec\n",value,instance_time);
			out[8]=ch;out[2]=ch;
			out[10]=c++;
	//		display(rootreal,out);
			no_of_nodes--;nodecount++;
		}
		c='A';
		printf("time-------case-%d-------> %ld microseconds\n",ch-48,total_time);
		fprintf(log,"\nNO_OF_INSERT_ATTEMPTS:: %d\n\n",nodecount);
		fprintf(log,"\nTOTAL_TIME_TAKEN:: %ld microsec\n",total_time);
		fprintf(log,"TOTAL_SPACE_TAKEN:: %ld BYTES\n\n\n",nodecount*sizeof(rbt));
		fprintf(log,"--------------------------------------------------------------------------------------------------------------------------------------------");
		final_output[2]=ch;
		final_output[17]=ch++;
		display(rootreal,final_output);
	//	d(rootreal);printf("\n\n");
		destroy(rootreal);
		rootreal=NULL;
	}
	fprintf(log,"--------------------------------------------------------------------------------------------------------------------------------------------\n\nEXITING_PROGRAM");
	fclose(log);
	return 1;
}


