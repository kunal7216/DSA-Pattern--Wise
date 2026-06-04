class Solution
{
public:
    vector<vector<int>> ans;

    // the idea is to use dfs to traverse the tree from all root to leaf paths
    // `path` is used to store the current route
    // `remainingSum` is used to store thre remaining sum that we need with the initial value `targetSum`.
    //  we substract it from the node value when we traverse down the tree
    // if we arrive the leaf and the the remaining sum is eqaul to leaf node value
    // then we can add `path` to ans
    // e.g. path = [5,4,11,2] and remainingSum = targetSum = 22
    // traverse node 5, remainingSum = 22 - 5 = 17
    // traverse node 4, remainingSum = 17 - 4 = 13
    // traverse node 11, remainingSum = 13 - 11 = 2
    // traverse node 2, remainingSum = 2 - 2 = 0
    // remainingSum is 0 which means the sum of current path is eqaul to targetSum
    // so how to find another path?
    // we can backtrack here
    // we can pop back a node and try another
    // e.g. path = [5, 4, 11, 7]
    // pop 7 out = [5, 4, 11]
    // push 2 = [5, 4, 11, 2]
    // ... etc
    void dfs(TreeNode *node, vector<int> &path, int remainingSum)
    {
        // if it is nullptr, then return
        if (!node)
            return;
        // add the current node val to path
        path.push_back(node->val);
        // !node->left && !node->right : check if it is a leaf node
        // remainingSum == node->val: check if the remaining sum - node->val == 0
        // if both condition is true, then we find one of the paths
        if (!node->left && !node->right && remainingSum == node->val)
            ans.push_back(path);
        // traverse left sub tree with updated remaining sum
        // we don't need to check if left sub tree is nullptr or not
        // as we handle it in the first line of this function
        dfs(node->left, path, remainingSum - node->val);
        // traverse right sub tree with updated remaining sum
        // we don't need to check if right sub tree is nullptr or not
        // as we handle it in the first line of this function
        dfs(node->right, path, remainingSum - node->val);
        // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        // used to store current route
        vector<int> path;
        // dfs from the root
        dfs(root, path, targetSum);
        return ans;
    }
};


********************************************************************Brute Solution********************************************************************************

class Solution {
public:
    vector<vector<int>> allPaths;

    void collectPaths(TreeNode* root, vector<int> path) {
        if (root == NULL) {
            return;
        }

        // Add current node to path
        path.push_back(root->val);

        // If current node is a leaf, store this path
        if (root->left == NULL && root->right == NULL) {
            allPaths.push_back(path);
            return;
        }

        // Explore left subtree
        collectPaths(root->left, path);

        // Explore right subtree
        collectPaths(root->right, path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        // Step 1: collect all root-to-leaf paths
        vector<int> path;
        collectPaths(root, path);

        // Step 2: calculate sum of every path
        for (auto p : allPaths) {
            long long sum = 0;

            for (int x : p) {
                sum += x;
            }

            if (sum == targetSum) {
                ans.push_back(p);
            }
        }

        return ans;
    }
};
********************************************************************Better Solution*********************************************************************************
   

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int targetSum, long long currentSum, vector<int> path) {
        if (root == NULL) {
            return;
        }

        // Include current node
        currentSum += root->val;
        path.push_back(root->val);

        // Check only at leaf node
        if (root->left == NULL && root->right == NULL) {
            if (currentSum == targetSum) {
                ans.push_back(path);
            }
            return;
        }

        // Explore left subtree
        dfs(root->left, targetSum, currentSum, path);

        // Explore right subtree
        dfs(root->right, targetSum, currentSum, path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, 0, path);
        return ans;
    }
};
********************************************************************Optimal SOlution*********************************************************************************
   
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == NULL) {
            return;
        }

        // Choose current node
        path.push_back(root->val);

        // Reduce targetSum by current node value
        targetSum -= root->val;

        // Check only when current node is a leaf
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == 0) {
                ans.push_back(path);
            }
        }

        // Explore left subtree
        dfs(root->left, targetSum, path);

        // Explore right subtree
        dfs(root->right, targetSum, path);

        // Backtrack: remove current node before returning
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;

        dfs(root, targetSum, path);

        return ans;
    }
};
