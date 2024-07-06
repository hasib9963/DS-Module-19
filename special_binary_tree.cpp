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

// Function to create a binary tree from user input
BinaryTreeNode<int>* createBinaryTree() {
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;

    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();

        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode->data << " (-1 for NULL): ";
        cin >> leftChild;

        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cout << "Enter right child of " << currentNode->data << " (-1 for NULL): ";
        cin >> rightChild;

        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

// Function to delete the binary tree and free memory
void deleteTree(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Function to create a sample binary tree and test the isSpecialBinaryTree function
int main() {
    // Create a sample binary tree
    BinaryTreeNode<int>* root = createBinaryTree();
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // root->left = new BinaryTreeNode<int>(2);
    // root->right = new BinaryTreeNode<int>(3);
    // root->left->left = new BinaryTreeNode<int>(4);
    // root->left->right = new BinaryTreeNode<int>(5);
    // root->right->left = new BinaryTreeNode<int>(6);
    // root->right->right = new BinaryTreeNode<int>(7);

    // Test the isSpecialBinaryTree function
    if (isSpecialBinaryTree(root)) {
        cout << "The binary tree is a special binary tree (full binary tree)." << endl;
    } else {
        cout << "The binary tree is not a special binary tree (full binary tree)." << endl;
    }

    // Clean up the allocated memory
    // delete root->left->left;
    // delete root->left->right;
    // delete root->left;
    // delete root->right->left;
    // delete root->right->right;
    // delete root->right;
    // delete root;

    deleteTree(root);
    return 0;
}
