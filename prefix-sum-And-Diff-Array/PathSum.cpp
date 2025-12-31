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

    // DFS helper to check if any root-to-leaf path sums to target
    bool hasPathSumHelper(TreeNode *root, int maxSum, int &targetSum)
    {
        if (!root)
        {
            return false; // invalid path beyond leaf
        }

        // accumulate current node value
        maxSum += root->val;

        // if leaf, check if final path sum matches target
        if (!root->left && !root->right)
        {
            return maxSum == targetSum;
        }

        // recursively search left and right paths
        bool left = hasPathSumHelper(root->left, maxSum, targetSum);
        bool right = hasPathSumHelper(root->right, maxSum, targetSum);

        // true if any subtree has valid path
        return left || right;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return hasPathSumHelper(root, 0, targetSum);
    }
};