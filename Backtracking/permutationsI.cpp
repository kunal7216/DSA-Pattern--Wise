// permutations I
// link: https://leetcode.com/problems/permutations/

// leetcode 46

                                                                      // Brute Solution 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        do {
            ans.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));

        return ans;
    }
};

                                                                      // better Solution
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;

    void backtrack(vector<int>& nums) {

        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums);

            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        used.resize(nums.size(), false);

        backtrack(nums);

        return ans;
    }
};

                                                                // Optimal Solution
class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index) {

        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            swap(nums[index], nums[i]);

            backtrack(nums, index + 1);

            swap(nums[index], nums[i]); // Undo
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        backtrack(nums, 0);

        return ans;
    }
};
