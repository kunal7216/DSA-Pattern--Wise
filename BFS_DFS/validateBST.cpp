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

***********************************************************Brute Solution***********************************************************************************
    class Solution {
public:
    // Function to find maximum value in a subtree
    long long findMax(TreeNode* root) {
        if (root == NULL) {
            return LLONG_MIN;
        }

        long long leftMax = findMax(root->left);
        long long rightMax = findMax(root->right);

        return max((long long)root->val, max(leftMax, rightMax));
    }

    // Function to find minimum value in a subtree
    long long findMin(TreeNode* root) {
        if (root == NULL) {
            return LLONG_MAX;
        }

        long long leftMin = findMin(root->left);
        long long rightMin = findMin(root->right);

        return min((long long)root->val, min(leftMin, rightMin));
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        // Maximum value in left subtree should be smaller than root
        long long leftMax = findMax(root->left);

        // Minimum value in right subtree should be greater than root
        long long rightMin = findMin(root->right);

        if (leftMax >= root->val || rightMin <= root->val) {
            return false;
        }

        // Recursively check left and right subtree
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
***********************************************************Better Solution***********************************************************************************
    class Solution {
public:
    void inorder(TreeNode* root, vector<long long>& arr) {
        if (root == NULL) {
            return;
        }

        // Visit left subtree
        inorder(root->left, arr);

        // Store current node value
        arr.push_back(root->val);

        // Visit right subtree
        inorder(root->right, arr);
    }

    bool isValidBST(TreeNode* root) {
        vector<long long> arr;

        // Get inorder traversal
        inorder(root, arr);

        // Check if inorder traversal is strictly increasing
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }

        return true;
    }
};
***********************************************************Optimal Solution***********************************************************************************
class Solution {
public:
    bool validate(TreeNode* root, long long low, long long high) {
        // Empty tree is always valid
        if (root == NULL) {
            return true;
        }

        // Current node value must lie strictly between low and high
        if (root->val <= low || root->val >= high) {
            return false;
        }

        // Left subtree values must be smaller than current node value
        bool leftValid = validate(root->left, low, root->val);

        // Right subtree values must be greater than current node value
        bool rightValid = validate(root->right, root->val, high);

        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

