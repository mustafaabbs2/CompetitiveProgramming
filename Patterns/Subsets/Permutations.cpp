using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// Input: [1,3,5]
// Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]
class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> result;
    queue<vector<int>> permutations;
    permutations.push(vector<int>());
    for (auto currentNumber : nums) {
      // we will take all existing permutations and add the current number to create new
      // permutations
      int n = permutations.size();
      for (int i = 0; i < n; i++) {
        vector<int> oldPermutation = permutations.front();  //[5 3 1]
        permutations.pop();
        // create a new permutation by adding the current number at every position
        for (int j = 0; j <= oldPermutation.size(); j++) {
          vector<int> newPermutation(oldPermutation);
          newPermutation.insert(newPermutation.begin() + j, currentNumber); //inserts element "currentNumber" at specified location
          if (newPermutation.size() == nums.size()) { //nums.size = 3
            result.push_back(newPermutation);
          } else {
            permutations.push(newPermutation); //keep adding to the permutation 
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}