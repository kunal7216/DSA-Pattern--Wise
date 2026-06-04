#include <bits/stdc++.h>
using namespace std;

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
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> prefix;
        prefix[0] = 1; // base
        return dfs(root, 0, targetSum, prefix);
    }

private:
    int dfs(TreeNode *node, long long currSum, int target,
            unordered_map<long long, int> &prefix)
    {
        if (!node)
            return 0;
        // update current prefix sum
        currSum += node->val;
        // check if any prev prefix makes a valid path
        int count = 0;
        if (prefix.count(currSum - target))
        {
            count += prefix[currSum - target];
        }
        // include curr prefix sum in map
        prefix[currSum]++;
        // explore chilren
        count += dfs(node->left, currSum, target, prefix);
        count += dfs(node->right, currSum, target, prefix);
        // backtrack
        prefix[currSum]--;
        return count;
    }
};


********************************************************************Brute Solution*********************************************************************************
    class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }

        // Count paths starting from current root
        int pathsFromRoot = countPaths(root, targetSum);

        // Count paths inside left subtree
        int pathsFromLeft = pathSum(root->left, targetSum);

        // Count paths inside right subtree
        int pathsFromRight = pathSum(root->right, targetSum);

        return pathsFromRoot + pathsFromLeft + pathsFromRight;
    }

    int countPaths(TreeNode* node, long long remainingSum) {
        if (node == NULL) {
            return 0;
        }

        int count = 0;

        // If current node completes the target sum
        if (node->val == remainingSum) {
            count++;
        }

        // Continue path downward
        count += countPaths(node->left, remainingSum - node->val);
        count += countPaths(node->right, remainingSum - node->val);

        return count;
    }
};
********************************************************************Better Solution*********************************************************************************
    
    class Solution {
public:
    int ans = 0;

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }

    void dfs(TreeNode* node, int targetSum, vector<int>& path) {
        if (node == NULL) {
            return;
        }

        // Add current node into current root-to-node path
        path.push_back(node->val);

        long long sum = 0;

        // Check all paths ending at current node
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];

            if (sum == targetSum) {
                ans++;
            }
        }

        // Explore left and right subtree
        dfs(node->left, targetSum, path);
        dfs(node->right, targetSum, path);

        // Backtrack
        path.pop_back();
    }
};
********************************************************************Optimal SOlution*********************************************************************************
    class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixFreq;

        // Prefix sum 0 exists once before starting traversal
        prefixFreq[0] = 1;

        return dfs(root, 0, targetSum, prefixFreq);
    }

    int dfs(TreeNode* node, long long currentSum, int targetSum,
            unordered_map<long long, int>& prefixFreq) {
        
        if (node == NULL) {
            return 0;
        }

        // Add current node value to root-to-current prefix sum
        currentSum += node->val;

        int count = 0;

        // Need previous prefix sum = currentSum - targetSum
        long long requiredPrefix = currentSum - targetSum;

        // If required prefix exists, those many paths end at current node
        if (prefixFreq.find(requiredPrefix) != prefixFreq.end()) {
            count += prefixFreq[requiredPrefix];
        }

        // Add current prefix sum before going to children
        prefixFreq[currentSum]++;

        // Count valid paths in left and right subtree
        count += dfs(node->left, currentSum, targetSum, prefixFreq);
        count += dfs(node->right, currentSum, targetSum, prefixFreq);

        // Backtrack: remove current prefix sum before returning
        prefixFreq[currentSum]--;

        return count;
    }
};
