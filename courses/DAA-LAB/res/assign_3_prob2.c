#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int method0 ( int *A, int n )
{
//your method should return 1 on success, and 0 on failure
//write code for method 0 to solve this probelm
}

int method1 ( int *A, int n )
{
//your method should return 1 on success, and 0 on failure
//write code for method 1 to solve this probelm
}

int method2 ( int *A, int n )
{
//your method should return 1 on success, and 0 on failure
//write code for method 2 to solve this probelm
}

int method3 ( int *A, int n )
{
//your method should return 1 on success, and 0 on failure
//write an O(n) method to solve this probelm
//hint: you may look into the stack concept
}

int main ( int argc, char *argv[] )
{
   int i, n, *A, *B;

   //scan the input
   scanf("%d", &n);
   A = (int*) malloc (sizeof(int)*n);
   for (i=0; i<n; ++i) scanf(" %d", &A[i]);

   printf("\n");
   printf("    Method 0: %s\n", method0(A,n) ? "Valid" : "Invalid");
   printf("    Method 1: %s\n", method1(A,n) ? "Valid" : "Invalid");
   printf("    Method 2: %s\n", method2(A,n) ? "Valid" : "Invalid");
   printf("    Method 3: %s\n", method3(A,n) ? "Valid" : "Invalid");

   exit(0);
}

