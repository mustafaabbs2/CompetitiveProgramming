#include <iostream>
#include <vector>

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high)
{
    // Choose the rightmost element as the pivot
    int pivot = arr[high];

    // Index of the smaller element
    int i = low - 1;

    // Traverse through the subarray
    for (int j = low; j < high; j++)
    {
        // If the current element is smaller than or equal to the pivot, swap it
        // with the element at the smaller index
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at the (smaller index + 1)
    std::swap(arr[i + 1], arr[high]);

    // Return the pivot index
    return i + 1;
}

// Recursive function to perform Quicksort
void quickSort(std::vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively call quickSort on the subarrays before and after the
        // pivot element
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    std::vector<int> arr = {9, 5, 2, 7, 1, 8, 3};
    int n = arr.size();

    std::cout << "Original Array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Call quickSort function to sort the array
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted Array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
