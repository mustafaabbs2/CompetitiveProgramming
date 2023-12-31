// Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the
// LinkedList from position ‘p’ to ‘q’.

#include <iostream>
using namespace std;

class ListNode
{
public:
    int value = 0;
    ListNode* next;

    ListNode(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class ReverseSubList
{
public:
    static ListNode* reverse(ListNode* head, int p, int q)
    {

        ListNode* current = head;
        ListNode* previous = nullptr;

        // skip p-1 nodes
        for (int i = 0; current != nullptr & i < p - 1; i++)
        {
            previous = current;
            current = current->next;
        }
        // we are interested in three parts of the LinkedList, part before index
        // 'p', part between 'p' and 'q', and the part after index 'q'
        ListNode* lastNodeOfFirstPart =
            previous; // points to the node at index 'p-1'

        // after reversing the LinkedList 'current' will become the last node of
        // the sub-list
        ListNode* lastNodeOfSubList = current;
        ListNode* next =
            nullptr; // will be used to temporarily store the next node

        for (int i = 0; current != nullptr & i < q - p + 1; i++)
        {
            next = current->next; // temp
            current->next = previous;
            // move both previous and current ahead
            previous = current;
            current = next;
        }

        // connect with the first part
        if (lastNodeOfFirstPart != nullptr)
        {
            lastNodeOfFirstPart->next =
                previous; // 'previous' is now the first node of the sub-list
        }
        else
        { // this means p == 1 i.e., we are changing the first node (head) of
          // the LinkedList
            head = previous;
        }

        // connect with the last part
        lastNodeOfSubList->next = current;

        return head;
    }
};

void print(ListNode* head)
{
    ListNode* p = head;
    while (p != nullptr)
    {
        cout << p->value << "->";
        p = p->next;
    }
}

int main(int argc, char* argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print(head);

    ListNode* result = ReverseSubList::reverse(head, 2, 4);
    cout << "Nodes of the reversed LinkedList are: ";
    print(result);
}