// subset I
// link: https://leetcode.com/problems/subsets/
//leetcode 78

// Brute Solution 
class Solution {
public:

    vector<vector<int>> ans;

    void solve(int index, vector<int>& nums, vector<int>& curr) {

        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Take
        curr.push_back(nums[index]);
        solve(index + 1, nums, curr);

        // Backtrack
        curr.pop_back();

        // Don't take
        solve(index + 1, nums, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> curr;

        solve(0, nums, curr);

        return ans;
    }
};
// Better Solution ---recursive include / exclude

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        int total = 1 << n;

        for (int mask = 0; mask < total; mask++) {

            vector<int> subset;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i))
                    subset.push_back(nums[i]);
            }

            ans.push_back(subset);
        }

        return ans;
    }
};
// optimal solution --- backtracking using loop

class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(int start, vector<int>& nums, vector<int>& curr) {

        // Every current subset is valid
        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {

            curr.push_back(nums[i]);

            backtrack(i + 1, nums, curr);

            // Undo the choice
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> curr;

        backtrack(0, nums, curr);

        return ans;
    }
};

