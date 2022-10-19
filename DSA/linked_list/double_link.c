#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct double_linked_list
{
	int val;
	struct double_linked_list* next;
	struct double_linked_list* prev;
}list;


list* new_node(int val)
{
	list* ptr = (list*) malloc (sizeof(list));
	if (ptr == NULL)
	{
		perror("node create failure");
		return NULL;
	}
	ptr->val = val;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}

void print (list** head)
{
	list* ptr = *head;
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

void add (list** head, int val)
{
	list *ptr = *head;
	if (!ptr)
		*head = new_node(val);
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_node(val);
		ptr->next->prev = ptr;
	}
}

void del (list** head, int val)
{
	list *ptr = *head, *tmp;
	if (ptr == NULL)
		printf ("blank list\n");
	else if (ptr->val == val)
	{
		if (ptr->next)
			ptr->next->prev = NULL;
		*head = ptr->next;
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
				if (ptr->next)
					ptr->next->prev = ptr;
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

void clear (list** head)
{
	list* ptr = *head, *tmp;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free (tmp);
	}
	*head = NULL;
	printf("list cleared\n");
}

int main ()
{
	list** HEAD;
	
	//initalize HEAD of the linked list	
	HEAD = (list**) malloc(sizeof(list*));

	int ch, val;
	while (1)
	{
		printf ("enter you choice\n\t1: display list\n\t2: add an element\n\t3: remove an element\n\t4: clear list\n\t5: exit\n\nchoice:: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				//display
				print (HEAD);
				break;
			case 2:
				//add
				printf ("enter value to insert:: ");
				scanf ("%d", &val);
				add (HEAD, val);
				break;
			case 3:
				//delete
				printf ("enter value to be deleted:: ");
				scanf ("%d", &val);
				del (HEAD, val);
				break;
			case 4:
				//destroy
				clear (HEAD);
				break;
			default:
				clear (HEAD);
				//free the head
				free(HEAD);
				printf ("Bye Bye!\n");
				exit(0);
		}
	}
}
