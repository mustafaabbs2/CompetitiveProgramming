#include "common.h"

//void Reverse(struct Array* arr)
//{
//    int temp[arr->length];
//    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
//    {
//        temp[j] = arr->A[i];
//    }
//
//    for (int i = 0; i < arr->length; i++)
//    {
//        arr->A[i] = temp[i];
//    }
//}

void Insert(struct Array* arr, int elem)
{
    int i = arr->length - 1;

    while (arr->A[i] > elem)
    {
        arr->A[i + 1] = arr->A[i];
        i -= 1;
    }

    arr->A[i + 1] = elem;
}

int main()
{
    struct Array arr1 = {{1, 2, 16, 7, 18}, 5, 5};

    Display(arr1);

    // Reverse(&arr1);

    // Insert(&arr1, 4);

    // Display(arr1);

    isSorted(&arr1);

    return 0;
}

// g++ -o 02_ArrayRev 02_ArrayRev.C ..\common.c