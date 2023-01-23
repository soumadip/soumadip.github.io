#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
   N.hi = //complete the code
   return N;
}

int main ( int argc, char *argv[] )
{
   two_val N1, N2, N3;
   int n;

   scanf("%d", &n);
   printf("n = %d\n", n);

   printf("\n+++ Method 0\n");
   N1.hi = hirec(n); N1.lo = lorec(n);
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N1.hi, n, N1.lo);

   printf("\n+++ Method 1\n");
   N2 = hilorec(n);
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N2.hi, n, N2.lo);

   printf("\n+++ Method 2\n");
   N3 = hiloformula(n);
   printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N3.hi, n, N3.lo);

   exit(0);
}

