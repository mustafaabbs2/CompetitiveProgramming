// Given an array of sorted numbers and a target sum, find a pair in the array
// whose sum is equal to the given target.

// Input: [1, 2, 3, 4, 6], target=6
// Output: [1, 3]
// Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6

// Note since you have to return a pair, use std::make_pair

using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class PairWithSum
{

public:
    static pair<int, int> searchPair2Pointers(const vector<int>& arr,
                                              int targetSum)
    {
        int p = 0;
        int q = arr.size() - 1; // last element

        while (p < q)
        {
            int sum = arr[p] + arr[q];

            if (sum == targetSum)
            {
                return make_pair(p, q);
            }

            if (targetSum > sum)
                p++;
            else
                q--;
        }

        return make_pair(p, q);
    }

    static pair<int, int>
    searchPairHashTable(const vector<int>& arr,
                        int targetSum) // O(N) - which is the time required to
                                       // add N elements to HT
    {
        unordered_map<int, int> nums; // number and index

        for (int i = 0; i < arr.size(); i++)
        {
            if (nums.find(targetSum - arr[i]) != nums.end())
            {
                return make_pair(nums[targetSum - arr[i]],
                                 i); // indices of elements in hash table that
                                     // sum up to the target
            }
            else
                nums[arr[i]] = i; // add element to hash table: the key is the
                                  // array entry and the value is the index
        }

        // print hash table
        //  for (auto x : nums)
        //      cout<< x.first << " , " << x.second <<endl;

        return make_pair(-1, -1);
    }
};

int main()
{
    auto result =
        PairWithSum::searchPair2Pointers(vector<int>{1, 2, 3, 4, 6}, 6);
    cout << "Pair with target sum [" << result.first << "," << result.second
         << "] \n";

    auto result_HT =
        PairWithSum::searchPairHashTable(vector<int>{1, 2, 3, 4, 6}, 6);
    cout << "Pair with target sum [" << result_HT.first << "," << result.second
         << "] \n";

    return 0;
}