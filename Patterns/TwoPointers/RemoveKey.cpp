// Given an unsorted array of numbers and a target ‘key’, remove all instances
// of ‘key’ in-place and return the new length of the array.

// Input: [3, 2, 3, 6, 3, 10, 9, 3], Key=3
// Output: 4
// Explanation: The first four elements after removing every 'Key' will be [2,
// 6, 10, 9].

#include <iostream>
#include <vector>
using namespace std;

class RemoveKey
{
private:
    /* data */
public:
    static int remove(vector<int>& arr, int key)
    {
        int nextElement = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != key)
            {
                arr[nextElement] = arr[i];
                nextElement++; // update only for non-key
            }
        }

        return nextElement;
    }
};

int main()
{

    vector<int> arr = {3, 2, 3, 6, 3, 10, 9, 3};
    int result = RemoveKey::remove(arr, 3);

    cout << "Length is: " << result;
}
