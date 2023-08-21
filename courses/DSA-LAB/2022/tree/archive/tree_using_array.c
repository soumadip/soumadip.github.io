#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct tree_node
{
	int val;
	typedef struct tree_node* left;
	typedef struct tree_node* right;
}node;

typedef struct tree
{
	node* root;
	int size;
}tree;

tree* initialize_tree ()
{
	//initialize the tree
	tree* ptr = (tree*) malloc (sizeof (tree));
	ptr->root = NULL;
	ptr->size = 0;
	return ptr;
}

bool add_node (tree* root, int val)
{}

bool remove (node* ptr, int val)
{
	if (ptr)
	{
		if (ptr -> val == val)
			
	}
}

bool remove_node (tree* root, int val)
{
	if (root)
		return remove (root -> root);
	else
		return false;
}

 
void display_in_order (node* ptr)
{
	//write code for in order traversal
	return;
}

void display_pre_order (node* ptr)
{
	//write code for pre order traversal
	return;
}

void display_post_order (node* ptr)
{
	//write code for post order traversal
	return;
}

bool display_custom (node* ptr)
{
	//write your own code for display function
	printf ("%d\n", ptr -> val);
	display_custom (ptr -> left);
	display_custom (ptr -> right);
	return;
}

void display (tree* root, int choice = 100)
{
	switch (choice)
	{
		case 1:
			display_pre_order (root -> root);
			return;
		case 1:
			display_in_order (root -> root);
			return;
		case 1:
			display_post_order (root -> root);
			return;
		default:
			display_custom (root -> root);
	}
}

void destroy (node* ptr)
{
	if (ptr)
	{
		destroy (ptr -> left);
		destroy (ptr -> right);
		free (ptr);
	}
}

bool clear (tree* root)
{
	if (root)
	{
		destroy (root -> root);
		free (root);
		return true;
	}
	else
		return false;
}

int main ()
{
	tree* root = NULL;
	int ch, val;
	
	while (true)
	{
		//take user preference
		printf ("\n1:: Add2:: Del\n3:: Display \n4:: Exit\n\tEnter Choice--> ");
        scanf ("%d", &ch);
		
		switch (ch)
		{
			case 1:
				root = initialize_tree ();
			case 2:
				printf ("Enter value to insert:: ");
				scanf ("%d", &val);
				if (add_node (root, val))
					printf ("\t...Success.\n");
				else
					printf ("\t...Failure.\n");
				break;
			case 3:
				printf ("Enter value to remove:: ");
				scanf ("%d", &val);
				if (remove_node (root, val))
					printf ("\t...Success.\n");
				else
					printf ("\t...Failure.\n");
				break;
			case 4:
				printf ("Enter 1 for Pre-order, 2 for In-order, 3 for Post-order to insert:: ");
				scanf ("%d", &val);
				display (root, val);
				break;
			case 6:
				display (root);
				break;
			case 7:
				clear (root);
				ptr = NULL;
				break;
			default:
				clear (root);
				ptr = NULL;
				exit (0);
		}
	}
	
}