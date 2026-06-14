// Flatten Binary Tree to Linked List
// leetcode: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


*************************************************************Brute Solution************************************************************************************
    class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == NULL) {
            return;
        }

        // Root
        nodes.push_back(root);

        // Left
        preorder(root->left, nodes);

        // Right
        preorder(root->right, nodes);
    }

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        vector<TreeNode*> nodes;

        // Step 1: Store preorder traversal
        preorder(root, nodes);

        // Step 2: Reconnect nodes like a linked list
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i + 1];
        }

        // Last node
        nodes.back()->left = NULL;
        nodes.back()->right = NULL;
    }
};
*************************************************************Better Solution************************************************************************************
    class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        // Process right subtree first
        flatten(root->right);

        // Then process left subtree
        flatten(root->left);

        // Attach already processed list after current node
        root->right = prev;

        // Left must be NULL in final flattened tree
        root->left = NULL;

        // Update prev
        prev = root;
    }
};
*************************************************************Optimal Solution************************************************************************************
    class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != NULL) {

            // If there is a left subtree, we need to move it to the right
            if (curr->left != NULL) {

                // Step 1: Find rightmost node of left subtree
                TreeNode* rightMost = curr->left;

                while (rightMost->right != NULL) {
                    rightMost = rightMost->right;
                }

                // Step 2: Attach current right subtree after rightmost node
                rightMost->right = curr->right;

                // Step 3: Move left subtree to right
                curr->right = curr->left;

                // Step 4: Left should become NULL
                curr->left = NULL;
            }

            // Move forward in the flattened list
            curr = curr->right;
        }
    }
};

