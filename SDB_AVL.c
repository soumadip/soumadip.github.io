#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _tree_node
{
	int data;
	int level;
	int left_subtree_height;
	int right_subtree_height;
	struct _tree_node *parent;
	struct _tree_node *left;
	struct _tree_node *right;
}node;

#define DIFF(X,Y) ((X)>(Y))?((X)-(Y)):((Y)-(X))
#define BALANCING_REQUIRED(X) (DIFF(((X)->left_subtree_height),((X)->right_subtree_height)) > 1)

typedef struct __balanced_avl_tree_container
{
	node* root_node;	//root of the tree
	int node_count;  	//number of nodes
}avl; 

avl* initilize_avl_tree ()
{
	avl* ptr = malloc(sizeof(avl));
	if(ptr)
	{
		ptr->root_node = NULL;
		ptr->node_count = 0;
	}
	return ptr;
}

node* new_tree_node(int val)
{
	node* ptr = malloc(sizeof (node));
	if(ptr)
	{
		ptr->data = val;
		ptr->left_subtree_height = ptr->right_subtree_height = ptr->level = 0;
		ptr->parent = ptr->left = ptr->right = NULL;
	}
	return ptr;
}

void rotate_LL (node* ptr)
{
	printf("rotating LL on node %d\n", ptr->data);
	node *parent = ptr->parent;
	node *left = ptr->left;

	if (parent->left == ptr)
		parent->left = left;
	else
		parent->right = left;
	ptr->left = left->right;
	left->parent = parent;
	ptr->parent = left;
}

void rotate_RR (node* ptr)
{
	printf("rotating RR on node %d\n", ptr->data);
	node *parent = ptr->parent;
	node *right = ptr->right;

	if (parent->left == ptr)
		parent->left = right;
	else
		parent->right = right;
	ptr->right = right->left;
	right->parent = parent;
	ptr->parent = right;
}

void rotate_LR (node* ptr)
{
	rotate_RR(ptr->left);
	rotate_LL(ptr);
}

void rotate_RL (node* ptr)
{
	rotate_LL(ptr->right);
	rotate_RR(ptr);
}


void rebalance (node* ptr)
{
	if (ptr->left_subtree_height > ptr->right_subtree_height)
	{
		if (ptr->left->left_subtree_height > ptr->left->right_subtree_height)
			rotate_LL(ptr);
		else //if (ptr->left->left_subtree_height < ptr->left->right_subtree_height)
			rotate_LR(ptr);
	}
	else // if (ptr->left_subtree_height < ptr->right_subtree_height)
	{
		if (ptr->right->left_subtree_height > ptr->right->right_subtree_height)
			rotate_RL(ptr);
		else // if (ptr->right->left_subtree_height < ptr->right->right_subtree_height)
			rotate_RR(ptr);
	}
}

bool insert_avl(node* ptr, node* new_node, int level)
{
	printf("checking node with data %d\n", ptr->data);
	if (ptr->data < new_node->data)
		if(ptr->right)
			if (insert_avl(ptr->right, new_node, level+1))
			{	
				ptr->right_subtree_height += 1;
				if (BALANCING_REQUIRED(ptr)) rebalance (ptr);
				return ptr->left_subtree_height < ptr->right_subtree_height ? true : false;
			}
		else
		{
			printf("insering data %d\n", new_node->data);
			ptr->right = new_node;
			new_node->level = level;
			new_node->parent = ptr;
			return true;
		}
	else if (ptr->data > new_node->data)
		if(ptr->left)
			if (insert_avl(ptr->left, new_node, level+1))
			{	
				ptr->left_subtree_height += 1;
				if (BALANCING_REQUIRED(ptr)) rebalance (ptr);
				return ptr->left_subtree_height > ptr->right_subtree_height ? true : false;
			}
		else
		{
			printf("insering data %d\n", new_node->data);
			ptr->left = new_node; 
			new_node->level = level;
			new_node->parent = ptr;
			return true;
		}
	else
		return NULL;
}


bool insert(avl* tree, int new_data)
{
	printf("starting insertion process for data %d\n", new_data);
	node* ptr = new_tree_node(new_data);
	if (ptr)
	{
		if (tree->root_node == NULL) 
		{
			tree->root_node = new_tree_node(new_data);
			tree->node_count = 1;
			return true;
		} 
		else 
			if(insert_avl(tree->root_node, ptr, 0))
			{
				tree->node_count += 1;
				return true;
			}
			else
				return false;
	}
	return false;
}

bool delete_avl(int key)
{
}
bool delete(avl* tree, int key)
{}
void traverse(avl* tree)
{}
void destroy(avl* tree)
{}
int main ()
{
    avl* tptr;
    if (!(tptr = initilize_avl_tree()))
    {
        printf ("Failed to allocate memory for AVL\nExiting\n");
        return -1;	
    }
    else
        printf ("AVL initialized\n");

    int ch, val;
    while (true)
    {
        printf ("\n1:: Insert\n2:: Delete\n3:: Traverse \n4:: Exit\n\tChoice::  ");
        scanf ("%d", &ch);
        switch (ch)
        {
        case 1:
            //insert
            printf ("\tEnter value to insert: ");
            scanf ("%d", &val);
            if (insert(tptr, val))
                printf ("\t..success\n");
            else
                printf ("\t..fail\n");
            break;
        case 2:
            //delete
			printf ("\tEnter value to delete: ");
            scanf ("%d", &val);
			if (delete(tptr, val))
                printf ("\t..success\n");
            else   
                printf ("\t..fail\n");
            break;
        case 3:
            //display
            traverse (tptr);
            break;
        default:
            destroy (tptr);
            printf ("Bye!\n");
            exit (0);
        }
    }
}
