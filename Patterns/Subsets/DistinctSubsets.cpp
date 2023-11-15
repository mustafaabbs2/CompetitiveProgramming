
#include <iostream>
#include <vector>

using namespace std;
// Use BFS
// Given set: [1, 5, 3]

// Start with an empty set: [[]]
// Add the first number (1) to all the existing subsets to create new subsets: [[], [1]];
// Add the second number (5) to all the existing subsets: [[], [1], [5], [1,5]];
// Add the third number (3) to all the existing subsets: [[], [1], [5], [1,5], [3], [1,3], [5,3], [1,5,3]].


class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;

     subsets.push_back(vector<int>());
    // subsets.push_back(vector<int>());


    for (auto number : nums) // 1 , 5 , 3
    {
      size_t n = subsets.size(); //find the new size of the subset list 
      //for each number, add combinations of all the other numbers
      for (size_t i = 0; i < n; i++) //add that number to all the subsets 
      {
        vector<int> set(subsets[i]); //initialize set with the values from subset[i]  
        set.push_back(number);//every number will be added to a new set
        subsets.push_back(set); //add to the subsets
        
      }

    }
    return subsets;
  }

};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3, 1});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}