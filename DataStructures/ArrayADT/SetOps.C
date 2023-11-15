#include "common.h"


struct Array* Union(struct Array* arr1, struct Array* arr2)
{
    struct Array* arr3;

    return arr3;
}

int main()
{
    struct Array arr1 = {{1, 14, 18, 22, 23}, 5, 5};

    struct Array arr2 = {{6, 7, 8, 9, 10}, 5, 5};

    struct Array* arr3;

    arr3 = Union(&arr1, &arr2);

    Display(*arr3);

    return 0;
}

// g++ -o 03_ArrayMerge 03_ArrayMerge.C ..\common.c