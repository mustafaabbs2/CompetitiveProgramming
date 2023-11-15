// Write a function that takes a string s as input and checks whether it’s a
// palindrome or not.

// A B C D B A is not

// A B C B A is

#include <iostream>
#include <string>

class Palindrome
{

public:
    static bool ValidPalindrome(const std::string& str)
    {
        int low, high;

        low = 0;
        high = str.length() - 1;

        while (low < high)
        {
            if (str[low] != str[high])
                return false;

            low++;
            high--;
        }

        return true;
    }
};

int main()
{
    auto print = [](bool result)
    {
        if (result)
            std::cout << "Yes, it's a palindrome" << std::endl;
        else
            std::cout << "Nope!" << std::endl;
    };

    // Checking for palindromes
    bool result = Palindrome::ValidPalindrome("ABCBA");
    print(result);

    result = Palindrome::ValidPalindrome("ABCBAD");
    print(result);

    result = Palindrome::ValidPalindrome("a bc d cb a");
    print(result);

    result = Palindrome::ValidPalindrome("racecar");
    print(result);

    return 0;
}