#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr)
{
    int n = arr.size();

    // Traverse the array
    for (int i = 0; i < n - 1; ++i)
    {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    // Example usage
    std::vector<int> arr = {64, 25, 12, 22, 11};

    // Print the original array
    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the array using Selection Sort
    selectionSort(arr);

    // Print the sorted array
    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
