using namespace std;

#include <iostream>
#include <vector>

// Input: [2, 3, 4, 1, 5], k=2
// Output: 7

class MaxSumSubArray
{
public:
    static int findMaxSum(const vector<int> arr, int k)
    {
        int windowStart = 0;
        int windowSum = 0;
        int maxSum = 0;

        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++)
        {
            windowSum += arr[windowEnd];

            if (windowEnd >= k - 1) // code to slide the window, sliding only
                                    // done once k is reached
            {
                if (windowSum > maxSum)
                    maxSum = windowSum;
                windowSum -= arr[windowStart];
                windowStart++; // keep moving start ahead so window size remains
                               // the same as windowEnd increases
            }
        }
        return maxSum;
    }
};

int main()
{
    int result = MaxSumSubArray::findMaxSum(vector<int>{2, 3, 4, 1, 5}, 2);
    cout << "The result is: " << result;

    return 0;
}