#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findKthLargest(vector<int>& nums, int k)
{
    // Create a max-heap
    priority_queue<int> maxHeap;

    // Insert elements into the max-heap
    for (int num : nums)
    {
        maxHeap.push(num);
    }

    // Extract the kth largest element
    for (int i = 1; i < k; ++i)
    {
        maxHeap.pop();
    }

    return maxHeap.top();
}

int main()
{
    // Example usage:
    vector<int> nums = {3, 2, 1, 5, 4, 6};
    int k = 2;

    int result = findKthLargest(nums, k);

    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
