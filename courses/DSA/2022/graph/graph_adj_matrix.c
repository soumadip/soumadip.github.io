#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main ()
{
	int n = 4;
	int adj[4][4];

	//printf ("No of nodes? -->");
	//scanf ("%d", &n);

	//adj = (int*) malloc (n*n*sizeof (int));

	adj [0][1] = adj [1][0] = 1;
	adj [0][2] = adj [2][0] = 1;
	adj [2][1] = adj [1][2] = 1;
	adj [3][2] = adj [2][3] = 1;
	adj [0][3] = adj [3][0] = 1;

	FILE *fp = fopen ("tmp_g.dot", "w");
	fprintf (fp, "strict graph {");
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (adj [i][j] == 1)
				fprintf (fp, "%d -- %d;", i, j);
	fprintf (fp, "}");
	fclose (fp);


}
