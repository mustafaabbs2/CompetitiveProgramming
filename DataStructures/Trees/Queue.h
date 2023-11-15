#ifndef Queue_h
#define Queue_h

// Node for tree
struct Node
{
    Node* lchild;
    Node* rchild;
    int data;
};

struct Queue // create a queue of nodes -> note, this is an array formulation of
             // a queue
{
    int front;
    int rear;
    int size;
    Node** Q; // why is this a double pointer? - this is a pointer to an array
              // of Node pointers
};

void create(Queue* q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node**)malloc(size * sizeof(Node*));
}

void enqueue(Queue* q, Node* x) // add Node* x to the last spot
{
    if ((q->rear + 1) % q->size == q->front) // circular array
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x; // store the address of the new node
    }
}

struct Node* dequeue(Queue* q) // remove from the first spot in the array
{

    struct Node* x = NULL;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(Queue q) { return q.front == q.rear; }

void Display(Queue* q)
{
    int i;
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", (q->Q[i])->data); // printing data in the node
    }
    printf("\n");
}

//-------Adding Stack Definitions-----------------------------//

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

#endif