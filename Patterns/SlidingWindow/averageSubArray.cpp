// Given an array, find the average of all subarrays of ‘K’ contiguous elements
// in it.

using namespace std;

#include <iostream>
#include <vector>

class AverageOverK
{
public:
    static vector<double> findAverageBruteForce(int k, const vector<int>& arr)
    {
        vector<double> result(arr.size() - k + 1);
        for (int i = 0; i < arr.size() - k; i++)
        {
            double sum = 0;

            for (int j = i; j < i + k; j++) // time complexity = O(n*k)
            {
                sum += arr[j];
            }

            result[i] = sum / k;
        }

        return result;
    }

    static vector<double> findAverageSliding(int k, const vector<int>& arr)
    {
        vector<double> result(arr.size() - k + 1);
        int windowStart = 0;

        double windowSum = 0.0;

        for (int windowEnd = 0; windowEnd < arr.size();
             windowEnd++) // time complexity O(n)
        {
            // slide the window
            windowSum += arr[windowEnd];

            // only if the window size is hit, store the average in result
            // remove the element going out
            // slide the window ahead

            if (windowEnd >= k - 1) // window size of k is hit; only then move
                                    // everything to the result
            {
                result[windowStart] = windowSum / k;
                windowSum -= arr[windowStart];
                windowStart++;
            }
        }

        return result;
    }
};

int main()
{

    vector<double> result = AverageOverK::findAverageBruteForce(
        5, vector<int>{1, 3, 4, 6, -1, 4, 1, 8, 2});
    vector<double> result2 = AverageOverK::findAverageSliding(
        5, vector<int>{1, 3, 4, 6, -1, 4, 1, 8, 2});

    cout << "Average of subarrays of size k (Brute Force): ";

    for (double d : result)
    {
        cout << d << " ";
    }

    cout << "\n Average of subarrays of size k (Sliding Window): ";

    for (double d : result)
    {
        cout << d << " ";
    }

    return 0;
}