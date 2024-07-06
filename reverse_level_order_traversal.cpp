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

// Function to perform reverse level order traversal
vector<int> reverseLevelOrder(TreeNode<int> *root)
{
    vector<int> v;
    queue<TreeNode<int> *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();
        v.push_back(node->val);
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    reverse(v.begin(), v.end());
    return v;
}

// Function to create a predefined binary tree
// TreeNode<int> *createPredefinedTree()
// {
//     TreeNode<int> *root = new TreeNode<int>(1);
//     root->left = new TreeNode<int>(2);
//     root->right = new TreeNode<int>(3);
//     root->left->left = new TreeNode<int>(4);
//     root->left->right = new TreeNode<int>(5);
//     root->right->right = new TreeNode<int>(6);
//     return root;
// }

// Function to create a binary tree from user input
TreeNode<int> *createBinaryTree()
{
    int data;
    cout << "Enter the value for the root node: ";
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();

        cout << "Enter left child of " << node->val << " (-1 for no left child): ";
        cin >> data;
        if (data != -1)
        {
            node->left = new TreeNode<int>(data);
            q.push(node->left);
        }

        cout << "Enter right child of " << node->val << " (-1 for no right child): ";
        cin >> data;
        if (data != -1)
        {
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

// Main function to test the reverseLevelOrder function
int main()
{
    // Create a predefined binary tree
    // TreeNode<int> *root = createPredefinedTree();

    // Create a binary tree by user
    cout << "Create your binary tree:" << endl;
    TreeNode<int> *root = createBinaryTree();

    // Perform reverse level order traversal
    vector<int> result = reverseLevelOrder(root);

    // Print the result
    cout << "Reverse Level Order Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    deleteTree(root);
    return 0;
}
