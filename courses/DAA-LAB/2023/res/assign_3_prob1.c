#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
   double hi;
   double lo;
} two_val;

double hirec ( int n )
{
//complete the code
}

double lorec ( int n )
{
//complete the code
}

two_val hilorec ( int n )
{
   two_val N;
//complete the code
}

two_val hiloformula ( int n )
{
   two_val N;

   N.hi = //complete the code
   N.lo = //complete the code
   return N;
}

int main ( int argc, char *argv[] )
{
   two_val N1, N2, N3;
   int n;

   clock_t start, end;
   double cpu_time_used;

   scanf("%d", &n);
   printf("n = %d\n", n);

   printf("\n+++ Method 0\n");
   start = clock();
   N1.hi = hirec(n); N1.lo = lorec(n);
   end = clock();
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N1.hi, n, N1.lo);
   cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   printf("Method 0 took %f seconds to execute \n", time_taken);

   printf("\n+++ Method 1\n");
   start = clock();
   N2 = hilorec(n);
   end = clock();
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N2.hi, n, N2.lo);
   cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   printf("Method 1 took %f seconds to execute \n", time_taken);

   printf("\n+++ Method 2\n");
   start = clock();
   N3 = hiloformula(n);
   end = clock();
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N3.hi, n, N3.lo);
   cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
   printf("Method 2 took %f seconds to execute \n", time_taken);

   exit(0);
}

