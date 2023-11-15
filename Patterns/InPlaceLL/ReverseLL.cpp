using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseLinkedList {
 public:
  static ListNode *reverse(ListNode *head) {
    ListNode *current = head; //pointer that moves
    ListNode *previous = nullptr;
    ListNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->next; //store temporarily

        current->next = previous; //link it to the previous node

        previous = current; //move previous one ahead 

        current = next; //move to the next node
    }
    return previous; //current will point to nullptr, since the increment is happening after the while check
  }
};

void print(ListNode *head)
{
    ListNode *p = head;
    while(p!=nullptr)
    {
        cout<<p->value<<"->";
        p = p->next; 
    }

}


int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
  print(head);

  ListNode *result = ReverseLinkedList::reverse(head);
  cout << "Nodes of the reversed LinkedList are: ";
  print(result);
}
