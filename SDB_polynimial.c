#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ABS(X) (X)>0?(X):-1*(X)

typedef struct _node
{
	double coeff;
	int expo;
	struct _node *next_term;
}term;

typedef struct Polynomial_Structure_Definition
{
	term* first_term;
	int size;
}Poly;

term* create_term(double coeff, int expo)
{
	term* ptr = malloc(sizeof (term));
	ptr->coeff = coeff;
	ptr->expo = expo;
	ptr->next_term = NULL;
	return ptr;
}

term* new_term()
{
	double coeff; int expo;
	printf("\tEnter coefficient:: "); scanf("%lf", &coeff); 
	printf("\tEnter exponent:: "); scanf("%d", &expo);
	return create_term(coeff, expo);
}
 
Poly* new_polynomial()
{
 	Poly* ptr = malloc(sizeof (Poly));
 	ptr->first_term = NULL;
 	ptr->size = 0;
 	return ptr;
}

bool display_polynomial(Poly* expr)
{
	if (expr)
	{
		if (expr->size == 0) 
			printf("Empty polynomial\n");
		else
		{
			term* ptr = expr->first_term;
			printf("%.2lfx^%d", ptr->coeff, ptr->expo);
			while (ptr)
			{
				if ((int)ptr->coeff)
				{
					if ((int)ptr->expo > 0)? printf(" + ") : printf(" - ");
					{
						printf(" + ");
						if ((int)ptr->coeff == 1 || (int)ptr->coeff == -1)
							printf("x^%d", ptr->expo);
						else
							printf("%.2lfx^%d", ABS(ptr->coeff), ptr->expo);
					}
					// else
					// {
						// printf(" - ");
						// if ((int)ptr->coeff == -1)
							// printf("x^%d", ptr->expo);
						// else
							// printf("%.2lfx^%d", ABS(ptr->coeff), ptr->expo);
					// }
					ptr = ptr->next_term;
				}
			}
			printf("\n");
		}
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
		if (expr->first_term && include_term(&expr->first_term, ptr))
				expr->size++;
		else if (expr->first_term == NULL)
		{
			expr->first_term = ptr;
			expr->size = 1;
		}
		return true;
	}
	else return false;
}

Poly* add_two_polynomials(Poly *expr1, Poly *expr2)
{
	if (!expr1 || !expr2 || !expr1->first_term || !expr2->first_term)
		return NULL;
		
	Poly* result_expr = new_polynomial();
	
	term* poly_term = expr1->first_term;
	while (poly_term)
	{
		insert_term(result_expr, create_term(poly_term->coeff, poly_term->expo));
		poly_term = poly_term->next_term;
	}
	poly_term = expr2->first_term;
	while (poly_term)
	{
		insert_term(result_expr, create_term(poly_term->coeff, poly_term->expo));
		poly_term = poly_term->next_term;
	}
	return result_expr;
}

Poly* multiply_two_polynomials(Poly *expr1, Poly *expr2)
{
	if (!expr1 || !expr2 || !expr1->first_term || !expr2->first_term)
		return NULL;
	
	Poly* result_expr = new_polynomial();
	
	term* p1_term = expr1->first_term;
	while (p1_term)
	{
		term* p2_term = expr2->first_term;
		while (p2_term)
		{
			insert_term(result_expr, create_term(p1_term->coeff * p2_term->coeff, p1_term->expo + p2_term->expo));
			p2_term = p2_term->next_term;
		}
		p1_term = p1_term->next_term;
	}
	return result_expr;
}

typedef struct polylist{Poly* ptr; int index; struct polylist* next_expr;}pl;
pl *list_head = NULL;

int add_to_list(Poly*);
void display_list();
Poly* get_from_list(int);

int main()
{
	Poly *expr;
	int choice, ind, no, p1, p2, ret;

	while(true)
	{
		printf("\nEnter\n1 to add polynomial\n2 to add terms\n3 to display all\n4 to multiply two polynomials\n5 to add two polynomials\n0 to exit\n\tchoice:: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				ret = add_to_list(new_polynomial());
				ret? printf("\tpolynomial no %d added\n", ret) : printf("\tfail to add polynomial\n");
				break;
			case 2:
				printf("\tchoose polynomial number: ");	scanf("%d", &ind);
				expr = get_from_list(ind);
				if (!expr) printf ("\tpolynomial does not exist\n");
				else
				{
					printf("\tselected polynomial is: "); display_polynomial(expr);
					printf("\tnumber of terms to add: "); scanf("%d", &no);
					while (no--)
						if (insert_term(expr, new_term())) printf ("\t\t.. term incorporated\n");
				}
				break;
			case 3:
				display_list(list_head);
				break;
			case 4:
				display_list(list_head);
				printf("\tselect first polynomial number: "); scanf("%d", &p1);
				printf("\tselect second polynomial number: "); scanf("%d", &p2);
				ret = add_to_list(multiply_two_polynomials(get_from_list(p1), get_from_list(p2)));
				ret? printf("\tresulting polynomial (no %d) added\n", ret) : printf("\tfail to add resulting polynomial\n");
				break;
				case 5:
				display_list(list_head);
				printf("\tselect first polynomial number: "); scanf("%d", &p1);
				printf("\tselect second polynomial number: "); scanf("%d", &p2);
				ret = add_to_list(add_two_polynomials(get_from_list(p1), get_from_list(p2)));
				ret? printf("\tresulting polynomial (no %d) added\n", ret) : printf("\tfail to add resulting polynomial\n");
				break;
			case 0:
				exit(0);
		}
	}
	
}

int add_to_list(Poly* expr)
{
	if (!expr) return 0;
	if (list_head == NULL)
	{
		list_head = malloc(sizeof(pl));
		if (list_head == NULL) return 0;
		list_head->ptr = expr;
		list_head->index = 1;
		list_head->next_expr = NULL;
		return 1;
	}
	pl *it = list_head;
	while(it->next_expr) it = it->next_expr;

	it->next_expr = malloc(sizeof (pl));
	if(it->next_expr == NULL) return 0;
	it->next_expr->ptr = expr;
	it->next_expr->index = it->index + 1;
	return it->index + 1;
}
void display_list()
{
	pl *curr = list_head;
	while(curr) 
	{
		printf("\t[%d]\t", curr->index);
		display_polynomial (curr->ptr);
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

