// permutations II
// link: https://leetcode.com/problems/permutations-ii/
// leetcode 47

// Brute Solution 
class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;

    void backtrack(vector<int>& nums, vector<int>& curr,
                   vector<bool>& used) {

        if (curr.size() == nums.size()) {
            st.insert(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            used[i] = true;
            curr.push_back(nums[i]);

            backtrack(nums, curr, used);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int> curr;
        vector<bool> used(nums.size(), false);

        backtrack(nums, curr, used);

        for (auto x : st)
            ans.push_back(x);

        return ans;
    }
};

// Better Solution
class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums,
               vector<int>& curr,
               vector<bool>& used) {

        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            if (i > 0 &&
                nums[i] == nums[i - 1] &&
                !used[i - 1])
                continue;

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, curr, used);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> curr;
        vector<bool> used(nums.size(), false);

        solve(nums, curr, used);

        return ans;
    }
};


// Optimal Solution -- frequency maps
class Solution {
public:
    vector<vector<int>> ans;

    void solve(unordered_map<int, int>& freq,
               vector<int>& curr,
               int n) {

        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for (auto &it : freq) {

            if (it.second == 0)
                continue;

            curr.push_back(it.first);
            it.second--;

            solve(freq, curr, n);

            it.second++;
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        vector<int> curr;

        solve(freq, curr, nums.size());

        return ans;
    }
};
