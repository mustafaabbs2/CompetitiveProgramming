// Write an algorithm to determine if a number is happy.

// Starting with any positive integer, replace the number by the sum of the
// squares of its digits. Repeat the process until the number equals 1 (where it
// will stay), or it loops endlessly in a cycle which does not include 1 Those
// numbers for which this process ends in 1 are happy.

// Solution - if there is a cycle, it is happy, keep moving fast pointer more
// steps ahead of the slow one
#include <iostream>

static void isHappy(int x)
{

    int fast, slow;
    slow = x;

    auto findSum = [](int x)
    {
        int sum = 0;
        int sqd;
        while (x > 0)
        {
            int dig1 = x % 10;
            sqd = dig1 * dig1;
            sum += sqd;
            x = x / 10;
        }
        return sum;
    };

    fast = findSum(x);

    while (fast != 1 && slow != fast)
    {
        slow = findSum(slow);
        fast = findSum(findSum(fast));
    }

    if (fast == 1)
        std::cout << "Yes, its happy \n";
    else
        std::cout << "Unhappy \n";
}

int main(int argc, char* argv[])
{
    int n = 28;
    isHappy(n);
}
