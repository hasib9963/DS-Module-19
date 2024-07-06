#include <bits/stdc++.h>
using namespace std;

// Following is the TreeNode class structure

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Function to determine the level of a node with the given value
int nodeLevel(TreeNode<int> *root, int searchedValue)
{
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
        pair<TreeNode<int> *, int> pr = q.front();
        TreeNode<int> *node = pr.first;
        int level = pr.second;
        q.pop();

        if (node->val == searchedValue)
        {
            return level;
        }
        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }
    return -1; // If the node is not found, return -1
}

// Function to create a predefined binary tree
// TreeNode<int> *createPredefinedBinaryTree()
// {
//     TreeNode<int> *root = new TreeNode<int>(1);
//     root->left = new TreeNode<int>(2);
//     root->right = new TreeNode<int>(3);
//     root->left->left = new TreeNode<int>(4);
//     root->left->right = new TreeNode<int>(5);
//     root->right->right = new TreeNode<int>(6);
//     root->left->left->left = new TreeNode<int>(7);
//     return root;
// }

// Function to create a binary tree from user input
TreeNode<int>* createBinaryTree() {
    int data;
    cout << "Enter the value for the root node: ";
    cin >> data;

    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();

        cout << "Enter left child of " << node->val << " (-1 for no left child): ";
        cin >> data;
        if (data != -1) {
            node->left = new TreeNode<int>(data);
            q.push(node->left);
        }

        cout << "Enter right child of " << node->val << " (-1 for no right child): ";
        cin >> data;
        if (data != -1) {
            node->right = new TreeNode<int>(data);
            q.push(node->right);
        }
    }

    return root;
}

// Function to delete the binary tree and free memory
void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function to test the nodeLevel function
int main()
{
    // TreeNode<int> *root = createPredefinedBinaryTree();
    
    cout << "Create your binary tree:" << endl;
    TreeNode<int>* root = createBinaryTree();

    int searchedValue;
    cout << "Enter the value to search for: ";
    cin >> searchedValue;

    int level = nodeLevel(root, searchedValue);
    if (level != -1)
    {
        cout << "Node with value " << searchedValue << " is at level " << level << "." << endl;
    }
    else
    {
        cout << "Node with value " << searchedValue << " is not present in the tree." << endl;
    }

    deleteTree(root);
    return 0;
}
