// lowest common ancestor in a binary search tree
// leetcode 235

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // Base case: if root is null, return null
        if (root == nullptr)
            return nullptr;

        // Store current node's value
        int curr = root->val;

        // If both p and q are greater than current node,
        // LCA must be in the right subtree
        if (curr < p->val && curr < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If both p and q are smaller than current node,
        // LCA must be in the left subtree
        if (curr > p->val && curr > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Otherwise, current node is the split point
        // This is the lowest common ancestor
        return root;
    }
};
