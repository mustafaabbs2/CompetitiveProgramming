// find the current maximum value in the window as it slides through the entire
// array.

// [1,2,3,4,5,6,7,8,9,10] , 3

// ==> result = 3,4,5,6,7,8,9,10

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MaxValue
{
private:
    /* data */
public:
    static vector<int> FindMaxSlidingWindow(vector<int> nums, int windowSize)
    {

        int windowStart = 0;
        vector<int> maxValues;

        while (windowStart < (nums.size() - windowSize + 1))
        {
            int maxValue = -100000;
            for (int i = windowStart; i < windowStart + windowSize; i++)
            {
                std::cout << maxValue;
                if (nums[i] > maxValue)
                    maxValue = nums[i];
            }

            std::cout << "windowStart " << windowStart << endl;
            maxValues.push_back(maxValue);
            windowStart++;
        }

        return maxValues;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result = MaxValue::FindMaxSlidingWindow(nums, 3);
    for (auto i : result)
    {
        cout << i << " ";
    }
}
