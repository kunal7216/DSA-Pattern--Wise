// lowest Common ancestor in a Binary Tree
// leetcode problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // Base case:
        // If root is null OR root matches p or q,
        // return root because it may be an ancestor
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        // Recursively search in left and right subtrees
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // If p and q are found in different subtrees,
        // current root is the lowest common ancestor
        if (left != nullptr && right != nullptr)
        {
            return root;
        }

        // If p and q are both in left subtree
        if (left != nullptr)
        {
            return left;
        }

        // If p and q are both in right subtree
        return right;
    }
};
