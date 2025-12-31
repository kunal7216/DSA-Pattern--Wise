// postorder traversal of a binary tree using DFS (Depth-First Search)
// leetcode problem: https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;      // Stores postorder traversal result
        postorder(root, res); // Call helper function
        return res;           // Return final result
    }

private:
    void postorder(TreeNode *root, vector<int> &result)
    {
        // Base case: if the current node is null, stop recursion
        if (root == nullptr)
            return;

        // Step 1: Traverse the left subtree
        postorder(root->left, result);

        // Step 2: Traverse the right subtree
        postorder(root->right, result);

        // Step 3: Visit the root node
        result.push_back(root->val);
    }
};
