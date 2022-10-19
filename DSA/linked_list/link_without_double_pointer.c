#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
	int val;
	struct node* next;
}node;

typedef struct linked_list
{
	node* HEAD;
	int size;
}LL;

node* new_node(int val)
{
	node* ptr = (node*) malloc (sizeof(node));
	if (ptr == NULL)
	{
		perror("node create failure");
		return NULL;
	}
	ptr->val = val;
	ptr->next = NULL;
	return ptr;
}

LL* initialize_list ()
{
	LL* ptr = (LL*) malloc(sizeof(LL));
	if (ptr == NULL)
	{
		perror("node create failure");
		return NULL;
	}
	ptr->HEAD = NULL;
	ptr->size = 0;
}

void print (LL* list)
{
	node* ptr = list->HEAD;
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

void add (LL* list, int val)
{
	node *ptr = list->HEAD;
	if (!ptr)
		list->HEAD = new_node(val);
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_node(val);
	}
}

void del (LL* list, int val)
{
	node *ptr = list->HEAD, *tmp;
	if (ptr == NULL)
		printf ("blank list\n");
	else if (ptr->val == val)
	{
		list->HEAD = ptr->next;
		free(ptr);
	}
	else
	{
		bool flag = false;
		while (ptr && ptr->next)
		{
			if (ptr->next->val == val)
			{
				tmp = ptr->next;
				ptr->next = ptr->next->next;
				free(tmp);
				flag = true;
				break;
			}
			ptr = ptr->next;
		}
		if(!flag)
			printf("item not found\n");
	}
}

void clear (LL* list)
{
	if (list)
	{
		node* ptr = list->HEAD, *tmp;
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			free (tmp);
		}
	}
	list->HEAD = NULL;
	printf("list cleared\n");
}


int main ()
{
	LL* list;
	
	//initalize HEAD of the linked list	
	list = initialize_list ();

	int ch, val;
	while (1)
	{
		printf ("enter you choice\n\t1: display list\n\t2: add an element\n\t3: remove an element\n\t4: clear list\n\t5: exit\n\nchoice:: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				//display
				print (list);
				break;
			case 2:
				//add
				printf ("enter value to insert:: ");
				scanf ("%d", &val);
				add (list, val);
				break;
			case 3:
				//delete
				printf ("enter value to be deleted:: ");
				scanf ("%d", &val);
				del (list, val);
				break;
			case 4:
				//destroy
				clear (list);
				break;
			default:
				clear (list);
				//free the list
				free(list);
				printf ("Bye Bye!\n");
				exit(0);
		}
	}
}
