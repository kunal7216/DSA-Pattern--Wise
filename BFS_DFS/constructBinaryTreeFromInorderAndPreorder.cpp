// consturct binary tree from inorder and preorder traversals
//// leetcode 105

/**
 * Definition for a binary tree node.
 */


class Solution
{
public:
    // HashMap to store inorder element -> index
    // This allows O(1) lookup of root position in inorder traversal
    unordered_map<int, int> inMap;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        // Step 1: Build hashmap for inorder traversal
        // Key   -> node value
        // Value -> index of that value in inorder array
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        // Step 2: Call recursive helper with full range of both arrays
        return buildTree(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd,
                        vector<int> &inorder, int inStart, int inEnd)
    {

        // Base Case:
        // If there are no elements to construct the subtree
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // Step 3: First element in preorder is always the root
        TreeNode *root = new TreeNode(preorder[preStart]);

        // Step 4: Find root index in inorder traversal
        int inRoot = inMap[root->val];

        // Step 5: Number of nodes in the left subtree
        int numsLeft = inRoot - inStart;

        // Step 6: Recursively construct the left subtree
        // Preorder range: preStart + 1 to preStart + numsLeft
        // Inorder range : inStart to inRoot - 1
        root->left = buildTree(preorder,
                               preStart + 1,
                               preStart + numsLeft,
                               inorder,
                               inStart,
                               inRoot - 1);

        // Step 7: Recursively construct the right subtree
        // Preorder range: preStart + numsLeft + 1 to preEnd
        // Inorder range : inRoot + 1 to inEnd
        root->right = buildTree(preorder,
                                preStart + numsLeft + 1,
                                preEnd,
                                inorder,
                                inRoot + 1,
                                inEnd);

        // Step 8: Return the constructed subtree
        return root;
    }
};


// using map
/**
 * Definition for a binary tree node.
 */
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     // Default constructor
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}

//     // Constructor with value
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

//     // Constructor with value and children
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    // Function to build binary tree from preorder and inorder traversals
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        // Step 1: Create a map for inorder element -> index
        // This allows O(1) lookup of root position in inorder traversal
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        // Step 2: Call recursive helper function with full range
        return buildTree(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1,
                         inMap);
    }

    // Recursive helper function
    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd,
                        vector<int> &inorder, int inStart, int inEnd,
                        map<int, int> &inMap)
    {

        // Base case: if no elements are left to construct the subtree
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        // Step 3: First element of preorder is the root of current subtree
        TreeNode *root = new TreeNode(preorder[preStart]);

        // Step 4: Find root index in inorder traversal
        int inRoot = inMap[root->val];

        // Step 5: Number of nodes in left subtree
        int numsLeft = inRoot - inStart;

        // Step 6: Recursively construct the left subtree
        // Preorder range: preStart + 1 to preStart + numsLeft
        // Inorder range : inStart to inRoot - 1
        root->left = buildTree(preorder,
                               preStart + 1,
                               preStart + numsLeft,
                               inorder,
                               inStart,
                               inRoot - 1,
                               inMap);

        // Step 7: Recursively construct the right subtree
        // Preorder range: preStart + numsLeft + 1 to preEnd
        // Inorder range : inRoot + 1 to inEnd
        root->right = buildTree(preorder,
                                preStart + numsLeft + 1,
                                preEnd,
                                inorder,
                                inRoot + 1,
                                inEnd,
                                inMap);

        // Step 8: Return the constructed subtree rooted at 'root'
        return root;
    }
};
