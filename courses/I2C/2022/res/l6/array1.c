#include <stdio.h>
    void main()
    {
        int i, a[4] = {1,2,3};
	printf(" 0--%d\n", a[0]);
	printf(" 1--%d\n", a[1]);
	printf(" 2--%d\n", a[2]);
	printf(" 3--%d\n", a[3]);
	printf(" 4--%d\n", a[4]); //unpredictable
	printf(" 5--%d\n", a[5]); //unpredictable
	printf(" 6--%d\n", a[6]); //unpredictable
	printf("-1--%d\n", a[-1]); //unpredictable
	

	printf("\n");

	printf("-1--%-20d \t%-20p\n", a[-1], &a[-1]);
	printf(" 0--%-20d \t%-20p\n", a[0], &a[0]);
	printf(" 1--%-20d \t%-20p\n", a[1], &a[1]);
	printf(" 2--%-20d \t%-20p\n", a[2], &a[2]);
	printf(" 3--%-20d \t%-20p\n", a[3], &a[3]);
	printf(" 4--%-20d \t%-20p\n", a[4], &a[4]);
	printf(" 5--%-20d \t%-20p\n", a[5], &a[5]);
	printf(" 6--%-20d \t%-20p\n", a[6], &a[6]);
    }
