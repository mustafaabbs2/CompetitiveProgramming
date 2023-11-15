//         1
//     2           3
// 4       5    6      7

// Sum 10 = 1 + 3 + 6

//DFS can use either a stack or recursion ...
// Recursion works like a stack..


// Start DFS with the root of the tree.
// If the current node is not a leaf node, do two things:
// Subtract the value of the current node from the given number to get a new sum => S = S - node.value
// Make two recursive calls for both the children of the current node with the new number calculated in the previous step.
// At every step, see if the current node being visited is a leaf node and if its value is equal to the given number ‘S’. If both these conditions are true, we have found the required root-to-leaf path, therefore return true.
// If the current node is a leaf but its value is not equal to the given number ‘S’, return false.

using namespace std;

#include <iostream>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class TreePathSum {
 public:
  static bool hasPath(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }

    // if the current node is a leaf and its value is equal to the sum, we've found a path
    if (root->val == sum && root->left == nullptr && root->right == nullptr) {
      return true;
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
  }
};


int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
  cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;
}

// 12
// 7 1
// 9 10 5

// 12->1->10 = 23

// But 16 does not happen