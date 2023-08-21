#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP 5

typedef struct queue
{
    int arr [CAP];
    int front, rear;
}queue;


queue* initilize_queue ()
{
    queue *ptr = (queue*) malloc (sizeof (queue));
    if (!ptr)
    {
        perror ("QUEUE create fail\n");
        return NULL;
    }
    for (int i = 0; i < CAP; i++)
        ptr->arr[i] = 0;    
    ptr->rear = ptr->front = -1;
    return ptr;
}

bool enqueue (queue* ptr, int val)
{
    if (ptr->rear - ptr->front + 1 == CAP)
    {
        printf ("QUEUE overflow\n");
        return false;
    }
    if (ptr->rear == -1)
        ptr->front++;
    ptr->rear++;
    ptr->arr [ptr->rear % CAP] = val;
    return true;
}

bool dequeue (queue* ptr, int* ret)
{
    if (ptr->front == -1 || ptr->front > ptr->rear)
    {
        printf ("QUEUE underflow\n");
        return false;
    }
    *ret = ptr->arr [ptr->front % CAP];
    ptr->front++;
    return true;
}

void display (queue* ptr)
{
    if (ptr->front == -1 || ptr->front > ptr->rear)
        printf ("QUEUE empty\n");
    else
    {
        printf ("\nQUEUE:: [FRONT]==");
        if (ptr->front % CAP - ptr->rear % CAP <= 0)
            for (int i = ptr->front % CAP; i <= ptr->rear % CAP ; i++)
                printf ("%d==", ptr->arr [i]);
        else
        {
            for (int i = ptr->front % CAP; i < CAP ; i++)
                printf ("%d==", ptr->arr [i]);
            for (int i = 0; i <= ptr->rear % CAP ; i++)
                printf ("%d==", ptr->arr [i]);
        }
        printf ("[REAR]\n");
    }
    printf("\nStructure contents:\nSTORAGE:: -");
    for (int i = 0; i < CAP ; i++)
        printf (" [%d]->%d -", i, ptr->arr [i]);
    printf("\nFRONT = [%d]~%d, REAR = [%d]~%d\n", ptr->front % CAP, ptr->front, ptr->rear % CAP, ptr->rear);
}

bool destroy (queue* ptr)
{
    if (!ptr)
        free (ptr);
    printf ("QUEUE destroyed\n");
}

int main ()
{
    queue* qptr = initilize_queue ();
    if (!qptr)
    {
        printf ("Failed to allocate memory for QUEUE\nExiting\n");
        return -1;
    }
    else
        printf ("QUEUE initialized with size CAP %d\n", CAP);

    int ch, val;
    while (true)
    {
        printf ("\n1:: Enqueue\n2:: Dequeue\n3:: Display \n4:: Exit\n\tEnter Choice--> ");
        scanf ("%d", &ch);
        switch (ch)
        {
        case 1:
            //push
            printf ("Enter value to insert:: ");
            scanf ("%d", &val);
            if (enqueue (qptr, val))
                printf ("Enqueue success\n");
            else
                printf ("Enqueue fail\n");
            break;
        case 2:
            //pop
            if (dequeue (qptr, &val))
                printf ("Dequeue success:: %d\n", val);
            else   
                printf ("Dequeue fail\n");
            break;
        case 3:
            //display
            display (qptr);
            break;
        default:
            destroy (qptr);
            printf ("Bye Bye!\n");
            exit (0);
        }
    }
}
