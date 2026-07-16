// combinations sum 
// link: https://leetcode.com/problems/combination-sum/
// leetcode 39


// ======================================================
// Approach 1: Brute Force
// Time Complexity: Exponential (Generates duplicate permutations)
// Space Complexity: O(Target)
// ======================================================

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& candidates, int target) {

        // Found a valid combination
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        // Sum exceeded target
        if (target < 0)
            return;

        // Try every candidate
        for (int num : candidates) {

            // Choose
            path.push_back(num);

            // Explore
            dfs(candidates, target - num);

            // Backtrack
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        dfs(candidates, target);

        return ans;
    }
};

// ======================================================
// Approach 2: Better
// Time Complexity: Exponential
// Space Complexity: O(Target)
// Removes duplicate permutations using index
// ======================================================

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void solve(vector<int>& candidates, int index, int target) {

        // Valid combination found
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // No candidates left
        if (index == candidates.size())
            return;

        // -------------------------
        // Take current element
        // -------------------------
        if (candidates[index] <= target) {

            current.push_back(candidates[index]);

            // Reuse same element
            solve(candidates, index, target - candidates[index]);

            // Backtrack
            current.pop_back();
        }

        // -------------------------
        // Skip current element
        // -------------------------
        solve(candidates, index + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // Sort for consistent ordering
        sort(candidates.begin(), candidates.end());

        solve(candidates, 0, target);

        return ans;
    }
};

// ======================================================
// Approach 3: Optimal (Backtracking + Pruning)
// Time Complexity: Exponential (Much faster due to pruning)
// Space Complexity: O(Target)
// ======================================================

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combination;

    void backtrack(vector<int>& candidates, int start, int target) {

        // Base Case
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        // Try every candidate from current index
        for (int i = start; i < candidates.size(); i++) {

            // Pruning:
            // Since array is sorted, no need to continue
            if (candidates[i] > target)
                break;

            // Choose current element
            combination.push_back(candidates[i]);

            // Reuse same element
            backtrack(candidates, i, target - candidates[i]);

            // Undo choice (Backtracking)
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // Sort enables pruning
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target);

        return ans;
    }
};
