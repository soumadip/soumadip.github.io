#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/*//////////////////////////////////////////////*/
//		STRUCTURE DEFINITION		//	
/*//////////////////////////////////////////////*/

/* 
	Name:	Binary_Search_tree
	Description:	This is the stricture of the tree 
*/
typedef struct Binary_Search_tree
{
	int value;				//this is the node value
	struct Binary_Search_tree *left;	//this is the left pointer
	struct Binary_Search_tree *right;	//this is the right pointer
	int bf;					//this is the balance factor of the node
	int heigh;				//this is the height of the node (level+1) i.e. distance from root
	int hh;					//this is the maximum height of the tree which root is this node
}tree;



/*//////////////////////////////////////////////*/
//		FUNCTION DEFINITIONS		//
/*//////////////////////////////////////////////*/

/*
	Name:	getnode
	Input:	void
	Output:	a new initialized node
	Description:	this function creates a new node and initializes it and then returns
*/
tree* getnode()
{
	tree *temp;
	temp=(tree*)malloc(sizeof(tree));	//creates new node
	temp->left=NULL;			//initializes
	temp->right=NULL;			//the 
	temp->bf=-1;				//attributes 
	temp->heigh=-1;				//of the
	temp->hh=-1;				//node
	return temp;				
}


/*	
	Name:	destroy
	Input:	a node pointer
	Output:	void
	Description:	this function destroyes a tree pointed by node pointer
*/

void destroy(tree *root)
{
	if(root!=NULL)
	{
		destroy(root->left);		//destroyes right sub-tree
		destroy(root->right);		//destroyes left sub-tree 
		free(root);			//frees itself
	}
}


/*
	Name:	insertNodeBST
	Input:	node pointer and data to be inserted(integer)
	Output:	tree with inserted value(if valid othewise old tree)
	Description:	if the data not already present in the tree it inserts the data to appropriate position 
*/
tree* insertNodeBST(tree *root,int data)
{
	if(root==NULL)							//if node is NULL creates new one and then inserts
	{
		root=getnode();						//calls getnode to get a new node
		root->value=data;		
	}
	else								//if node is not NULL then finds appropriate position to insert
	{
		if(data<root->value)
			root->left=insertNodeBST(root->left,data);	//inserts to left if data is less than node value
		else if(data>root->value)
			root->right=insertNodeBST(root->right,data);	//inserts to right if data is greater than node value 
	}
	return root;
}

/* 
	Name:	searchNodeBST
	Input:	node pointer and data to search
	Output:	1 or 0
	Description:	returns 1 if data is found else 0
*/

int searchNodeBST(tree *root, int data)
{
	if(root==NULL)
		return 0;						//not found

	else	if (root->value==data)
			return 1;					//found

		else	if(data<root->value)
				return searchNodeBST(root->left,data);	//recursive call to left sub-tree if data value is lesser than node value

			else 
				return searchNodeBST(root->right,data);	//recursive call to right sub-tree if data value is greater than node value
}


/* 
	Name:	mergeBST
	Input:	two node pointers
	Output:	node pointer
	Description:	merges 2nd tree pointed by 2nd node to the 1st tree ponted by 1st node and returns 1st node pointer
*/
tree* mergeBST(tree *root1,tree *root2)
{
	if(root2!=NULL)							//only proceed if 2nd pointer is valid
	{
		if(!searchNodeBST(root1,root2->value))			//checks whether value is already present by calling searchNodeBST
			root1=insertNodeBST(root1,root2->value);	//if not present then inserts
		mergeBST(root1,root2->left);				//recursive call to merge left sub-tree with the same
		mergeBST(root1,root2->right);				//recursive call to merge right sub-tree with the same
	}
	return root1;							//returns 1st pointer
}


/* 
	Name:	computeHeigh
	Input:	two node pointer
	Output:	height(integer)
	Description:	returns the height of the 2nd node from the root node in the tree pointed by 2nd node pointer
*/
int computeHeigh(tree *root,tree *node)
{
	if(root==NULL)										//not there
		return 0;

	else	if(root->value==node->value)
			return 1;								//found

		else	if(node->value<root->value)						
				return 1+computeHeigh(root->left,node);				//recursive call to left sub-tree if node value lesser than root value

			else									
				return 1+computeHeigh(root->right,node);			//recursive call to rght sub-tree if node value greater than root value
}


/* 
	Name:	diff
	Input:	two integers
	Output:	integer
	Description:	returns difference between tow input integers
*/
int diff(int x,int y)
{
	return x>y?x-y:y-x;		//uses tenary operator
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
	Name:	saveBF
	Input:	node pointer
	Output:	node pointer
	Description:	calculates balance factor at all the nodes of the tree pointed by the node
*/
void saveBF(tree *root)
{
	if(root!=NULL&&root->left!=NULL&&root->right!=NULL)					//when root with left and right child present 
		root->bf=diff(root->left->hh,root->right->hh);					//call diff between height if left and right sub-tree

		else	if(root!=NULL&&root->left!=NULL)					//if only one child(left) present
			root->bf=root->left->hh==0?1:root->left->hh;				
		
			else	if(root!=NULL&&root->right!=NULL)				//if only one child(right) present
					root->bf=root->right->hh==0?1:root->right->hh;

				else	if(root!=NULL)						//no child present
						root->bf=0;
	if(root!=NULL)
	{
		saveBF(root->left);						//recursive call to left sub-tree
		saveBF(root->right);						//recursive call to right sub-tree
	}		
}


/* 
	Name:	heightDown
	Input:	node pointer
	Output:	integer
	Description:	returns the maximum height of ant tree pointed by the node 
*/
int heightDown(tree *node) 
{
	if(node==NULL)
		return -1;							
	else 
	{
		node->hh=max(heightDown(node->left),heightDown(node->right)) + 1;	//calls max, finds maximum of two sub-tree heights
		return node->hh;
	}
}


/* 
	Name:	saveHeigh
	Input:	two node pointer
	Output:	void
	Description:	1st node pointer is the node which distance to be calculated
			2nd node pointer is the node from which distanceis to be calculated
			saves height of all nodes of the tree pointed by 1st node from the 2nd node 
*/
void saveHeigh(tree *root,tree *mainroot)
{
	if(root!=NULL)							//stops if node is NULL
	{
		saveHeigh(root->left,mainroot);				//recursive call to left sub-tree
		saveHeigh(root->right,mainroot);			//recursive call to right sub-tree
		root->heigh=computeHeigh(mainroot,root);		//calls computeHeigh
		root->hh=heightDown(root);				//calls heighDown
	}
}


/* 
	Name: d
	Input: node pointer
	Output: void
	Description: test function:: prints to console file output format of graphviz
*/
void d(tree *root)
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
	Name: adjust
	Input: node pointer
	Output: node pointer
	Description: adjusts all the values of any distorted tree 
*/
void adjustBST(tree *root)
{
	saveHeigh(root,root);			//calls saveHeigh
	saveBF(root);			//calls saveBF
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
void disp(tree *root,FILE *fp)
{
	if(root!=NULL)
	{
		disp(root->left,fp);			//recursive call to the left node
		if(root->left!=NULL)
		{
			fprintf(fp,"\n\"%d|%d|%d|%d\" -- \"%d|%d|%d|%d\"",root->value,root->bf,root->hh,root->heigh,root->left->value,root->left->bf,root->left->hh,root->left->heigh);
			fprintf(fp,"[style=bold,label=\" LEFT\"];");
		}
		if(root->right!=NULL)
		{
			fprintf(fp,"\n\"%d|%d|%d|%d\" -- \"%d|%d|%d|%d\"",root->value,root->bf,root->hh,root->heigh,root->right->value,root->right->bf,root->right->hh,root->right->heigh);
			fprintf(fp,"[style=bold,label=\" RIGHT\"];");
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
void display(tree *root,char* outfilename)
{
	FILE *fp;char buffer[100]="";
	adjustBST(root);
	fp=fopen(outfilename,"w");			//opens a file named output in write mode to write the information about tree
	fprintf(fp,"graph g {\nlabel = \"CONVENSION: NODEVALUE | BALANCE FACTOR | HEIGHT of SUBTREE | HEIGHT OF NODE\";\nnode [shape=record,width=0.75,style=filled,fillcolor=lightgray];");
	disp(root,fp);					//calls the disp function and passes the file pointer
	fprintf(fp,"\n}");
	fclose(fp);					//closes the file
	strcat(buffer,"dot -Tpng ");
	strcat(buffer,outfilename);
	strcat(buffer," -o ");
	strcat(buffer,outfilename);
	strcat(buffer,".png");puts(buffer);
	system(buffer);					//creates the png file -- system call
	
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
	tree *root=NULL;
	int choice,data,tno=0;

	while(1)
	{
		printf("\n		1:Insert\n		2:Search\n		3:Display Text Mode\n		4:Create Png[named:: MENU_OUT.PNG]\n    Any Other Key:exit\n 	choice:: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	
				printf("Enter data to insert:: ");scanf("%d",&data);
				root=insertNodeBST(root,data);				//calls inserNodeBST
				break;
			case 2:	
				printf("Enter data to search:: ");scanf("%d",&data);
				if(searchNodeBST(root,data))				//calls searchNodeBST
					printf("..FOUND\n");
				else
					printf("..NOT FOUND\n");
				break;
			case 3:	
				d(root);						//calls d
				break;
			case 4: 
				display(root,"Menu_out");				//calls display
				break;
			default:exit(1);						//exits returning 1
		}
	}
}
