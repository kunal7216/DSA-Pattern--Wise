// Kth smallest element in a BST
// leetcode: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
public:
    int count = 0;   // Keeps track of how many nodes have been visited so far
    int result = -1; // Stores the kth smallest value once found

    // Inorder traversal function
    void inorder(TreeNode *root, int k)
    {
        // Base case: if the node is null, return
        if (root == nullptr)
            return;

        // Step 1: Traverse the left subtree
        inorder(root->left, k);

        // Step 2: Visit the current node
        count++; // Increment count when visiting a node

        // If the current node is the kth visited node
        if (count == k)
        {
            result = root->val; // Store the answer
            return;             // Stop further traversal
        }

        // Step 3: Traverse the right subtree
        inorder(root->right, k);
    }

    // Main function called by LeetCode
    int kthSmallest(TreeNode *root, int k)
    {
        // Perform inorder traversal
        inorder(root, k);

        // Return the stored kth smallest value
        return result;
    }
};


******************************************************************Brute Solution********************************************************************************
    class Solution {
public:
    void dfs(TreeNode* root, vector<int>& values) {
        if (root == NULL) return;

        values.push_back(root->val);
        dfs(root->left, values);
        dfs(root->right, values);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;

        dfs(root, values);

        sort(values.begin(), values.end());

        return values[k - 1];
    }
};
******************************************************************Better Solution********************************************************************************
    class Solution {
public:
    void inorder(TreeNode* root, vector<int>& values) {
        if (root == NULL) return;

        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;

        inorder(root, values);

        return values[k - 1];
    }
};
******************************************************************Optimal Solution********************************************************************************
    class Solution {
public:
    int count = 0;
    int answer = -1;

    void inorder(TreeNode* root, int k) {
        if (root == NULL) return;

        // If answer already found, stop further recursion
        if (answer != -1) return;

        inorder(root->left, k);

        if (answer != -1) return;

        count++;

        if (count == k) {
            answer = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return answer;
    }
};
