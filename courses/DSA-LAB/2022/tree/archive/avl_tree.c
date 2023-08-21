#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>


/*//////////////////////////////////////////////*/
//		STRUCTURE DEFINITION		//	
/*//////////////////////////////////////////////*/

/* 
	Name:	AVL_tree
	Description:	This is the stricture of the tree 
*/
typedef struct AVL_tree
{
	int value;			//this is the node value
	struct AVL_tree *left;		//this is the left pointer
	struct AVL_tree *right;		//this is the right pointer
	int height;			//this is the height of the tree pointer by the node
	int bf;				//this is balance factor of the node
}avl;

avl *rootreal=NULL;


/*//////////////////////////////////////////////*/
//		FUNCTION DEFINITIONS		//
/*//////////////////////////////////////////////*/


/*
	Name:	getnode
	Input:	value as integer
	Output:	a new initialized node
	Description:	this function creates a new node and initializes it and then returns
*/
avl* getNode(int data)
{
	avl *temp;
	temp=(avl*)malloc(sizeof(avl));	//creates new node
	temp->value=data;
	temp->left=NULL;				//initializes
	temp->right=NULL;				//the 
	temp->height=1;					//attributes 
	temp->bf=0;					//node
	return temp;					//returns new node
}


/*
	Name:	destroy
	Input:	a node pointer
	Output:	void
	Description:	this function destroyes a tree pointed by node pointer
*/
void destroy(avl *root)
{
	if(root!=NULL)
	{
		destroy(root->left);		//destroyes right sub-tree
		destroy(root->right);		//destroyes left sub-tree 
		free(root);			//frees itself
	}
}


/*
	Name:	parent
	Input:	two pointer to two nodes 
	Output:	a pointer to a node
	Description:	this function 	returns the parent node of corresponding node
*/
avl* parent(avl *root,avl *current)
{
	if(current !=root)
	{
		if(current->left==root || current->right==root) return current;
		else if(current->value > root->value)
			return parent(root,current->left);
			else return parent(root,current->right);
	}
	else return NULL;
}


/*
	Name:	L2L
	Input:	a pointer to a node
	Output:	a pointer to a node
	Description:	rotates left to left w.r.t. pivot and returns new node at that place
*/
avl* L2L(avl *pivot)
{
	avl *temp,*prnt;
if(pivot==NULL)return NULL;
	temp = pivot;
	
	pivot = pivot->left;
	temp->left = pivot->right;
	pivot->right = temp;
	if(rootreal == temp)
	rootreal = pivot;
	else
	{
		prnt=parent(temp,rootreal);
		if(prnt->left==temp)prnt->left=pivot;
		else prnt->right=pivot;
	}
	return pivot;
}


/*
	Name:	R2R
	Input:	a pointer to a node
	Output:	a pointer to a node
	Description:	rotates right to right w.r.t. pivot and returns new node at that place
*/
avl* R2R(avl *pivot)
{
	avl *temp,*prnt;
if(pivot==NULL)return NULL;
	temp = pivot;
	
	pivot = pivot->right;
	temp->right = pivot->left;
	pivot->left = temp;
	if(rootreal == temp)
	rootreal = pivot;
	else
	{
		prnt=parent(temp,rootreal);
		if(prnt->left==temp)prnt->left=pivot;
		else prnt->right=pivot;
	}
	return pivot;
}


/*
	Name:	L2R
	Input:	a pointer to a node
	Output:	a pointer to a node
	Description:	rotates left to right w.r.t. pivot and returns new node at that place
*/
avl* L2R(avl *pivot)
{
	pivot->right=L2L(pivot->right);
	return R2R(pivot);
}


/*
	Name:	R2L
	Input:	a pointer to a node
	Output:	a pointer to a node
	Description:	rotates right to left w.r.t. pivot and returns new node at that place
*/
avl* R2L(avl *pivot)
{
	pivot->left=R2R(pivot->left);
	return L2L(pivot);
}


/* 
	Name:	max
	Input:	two integers
	Output:	integer
	Description:	returns maximum of two input integers
*/
int max(int x,int y)
{
	return x>y?x:y;			//uses tenary operator
}


/*
	Name:	heightDown
	Input:	a pointer to a node 
	Output:	returns the height of a tree pointing by the node
	Description:	this function returns the height of a tree pointing by the node 
*/
int heightDown(avl *root) 
{
	if(root	==NULL)
		return 0;							
	else 
	{
		root->height = max(heightDown(root->left),heightDown(root->right)) + 1;	//calls max, finds maximum of two sub-tree heights
		return root->height;
	}
}

int flag;


/*
	Name:	saveBF
	Input:	a pointer to a node and access a global integer
	Output:	1 if banancing is required else 0
	Description:	this function calculates all balance factor of the tree
*/
int saveBF(avl *root)
{	
	if(root!=NULL&&root->left!=NULL&&root->right!=NULL)					//when root with left and right child present 
		root->bf=root->left->height - root->right->height;					//call diff between height if left and right sub-tree

		else	if(root!=NULL&&root->left!=NULL)					//if only one child(left) present
			root->bf=root->left->height==0?1:root->left->height;				
		
			else	if(root!=NULL&&root->right!=NULL)				//if only one child(right) present
					root->bf=root->right->height==0?-1:(-1)*root->right->height;

				else	if(root!=NULL)						//no child present
						root->bf=0;
	if(root)if(root->bf > 1||root->bf < -1)flag=1;
	if(root!=NULL)
	{
		saveBF(root->left);						//recursive call to left sub-tree
		saveBF(root->right);						//recursive call to right sub-tree
	}	
	return flag;	
}


/*
	Name:	calculateFact
	Input:	a pointer to a node 
	Output:	1 if banancing is required else 0
	Description:	this function calls heigthtDown and savBF method 
*/
int calculateFact(avl *root)
{
	heightDown(root);
	return saveBF(root);
}


/*
	Name:	insertNodeBST
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
void insertNodeAVL(avl *root,int data)
{
	if(root !=NULL)							//if node is not NULL then finds appropriate position to insert
	{
		if(data<root->value)
				root->left=getNode(data);	//inserts to left if data is less than node value
		else if(data>root->value)
				root->right=getNode(data);;	//inserts to right if data is greater than node value 
	}
}


/* 
	Name: d
	Input: node pointer
	Output: void
	Description: test function:: prints to console file output format of graphviz
*/
void d(avl *root)
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
	Name:	disp
	Input:	a pointer to the node and the file pointer 
	Output:	writes information to the file
	Description:	this function writes the information 
			required by software "GraphViz" 
			to display the graph which node is the pointer to node 
			to the file pointed by the file pointer
*/
void disp(avl *root,FILE *fp)
{
	if(root!=NULL)
	{
		disp(root->left,fp);			//recursive call to the left node
		if(root->left!=NULL)
		{
			fprintf(fp,"\n\"%d|%d|%d\" -- \"%d|%d|%d\"",root->value,root->bf,root->height,root->left->value,root->left->bf,root->left->height);
			fprintf(fp,"[style=bold,label=\" L\"];");
		}
		if(root->right!=NULL)
		{
			fprintf(fp,"\n\"%d|%d|%d\" -- \"%d|%d|%d\"",root->value,root->bf,root->height,root->right->value,root->right->bf,root->right->height);
			fprintf(fp,"[style=bold,label=\" R\"];");
		}
		disp(root->right,fp);			//recursive call to the right node
	}
}


/*
	Name:	Display
	Input:	a pointer to a node and a string
	Output:	creates a png file with name as the input string
	Description:	the output png display the graph pointed by the node 
*/
void display(avl *root,char* outfilename)
{
	FILE *fp;char buffer[100]="";
	fp=fopen(outfilename,"w");			//opens a file named output in write mode to write the information about tree
	fprintf(fp,"graph g {\nlabel = \"CONVENSION: NODEVALUE | BALANCE FACTOR | HEIGHT\";\nnode [shape=record,width=0.75,style=filled,fillcolor=lightgray];");
	disp(root,fp);					//calls the disp function and passes thprintf("/n/nleft to left called/n/n");e file pointer
	fprintf(fp,"\n}");
	fclose(fp);					//closes the file
	strcat(buffer,"dot -Tpng ");
	strcat(buffer,outfilename);
	strcat(buffer," -o ");
	strcat(buffer,outfilename);
	strcat(buffer,".png");
	system(buffer);					//creates the png file -- system call
	
}
	int typePivot,typeInsert;


/*
	Name:	searchWhereToInsert
	Input:	a pointer to a node and a integer
	Output:	pointer to a node 
	Description:	this function searches the tree and finds the position where to insert the given value
*/
avl* searchWhereToInsert(avl *root,int data)
{

	if ( root->value < data)
	{
		if(root->right != NULL)
			{
				typePivot=1;
				return searchWhereToInsert(root->right,data);
			}
		else
			return root;
	}
	else if ( root->value > data )
		{
			if(root->left != NULL)
				{
					typePivot=0;
					return searchWhereToInsert(root->left,data);
				}
			else
				return root;
		}
		else
			return NULL;
}


/*
	Name:	searchWhereToBalance
	Input:	a pointer to a node 
	Output:	pointer to a node 
	Description:	this function searches the tree and finds the position where the balacing is required
*/
avl* searchWhereToBalance(avl *root)
{
	if(root==NULL) return NULL;

	if(root->bf>1||root->bf<-1)
		return root;
	else 
		return searchWhereToBalance(parent(root,rootreal));
}


/*
	Name:	balance
	Input:	a pointer to a node and the data to be inserted 
	Output:	void
	Description:	this function checks and takes required action to balance the tree
*/
void balance(avl *root,int data)
{

	if(root!=NULL)
	{
		root=searchWhereToBalance(root);
		if(root->value > data)
		{
		typePivot=0; 
		if(root->left->value > data)
			typeInsert=0;
		else 
			typeInsert=1;
		}
		else 
		{
		typePivot=1;
		if(root->right->value > data)
			typeInsert=0;
		else 
			typeInsert=1;
		}
		if(root!=NULL)
		{
			if(!typeInsert && !typePivot)
				L2L(root);
			else if(!typeInsert && typePivot)
					L2R(root);
				else if(typeInsert && !typePivot)
						R2L(root);
					else 
						R2R(root);
		}
		flag=0;
		if(calculateFact(rootreal))
			balance(root,root->value);
	}
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
	avl *temp;
	int testcase,no,data,nodecount;
	struct timeval time_start,time_end;
	long total_time,instance_time;
	char filename[50];
	char out[20]="./_/out____";char c='A';
	char final_output[20]="./_/final_output__";char ch='1';
	char command1[20]="mkdir _";
	char command2[20]="rm -rf _";
	FILE *log,*fcase;
	log=fopen("stat.avl","w");
	scanf("%d",&testcase);			//input no of testcases

	while(testcase--)
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
		fscanf(fcase,"%d",&no);			//input no of nodes
		command2[7]=ch;
		system(command2);
		command1[6]=ch;
		system(command1);
		total_time=0;
		fprintf(log,"\n--------------------------------------------------------------------------------------------------------------------------------------------");
		nodecount=0;
		fprintf(log,"\n\nFILENAME:: %s\n",filename);
		fprintf(log,"\nNO_OF_NODES(FROM_FILE):: %d\n\n",no);
		while(no)
		{
			gettimeofday(&time_start, NULL);
			if(fscanf(fcase,"%d",&data) == EOF)break;//scanf("%d",&data);		//input data or node value
			if(rootreal==NULL)
			rootreal=getNode(data);
			else
			{
				temp=searchWhereToInsert(rootreal,data);
				insertNodeAVL(temp,data);	//calls insertNodeBST	
				flag=0;
				if(calculateFact(rootreal))
					balance(temp,data);	//d(rootreal);		//should put before this statement if activated
			}
			gettimeofday(&time_end, NULL);
			instance_time=(time_end.tv_sec-time_start.tv_sec)*1000000+(time_end.tv_usec-time_start.tv_usec);
			total_time+=instance_time;
			fprintf(log,"TIME_TAKEN_FOR_INSERTION_OF %4d:: %d microsec\n",data,instance_time);
			out[8]=ch;out[2]=ch;
			out[10]=c++;
	//		display(rootreal,out);
			no--;nodecount++;
		}
		c='A';
		printf("time-------case-%d-------> %ld microseconds\n",ch-48,total_time);
		fprintf(log,"\nNO_OF_INSERT_ATTEMPTS:: %d\n\n",nodecount);
		fprintf(log,"\nTOTAL_TIME_TAKEN:: %ld microsec\n",total_time);
		fprintf(log,"TOTAL_SPACE_TAKEN:: %ld BYTES\n\n\n",nodecount*sizeof(avl));
		fprintf(log,"--------------------------------------------------------------------------------------------------------------------------------------------");
		final_output[2]=ch;
		final_output[17]=ch++;
		display(rootreal,final_output);
	//	d(rootreal);printf("\n\n");
		destroy(rootreal);				//calls destroy
	}	
	fprintf(log,"--------------------------------------------------------------------------------------------------------------------------------------------\n\nEXITING_PROGRAM");
	fclose(log);
	return 1;				//return success
}

