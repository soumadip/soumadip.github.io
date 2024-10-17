#include <stdio.h>

#define DEBUG  // Uncomment to enable debug mode

int main() {
    int x = 5;
    int y = 10;
    
    #ifdef DEBUG
    printf("Debug: x = %d, y = %d\n", x, y);  // This line will only compile if DEBUG is defined
    #endif

    int sum = x + y;
    printf("Sum: %d\n", sum);
    return 0;
}
