#include <stdio.h>

#pragma pack(push, 1)  // Set structure alignment to 1 byte

struct my_struct {
    char a;   // 1 byte
    int b;    // 4 bytes
};

#pragma pack(pop)  // Restore default alignment

struct my_another_struct {
    char a;   // 1 byte
    int b;    // 4 bytes
};

int main() {
    printf("Size of structure: %lu bytes\n", sizeof(struct my_struct));  // Should print 5 bytes
    printf("Size of structure: %lu bytes\n", sizeof(struct my_another_struct));  // Should print 8 bytes
	return 0;
}
