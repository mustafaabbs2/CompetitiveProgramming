#include <iostream>
#include <stack>

// Implementation of Queue using 2 Stacks
// You can enqueue in the first stack and dequeue in the second stack

// imagine pouring a stack of pringles from one bottle to another. To enqueue,
// you pour the pringles from the first bottle to the second bottle and then add
// to the first bottle. To dequeue, you remove from the second bottle once you've
// moved all the chips

class Queue
{
private:
    std::stack<int> e_stack; // enqueue stack
    std::stack<int> d_stack; // dequeue stack
public:
    Queue()
    {
        // empty
    }

    ~Queue()
    {
        // empty
    }

    void enqueue(int x) { e_stack.push(x); }

    int dequeue();

    void display();
};

int Queue::dequeue()
{
    //  int x = -1

    if (d_stack.empty()) // if dequeue stack is empty
    {
        if (e_stack.empty()) // if enqueue stack is empty
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }

        else
        {
            while (
                !e_stack
                     .empty()) // empty the enqueue stack into the dequeue stack
            {
                d_stack.push(
                    e_stack.top()); // push the top element of the enqueue stack
                                    // into the dequeue stack
                e_stack.pop(); // pop the top element of the enqueue stack
            }
        }
    }

    if (d_stack.empty())
    {
        return -1;
    }

    int x = d_stack.top(); // get the top element of the dequeue stack = as you
                           // dequeue it
    d_stack.pop();
    return x;
}

void Queue::display()
{
    while (!this->d_stack.empty())
    {
        std::cout << this->d_stack.top() << " ";
        this->d_stack.pop();
    }
}

int main()
{

    int A[] = {1, 3, 5, 7, 9};

    Queue q;

    // std::cout << "Enqueue: " << std::flush;
    // for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
    //     q.enqueue(A[i]);
    //     std::cout << A[i] << std::flush;
    //     if (i < sizeof(A)/sizeof(A[0])-1){
    //         std::cout << " <- " << std::flush;
    //     }
    // }
    // std::cout << std::endl;

    // std::cout << "Dequeue: " << std::flush;
    // for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
    //     std::cout << q.dequeue() << std::flush;
    //     if (i < sizeof(A)/sizeof(A[0])-1){
    //         std::cout << " <- " << std::flush;
    //     }
    // }

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.dequeue();
    q.display();

    // q.dequeue();
    // q.display();

    return 0;
}
