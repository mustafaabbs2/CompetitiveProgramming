#include <stdlib.h> //for malloc
#include <stdio.h>
struct Queue
{
    int* arr;
    int front;
    int rear;
    int size;
};

void enqueue(Queue* q, int x) // adding to the last spot in the array
{
    // For the queue full condition, we need to check if the rear one behind
    // front No longer necessarily if rear is at the end of the array, because
    // this is now circular
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        // This moves rear ahead, but the moment it becomes greater than the
        // size of the array, it will be reset to 0
        q->arr[q->rear] = x;
    }
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
        q->front = (q->front + 1) % q->size; // front will also move circularly
        x = q->arr[q->front];
    }

    return x;
}

void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.arr[i]);
        i = (i + 1) % q.size; // move i circularly
    } while (i != (q.rear + 1) %
                      q.size); // should not exceed where the rear pointer is
    printf("\n");
}

int main()
{

    struct Queue q;
    q.size = 6;
    q.arr = (int*)malloc(q.size * sizeof(int));

    q.front = q.rear = 0;
    // this time, start them from 0, because we are using a circular array,
    // otherwise mod wont work

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    Display(q);

    int x = dequeue(&q);
    int y = dequeue(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);
    // enqueue(&q, 80);
    Display(q);

    return 0;
}