// Flatten Binary Tree to Linked List
// leetcode: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * This is the standard TreeNode structure used in LeetCode problems.
 */
// struct TreeNode
// {
//     int val;         // Value of the node
//     TreeNode *left;  // Pointer to left child
//     TreeNode *right; // Pointer to right child
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    TreeNode *nextRight = NULL; // Tracks the previously processed node during traversal

    // Recursive function to flatten the tree
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return; // Base case: if node is null, return
        }

        // Step 1: Recursively flatten the right subtree first
        flatten(root->right);

        // Step 2: Recursively flatten the left subtree
        flatten(root->left);

        // Step 3: Rewire pointers
        root->left = NULL;       // Set left child to NULL (as required in flattened tree)
        root->right = nextRight; // Point right child to previously processed node

        // Step 4: Update the previously processed node
        nextRight = root;
    }
};
