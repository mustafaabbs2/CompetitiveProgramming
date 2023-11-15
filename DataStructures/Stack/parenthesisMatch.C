#include <stdlib.h> //for malloc
#include <stdio.h>
// Application of stack

// ((a+b)*(c-d)) --. will pass
// (((a+b)*(c-d)) --. will fail

struct Node
{
    int data;
    struct Node* next; // self-referential structure
}* top = NULL;         // global struct pointer

void push(char x) // adds to the leftmost part of the LL (start)
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("Stack overflow!");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node* t;
    char x = -1;
    if (top == NULL)
        printf("Stack underflow!");
    else
    {
        t = top;
        top = top->next;
        x = t->data; // need to return what we've popped
        free(t);
    }

    return x;
}

void display()
{
    struct Node* p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

int isBalanced(char* exp)
{

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]); // push any opening bracket into the stack
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0; // if stack is empty, then it's not balanced
            pop();        // pop any closing bracket from the stack
        }
    }

    if (top == NULL)
        return 1; // if at the END OF THE WHOLE THING, stack is empty, then it's
    // balanced
    else
        return 0;
}

int main()
{
    char exp[] = "((a+b)*(c-d)))";
    printf("%d\n", isBalanced(exp));
    return 0;
}
