#include "Queue.h"
#include <stdlib.h> //for malloc
#include <stdio.h>
// #include <stack> //this is in C++

struct Node* root = NULL;

// what is done here:
// 1. Create a queue where the addresses of nodes are stored
// 2. The FIFO structure ensures that nodes added first are dequeued first,
// which means earlier levels can be used to add children to
// 3. The higher levels of the tree get the priority to add children to
// 4. You can traverse the tree in either preorder or inorder or postorder

void TreeCreate()
{
    struct Node *p, *t; // p = parent node and t = temporary node

    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter the root element: ");
    scanf("%d", &x);
    root = (struct Node*)malloc(sizeof(struct Node));

    root->data = x;
    root->lchild = root->rchild =
        NULL;          // both children of the root are NULL at first
    enqueue(&q, root); // put this node's address in the queue

    while (!isEmpty(q))
    {
        p = dequeue(&q); // dequeue the first node in the queue. This will be
                         // the parent node

        // read left child
        printf("Enter the left child of %d: ", p->data); // enter -1 for no
                                                         // child
        scanf("%d", &x);

        if (x != -1) // if -1, no left child
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;  // assign the left child of p to t
            enqueue(&q, t); // put t's address in the queue
        }

        // read right child
        printf("Enter the right child of %d: ",
               p->data); // enter -1 for no child
        scanf("%d", &x);

        if (x != -1) // if -1, no left child
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;  // assign the right child of p to t
            enqueue(&q, t); // put t's address in the queue
        }

    } // while loop
}

void PreOrder(struct Node* p) // traversing the tree in preorder
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void InOrder(struct Node* p) // traversing the tree in inorder
{
    if (p != NULL)
    {
        InOrder(p->lchild);
        printf("%d ", p->data);
        InOrder(p->rchild);
    }
}

void PostOrder(struct Node* p) // traversing the tree in postorder
{
    if (p != NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%d ", p->data);
    }
}

// convert recursion to iteration: you have to use a stack

// When traversing a tree, push the address to a stack and then go to the left
// child of the node. if you reach a null and if the stack isnt empty, pop an
// element, use its address and get the right child

void PreOrderIter(struct Node* p) // traversing the tree in preorder
{
    Struct Stack st;

    while (p != NULL || !isEmpty(st))
    {
        if (p != NULL) // if you reached a node, print the value and proceed
                       // along its left
        {
            printf("%d ", p->data);
            push(&st, p);
            p = p->lchild;
        }
        else // if you reached a null and stack isn't empty, go down the right
             // direction
        {
            p = pop(&st);
            p = p->rchild; // go to the right child of the element whose left
                           // child was found to be null
        }
    }
}

// generating tree from traversal:

int main()
{

    TreeCreate();

    printf("\nPre Order: ");

    // PreOrder(root);
    PreOrderIter(root);

    printf("\nIn Order: ");

    InOrder(root);

    printf("\nPost Order: ");

    PostOrder(root);

    return 0;
}