#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//GLOBAL VARIABLES USED FOR CHEKING MEMORY LEAKS  AND DEBUGGING
int allocated=0; 
int freed=0;

typedef struct node
{
	char* str;
	struct node* next;
}node;

typedef struct linked_list
{
	node* HEAD;
	int size;
}LL;

typedef struct nested_node
{
	char* str;
	LL* LL_PTR;
	struct nested_node* next;;
}nested_node;

typedef struct nested_linked_list
{
	nested_node* NLL_HEAD;
	int size;
}NLL;

node* new_node(char *str)
{
	node* ptr = (node*) malloc (sizeof(node));
	if (ptr == NULL)
	{
		perror("node create failure");
		return NULL;
	}
	ptr->str = str;
	ptr->next = NULL;
	allocated += sizeof(ptr);
	return ptr;
}

LL* initialize_list ()
{
	LL* ptr = (LL*) malloc(sizeof(LL));
	if (ptr == NULL)
	{
		perror("list initalize failure");
		return NULL;
	}
	ptr->HEAD = NULL;
	ptr->size = 0;
	allocated += sizeof(ptr);
	return ptr;
}

nested_node* new_nested_node(char* str)
{
	nested_node* ptr = (nested_node*) malloc (sizeof(nested_node));
	if (ptr == NULL)
	{
		perror("nested node create failure");
		return NULL;
	}
	ptr->str = str;
	ptr->LL_PTR = initialize_list();
	if(ptr->LL_PTR)
	{
		ptr->next = NULL;
		return ptr;
	}
	else
	{
		free(ptr);
		return NULL;
	}
}

NLL* initialize_nested_list ()
{
	NLL* ptr = (NLL*) malloc(sizeof(NLL));
	if (ptr == NULL)
	{
		perror("nested list initalize failure");
		return NULL;
	}
	ptr->NLL_HEAD = NULL;
	ptr->size = 0;
	return ptr;
}

void print_LL (LL* list)
{
	node* ptr = list->HEAD;
    if (!ptr)
		printf ("  [[ ]]\n");
	else 
	{
		printf ("  [[");
		while (ptr)
		{
			printf (" %s ", ptr->str);
			ptr = ptr->next;
			if(ptr) printf ("→");
		}
		printf("]]\n");
	}
		
}

void print_NLL (NLL* nlist)
{
	nested_node* ptr = nlist->NLL_HEAD;
    if (!ptr)
		printf ("blank nested list\n");
	else 
	{
		while(ptr)
		{
			printf("%s", ptr->str);
			print_LL(ptr->LL_PTR);
			ptr = ptr->next;
			if (ptr) printf("\n  ↓↓\n");
		}		
	}
}

bool add_to_LL (LL* list, char* str)
{
	node *ptr = list->HEAD;
	if (!ptr)
	{
		list->HEAD = new_node(str);
		return list->HEAD? true : false;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_node(str);
		return ptr->next? true : false;
	}
}

bool add_to_NLL (NLL* nlist, char* str)
{
	nested_node *ptr = nlist->NLL_HEAD;
	if (!ptr)
	{
		nlist->NLL_HEAD = new_nested_node(str);
		return nlist->NLL_HEAD? true : false;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_nested_node(str);
		return ptr->next? true : false;
	}
}

LL* locate_in_NLL(char* str, NLL *nlist)
{
	printf("searching for %s\n", str);
	nested_node* ptr = nlist->NLL_HEAD;
	while (ptr)
	{
		printf("comparing with %s\n", ptr->str);
		if(!strcmp(str, ptr->str))
			return ptr->LL_PTR;
		else 
			ptr = ptr->next;
	}
	printf("%s not found\n", str);
	return NULL;
}

bool add_level1(NLL* nlist, char* str1)
{
	return add_to_NLL(nlist, str1)? true : false;
}

bool add_level2(NLL* nlist, char* str1, char* str2)
{
	LL* ptr = locate_in_NLL (str1, nlist);
	if (ptr)
		return add_to_LL(ptr, str2)? true : false;
	else
		return false;
}
/*void del (LL* list, int val)
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
}*/

void clear_LL (LL* list)
{
	if (list)
	{
		node* ptr = list->HEAD, *tmp;
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			if (tmp->str) 
			{
				freed += sizeof(tmp->str);
				free(tmp->str);
			}
			freed += sizeof(tmp);
			free (tmp);
		}
	}
	list->HEAD = NULL;
	printf("LL cleared\n");
}

void clear_NLL (NLL* nlist)
{
	if (nlist)
	{
		nested_node* ptr = nlist->NLL_HEAD, *tmp;
		while (ptr)
		{
			printf("%s: ", ptr->str);
			clear_LL(ptr->LL_PTR);
			tmp = ptr;
			ptr = ptr->next;
			freed += sizeof(tmp->str);
			free(tmp->str);
			freed += sizeof(tmp);
			free (tmp);
		}
		nlist->NLL_HEAD = NULL;
	}
	printf("NLL cleared\ntotal allocated: %d bytes, total freed: %d bytes\n", allocated, freed);
}

char* get_string()
{
	int size=1; char ch;
	char* str  = (char*)malloc(sizeof(char));
					
	//fflush(stdin);
	fgetc(stdin); //?? rethink
	//while ((ch = getchar()) != '\n' && ch != EOF);
	while ('\n' != (str[size++ - 1] = fgetc(stdin)))
		str = realloc(str, size*sizeof(char));
	/*
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '\n')
		{
			printf("nl encountered");
			break;
		}
		else
			str[size-1] = (char)ch;
		size++;
		str = realloc (str, size*sizeof(char));
		printf("%d ", ch);
	}
	*/
	str [size-1] = '\0';
	printf("\n%s :: %d chars scanned\n", str, size);
	//char *str = (char*)malloc(100);
	//scanf("%s", str);
	allocated += sizeof(str);
	return str;
}

int main ()
{
	NLL* nlist;
	
	//initalize HEAD of the linked list	
	nlist = initialize_nested_list ();

	int ch;
	
	while (1)
	{
		printf ("enter you choice\n\t1: display list\n\t2: add L1 element\n\t3: add L2 element\n\t4: <todo>\n\t5: clear\n\t6: exit\n\nchoice:: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				//display
				print_NLL (nlist);
				break;
			case 2:
				//add
				printf ("enter level 1 string to insert:: ");
				if(add_level1 (nlist, get_string()))
					printf("success\n");
				else
					printf("failure\n");
				break;
			case 3:
				//add
				printf ("enter level 1 string to search:: ");
				char* str = get_string();
				printf ("enter level 2 string to insert:: ");
				if(add_level2 (nlist, str, get_string()))
					printf("success\n");
				else
					printf("failure\n");
				break;
			case 4:
				//delete
				printf ("enter value to be deleted:: ");
				//scanf ("%d", &val);
				//del (nlist, val);
				break;
			case 5:
				//destroy
				clear_NLL (nlist);
				break;
			default:
				clear_NLL (nlist);
				//free the list
				free(nlist);
				printf ("Bye Bye!\n");
				exit(0);
		}
	}
}