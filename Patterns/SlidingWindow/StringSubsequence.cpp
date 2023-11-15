// Given strings str1 and str2, find the minimum (contiguous) substring subStr
// of str1, such that every character of str2 appears in subStr in the same
// order as it is present in str2.

#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string MinWindow(std::string str1, std::string str2)
{
    // Save the length of str1 and str2
    int sizeStr1 = str1.length(), sizeStr2 = str2.length();
    // Initialize length to a very large number (infinity)
    int length = INT_MAX;
    // Initialize pointers to zero and the min_subsequence to an empty string
    int indexS1 = 0, indexS2 = 0;
    std::string minSubsequence = "";

    // Process every character of str1
    while (indexS1 < sizeStr1)
    {
        // Check if the character pointed by indexS1 in str1
        // is the same as the character pointed by indexS2 in str2
        if (str1[indexS1] == str2[indexS2])
        {
            // If the pointed character is the same
            // in both strings increment indexS2
            indexS2 += 1;
            // Check if indexS2 has reached the end of str2
            if (indexS2 == sizeStr2)
            {
                // At this point the str1 contains all characters of str2
                int start = indexS1, end = indexS1 + 1;
                // Initialize start to the index where all characters of
                // str2 were present in str1
                indexS2 -= 1;
                // Decrement pointer indexS2 and start a reverse loop
                while (indexS2 >= 0)
                {
                    // Decrement pointer indexS2 until all characters of
                    //  str2 are found in str1
                    if (str1[start] == str2[indexS2])
                    {
                        indexS2 -= 1;
                    }
                    // Decrement start pointer everytime to find the
                    // starting point of the required subsequence
                    start -= 1;
                }
                start += 1;
                // Check if length of sub sequence pointed
                // by start and end pointers is less than current min length
                if (end - start < length)
                {
                    // Update length if current sub sequence is shorter
                    length = end - start;
                    // Update minimum subsequence string
                    // to this new shorter string
                    minSubsequence = str1.substr(start, length);
                }
                // Set indexS1 to start to continue checking in str1
                // after this discovered subsequence
                indexS1 = start;
                indexS2 = 0;
            }
        }
        // Increment pointer indexS1 to check next character in str1
        indexS1 += 1;
    }
    return minSubsequence;
}

int main()
{
    std::vector<std::string> str1 = {"abcdebdde", "fgrqsqsnodwmxzkzxwqegkndaa",
                                     "qwewerrty", "aaabbcbq",
                                     "zxcvnhss",  "alpha",
                                     "beta",      "asd",
                                     "abcd"};

    std::vector<std::string> str2 = {"bde", "kzed", "werty", "abc", "css",
                                     "la",  "ab",   "as",    "pp"};

    for (int i = 0; i < str1.size(); i++)
    {
        std::cout << (i + 1) << ".\tInput strings: (" << str1[i] << ", "
                  << str2[i] << ")" << std::endl;
        std::cout << "\tSubsequence string: " << MinWindow(str1[i], str2[i])
                  << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
}