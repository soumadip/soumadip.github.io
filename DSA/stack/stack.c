#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define CAP 10

typedef struct linked_list
{
	int val;
	struct linked_list *next;
}node;

typedef node** list;

typedef struct stack
{
	list HEAD;
	node* top;
	int size;
}stack;


node* get_node (int val)
{
	node *ptr = (node*) malloc (sizeof(node));
	if (ptr == NULL)
	{
		perror ("node create fail");
		return NULL;
	}
	ptr->val = val;
	ptr->next = NULL;
	return ptr;
}

void print (list head)
{
	node* ptr = *head;
       	if (!ptr)
		printf ("blank list\n");
	else 
	{
		printf ("HEAD ");
		while (ptr)
		{
			printf (" --> %d", ptr->val);
			ptr = ptr->next;
		}
		printf("\n");
	}
		
}

bool add_head (list head, int val)
{
	node* ptr = get_node (val);
	if (ptr == NULL)
		return false;
	ptr->next = *head;
	*head = ptr;
	return true;
}

bool del_head (list head, int* ret)
{
	node *ptr = *head;
	*ret = ptr->val;
	*head = ptr->next;
        return true;	
}

void clear (list head)
{
	node* ptr = *head, *tmp;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free (tmp);
	}
	*head = NULL;
	printf("list cleared\n");
}

stack* initialize_stack (void)
{
	stack *ptr = (stack*) malloc (sizeof(stack));
	if (ptr == NULL)
	{
		perror ("stack create fail\n");
		return NULL;
	}

	ptr->HEAD = (list) malloc (sizeof (node*));
	if (ptr->HEAD == NULL)
	{
		perror ("storage create fail\n");
		return NULL;
	}
	ptr->size = 0;
	return ptr;
}

bool push (stack* sptr, int val)
{
	if (sptr == NULL)
	{
		printf("invalid stack\n");
		return false;
	}
	if (sptr->size == CAP)
	{
		printf("overflow\n");
		return false;
	}
	if (add_head (sptr->HEAD, val))
	{
		sptr->size ++;
		return true;
	}
	else
		return false;
}

bool pop (stack* sptr, int* ret_val)
{
	if (sptr == NULL)
	{
		printf ("invalid stack\n");
		return false;
	}
	if (sptr->size == 0)
	{
		printf ("underflow\n");
		return false;
	}
	sptr->size --;
	return del_head (sptr->HEAD, ret_val);
}

bool peek (stack* sptr, int* ret)
{
	node* ptr;
	if (sptr->size == 0)
		return false;
	else
	{
		ptr = *(sptr->HEAD);
		*ret = ptr->val;			
	}
	return true;
}

void display (stack* sptr)
{
	print (sptr->HEAD);
}

void destroy (stack* sptr)
{
	if (sptr)
	{
		if (sptr->HEAD)
		{
			clear (sptr->HEAD);
			free (sptr->HEAD);
			printf ("HEAD released\n");
		}
		free (sptr);
	}
	printf ("Stack destroyed.\n");
}

int main (void)
{
	stack *sptr = initialize_stack ();
	int pop_ret, peek_ret, ch, val;
	
	while (1)
	{
		printf ("enter you choice\n\t1: display stack contents\n\t2: push on the stack\n\t3: pop from the stack\n\t4: peek the stack\n\t5: exit\n\nchoice:: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				//display
				display (sptr);
				break;
			case 2:
				//add
				printf ("enter value :: ");
				scanf ("%d", &val);
				if (push(sptr, val))
					printf ("value %d pushed\n", val);
				break;
			case 3:
				//delete
				if (pop (sptr, &pop_ret))
					printf ("value %d popped\n", pop_ret);
				break;
			case 4:
				//peek
				if (peek(sptr, &peek_ret))
					printf ("value %d peeked\n", peek_ret);
				break;
			default:
				//free the head
				destroy(sptr);
				printf ("Bye Bye!\n");
				exit(0);
		}
	}
}
