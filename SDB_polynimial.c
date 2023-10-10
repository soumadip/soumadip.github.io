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

void remove_polynomial(Poly *expr)
{
	if(expr)
	{
		term *it = expr->first_term, *tmp;
		while (it)
		{
			tmp = it;
			it = it->next_term;
			free(tmp);
		}
		free(expr);
	}
}

bool display_polynomial(Poly* expr)
{
	if (expr)
	{
		bool first_print = true;
		if (expr->size == 0) 
			printf("Empty polynomial\n");
		else
		{
			term* it = expr->first_term;
			while (it)
			{					
				if (first_print) ((int)it->coeff > 0)? (first_print = !first_print) : printf(" - ") && (first_print = !first_print);
				else ((int)it->coeff > 0)? printf(" + ") : printf(" - ");
				
				if (it->expo == 0)
					printf ("%.2lf", ABS(it->coeff));
				else if ((int)it->coeff == 1 || (int)it->coeff == -1)
					printf("x^%d", it->expo);
				else
					printf("%.2lfx^%d", ABS(it->coeff), it->expo);
				it = it->next_term;
			}
			printf("\n");
		}
		return true;
	}
	return false;
}

bool insert_term (Poly* expr, term* new_term)
{
	if (expr)
	{
		if ((int)new_term->coeff == 0)
		{
			free (new_term); 
			return false;
		}
		else if (expr->first_term == NULL)
		{
			expr->first_term = new_term;
			expr->size = 1;
		}
		else if (expr->first_term)
		{
			term* curr = expr->first_term, *prev = NULL;
			while (curr)
			{
				if(curr->expo == new_term->expo)
				{
					curr->coeff += new_term->coeff;
					free(new_term);
					if ((int)curr->coeff == 0)
					{
						if (prev)
							prev->next_term = curr->next_term;
						else
							expr->first_term = curr->next_term;
						free(curr);
						expr->size--;
					}
					break;
				}
				if (curr->expo < new_term->expo)
				{
					new_term->next_term = curr;
					if (prev) 
						prev->next_term = new_term;
					else
						expr->first_term = new_term;
					expr->size++;
					break;
				}
				prev = curr;
				curr = curr->next_term;
			}
			if(!curr)
			{
				prev->next_term = new_term;
				expr->size++;
			}
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

typedef struct polylist{Poly* expr; int index; struct polylist* next_polynomial;}pl;
pl *list_head = NULL;

int add_to_list(Poly*);
bool remove_from_list(int);
void display_list();
Poly* get_from_list(int);
void release_list();

int main()
{
	Poly *expr;
	int choice, ind, no, p1, p2, ret;
	bool flag = true;

	while(true)
	{
		if (flag) printf("\nEnter\n1 to add polynomial\n2 to add terms\n3 to display all\n4 to remove a polynomial from list\n5 to multiply two polynomials\n6 to add two polynomials\n0 to exit\n\tchoice:: ");
		else flag = !flag;
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				ret = add_to_list(new_polynomial());
				ret? printf("\t\t..added at index %d\n", ret) : printf("\t\t..fail to add\n");
				break;
			case 2:
				printf("\t\tchoose polynomial number: ");	scanf("%d", &ind);
				expr = get_from_list(ind);
				if (!expr) printf ("\t\tpolynomial does not exist\n");
				else
				{
					printf("\t\tselected polynomial is: "); display_polynomial(expr);
					printf("\t\tnumber of terms to add: "); scanf("%d", &no);
					while (no > 0 && no--)
						if (insert_term(expr, new_term())) printf ("\t\t.. term incorporated\n");
						else printf ("\t\t.. term not incorporated\n");
				}
				break;
			case 3:
				display_list();
				break;
			case 4:
				//display_list();
				printf("\t\tchoose polynomial number to remove: ");	scanf("%d", &ind);
				printf("\t\t..%s\n", remove_from_list(ind)? "success" : "failure");
				break;
			case 5:
				display_list();
				printf("\t\tselect first polynomial number: "); scanf("%d", &p1);
				printf("\t\tselect second polynomial number: "); scanf("%d", &p2);
				ret = add_to_list(multiply_two_polynomials(get_from_list(p1), get_from_list(p2)));
				ret? printf("\t\t..added resulting polynomial (index %d)\n", ret) : printf("\t\t..failure\n");
				break;
				case 6:
				display_list();
				printf("\t\tselect first polynomial number: "); scanf("%d", &p1);
				printf("\t\tselect second polynomial number: "); scanf("%d", &p2);
				ret = add_to_list(add_two_polynomials(get_from_list(p1), get_from_list(p2)));
				ret? printf("\t\t..added resulting polynomial (index %d)\n", ret) : printf("\t\t..failure\n");
				break;
			case 0:
				release_list();
				exit(0);
			default:
				printf("<<invalid choice>> Please retry.\n\tchoice:: ");
				flag = !flag;
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
		list_head->expr = expr;
		list_head->index = 1;
		list_head->next_polynomial = NULL;
		return 1;
	}
	pl *it = list_head;
	while(it->next_polynomial) it = it->next_polynomial;

	it->next_polynomial = malloc(sizeof (pl));
	if(it->next_polynomial == NULL) return 0;
	it->next_polynomial->expr = expr;
	it->next_polynomial->index = it->index + 1;
	it->next_polynomial->next_polynomial = NULL;
	return it->index + 1;
}
void display_list()
{
	if(!list_head) printf("\t\tlist empty");
	pl *curr = list_head;
	while(curr) 
	{
		printf("\t[%d]\t", curr->index);
		display_polynomial (curr->expr);
		curr = curr->next_polynomial;
	}
}
Poly* get_from_list(int ind)
{
	pl *curr = list_head;
	while(curr) 
	{
		if(curr->index == ind)
			return curr->expr; 
		curr = curr->next_polynomial;
	}
	return NULL;
}

void release_list()
{
	pl *curr = list_head, *tmp;
	while(curr)
	{
		remove_polynomial(curr->expr);
		tmp = curr;
		curr = curr->next_polynomial;
		free(tmp);
	}
	printf("list released\n");
}

bool remove_from_list(int ind)
{
	if (!list_head) return false;
	pl *curr = list_head, *prev = NULL;
	while (curr)
	{
		if (curr->index == ind)
		{
			if (prev)
				prev->next_polynomial = curr->next_polynomial;
			else
				list_head = curr->next_polynomial;
			remove_polynomial(curr->expr);
			free(curr);
			return true;
		}
		prev = curr;
		curr = curr->next_polynomial;
	}
	return false;
}

