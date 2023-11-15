#include <stdlib.h> //for malloc
#include <stdio.h>



// Defined in common.c
// struct Node
// {
//     int data;
//     struct Node* next; //self-referential structure
// } *top=NULL; //global struct pointer

// for LL, push and pop at the start (left) of the array

struct Node* push(struct Node* top,
                  int key) // adds to the leftmost part of the LL (start)
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("Stack overflow!");
    else
    {
        t->data = key;
        t->next = top; // make the link
        top = t;       // move the pointer
    }

    return top;
}

struct Node*
pop(struct Node* top) // deletes from the leftmost part of the LL (start)
{
    struct Node* p;

    if (top == NULL)
        printf("Stack underflow!");
    else
    {
        p = top;
        top = top->next;
        free(p);
    }

    return top;
}

int isEmpty(struct Node* top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isFull(struct Node* top) // can only be full if no heap space is available
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node* top = NULL;

    top = push(top, 10);
    DisplayLL(top);
    top = push(top, 20);
    DisplayLL(top);
    top = push(top, 30);
    DisplayLL(top);

    top = pop(top);
    DisplayLL(top);
}