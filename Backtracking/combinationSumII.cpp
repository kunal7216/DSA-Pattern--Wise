// combination sum II
// link: https://leetcode.com/problems/combination-sum-ii/
// leetcode 40

// ===========================
// Approach 1: Brute Force (Bitmasking + Set)
// Time Complexity: O(2^N * N log N)
// Space Complexity: O(2^N)
// ===========================

class Solution1 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        set<vector<int>> st;

        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> temp;
            int sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp.push_back(candidates[i]);
                    sum += candidates[i];
                }
            }

            if (sum == target) {
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};



// ===========================
// Approach 2: Backtracking + Set
// Time Complexity: O(2^N)
// Space Complexity: O(N) + O(K)
// (K = number of unique combinations stored in the set)
// ===========================

class Solution2 {
public:
    set<vector<int>> st;

    void dfs(vector<int>& candidates, int index, int target, vector<int>& path) {

        if (target == 0) {
            vector<int> temp = path;
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        // Take current element
        path.push_back(candidates[index]);
        dfs(candidates, index + 1, target - candidates[index], path);
        path.pop_back();

        // Skip current element
        dfs(candidates, index + 1, target, path);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> path;

        dfs(candidates, 0, target, path);

        return vector<vector<int>>(st.begin(), st.end());
    }
};



// ===========================
// Approach 3: Optimal (Sorting + Backtracking)
// Time Complexity: O(2^N)
// Space Complexity: O(N)
// ===========================

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(vector<int>& candidates, int target, int start) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Pruning
            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], i + 1);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return ans;
    }
};
