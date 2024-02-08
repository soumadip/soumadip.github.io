#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct __graph_adj_list
{
	int** adj;
	int size;
}Graph;

Graph* new_graph(int no_of_vertices)
{
	Graph *ptr = malloc(sizeof(Graph));
	if(ptr)
	{
		ptr->size = no_of_vertices;
		ptr->adj = calloc(ptr->size, sizeof(int*));
		for (int i=0; i<ptr->size; i++)
			*(ptr->adj+i) = calloc(ptr->size, sizeof(int));
		//you should check for the sucess of the calloc calls above as well
	}
	else
		perror("new_grpah: memory allocation failed\n");
	return ptr;
}

void print_graph(Graph *ptr)
{
	if(ptr)
	{
		for (int i=0; i<ptr->size; i++)
		{
			for (int j=0; j<ptr->size; j++)
				printf("%3d ", *(j+*(i+ptr->adj)));
			printf("\n");
		}
	}
}

void free_graph(Graph *ptr)
{
	return;
	if(ptr)
	{
		for (int i=0; i<ptr->size; i++)
			free(i+ptr->adj);
		free(ptr->adj);
		free(ptr);
	}
}

Graph* gen_random_graph_undirected(int no_of_vertices, float edge_probability)
{
	Graph *ptr = new_graph(no_of_vertices);
	if  (ptr)
	{
		for (int i=0; i<ptr->size; i++)
			for (int j=0; j<ptr->size; j++)
				if((float)(rand()%100)/100 > edge_probability)
					*(j+*(i+ptr->adj)) = *(i+*(j+ptr->adj)) = 1;
	}
	return ptr;
}

Graph* gen_random_graph_directed(int no_of_vertices, float edge_probability)
{
	Graph *ptr = new_graph(no_of_vertices);
	if  (ptr)
	{
		for (int i=0; i<ptr->size; i++)
			for (int j=0; j<ptr->size; j++)
			{
				if((float)(rand()%100)/100 > edge_probability)
					*(j+*(i+ptr->adj)) = 1;
				if((float)(rand()%100)/100 > edge_probability)
					*(j+*(i+ptr->adj)) = 1;
			}
	}
	return ptr;
}

Graph* gen_random_graph_weighted_undirected(int no_of_vertices, float edge_probability)
{
	Graph *ptr = new_graph(no_of_vertices);
	if  (ptr)
	{
		for (int i=0; i<ptr->size; i++)
			for (int j=0; j<ptr->size; j++)
				if((float)(rand()%100)/100 > edge_probability)
					*(j+*(i+ptr->adj)) = *(i+*(j+ptr->adj)) = rand()%99 + 1; //assign an weight from 1-100
	}
	return ptr;
}

Graph* gen_random_graph_weighted_directed(int no_of_vertices, float edge_probability)
{
	Graph *ptr = new_graph(no_of_vertices);
	if  (ptr)
	{
		for (int i=0; i<ptr->size; i++)
			for (int j=0; j<ptr->size; j++)
			{
				if((float)(rand()%100)/100 > edge_probability)
					*(j+*(i+ptr->adj)) = rand()%99 + 1;
				if((float)(rand()%100)/100 > edge_probability)
					*(i+*(j+ptr->adj)) = rand()%99 + 1;
			}
	}
	return ptr;
}

int main ()
{
	/* initialize random seed: */
	srand ( time(NULL) );

	Graph *udg, *dg, *wudg, *wdg;
	float edge_probability = 0.6;
	int no_of_vertices = 10;
	udg = gen_random_graph_undirected(no_of_vertices, edge_probability);
	dg = gen_random_graph_directed(no_of_vertices, edge_probability);
	wudg = gen_random_graph_weighted_undirected(no_of_vertices, edge_probability);
	wdg = gen_random_graph_weighted_directed(no_of_vertices, edge_probability);

	printf("undirected graph\n");
	print_graph(udg);
	printf("directed graph\n");
	print_graph(dg);
	printf("weighted undirected graph\n");
	print_graph(wudg);
	printf("weighted directed graph\n");
	print_graph(wdg);

	free_graph(udg);
	free_graph(dg);
	free_graph(wudg);
	free_graph(wdg);
	return 0;
}
