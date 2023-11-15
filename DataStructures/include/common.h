#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>


// Array ADT
//*****************************************************************************

struct Array
{
    int A[10];
    int size;
    int length;
};

void HelloWorld();
void Display(struct Array arr);
void Swap(int* x, int* y);
int Sum(struct Array arr);
void isSorted(struct Array* arr);

// Linked List
//*****************************************************************************

struct Node
{
    int data;
    struct Node* next; // self-referential structure
};

void DisplayLL(struct Node* head);
void RecursiveDisplayLL(struct Node* head);
struct Node* createLL(int A[], int size, struct Node* head);
void countLL(struct Node* p);
void maxLL(struct Node* p);
void sumLL(struct Node* p);
struct Node* searchLL(struct Node* p, int key);
struct Node* improvedSearchLL(struct Node* p, int key);
struct Node* insertLL(struct Node* p, int index, int key);
struct Node* insertAtEnd(struct Node* p, int key);
struct Node* insertInSortedLL(struct Node* p, int key);

// Stack
//*****************************************************************************
#endif /* COMMON_H */
