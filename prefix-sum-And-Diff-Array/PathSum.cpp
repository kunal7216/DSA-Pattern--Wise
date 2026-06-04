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

********************************************************************Brute Solution*********************************************************************************

class Solution {
public:
    bool found = false;

    void dfs(TreeNode* root, int targetSum, int currentSum) {
        // If current node is null, return
        if (root == nullptr) {
            return;
        }

        // Add current node value to path sum
        currentSum += root->val;

        // If current node is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            // Check whether path sum equals targetSum
            if (currentSum == targetSum) {
                found = true;
            }
            return;
        }

        // Explore left subtree
        dfs(root->left, targetSum, currentSum);

        // Explore right subtree
        dfs(root->right, targetSum, currentSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0);
        return found;
    }
};
********************************************************************Better Solution*********************************************************************************

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Empty tree has no root-to-leaf path
        if (root == nullptr) {
            return false;
        }

        // If current node is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            // Leaf value should be equal to remaining target
            return root->val == targetSum;
        }

        // Search in left subtree with reduced target
        bool leftAns = hasPathSum(root->left, targetSum - root->val);

        // Search in right subtree with reduced target
        bool rightAns = hasPathSum(root->right, targetSum - root->val);

        // If either side has a valid path, return true
        return leftAns || rightAns;
    }
};
********************************************************************Optimal SOlution*********************************************************************************

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Empty tree has no root-to-leaf path
        if (root == nullptr) {
            return false;
        }

        // Stack stores {node, sum from root to this node}
        stack<pair<TreeNode*, int>> st;

        // Start from root
        st.push({root, root->val});

        while (!st.empty()) {
            auto current = st.top();
            st.pop();

            TreeNode* node = current.first;
            int currentSum = current.second;

            // If current node is a leaf node
            if (node->left == nullptr && node->right == nullptr) {
                // Check if root-to-leaf sum equals targetSum
                if (currentSum == targetSum) {
                    return true;
                }
            }

            // Push right child with updated sum
            if (node->right != nullptr) {
                st.push({node->right, currentSum + node->right->val});
            }

            // Push left child with updated sum
            if (node->left != nullptr) {
                st.push({node->left, currentSum + node->left->val});
            }
        }

        // No valid path found
        return false;
    }
};
