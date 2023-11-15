#include "common.h"
#include <stdio.h>

int GetIndex(struct Array arr, int elem)
{
    for (int i = 0; i < arr.size; i++)
    {
        if (elem == arr.A[i])
            return i;
    }

    return -1;
}

int GetElem(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void SetElem(struct Array* arr, int index, int elem)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = elem;
}

// int Sum(struct Array arr)
// {
//     int sum = 0;
//       for(int i=0; i<arr.size; i++)
//       {
//           sum+= arr.A[i];
//       }

//     return sum;

// }

int main()
{
    struct Array arr1 = {{1, 2, 3, 4, 5}, 5, 5};

    Display(arr1);
    printf("\nThe index is %d ", GetIndex(arr1, 5));
    printf("\nThe elem is %d ", GetElem(arr1, 4));

    SetElem(&arr1, 0, 27);

    Display(arr1);

    printf("\nThe sum is %d ", Sum(arr1));

    return 0;
}

// g++ -o 01_GetSet 01_GetSet.C ..\common.c