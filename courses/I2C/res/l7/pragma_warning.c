#include <stdio.h>

// Disable specific warning for this section of code
#pragma warning(push)
#pragma warning(disable : 4996)

void demo_function() {
    char str[100];
    printf("Enter your name: ");
    gets(str);  // Deprecated usage
}

#pragma warning(pop)  // Restore previous warning state

int main() {
    // The following code is typically a deprecated function warning
    // Here we assume that 'gets' may generate a warning in some compilers
    // (it's considered unsafe and deprecated)
    
    // Suppress the specific warning for deprecated functions
    #pragma warning(push)                  // Save the current warning state
    #pragma warning(disable : 4996)        // Disable warning 4996 (deprecated function)
    
    char str[100];
    printf("Enter a string: ");
    gets(str);  // Using 'gets', which is deprecated and may cause a warning
    printf("You entered: %s\n", str);
    
    #pragma warning(pop)                   // Restore previous warning state

    // After restoring the warning, using 'gets' will again trigger a warning
    printf("Warning should be enabled again:\n");
    // Uncommenting the next line will trigger the warning
    // gets(str);  // Uncommenting this will show the warning if the compiler supports it

    demo_function();  // Call the function with suppressed warnings
    printf("Function executed without warnings.\n");
    return 0;
}

