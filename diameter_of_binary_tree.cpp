#include <bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int mx = 0;

int maxHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    int d = l + r;
    mx = max(mx, d);
    return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    mx = 0;
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    return max(mx, l + r);
}

int main() {
    // Create a sample binary tree
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);
    root->left->left->left = new TreeNode<int>(8);

    // Calculate and print the diameter of the binary tree
    cout << "Diameter of the binary tree is: " << diameterOfBinaryTree(root) << endl;

    // Clean up the allocated memory
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}