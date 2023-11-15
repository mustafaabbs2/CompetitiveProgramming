#include<iostream>
#include<queue>
#include<deque>

// To do a reverse level order, you just need to add your items in the reverse order - i.e. so the last thing you add comes first. This can be done with a deque, where you add to the front. Insertion and deletion can happen from both ends.

using namespace std;

class TreeNode{
public:

int val = 0;
TreeNode *left;
TreeNode *right;

TreeNode(int x)
{
    val = x;
    left = right = nullptr;
}

};


class ReverseLevelOrderTraversal {

public:
static deque<vector<int>> traverse(TreeNode *root) { 
    deque<vector<int>> result = deque<vector<int>>();


    if (root == nullptr) {
        return result;
    }

    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        int levelSize = queue.size();
        vector<int> currentLevel;
        
        for(int i = 0; i < levelSize; i++)
        {
            TreeNode *currentNode = queue.front();
            queue.pop();
            currentLevel.push_back(currentNode->val);
            if (currentNode->right != nullptr) {
                queue.push(currentNode->right);
            }
            if (currentNode->left != nullptr) {
                queue.push(currentNode->left);
            }
        }

        result.push_front(currentLevel);
    }

    return result;

    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  auto result = ReverseLevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}


//  9  10  5
//    7  1 
//     12  