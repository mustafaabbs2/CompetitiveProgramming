#include "common.h"

// Array ADT
//*****************************************************************************
void HelloWorld() { printf("Hello World  \n"); }

void Display(struct Array arr)
{
    printf("\nThe array elements are:  \n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size; i++)
    {
        sum += arr.A[i];
    }

    return sum;
}

void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//  int x = 5, y = 3;
//  printf("\nx = %d, y = %d \n", x, y);
//  Swap(&x,&y);
//  printf("\nx = %d, y = %d \n", x, y);

void isSorted(struct Array* arr)
{
    int notsorted = 0;
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] > arr->A[i + 1])
        {
            notsorted = 1;
            break;
        }
    }

    if (notsorted == 1)
        printf("\nThe array is not sorted \n");
    else
        printf("\nThe array is sorted \n");
}

// Linked List
//*****************************************************************************

void DisplayLL(struct Node* first) // send the first element of the LL
{
    struct Node* temp = first;
    printf("\nThe linked list elements are:  \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void RecursiveDisplayLL(struct Node* p) // send the first element of the LL
{

    if (p != NULL)
    {
        printf("%d ", p->data);
        RecursiveDisplayLL(p->next);
    }
}

void countLL(struct Node* p) // send the first element of the LL
{
    int count = 0;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    printf("\nThere are %d nodes \n", count);
}

void sumLL(struct Node* p) // send the first element of the LL
{
    int sum = 0;

    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }

    printf("\nThe sum is %d\n", sum);
}

void maxLL(struct Node* p) // send the first element of the LL
{
    int max = 0;

    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }

    printf("\nThe max is %d\n", max);
}

struct Node* searchLL(struct Node* p,
                      int key) // send the first element of the LL
{
    while (p != NULL)
    {
        if (key == p->data)
            return p; // return the node
        p = p->next;
    }

    return NULL;
}

// can improve search by moving a searched element to the starting position of a
// linked list this can be done via a tail pointer which follows the p pointer

struct Node* improvedSearchLL(struct Node* p,
                              int key) // note this does not work properly
{

    struct Node* tail;
    struct Node* first = p;

    while (p != NULL)
    {
        if (key == p->data)
        {
            tail->next =
                p->next; // make a link between the previous node and the next
                         // node (removing the current node from chain)
            p->next = first; // make a link between the current node and the
                             // first node
            first = p;       // make the current node the first node
            return p;        // return the node
        }

        tail = p;    // move tail up to where p was
        p = p->next; // move p one ahead, so tail lags behind p
    }

    return NULL;
}

struct Node* insertLL(struct Node* p, int index, int key)
{
    struct Node* t;
    struct Node* q = p;
    struct Node* first = p;

    if (index ==
        0) // if you have to insert at the start of the list, this is easy
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->next = first;
        first = t;
    }
    else // else use your pointer q to move up to just one before the index
         // (where you want to insert)
    {
        int i = 0;
        while (q != NULL)
        {
            if (i == index - 1)
            {
                t = (struct Node*)malloc(sizeof(struct Node));
                t->data = key;
                t->next = q->next;
                q->next = t;
                break;
            }
            q = q->next;
            i++;
        }
    }

    return first;
}

struct Node* insertAtEnd(struct Node* p, int key)
{
    struct Node* t;
    struct Node* last;

    // create the new node
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;

    if (p == NULL)
    {
        last = t;
        p = last;
    }
    else
    {
        last = p;
        while (last->next)
            last = last->next; // go to the last node
        last->next = t;
        last = t;
    }

    return p;
}

struct Node* insertInSortedLL(struct Node* p,
                              int key) // this doesn't work - find out why
{
    struct Node* t;

    // Now you need two pointers - one tailing pointer to map the node before
    // the inserted node to mark the link, and one leading pointer to compare if
    // data<key

    struct Node *lead = p, *tail = NULL;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;

    // if the LL is empty
    if (p == NULL)
        p = t;

    else
    {
        while (lead &&
               lead->data < key) // while the lead pointer exists and condition
                                 // for insertion is NOT met yet
        {
            tail = lead;         // bring tail up to lead
            lead = lead->next;   // move lead ahead
        }

        // now the movement is over, the loop has exited

        if (lead == p)
        {
            t->next = p;
            p = t;
        }
        else
        {
            t->next = tail->next;
            tail->next = t;
        }
    }

    return p;
}

struct Node* createLL(int A[], int size, struct Node* first)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;

    last = first; // at the start, last and first point to the same node

    for (i = 1; i < size; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;

        last->next =
            temp; // connect the last node to the new node i.e. build the chain
        last = temp; // make the new node the last node i.e update the
                     // designation of the last node
        // printf("\n element is = %d ", last->data); debugging
    }

    return first;
}

// Compile with
// gcc -c common.c -o common.o

// Linux: Convert to static library using
// ar rcs libcommon.a common.o

// int main()
// {
//     return 0;
// }
