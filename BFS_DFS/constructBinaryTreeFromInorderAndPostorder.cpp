// construct binary tree from inorder and postorder traversals
//// leetcode 106

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

//     // Constructor with value only
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

//     // Constructor with value and child nodes
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    // Main function to build tree from inorder and postorder
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        // Edge case: if arrays are not same size, return nullptr
        if (inorder.size() != postorder.size())
            return nullptr;

        // Step 1: Build a hashmap for fast index lookup in inorder
        // Key   -> node value
        // Value -> index of that value in inorder array
        unordered_map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++)
        {
            hm[inorder[i]] = i;
        }

        // Step 2: Start recursive tree construction
        // Pass full range of inorder and postorder arrays
        return buildTreePostIn(inorder, 0, inorder.size() - 1,
                               postorder, 0, postorder.size() - 1, hm);
    }

    // Recursive helper function
    TreeNode *buildTreePostIn(vector<int> &inorder, int is, int ie,
                              vector<int> &postorder, int ps, int pe,
                              unordered_map<int, int> &hm)
    {

        // Base case:
        // If there are no elements in current range, return nullptr
        if (ps > pe || is > ie)
            return nullptr;

        // Step 3: Last element of postorder is the root of current subtree
        TreeNode *root = new TreeNode(postorder[pe]);

        // Step 4: Find root index in inorder using hashmap
        int inRoot = hm[root->val];

        // Step 5: Compute number of nodes in left subtree
        int numsLeft = inRoot - is;

        // Step 6: Recursively build the left subtree
        // Inorder range: is to inRoot - 1
        // Postorder range: ps to ps + numsLeft - 1
        root->left = buildTreePostIn(inorder, is, inRoot - 1,
                                     postorder, ps, ps + numsLeft - 1, hm);

        // Step 7: Recursively build the right subtree
        // Inorder range: inRoot + 1 to ie
        // Postorder range: ps + numsLeft to pe - 1
        root->right = buildTreePostIn(inorder, inRoot + 1, ie,
                                      postorder, ps + numsLeft, pe - 1, hm);

        // Step 8: Return the constructed root node
        return root;
    }
};
