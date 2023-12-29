#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

class TreeTraversal
{
public:
    static void preOrder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    static void postOrder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }

    static void inOrder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
};

int main()
{
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);

    cout << "Preorder traversal: ";
    TreeTraversal::preOrder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    TreeTraversal::postOrder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    TreeTraversal::inOrder(root);
    cout << endl;

    // Clean up memory (deallocate the dynamically allocated nodes)
    // This is important to avoid memory leaks
    delete root->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

//    12
//  7      1
// 4     10   5

// Preorder traversal: 12 7 4 1 10 5
// Postorder traversal: 4 7 10 5 1 12
// Inorder traversal: 4 7 12 10 1 5
