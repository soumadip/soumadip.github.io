#include <stdio.h>

void my_function() {
    int sum = 0;
    for (int i = 0; i < 10000; i++) {
        sum += i;  // Some operation that could be optimized away
    }
    printf("Sum: %d\n", sum);
}

int main() {
    #pragma optimize("", off)  // Turn off optimization
    my_function();             // Call function
    #pragma optimize("", on)   // Turn on optimization

    printf("Optimization restored.\n");
    return 0;
}
