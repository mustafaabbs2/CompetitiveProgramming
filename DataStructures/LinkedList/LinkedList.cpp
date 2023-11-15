// create a linked list in CPP, as well as reverse it
#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value)
    {
        Node* newnode = new Node(value);
        newnode->next = head;
        head = newnode;
    }

    void insertAtEnd(int value)
    {
        Node* newnode = new Node(value);
        Node* current = head;

        if (head == nullptr)
            head = newnode;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newnode;
    }

    void printLinkedList() const
    {
        Node* node = head;
        while (node != nullptr)
        {
            std::cout << node->data << std::endl;
            node = node->next;
        }
    }

private:
    Node* head;
};

int main()
{

    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtBeginning(0);
    list.insertAtEnd(15);

    list.printLinkedList();
}