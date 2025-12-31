// Inorder traversal of a binary tree using DFS (recursive approach)
// leetcode problem: https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;    // Stores the inorder traversal result
        inorder(root, res); // Call helper function
        return res;         // Return final result
    }

private:
    void inorder(TreeNode *node, vector<int> &res)
    {
        // Base case: if the current node is null, stop recursion
        if (node == nullptr)
        {
            return;
        }

        // Step 1: Traverse the left subtree
        inorder(node->left, res);

        // Step 2: Visit the current node (Root)
        res.push_back(node->val);

        // Step 3: Traverse the right subtree
        inorder(node->right, res);
    }
};
