// Write a function that takes a string as input and checks whether it can be a
// valid palindrome by removing at most one character from it.

// Can “abbababa” be a palindrome? - yes if we remove the second 'b'

#include <iostream>
#include <string>

class Palindrome
{

public:
    static bool ValidPalindromeII(const std::string& str)
    {
        int low, high;

        low = 0;
        high = str.length() - 1;
        size_t count_miss = 0;

        while (low < high)
        {
            if (str[low] != str[high])
            {
                count_miss += 1;
                high--;
            }
            else
            {
                low++;
                high--;
            }
        }

        if (count_miss > 1)
            return false;
        else
            return true;
    }
};

int main()
{
    auto print = [](bool result)
    {
        if (result)
            std::cout << "Yes, it can be palindrome" << std::endl;
        else
            std::cout << "Nope!" << std::endl;
    };

    // Checking for palindromes

    bool result = Palindrome::ValidPalindromeII("ABCBAD");
    print(result);

    result = Palindrome::ValidPalindromeII("abbababa");
    print(result);

    result = Palindrome::ValidPalindromeII(
        "ognfjhgbjhzkqhzadmgqbwqsktzqwjexqvzjsopolnmvnymbbzoofzbbmynvmnloposjzv"
        "qxejwqztksqwbqgmdazhqkzhjbghjfno");
    print(result);

    return 0;
}