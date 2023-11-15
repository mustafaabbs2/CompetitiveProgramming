#include <stdlib.h> //for malloc
#include <stdio.h>
// struct Node
// {
//     int data;
//     struct Node* next; //self-referential structure
// };

int main()
{

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int B[] = {2, 27, 8};

    struct Node* p; // created in stack
    struct Node* q; // created in stack

    struct Node *first, *temp, *tempA, *search, *impsearch; // created in stack

    struct Node* temp2 = NULL;

    p = (struct Node*)malloc(
            sizeof(struct Node)); // allocated in heap, typecasting is required for
    // malloc to work

    p->data = 10;
    p->next = NULL; // last node in a linked list is NULL

    q = p;

    // printf("\n p holds data = %d ", p->data);
    // printf("\n q holds data = %d ", q->data);

    // printf("\n p has size = %ld ", sizeof(struct Node));
    // printf("\n p has next pointing to %d ", p->next);

    // DisplayLL(p);

    // createLL(A, 10, first);
    // DisplayLL(first); //cannot use "first" from here, since first is not a
    // global variable (i think ) countLL(first);

    temp = createLL(B, 3, first);

    tempA = createLL(A, 10, first);

    // normal printing
    // DisplayLL(temp);

    // recursive printing
    printf("\nThe linked list elements are:  \n");
    RecursiveDisplayLL(temp);

    // counting the number of nodes
    countLL(temp);

    // summing the elements
    sumLL(temp);

    // finding the max
    maxLL(temp);

    // searching for an element
    search = searchLL(temp, 28);

    if (search != NULL)
    {
        printf("\nThe element is present in the linked list");
    }
    else
    {
        printf("\nThe element is not present in the linked list");
    }

    // impsearch=searchLL(temp, 8);
    // DisplayLL(impsearch);  this is not working rn

    // inserting into a LL
    printf("\nThe linked list elements before insertion are:  \n");
    RecursiveDisplayLL(tempA);
    temp = insertLL(tempA, 5, 22);
    // recursive printing
    printf("\nThe linked list elements after insertion are:  \n");
    RecursiveDisplayLL(temp);

    // Creating a LL using insert
    temp2 = insertLL(temp2, 0, 7);
    temp2 = insertLL(temp2, 1, 14);
    temp2 = insertLL(temp2, 2, 21);

    printf("\nThe created LL using insert is:  \n");
    RecursiveDisplayLL(temp2);

    temp2 = insertAtEnd(temp2, 24);
    temp2 = insertAtEnd(temp2, 212);

    printf("\nThe created LL using last node insert is:  \n");
    RecursiveDisplayLL(temp2);

    temp2 = insertInSortedLL(temp2, 25);
    RecursiveDisplayLL(temp2);

    return 0;
}