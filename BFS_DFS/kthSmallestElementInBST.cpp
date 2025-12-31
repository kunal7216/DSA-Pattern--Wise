// Kth smallest element in a BST
// leetcode: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    int count = 0;   // Keeps track of how many nodes have been visited so far
    int result = -1; // Stores the kth smallest value once found

    // Inorder traversal function
    void inorder(TreeNode *root, int k)
    {
        // Base case: if the node is null, return
        if (root == nullptr)
            return;

        // Step 1: Traverse the left subtree
        inorder(root->left, k);

        // Step 2: Visit the current node
        count++; // Increment count when visiting a node

        // If the current node is the kth visited node
        if (count == k)
        {
            result = root->val; // Store the answer
            return;             // Stop further traversal
        }

        // Step 3: Traverse the right subtree
        inorder(root->right, k);
    }

    // Main function called by LeetCode
    int kthSmallest(TreeNode *root, int k)
    {
        // Perform inorder traversal
        inorder(root, k);

        // Return the stored kth smallest value
        return result;
    }
};
