#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
	int type; //0 means start/intermediate, 1 means final
	struct _node* dest_0;
	struct _node* dest_1;
}node;

typedef node** FSM;

node* get_node (int type)
{
	node* ptr = (node*) malloc (sizeof(node));
	ptr->type = type;
	ptr->dest_0 = ptr->dest_1 = NULL;
	return ptr;
}

void create_fsm (FSM f)
{
	//creates an FSM which accepts strings over {0,1} that contains 001
	node* A = get_node(0);
	node* B = get_node(0);
	node* C = get_node(0);
	node* D = get_node(1);

	A->dest_0 = B; A->dest_1 = A;
	B->dest_0 = C; B->dest_1 = A;
	C->dest_0 = C; C->dest_1 = D;
	D->dest_0 = D; D->dest_1 = D;

	*f = A;
}

int check_acceptance (FSM f, char* input) //returns 1 on acceptance
{
	int i=0, len = strlen (input);
	node* ptr = *f;
	while (i < len)
	{
		if (input[i] == '0')
			ptr = ptr->dest_0;
		else if (input[i] == '1')
			ptr = ptr->dest_1;
		else
			return 0;
		i++;
	}
	return ptr->type;
}

void destroy (node* ptr)
{
	//?
}

void destroy_fsm (FSM f)
{
	//destroy (*f);
}

int main ()
{
	FSM fsm_container;
	char input[100];

	fsm_container = (FSM)malloc (sizeof (node*));

	create_fsm (fsm_container);
	printf ("Enter string over {0,1}: ");
	scanf ("%s", input);
	if (check_acceptance (fsm_container, input))
		printf("string is accepted\n");
	else
		printf("string is not accepted\n");
	//destroy_fsm (fsm_container); //todo

	free (fsm_container);
}
