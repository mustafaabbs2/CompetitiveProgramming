// Given a sorted array, create a new array containing squares of all the
// numbers of the input array in the sorted order.

// Example 1:

// Input: [-2, -1, 0, 2, 3]
// Output: [0, 1, 4, 4, 9]

#include <iostream>
#include <vector>
using namespace std;
class SquareArray
{

public:
    static vector<int> square(const vector<int>& arr)
    {
        int n = arr.size();
        vector<int> squares(n);
        int left = 0;
        int right = n - 1;
        int top = n - 1; // this is where we'll put the biggest squares

        while (left <= right)
        {

            int leftSquare = arr[left] * arr[left];
            int rightSquare = arr[right] * arr[right];
            if (leftSquare > rightSquare)
            {
                squares[top--] = leftSquare;
                left++;
            }
            else
            {
                squares[top--] = rightSquare;
                right--;
            }
        }
        return squares;
    }
};

int main()
{
    vector<int> arr = {-2, -1, 0, 2, 3};
    vector<int> result = SquareArray::square(arr);

    for (auto num : result)
    {
        cout << num << " ";
    }
}