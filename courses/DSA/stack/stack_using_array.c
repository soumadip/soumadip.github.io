#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP 5

typedef struct stack
{
    int arr [CAP];
    int top;
}stack;


stack* initilize_stack ()
{
    stack *ptr = (stack*) malloc (sizeof (stack));
    if (!ptr)
    {
        perror ("stack create fail\n");
        return NULL;
    }
    for (int i = 0; i < CAP; i++)
        ptr->arr[i] = 0;    
    ptr->top = -1;
    return ptr;
}

bool push (stack* ptr, int val)
{
    if (ptr->top == CAP-1)
    {
        printf ("Stack overflow\n");
        return false;
    }
    ptr->top++;
    ptr->arr [ptr->top] = val;
    return true;
}

bool pop (stack* ptr, int* ret)
{
    if (ptr->top == -1)
    {
        printf ("Stack underflow\n");
        return false;
    }
    *ret = ptr->arr [ptr->top];
    ptr->top--;
    return true;
}

bool peek (stack* ptr, int* ret)
{
    if (ptr->top == -1)
        return false;
    *ret = ptr->arr [ptr->top];
    return true;
}

void display (stack* ptr)
{
    if (ptr->top == -1)
        printf ("Stack empty\n");
    else
    {
        printf ("||    %d\t|| <-- [top]\n", ptr->arr [ptr->top]);
        for (int i = ptr->top - 1; i >= 0 ; i--)
            printf ("||    %d\t||\n", ptr->arr [i]);
    }
}

bool destroy (stack* ptr)
{
    if (!ptr)
        free (ptr);
    printf ("Stack destroyed\n");
}

int main ()
{
    stack* sptr = initilize_stack ();
    if (!sptr)
    {
        printf ("Failed to allocate memory for stack\nExiting\n");
        return -1;
    }
    else
        printf ("Stack initialized with size CAP %d\n", CAP);

    int ch, val;
    while (true)
    {
        printf ("1:: Push\n2:: Pop \n3:: Peek \n4:: Display \n5:: Exit\n\tEnter Choice--> ");
        scanf ("%d", &ch);
        switch (ch)
        {
        case 1:
            //push
            printf ("Enter value to insert:: ");
            scanf ("%d", &val);
            if (push (sptr, val))
                printf ("Push success\n");
            else
                printf ("Push fail\n");
            break;
        case 2:
            //pop
            if (pop (sptr, &val))
                printf ("Popped value is %d\n", val);
            else   
                printf ("Pop fail\n");
            break;
        case 3:
            //peek
            if (peek (sptr, &val))
                printf ("Top value is %d\n", val);
            else
                printf ("Stack empty\n");
            break;
        case 4:
            //display
            display (sptr);
            break;
        default:
            destroy (sptr);
            printf ("Bye!\n");
            exit (0);
        }
    }
}