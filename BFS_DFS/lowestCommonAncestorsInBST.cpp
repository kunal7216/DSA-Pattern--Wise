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

***********************************************************Brute Solution************************************************************************************
    class Solution {
public:
    TreeNode* answer = NULL;

    // Function to check whether target exists in subtree rooted at root
    bool contains(TreeNode* root, TreeNode* target) {
        if (root == NULL) {
            return false;
        }

        if (root == target) {
            return true;
        }

        return contains(root->left, target) || contains(root->right, target);
    }

    // DFS over every node
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return;
        }

        // If current node's subtree contains both p and q,
        // then current node can be an ancestor
        if (contains(root, p) && contains(root, q)) {
            answer = root;
        }

        dfs(root->left, p, q);
        dfs(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return answer;
    }
};
***********************************************************Better Solution*************************************************************************************
    class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        // Both nodes lie in left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Both nodes lie in right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Current root is the split point
        return root;
    }
};
***********************************************************Optimal Solution************************************************************************************
    class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        // Both nodes lie in left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Both nodes lie in right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Current root is the split point
        return root;
    }
};
