#include "common.h"
#include <stdlib.h> //for malloc
#include <stdio.h>
// This has ADT for a stack (as an array)
// You need a pointer to the top of the stack..
// and space to store elements

// note insertion and deletion are O(1) - constant time
// they are both done from the same end

struct Stack
{
    int* s;   // pointer to an array
    int size; // size of the array
    int top;  // top of the stack
};

void push(struct Stack* s, int x)
{
    if (s->top == s->size - 1)
    {
        printf("\nStack overflow!\n");
        return;
    }
    s->s[s->top] = x;
    s->top++;
    // printf("The element %d was added at position %d \n", x, s->top);
}

void pop(struct Stack* s)
{
    if (s->top == -1)
    {
        printf("\nStack underflow!\n");
        return;
    }
    s->top--;
    // printf("The element %d was removed from position %d \n", s->s[s->top],
    // s->top);
}

int stackTop(struct Stack* s)
{
    if (s->top == -1)
    {
        printf("\nStack underflow!\n");
        return -1;
    }
    else
        return s->s[s->top];
    // printf("\nThe top element is %d \n", s->s[s->top]);
}

int isEmpty(struct Stack* s)
{
    if (s->top == -1)
    {
        printf("\nStack is empty!\n");
        return 1;
    }
    else
        return 0;
}

int isFull(struct Stack* s)
{

    if (s->top == s->size - 1)
    {
        printf("\nStack is full!\n");
        return 1;
    }
    else
        return 0;
}

void display(struct Stack s) // prints backwards  + call by value
{
    int i;
    // printf("The top index is %d \n", s->top);
    for (i = s.top - 1; i >= -1; i--)
    {
        printf("%d ", s.s[i]);
    }
}

int main()
{
    struct Stack st;
    st.size = 10;
    st.s = (int*)malloc(st.size * sizeof(int));
    st.top = -1; // initialize top of the stack to -1

    push(&st, 15);
    push(&st, 16);
    push(&st, 17);
    display(st);

    pop(&st);
    printf("\nAfter deletion: \n");
    display(st);
    // printf("Hello World");

    return 0;
}