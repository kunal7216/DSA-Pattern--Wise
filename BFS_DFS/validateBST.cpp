// validate binary search tree
// leetcode problem: https://leetcode.com/problems/validate-binary-search-tree/

class Solution
{
public:
    // Helper function to validate BST using min/max bounds
    bool helper(TreeNode *root, TreeNode *min, TreeNode *max)
    {

        // Base case: empty subtree is valid
        if (root == nullptr)
        {
            return true;
        }

        // If current node violates the minimum constraint
        if (min != nullptr && root->val <= min->val)
            return false;

        // If current node violates the maximum constraint
        if (max != nullptr && root->val >= max->val)
            return false;

        // Recursively validate left and right subtrees
        // Left subtree: max bound becomes current node
        // Right subtree: min bound becomes current node
        return helper(root->left, min, root) &&
               helper(root->right, root, max);
    }

    bool isValidBST(TreeNode *root)
    {
        // Start recursion with no bounds
        return helper(root, nullptr, nullptr);
    }
};
