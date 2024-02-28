#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>

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

void graphviz(Graph *ptr, char* graph_type, char* outfile_name) 
	//graph_type can be any of the following: diagraph, undirected, weighted_diagraph, weighted_undirected
{
	bool weighted = false, directed = false;
	char outfname[15] = "", command[100] = "";

	if (strstr(graph_type, "diagraph"))	directed = true && strcat(outfname, "D_");
	if (strstr(graph_type, "weight"))	weighted = true && strcat(outfname, "W_");
	strcat (outfname, "G.dot");

	FILE *fp = fopen(outfname, "w");
	if(ptr && fp)
	{
		if (directed)	fprintf(fp, "di");
		fprintf(fp, "graph G{\n");

		for (int i=0; i<ptr->size; i++)
			fprintf(fp, "v_%d[label=V%d];\n", i, i+1);
			//fprintf(fp, "v_%d[label=<v<SUB>%d</SUB>>];\n", i, i+1);

		for (int i=0; i<ptr->size; i++)
		{
			for (int j=directed ? 0 : i+1; j<ptr->size; j++)
			{
				int weight = *(j+*(i+ptr->adj));
				if (i !=j && weight)
				{
					fprintf(fp, "v_%d", i);
					fprintf(fp, directed ? " -> " : " -- ");
					fprintf(fp, "v_%d", j);
					fprintf(fp, weighted ? "[label=%d];\n" : ";\n", weight);
				}
			}
		}
		fprintf(fp, "}");
	}
	fclose(fp);
	sprintf(command, "dot -Tpng %s -o %s", outfname, outfile_name);
	if(!system(command))
		printf("Graph image %s generation successful!\n", outfile_name);
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
	if(ptr)
	{
		for (int i=0; i<ptr->size; i++)
			free(*(i+ptr->adj));
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
				if(i!=j && (float)(rand()%100)/100 < edge_probability)
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
				if(i!=j && (float)(rand()%100)/100 < edge_probability)
					*(j+*(i+ptr->adj)) = 1;
				if(i!=j && (float)(rand()%100)/100 < edge_probability)
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
				if(i!=j && (float)(rand()%100)/100 < edge_probability)
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
				if(i!=j && (float)(rand()%100)/100 < edge_probability)
					*(j+*(i+ptr->adj)) = rand()%99 + 1;
				if(i!=j && (float)(rand()%100)/100 < edge_probability)
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
	float edge_probability;
	int no_of_vertices = 10;

	printf("Enter number of verices (positive integer):"); 
	scanf("%d", &no_of_vertices);
	if(no_of_vertices <= 0)
	{
		printf("error in number of vertices, defaulting to 10\n");
		edge_probability = 10;
	}
	printf("Enter edge probability (0-1):"); 
	scanf("%f", &edge_probability);
	if(edge_probability < 0 || edge_probability > 1)
	{
		printf("error in probability, defaulting to 0.5\n");
		edge_probability = 0.5;
	}

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

	//graph_type can be any of the following: diagraph, undirected, weighted_diagraph, weighted_undirected
	graphviz(udg, "undirected", "udg.png");
	graphviz(dg, "diagraph", "dg.png");
	graphviz(wudg, "weighted_undirect", "wudg.png");
	graphviz(wdg, "weight_diagraph", "wdg.png");
	free_graph(udg);
	free_graph(dg);
	free_graph(wudg);
	free_graph(wdg);
	return 0;
}