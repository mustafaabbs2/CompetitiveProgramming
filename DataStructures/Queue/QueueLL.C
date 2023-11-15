#include <stdlib.h> //for malloc
#include <stdio.h>

// Implementation of Queue using Linked List

// You need two pointers here too, one at the front, and one at the rear

// 1. When first node is inserted, front and rear are both pointing to it
// 2. There is no limit to the size of the queue (unless heap is used)

struct Node
{
    int data;
    Node* next;
}* front = NULL, *rear = NULL;

void enqueue(int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    int x;
    struct Node* p;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        p = front;
        x = front->data;
        front = front->next;
        free(p);
        return x;
    }
}

void display()
{
    struct Node* t = front;

    if (t == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main()
{
    // struct Node *front = NULL;
    // struct Node *rear = NULL;

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    int ret = dequeue();
    printf("\nSuccessfully dequeued %d\n", ret);
    display();

    return 0;
}
