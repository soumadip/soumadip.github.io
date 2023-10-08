#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _node
{
	double coeff;
	int expo;
	struct _node *next_term;
}term;

typedef struct Polynomial_Structure_Definition
{
	term* HEAD;
	int size;
}Poly;

term* new_term()
{
	double coeff; int expo;
	printf("Enter coefficient:: "); scanf("%lf", &coeff); 
	printf("Enter exponent:: "); scanf("%d", &expo);
	
	term* ptr = malloc(sizeof (term));
	ptr->coeff = coeff;
	ptr->expo = expo;
	ptr->next_term = NULL;
	return ptr;
}
 
Poly* new_polynomial()
{
 	Poly* ptr = malloc(sizeof (Poly));
 	ptr->HEAD = NULL;
 	ptr->size = 0;
 	return ptr;
}

bool display_polynomial(Poly* expr)
{
	if (expr && expr->size)
	{
		term* ptr = expr->HEAD;
		while (ptr)
		{
			printf("(%.2lf)*x^%d", ptr->coeff, ptr->expo);
			ptr = ptr->next_term;
			if(ptr) printf(" + ");
		}
		printf("\n");
		return true;
	}
	return false;
}

bool include_term(term** expr_head_addr, term* to_add)
{
	term* curr = *expr_head_addr, *prev = NULL;
	while (curr)
	{
		if(curr->expo == to_add->expo)
		{
			curr->coeff += to_add->coeff;
			free(to_add);
			return false;
		}
		if (curr->expo < to_add->expo)
			break;
		prev = curr;
		curr = curr->next_term;
	}
	to_add->next_term = curr;
	if (prev) 
		prev->next_term = to_add;
	else
		*expr_head_addr = to_add;
	return true;
}

bool insert_term (Poly* expr, term* ptr)
{
	if (expr)
	{
		if (expr->HEAD && include_term(&expr->HEAD, ptr))
				expr->size++;
		else if (expr->HEAD == NULL)
		{
			expr->HEAD = ptr;
			expr->size = 1;
		}
		return true;
	}
	else return false;
}


typedef struct polylist{Poly* ptr; int index; struct polylist* next_expr;}pl;
pl *list_head = NULL;

void add_to_list(Poly*);
void display_list();
Poly* get_from_list(int);

int main()
{
	Poly *expr;
	int choice, ind, no;

	while(true)
	{
		printf("1 to add polynomial\n2 to add terms\n3 to display all\n0 to exit\n choice:: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				add_to_list(new_polynomial());
				break;
			case 2:
				printf("choose polynomial number: ");	scanf("%d", &ind);
				expr = get_from_list(ind);
				if (!expr) printf ("polynomial does not exist\n");
				else
				{
					printf("number of terms to add: "); scanf("%d", &no);
					while (no--)
						if (insert_term(expr, new_term())) printf (".. term incorporated\n");
				}
				break;
			case 3:
				display_list(list_head);
				break;
			case 0:
				exit(0);
		}
	}
	
}

void add_to_list(Poly* expr)
{
	if (list_head == NULL)
	{
		list_head = malloc(sizeof(pl));
		list_head->ptr = expr;
		list_head->index = 1;
		list_head->next_expr = NULL;
		return;
	}
	pl *it = list_head;
	while(it->next_expr) it = it->next_expr;

	it->next_expr = malloc(sizeof (pl));
	it->next_expr->ptr = expr;
	it->next_expr->index = it->index + 1;
}
void display_list()
{
	pl *curr = list_head;
	while(curr) 
	{
		printf("\t[%d]\t", curr->index);
		if (!display_polynomial (curr->ptr))
			printf("Empty polynomial\n");
		curr = curr->next_expr;
	}
}
Poly* get_from_list(int ind)
{
	pl *curr = list_head;
	while(curr) 
	{
		if(curr->index == ind)
			return curr->ptr; 
		curr = curr->next_expr;
	}
	return NULL;
}
