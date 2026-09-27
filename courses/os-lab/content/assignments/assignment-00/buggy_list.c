#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* 
 * Task 1: This function contains a critical bug that causes undefined behavior.
 * Find it and fix it.
 */
void insert_tail(Node** head, int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    // Missing: new_node->next = NULL; (Causes segfault or infinite loop)

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*
 * Task 2: Implement this function to resolve the memory leak.
 */
void free_list(Node* head) {
    // TODO: Implement memory cleanup
}

int main() {
    Node* my_list = NULL;

    printf("Inserting elements...\n");
    insert_tail(&my_list, 10);
    insert_tail(&my_list, 20);
    insert_tail(&my_list, 30);

    printf("List contents:\n");
    print_list(my_list);

    // TODO: Call free_list(my_list) before exiting to prevent memory leaks

    return 0;
}

