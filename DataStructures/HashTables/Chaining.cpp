#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node* next;
};
// Hash Table
class HashTable
{

public:
    Node** HT;
    HashTable();
    int hash(int key);
    void Insert(int key);
    int Search(int key);
    ~HashTable();
};

HashTable::HashTable()
{
    HT = new Node*[10]; // create an array of pointers to Node with size 10
    for (int i = 0; i < 10; i++)
    {
        HT[i] = nullptr; // initialize all the pointers to null
    }
}

int HashTable::hash(int key) { return key % 10; }

void HashTable::Insert(int key)
{
    int hIdx = hash(key);

    // create a new node to be inserted into the hash table
    Node* t = new Node;
    t->data = key;
    t->next = nullptr;

    // Case: No nodes in the linked list
    if (HT[hIdx] == nullptr)
    {
        HT[hIdx] = t; // the index will point to the new node
    }
    else // if there are nodes in the linked list, now have to insert in a
         // sorted order
    {
        // need two pointers to traverse the linked list (one to trail and one
        // to move forward)
        Node* p = HT[hIdx];
        Node* q = HT[hIdx];

        // Traverse to find insert position
        while (p && p->data < key)
        {
            q = p;
            p = p->next; // move the pointer p forward
        }

        // Case: insert position is first
        if (q == HT[hIdx])
        {
            t->next = HT[hIdx]; // the temp node is attached to the head of the
                                // linked list
            HT[hIdx] = t;       // the index will point to the new node
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable::Search(int key)
{
    int hIdx = hash(key); // find the index from which to start searching
    Node* p = HT[hIdx];
    while (p)
    {
        if (p->data == key)
        {
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

HashTable::~HashTable()
{
    for (int i = 0; i < 10; i++)
    {
        Node* p = HT[i];
        while (HT[i])
        {
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    delete[] HT;
}

int main()
{
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int n = sizeof(A) / sizeof(A[0]);
    HashTable H;
    for (int i = 0; i < n; i++)
    {
        H.Insert(A[i]);
    }
    cout << "Successful Search" << endl;
    int key = 6;
    int value = H.Search(key);
    cout << "Key: " << key << ", Value: " << value << endl;
    cout << "Unsuccessful Search" << endl;
    key = 95;
    value = H.Search(key);
    cout << "Key: " << key << ", Value: " << value << endl;
    sizeof(A);

    return 0;
}
