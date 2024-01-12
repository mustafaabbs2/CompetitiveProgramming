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
    int goodNodes(TreeNode* root)
    {
        return countGoodNodes(
            root, INT_MIN); // Initialize with the minimum possible value
    }

private:
    int countGoodNodes(TreeNode* node, int maxValueSoFar)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int count = (node->val >= maxValueSoFar) ? 1 : 0;

        // Update maxValueSoFar for the child nodes in the path
        maxValueSoFar = max(maxValueSoFar, node->val);

        // Recursive calls for left and right subtrees
        count += countGoodNodes(node->left, maxValueSoFar);
        count += countGoodNodes(node->right, maxValueSoFar);

        return count;
    }
};

int main()
{
    // Example usage:
    // Tree:     3
    //          / \
    //         1   4
    //        / \ / \
    //       3  1 5  9

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(9);

    Solution solution;
    int count = solution.goodNodes(root);

    cout << "Number of good nodes in the binary tree: " << count << endl;

    // Clean up memory (deallocate the dynamically allocated nodes)
    // This is important to avoid memory leaks
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
