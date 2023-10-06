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
		printf("\n");
		while (ptr)
		{
			printf("%lf x^%d", ptr->coeff, ptr->expo);
			ptr = ptr->next_term;
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
			curr->expo += to_add->expo;
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
		else
		{
			expr->HEAD = ptr;
			expr->size = 1;
		}
	}
	else return false;
}


int main()
{
	typedef struct polylist{Poly* ptr; int index; struct polylist* next_expr;}pl;
	void add_to_list(Poly*);
	void display_list();
	Poly* get_from_list(int);
	
	pl *list_head, *expr;
	list_head = malloc(sizeof (pl));
	list_head->ptr = NULL;
	list_head->next_expr = NULL;
	
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
				printf("number of terms to add: "); scanf("%d", &no);
				while (no--)
					insert_term(expr, new_term());
				break;
			case 3:
				display_list(list_head);
				break;
			case 0:
				exit(0);
		}
	}
	
	
	void add_to_list( Poly* expr;)
	{
		pl *tmp = list_head;
		while(tmp->next_expr) tmp = tmp->next_expr;
		tmp->next_expr = malloc(sizeof pl);
		tmp->next_expr->ptr = expr;
		tmp->next_expr->index = tmp->index + 1;
	}
	void display_list()
	{
		pl *tmp = list_head;
		while(tmp->next_expr) 
		{
			printf("%d: ", tmp->index);
			display_polynomial (tmp->ptr);
			tmp = tmp->next_expr;
		}
	}
	Poly* get_from_list(int ind)
	{
		pl *tmp = list_head;
		while(tmp->next_expr) 
		{
			if(tmp->index == ind)
				return tmp->ptr; 
			tmp = tmp->next_expr;
		}
	}
}
