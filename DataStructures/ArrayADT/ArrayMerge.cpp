#include <iostream>

class Array
{
private:
    int* A;
    int size;
    int length;

public:
    Array(int size)
    {
        this->size = size;
        A = new int[size];

        for (int i = 0; i < size; i++)
        {
            A[i] = i;
        }
    }

    ~Array() { delete[] A; }

    void Display()
    {
        std::cout << "\nThe array elements are \n";
        for (int i = 0; i < size; i++)
        {
            std::cout << A[i] << " ";
        }
    }
};

int main()
{

    Array arr1(15);
    arr1.Display();

    Array arr2(5);
    arr2.Display();

    return 0;
}

// g++ -o 03_ArrayMergeCPP 03_ArrayMerge.cpp ..\common.c