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

****************************************************************Brute Solution*****************************************************************************
    class Solution {
public:
    // Function to check whether target node exists in current subtree
    bool contains(TreeNode* root, TreeNode* target) {
        if (root == NULL) {
            return false;
        }

        if (root == target) {
            return true;
        }

        return contains(root->left, target) || contains(root->right, target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        // Check if both p and q exist in left subtree
        bool pInLeft = contains(root->left, p);
        bool qInLeft = contains(root->left, q);

        // If both are in left subtree, LCA must be in left subtree
        if (pInLeft && qInLeft) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Check if both p and q exist in right subtree
        bool pInRight = contains(root->right, p);
        bool qInRight = contains(root->right, q);

        // If both are in right subtree, LCA must be in right subtree
        if (pInRight && qInRight) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Otherwise, current node is the split point
        return root;
    }
};
****************************************************************Better Solution****************************************************************************
    class Solution {
public:
    void buildParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (root == NULL) {
            return;
        }

        if (root->left != NULL) {
            parent[root->left] = root;
            buildParent(root->left, parent);
        }

        if (root->right != NULL) {
            parent[root->right] = root;
            buildParent(root->right, parent);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;

        // Root has no parent
        parent[root] = NULL;

        // Store parent of every node
        buildParent(root, parent);

        unordered_set<TreeNode*> ancestors;

        // Store all ancestors of p
        TreeNode* curr = p;

        while (curr != NULL) {
            ancestors.insert(curr);
            curr = parent[curr];
        }

        // Move upward from q
        curr = q;

        while (curr != NULL) {
            if (ancestors.find(curr) != ancestors.end()) {
                return curr;
            }

            curr = parent[curr];
        }

        return NULL;
    }
};
****************************************************************Optimal Solution****************************************************************************
    class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case:
        // If root is NULL, return NULL
        if (root == NULL) {
            return NULL;
        }

        // If current node is either p or q,
        // return current node
        if (root == p || root == q) {
            return root;
        }

        // Search in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-NULL,
        // it means p and q are found on different sides
        if (left != NULL && right != NULL) {
            return root;
        }

        // If only left side has answer, return left
        if (left != NULL) {
            return left;
        }

        // If only right side has answer, return right
        return right;
    }
};
