// find diameter of binary tree
// link: https://leetcode.com/problems/diameter-of-binary-tree/

class Solution
{
public:
    // Main function that returns the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        // Start DFS to compute height and update diameter
        height(root, diameter);
        return diameter;
    }

private:
    // Helper function to compute height of the tree
    // At the same time, it updates the diameter
    int height(TreeNode *node, int &diameter)
    {
        // Base case: empty subtree has height 0
        if (!node)
        {
            return 0;
        }

        // Recursively compute height of left subtree
        int leftHeight = height(node->left, diameter);

        // Recursively compute height of right subtree
        int rightHeight = height(node->right, diameter);

        // The diameter passing through this node is
        // left subtree height + right subtree height
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of current node
        // 1 for current node + max of left/right subtree height
        return 1 + max(leftHeight, rightHeight);
    }
};
