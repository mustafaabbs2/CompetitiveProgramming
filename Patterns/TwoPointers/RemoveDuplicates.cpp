// Given an array of sorted numbers, remove all duplicates from it.
// You should not use any extra space; after removing the duplicates in-place
// return the length of the subarray that has no duplicate in it.

// Input: [2, 3, 3, 3, 6, 9, 9]
// Output: 4
// Explanation: The first four elements after removing the duplicates will be
// [2, 3, 6, 9].

using namespace std;

#include <iostream>
#include <vector>

class removeDuplicates
{
private:
    /* data */
public:
    // not that to bind via reference to a constant r-value, you need 'const' as
    // a keyword but we need to edit this, so dont have const, instead, pass an
    // l-value 'arr'
    static int removeDup(vector<int>& arr)
    {
        int nextNonDuplicate = 1;
        // keep this pointer to place non-duplicate elements; update this
        // only when you meet a non-duplicate element

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[nextNonDuplicate - 1] != arr[i])
            {
                arr[nextNonDuplicate] = arr[i];
                nextNonDuplicate++; // this will only update when you encounter
                                    // non-duplicate elements
            }
        }

        return nextNonDuplicate; // the pointer ends up on the length of
                                 // non-duplicate elements
    }
};

int main()
{
    // int len = removeDuplicates::removeDup(vector<int>{2, 3, 3, 6, 9, 9});
    // //this will not work because this is an r-value
    vector<int> arr = {2, 3, 3, 6, 9, 9};
    int len = removeDuplicates::removeDup(arr);
    cout << "Non duplicate array length: " << len << endl;

    return 0;
}
