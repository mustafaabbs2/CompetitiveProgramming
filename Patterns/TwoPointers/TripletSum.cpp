// Given an array of integers, nums, and an integer value, target, determine if
// there are any three integers in nums whose sum equals the target. Return TRUE
// if three such integers are found in the array. Otherwise, return FALSE.

using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
bool FindSumOfThree(std::vector<int> nums, int target)
{
    // Sorting the input vector
    std::sort(nums.begin(), nums.end());
    // Fix one element at a time and find the other two
    for (int i = 0; i < (nums.size() - 2); i++)
    {
        // Set the indices of the two pointers
        // Index of the first of the remaining elements
        int low = i + 1;
        // Last index
        int high = nums.size() - 1;
        while (low < high)
        {
            // Check if the sum of the triple is equal to the sum
            int triple = nums[i] + nums[low] + nums[high];
            // Found a triple whose sum equals the target
            if (triple == target)
                return true;
            // Move low pointer forward if the triple sum is less
            // than the required sum
            else if (triple < target)
                low += 1;
            // Move the high pointer backwards if the triple
            // sum is greater than the required sum
            else
                high -= 1;
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> numsLists = {{3, 7, 1, 2, 8, 4, 5},
                                               {-1, 2, 1, -4, 5, -3},
                                               {2, 3, 4, 1, 7, 9},
                                               {1, -1, 0},
                                               {2, 4, 2, 7, 6, 3, 1}};

    std::vector<std::vector<int>> testLists = {
        {10, 20, 21}, {-8, 0, 7}, {8, 10, 20}, {1, -1, 0}, {8, 11, 15}};

    for (int i = 0; i < numsLists.size(); i++)
    {
        // std::cout << (i + 1) << ".\tInput array: " << Print(numsLists[i])
        // << std::endl;

        for (int j = 0; j < testLists[i].size(); j++)
        {
            if (FindSumOfThree(numsLists[i], testLists[i][j]))
                std::cout << " \tSum for " << testLists[i][j] << " exists"
                          << std::endl;
            else
                std::cout << " \tSum for " << testLists[i][j]
                          << " does not exist" << std::endl;
        }
        std::cout << std::string(100, '-') << std::endl;
    }
    return 0;
}