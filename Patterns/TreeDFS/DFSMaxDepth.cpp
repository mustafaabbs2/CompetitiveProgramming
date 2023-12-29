#include <algorithm>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // The maximum depth is the maximum of the left and right subtrees plus
        // 1 for the current node.
        return 1 + max(leftDepth, rightDepth);
    }
};

int main()
{
    // Example usage:
    // Create a binary tree:  3
    //                       / \
    //                      9  20
    //                        /  \
    //                       15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int depth = solution.maxDepth(root);

    cout << "Maximum Depth of Binary Tree: " << depth << endl;

    // Clean up memory (deallocate the dynamically allocated nodes)
    // This is important to avoid memory leaks
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
