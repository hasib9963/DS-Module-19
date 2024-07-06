#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to check if a binary tree is a special binary tree (full binary tree)
bool isSpecialBinaryTree(BinaryTreeNode<int> *root) {
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left == NULL || root->right == NULL)
        return false;
    bool l = isSpecialBinaryTree(root->left);
    bool r = isSpecialBinaryTree(root->right);
    return l && r;
}

// Function to create a sample binary tree and test the isSpecialBinaryTree function
int main() {
    // Create a sample binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    // root->right = new BinaryTreeNode<int>(8);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    // Test the isSpecialBinaryTree function
    if (isSpecialBinaryTree(root)) {
        cout << "The binary tree is a special binary tree (full binary tree)." << endl;
    } else {
        cout << "The binary tree is not a special binary tree (full binary tree)." << endl;
    }

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
