#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct poly_node
{
	// write the appropriate variables for coefficient, exponent and link
}node;

node* new_node (int coeff, int expo)
{
	node *ptr;
	//write the required code here and do the necessar error checks
	
	return ptr;
}

bool add_node (node** ptr, int coeff, int expo)
{
	//extract the address of the first node
	node *poly = *ptr;
	
	//create a new node
	
	//find the position by trversing the polynomial where to insert the node
	
	//insert the node
	
	//return true or false based on the status
}

node* find_node (node** ptr, int expo)
{
	//extract the address of the first node using node* poly = *ptr
	
	//traverse the list and find the address of the node
	
	// return the address of the node OR NULL in case there is no such node
}

bool modify_node (node* ptr, int new_coeff)
{
	//check the validity of the ptr i.e. whether it is NULL or not
	
	//access the node values and modify
	
	//return status as true or false
}

bool del_node (node** ptr, int expo)
{
	//extract the address of the first node using node* poly = *ptr
	
	//traverse the list and find the address of the node to be deleted
	
	//delete the node and return true, and if there is no such node then return false
}

void destroy (node** ptr)
{
	node *tmp, *poly = *ptr;
	while (poly)
	{
		tmp = poly;
		poly = poly->next;
		free (tmp);
	}
}

void display_poly (node* poly)
{
	//write the code to display the polynomial in proper form
}

int main ()
{
	node** P1; // container of the first address of the polynomial

	P1 = (node**) malloc (sizeof (node*)); //allocate memory for the container
	*P1 = NULL;	//initialize 

	//declare required variables
	
	//write the code to scan the polynomial and store the values
	
	display_poly(P1);	

	destroy (P1);
	free (P1);
}
