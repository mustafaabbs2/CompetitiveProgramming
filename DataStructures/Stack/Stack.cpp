#include <iostream>
#include <vector>
// pop, push

template <typename T>
class Stack
{
public:
    Stack(const std::vector<T>& list)
    {
        for (auto elem : list)
            push(elem);
    }
    void push(const T& x) { data.push_back(x); }

    T pop()
    {
        T elem;
        if (!data.empty())
        {
            elem = data.back();
            data.pop_back();
        }
        else
            throw std::out_of_range("Empty");
        return elem;
    }

    void print()
    {
        if (data.empty())
        {
            std::cout << "Empty" << std::endl;
            return;
        }
        std::cout << std::endl;
        for (const auto& elem : data)
            std::cout << elem << " ";
    }

private:
    std::vector<T> data;
};

int main()
{
    // std::vector<int> init = {1, 2, 3};
    Stack<int> stack({1, 2, 3});
    stack.print();
    auto p1 = stack.pop();
    stack.print();
    stack.push(5);
    stack.print();
}