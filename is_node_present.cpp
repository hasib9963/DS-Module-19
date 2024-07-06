#include <bits/stdc++.h>
using namespace std;

// Definition of the BinaryTreeNode class
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to check if a node with a given value is present in the tree
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    // Base case
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    bool l = isNodePresent(root->left, x);
    bool r = isNodePresent(root->right, x);
    return (l || r);
}

// Function to create a predefined binary tree
BinaryTreeNode<int> *createPredefinedBinaryTree()
{
    // Creating nodes
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(6);
    root->left->left->left = new BinaryTreeNode<int>(7);

    // The tree looks like this:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6
    //   /
    //  7

    return root;
}

// Function to delete the binary tree and free memory
void deleteTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function to test the isNodePresent function
int main()
{
    BinaryTreeNode<int> *root = createPredefinedBinaryTree();

    int x;
    cout << "Enter the value to search for: ";
    cin >> x;

    if (isNodePresent(root, x))
    {
        cout << "Node with value " << x << " is present in the tree." << endl;
    }
    else
    {
        cout << "Node with value " << x << " is not present in the tree." << endl;
    }

    deleteTree(root);
    return 0;
}
