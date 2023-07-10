#include<stdio.h>
#include<stdlib.h>
typedef struct something
{
	int a;
}nn;

int fact (int n )
{
	return n==0?1:n*fact (n-1);
}

void main ()
{
	int* ptr;
	int ch, v;
	nn* nptr;
	FILE* fp;

	scanf ("%d", &ch);
	printf ("\n\n");
	switch (ch)
	{
		case 1:
			printf ("ptr %p\n", ptr);
			printf ("*ptr %d\n", *ptr);
			break;
		case 2: 
			printf ("ptr %p\n", ptr);
			printf ("*ptr %d\n", *ptr);
			*ptr = 10;
			break;
		case 21:	
			ptr = NULL;
			printf ("ptr %p\n", ptr);
			printf ("*ptr %d\n", *ptr);
			break;
		case 23:
			printf ("nptr %p\n", nptr);
			printf ("nptr->a %d\n", nptr->a);
			nptr->a = 10;
			break;
		case 3:
			nptr = (nn*) malloc (sizeof (nn));
			nptr->a = 10;
			printf ("nptr->a %d\n", nptr->a);
			
			printf ("%d\n", (nptr+1)->a);
			break;
		case 4:
			nptr = (nn*) malloc (sizeof (nn)*5);
			for (int i=0; i<5; i++)
				printf ("%d\n", (nptr+i)->a);
			printf ("%d\n", (nptr+10)->a);
			break;
		case 5:
			break;
		case 6:
			v = fact (5);
			printf ("%d\n", v);
		case 7:
			fp = fopen("file.txt", "r");
			if( fp == NULL ) 
			{
				perror("The error is ");
 			}
			break;
		default:
			printf ("Bye\n");
			exit(0);
	}
}


