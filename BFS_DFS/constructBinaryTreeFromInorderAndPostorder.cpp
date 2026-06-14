// construct binary tree from inorder and postorder traversals
//// leetcode 106

**********************************************************Brute Solution****************************************************************************************


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        int rootVal = postorder.back();
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = 0;

        // Search root in inorder
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        // Split inorder
        vector<int> leftInorder(
            inorder.begin(),
            inorder.begin() + rootIndex
        );

        vector<int> rightInorder(
            inorder.begin() + rootIndex + 1,
            inorder.end()
        );

        // Split postorder
        vector<int> leftPostorder(
            postorder.begin(),
            postorder.begin() + leftInorder.size()
        );

        vector<int> rightPostorder(
            postorder.begin() + leftInorder.size(),
            postorder.end() - 1
        );

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};
**********************************************************Better Solution****************************************************************************************


class Solution {
public:
    unordered_map<int, int> inorderIndex;

    TreeNode* solve(
        vector<int>& inorder,
        vector<int>& postorder,
        int inStart,
        int inEnd,
        int postStart,
        int postEnd
    ) {
        // Base case: no nodes in this subtree
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // Last element in postorder is root
        int rootVal = postorder[postEnd];

        TreeNode* root = new TreeNode(rootVal);

        // Get root index in inorder in O(1)
        int rootIndex = inorderIndex[rootVal];

        // Number of nodes in left subtree
        int leftSize = rootIndex - inStart;

        // Build left subtree
        root->left = solve(
            inorder,
            postorder,
            inStart,
            rootIndex - 1,
            postStart,
            postStart + leftSize - 1
        );

        // Build right subtree
        root->right = solve(
            inorder,
            postorder,
            rootIndex + 1,
            inEnd,
            postStart + leftSize,
            postEnd - 1
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        // Store inorder index of every value
        for (int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }

        return solve(
            inorder,
            postorder,
            0,
            n - 1,
            0,
            n - 1
        );
    }
};
**********************************************************Optimal Solution***************************************************************************************

class Solution {
public:
    unordered_map<int, int> inorderIndex;

    TreeNode* solve(
        vector<int>& inorder,
        vector<int>& postorder,
        int inStart,
        int inEnd,
        int postStart,
        int postEnd
    ) {
        // Base case: no nodes in this subtree
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // Last element in postorder is root
        int rootVal = postorder[postEnd];

        TreeNode* root = new TreeNode(rootVal);

        // Get root index in inorder in O(1)
        int rootIndex = inorderIndex[rootVal];

        // Number of nodes in left subtree
        int leftSize = rootIndex - inStart;

        // Build left subtree
        root->left = solve(
            inorder,
            postorder,
            inStart,
            rootIndex - 1,
            postStart,
            postStart + leftSize - 1
        );

        // Build right subtree
        root->right = solve(
            inorder,
            postorder,
            rootIndex + 1,
            inEnd,
            postStart + leftSize,
            postEnd - 1
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        // Store inorder index of every value
        for (int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }

        return solve(
            inorder,
            postorder,
            0,
            n - 1,
            0,
            n - 1
        );
    }
};
