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
    int pathSum(TreeNode* root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // Start the traversal from each node
        int pathsFromRoot = countPathsFromNode(root, sum);
        int pathsFromLeft = pathSum(root->left, sum);
        int pathsFromRight = pathSum(root->right, sum);

        return pathsFromRoot + pathsFromLeft + pathsFromRight;
    }

private:
    int countPathsFromNode(TreeNode* node, int targetSum)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int paths = 0;

        // Check if the current node itself forms a path
        if (node->val == targetSum)
        {
            paths++;
        }

        // Recursively explore paths including the current node
        paths += countPathsFromNode(node->left, targetSum - node->val);
        paths += countPathsFromNode(node->right, targetSum - node->val);

        return paths;
    }
};

int main()
{
    // Example usage:
    // Create a binary tree:  10
    //                      /    \
    //                     5     -3
    //                    / \      \
    //                   3   2     11
    //                  / \   \
    //                 3  -2   1

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution solution;
    int targetSum = 8;
    int result = solution.pathSum(root, targetSum);

    cout << "Number of paths with sum " << targetSum << ": " << result << endl;

    // Clean up memory (deallocate the dynamically allocated nodes)
    // This is important to avoid memory leaks
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
