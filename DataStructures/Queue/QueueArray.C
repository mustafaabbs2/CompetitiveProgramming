#include <stdlib.h> //for malloc
#include <stdio.h>


// Queue is a FIFO data structure

// Here, both front and rear ends are used to implement the queue
// in stacks, we use only one end

// Operations:
// enqueue(x) ---> adds x to the rear end of the queue
// dequeue() ---> removes the element from the front end of the queue

// Queue can be implemented using Arrays as well as LLs

// You can use one pointer or two pointers to implement the queue - this is
// quicker - both enqueue and dequeue can take constant time O(1)

// Drawbacks of implementing a queue using an array are:
// 1. cannot use blank spaces at the front of the array if you've deleted
// elements

struct Queue
{
    int* arr;
    int front;
    int rear;
    int size;
};

void enqueue(Queue* q, int x) // adding to the last spot in the array
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
        return;
    }

    q->rear++;
    q->arr[q->rear] = x;
}

int dequeue(Queue* q) // remove from the first spot in the array
{

    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++; // front is designed to be behind the first element in the
        // array
        x = q->arr[q->front];
    }

    return x;
}

void Display(Queue* q)
{
    int i;
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{

    struct Queue q;
    q.size = 5;
    q.arr = (int*)malloc(q.size * sizeof(int));

    q.front = q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    Display(&q);

    int x = dequeue(&q);

    Display(&q);

    return 0;
}