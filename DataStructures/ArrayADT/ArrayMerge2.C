#include "common.h"

struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    // for any remaining elements

    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = arr1->length + arr2->length;

    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1 = {{1, 14, 18, 22, 23}, 5, 5};

    struct Array arr2 = {{6, 7, 8, 9, 10}, 5, 5};

    Display(arr1);

    struct Array* arr3;
    arr3 = Merge(&arr1, &arr2);

    Display(*arr3);

    return 0;
}

// g++ -o 03_ArrayMerge 03_ArrayMerge.C ..\common.c