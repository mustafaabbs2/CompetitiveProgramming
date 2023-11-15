// Given the head of a Singly LinkedList, write a function to determine if the
// LinkedList has a cycle in it or not.

using namespace std;

#include <iostream>

// Always create a class like this for the LL

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

void print(ListNode* head)
{
    ListNode* p = head;
    while (p != nullptr)
    {
        cout << p->value << "->";
        p = p->next;
    }
}

// Imagine we have a slow and a fast pointer to traverse the LinkedList.
// In each iteration, the slow pointer moves one step and the fast pointer moves
// two steps. This gives us two conclusions:

// If the LinkedList doesn’t have a cycle in it, the fast pointer will reach the
// end of the LinkedList before the slow pointer to reveal that there is no
// cycle in the LinkedList.

// The slow pointer will never be able to catch up to the fast pointer if there
// is no cycle in the LinkedList. If the LinkedList has a cycle, the fast
// pointer enters the cycle first, followed by the slow pointer. After this,
// both pointers will keep moving in the cycle infinitely. If at any stage both
// of these pointers meet, we can conclude that the LinkedList has a cycle in
// it.

class LinkedListCycle
{
public:
    static bool hasCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};

class LinkedListCycleLength
{
public:
    static int findCycleLength(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) // found the cycle - have to do this to see if a
                              // cycle exists
            {
                return calculateLength(slow);
            }
        }
        return 0;
    }

private:
    static int calculateLength(ListNode* slow)
    {
        ListNode* current = slow;
        int cycleLength = 0;
        do
        {
            current = current->next;
            cycleLength++;
        } while (current != slow);
        return cycleLength;
    }
};

int main(int argc, char* argv[])
{

    ListNode* head =
        new ListNode(1); // this uses the heap to create a class object
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    print(head);

    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

    head->next->next->next->next->next->next = head->next->next;
    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;
    cout << "LinkedList cycle length: "
         << LinkedListCycleLength::findCycleLength(head) << endl;

    head->next->next->next->next->next->next = head->next->next->next;
    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;
    cout << "LinkedList cycle length: "
         << LinkedListCycleLength::findCycleLength(head) << endl;
}
