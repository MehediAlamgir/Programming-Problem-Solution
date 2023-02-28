#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};


// find the depth of a binary tree
int findDepthofBT(Node* head)
{
    if (head == nullptr)
        return 0;

    int left = findDepthofBT(head->left);
    int right = findDepthofBT(head->right);

    return max(left,right)+1;
}

//InOrder traversal of a tree
void inOrderTraversal(Node* head)
{
    if (head == nullptr)
        return;
    inOrderTraversal(head->left);
    cout<<head->value<<" ";
    inOrderTraversal(head->right);
}

//Print out all leaf node of a binary tree
void printLeafNodes(Node* root) {
    if (!root) return; // base case
    if (!root->left && !root->right) {
        cout << root->value << " "; // print leaf node
    }
    printLeafNodes(root->left); // recursively check left subtree
    printLeafNodes(root->right); // recursively check right subtree
}

/*
Check if a Binary Tree is BST or not.
Here we define each node value range and check if node value fall under range or not.
Ref: https://afteracademy.com/blog/check-if-a-binary-tree-is-BST-or-not */

bool isBSTUtil(Node* root, int minValue, int maxValue)
{
    // an empty tree is BST
    if (root == nullptr)
        return true;

    // false if this node violates the min/max constraint
    if (root->value < minValue || root->value > maxValue)
        return false;

    // otherwise check the subtrees recursively, tightening the min or max constraint. Allow only distinct values
    return isBSTUtil(root->left, minValue, root->value-1) && isBSTUtil(root->right, root->value+1, maxValue);
}

bool isBST(Node* head)
{
    return isBSTUtil(head, INT_MIN, INT_MAX);
}

int main()
{
    // create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // find the depth of the binary tree
    int depth = findDepthofBT(root);
    cout << "Depth of the binary tree is: " << depth << endl;

    inOrderTraversal(root);

    return 0;
}
