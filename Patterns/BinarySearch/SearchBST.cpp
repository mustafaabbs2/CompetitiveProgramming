#include <iostream>

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
    TreeNode* searchBST(TreeNode* root, int val)
    {
        // Base case: If the root is null or the value is found
        if (root == nullptr || root->val == val)
        {
            return root;
        }

        // If the value is less than the current node's value, search in the
        // left subtree
        if (val < root->val)
        {
            return searchBST(root->left, val);
        }

        // If the value is greater than the current node's value, search in the
        // right subtree
        return searchBST(root->right, val);
    }
};

int main()
{
    // Example usage:
    // Create a binary search tree:   4
    //                                / \
    //                               2   7
    //                              / \
    //                             1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;
    int targetValue = 2;
    TreeNode* result = solution.searchBST(root, targetValue);

    if (result != nullptr)
    {
        std::cout << "Node with value " << targetValue << " found in the BST."
                  << std::endl;
    }
    else
    {
        std::cout << "Node with value " << targetValue
                  << " not found in the BST." << std::endl;
    }

    // Clean up memory (deallocate the dynamically allocated nodes)
    // This is important to avoid memory leaks
    delete root->left->left;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
