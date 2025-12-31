// preorder traversal of a binary tree using DFS (Depth-First Search)
// leetcode problem: https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;     // Vector to store preorder result
        preorder(root, res); // Call helper function
        return res;          // Return final traversal
    }

private:
    void preorder(TreeNode *root, vector<int> &result)
    {
        // Base case: if the current node is null, stop recursion
        if (root == nullptr)
            return;

        // Step 1: Visit the root node first
        result.push_back(root->val);

        // Step 2: Traverse the left subtree
        preorder(root->left, result);

        // Step 3: Traverse the right subtree
        preorder(root->right, result);
    }
};
