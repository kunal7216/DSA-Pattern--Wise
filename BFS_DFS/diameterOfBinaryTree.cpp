// find diameter of binary tree
// link: https://leetcode.com/problems/diameter-of-binary-tree/

**************************************************************Brute Solution***********************************************************************************


class Solution {
public:
    // Function to calculate height of a tree
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    // Brute force diameter function
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Diameter passing through current root
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int currentDiameter = leftHeight + rightHeight;

        // Diameter completely inside left subtree
        int leftDiameter = diameterOfBinaryTree(root->left);

        // Diameter completely inside right subtree
        int rightDiameter = diameterOfBinaryTree(root->right);

        // Maximum of all three possibilities
        return max(currentDiameter, max(leftDiameter, rightDiameter));
    }
};
**************************************************************Better Solution***********************************************************************************


class Solution {
public:
    unordered_map<TreeNode*, int> heightMap;

    // Store height of every node
    int calculateHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        heightMap[root] = 1 + max(leftHeight, rightHeight);

        return heightMap[root];
    }

    // Traverse all nodes and calculate diameter
    void calculateDiameter(TreeNode* root, int &diameter) {
        if (root == nullptr) {
            return;
        }

        int leftHeight = 0;
        int rightHeight = 0;

        if (root->left != nullptr) {
            leftHeight = heightMap[root->left];
        }

        if (root->right != nullptr) {
            rightHeight = heightMap[root->right];
        }

        diameter = max(diameter, leftHeight + rightHeight);

        calculateDiameter(root->left, diameter);
        calculateDiameter(root->right, diameter);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        calculateHeight(root);

        int diameter = 0;
        calculateDiameter(root, diameter);

        return diameter;
    }
};
**************************************************************Optimal Solution***********************************************************************************
  

class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Get height of left subtree
        int leftHeight = height(root->left);

        // Get height of right subtree
        int rightHeight = height(root->right);

        // Diameter passing through current node
        int currentDiameter = leftHeight + rightHeight;

        // Update maximum diameter
        diameter = max(diameter, currentDiameter);

        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
