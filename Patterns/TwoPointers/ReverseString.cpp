// Given a sentence, reverse the order of its words without affecting the order
// of letters within a given word.

// Hello World => World Hello

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Reversal
{

public:
    // note: this a hacky solution, not using Two Pointers, but what works
    // works...
    static std::string ReverseWords(const std::string& str)
    {
        std::string result;
        std::vector<std::string> sentence;
        std::istringstream iss(str);
        std::string word;

        while (iss >> word)
            sentence.push_back(word);

        std::reverse(sentence.begin(), sentence.end());

        for (auto w : sentence)
        {
            result += w + " ";
        }

        return result;
    }
};

int main()
{
    auto print = [](std::string string)
    {
        std::cout << "The OG string was " << string << std::endl;
        std::string result = Reversal::ReverseWords(string);
        std::cout << "The new string is " << result << std::endl;
    };

    print("ABCDEF 12334 Mustafa Hello Yakuta");

    return 0;
}