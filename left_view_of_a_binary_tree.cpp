#include <bits/stdc++.h>
using namespace std;

// Definition of the TreeNode class
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

// Function to get the left view of the binary tree
vector<int> getLeftView(TreeNode<int> *root)
{
    bool frq[3005] = {false};
    queue<pair<TreeNode<int> *, int>> q;
    if (root)
        q.push({root, 1});
    vector<int> v;
    while (!q.empty())
    {
        pair<TreeNode<int> *, int> pr = q.front();
        q.pop();
        TreeNode<int> *node = pr.first;
        int level = pr.second;

        if (frq[level] == false)
        {
            v.push_back(node->data);
            frq[level] = true;
        }

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    return v;
}

// Function to create a predefined binary tree
TreeNode<int> *createPredefinedBinaryTree()
{
    // Creating nodes
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->right = new TreeNode<int>(6);
    root->left->left->left = new TreeNode<int>(7);

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
void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function to test the getLeftView function
int main()
{
    // Creating nodes
    // TreeNode<int>* root = new TreeNode<int>(1);
    // call the TreeNode function
    TreeNode<int> *root = createPredefinedBinaryTree();
    // root->left = new TreeNode<int>(2);
    // root->right = new TreeNode<int>(3);
    // root->left->left = new TreeNode<int>(4);
    // root->left->right = new TreeNode<int>(5);
    // root->right->right = new TreeNode<int>(6);
    // root->left->left->left = new TreeNode<int>(7);

    // The tree looks like this:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6
    //   /
    //  7

    vector<int> leftView = getLeftView(root);

    cout << "Left view of the binary tree: ";
    for (int val : leftView)
    {
        cout << val << " ";
    }
    cout << endl;

    deleteTree(root);
    return 0;
}
