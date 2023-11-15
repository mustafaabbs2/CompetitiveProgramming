// Given an array of positive numbers and a positive number ‘S,’ find the length
// of the smallest contiguous subarray whose sum is greater than or equal to
// ‘S’. Return 0 if no such subarray exists.

// Input: [2, 1, 5, 2, 3, 2], S=7
// Output: 2
// Explanation: The smallest subarray with a sum greater than or equal to '7' is
// [5, 2].

using namespace std;

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

class SmallestSubArray
{

public:
    static int findSmallestSubArray(const vector<int> arr, int sum)
    {
        int windowStart = 0;
        int windowSum = 0;
        // int minLength = 100000;
        int minLength = numeric_limits<int>::max();

        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
        {

            windowSum += arr[windowEnd];
            cout << windowEnd << " " << windowSum << endl;
            // code to slide the window
            if (windowSum >=
                sum) // the condition is met, window size is not a factor
            {
                minLength = min(minLength, windowEnd - windowStart);
                windowSum -= arr[windowStart];
                windowStart++;
            }
        }

        return minLength;
    }
};

int main()
{
    int minLength = SmallestSubArray::findSmallestSubArray(
        vector<int>{2, 1, 5, 2, 3, 2}, 7);

    cout << "min length is: " << minLength;

    return 0;
}