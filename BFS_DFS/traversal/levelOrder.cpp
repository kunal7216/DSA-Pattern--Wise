// level order traversal of a binary tree using BFS
// leetcode problem: https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> result; // Stores final level-wise traversal

        // Edge case: empty tree
        if (root == nullptr)
            return result;

        queue<TreeNode *> q; // Queue for BFS
        q.push(root);        // Start with root node

        // Continue until all levels are processed
        while (!q.empty())
        {

            int levelSize = q.size(); // Number of nodes in current level
            vector<int> level;        // Stores values of current level

            // Process all nodes of the current level
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // Add current node's value to level
                level.push_back(node->val);

                // Push left child if it exists
                if (node->left != nullptr)
                    q.push(node->left);

                // Push right child if it exists
                if (node->right != nullptr)
                    q.push(node->right);
            }

            // Add current level to result
            result.push_back(level);
        }

        return result;
    }
};
