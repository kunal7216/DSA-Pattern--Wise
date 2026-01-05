// permutations II
// link: https://leetcode.com/problems/permutations-ii/
// leetcode 47

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> perms;
        vector<int> solution;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        backtrack(nums, used, solution, perms);
        return perms;
    }

private:
    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &solution, vector<vector<int>> &perms)
    {
        if (solution.size() == nums.size())
        {
            perms.push_back(solution);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // Skip if already used
            if (used[i])
                continue;

            // Skip duplicates: only use the first unused duplicate
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            solution.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used, solution, perms);
            used[i] = false;
            solution.pop_back();
        }
    }
};
