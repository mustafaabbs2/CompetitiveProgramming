#include <iostream>
#include <stack>
#include <vector>

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }

private:
    void getLeaves(TreeNode* root, vector<int>& leaves)
    {
        if (root == nullptr)
        {
            return;
        }

        stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode* current = nodes.top();
            nodes.pop();

            if (current->left == nullptr && current->right == nullptr)
            {
                leaves.push_back(current->val);
            }

            if (current->right != nullptr)
            {
                nodes.push(current->right);
            }

            if (current->left != nullptr)
            {
                nodes.push(current->left);
            }
        }
    }
};

int main()
{
    // Example usage:
    // Tree 1:   3
    //          / \
    //         5   1
    //        / \ / \
    //       6  2 9  8
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);

    // Tree 2:   5
    //          / \
    //         6   7
    //        / \ / \
    //       6  2 9  8
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(6);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(2);
    root2->right->left = new TreeNode(9);
    root2->right->right = new TreeNode(8);

    Solution solution;
    bool isLeafSimilar = solution.leafSimilar(root1, root2);

    cout << "Are the trees leaf-similar? " << (isLeafSimilar ? "Yes" : "No")
         << endl;

    // Clean up memory (deallocate the dynamically allocated nodes)
    // This is important to avoid memory leaks
    delete root1->left->left;
    delete root1->left->right;
    delete root1->right->left;
    delete root1->right->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left;
    delete root2->left->right;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
