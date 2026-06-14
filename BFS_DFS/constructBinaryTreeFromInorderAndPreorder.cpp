// consturct binary tree from inorder and preorder traversals
//// leetcode 105

*********************************************************Brute Solution*****************************************************************************************
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int preorderIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        // Base case: no elements left
        if (inStart > inEnd) {
            return nullptr;
        }

        // First unused preorder element is root
        int rootVal = preorder[preorderIndex];
        preorderIndex++;

        TreeNode* root = new TreeNode(rootVal);

        // Brute force linear search in inorder
        int rootIndex = inStart;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        // Build left subtree first because preorder is Root -> Left -> Right
        root->left = build(preorder, inorder, inStart, rootIndex - 1);

        // Build right subtree
        root->right = build(preorder, inorder, rootIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        int n = preorder.size();

        return build(preorder, inorder, 0, n - 1);
    }
};
*********************************************************Better Solution*****************************************************************************************
    class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = 0;

        // Find root in inorder
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        // Inorder split
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

        int leftSize = leftInorder.size();

        // Preorder split
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};
*********************************************************Optimal Solution*****************************************************************************************
    class Solution {
public:
    int preorderIndex;
    unordered_map<int, int> inorderIndex;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        // No nodes in this range
        if (inStart > inEnd) {
            return nullptr;
        }

        // Current preorder element is root
        int rootVal = preorder[preorderIndex];
        preorderIndex++;

        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder in O(1)
        int rootIndex = inorderIndex[rootVal];

        // Left subtree is before root in inorder
        root->left = build(preorder, inStart, rootIndex - 1);

        // Right subtree is after root in inorder
        root->right = build(preorder, rootIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        inorderIndex.clear();

        int n = inorder.size();

        // Store value -> index mapping of inorder
        for (int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(preorder, 0, n - 1);
    }
};
