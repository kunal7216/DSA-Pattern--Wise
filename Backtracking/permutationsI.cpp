// permutations I
// link: https://leetcode.com/problems/permutations/

// leetcode 46

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> perms; // stores all permutations
        vector<int> solution;      // current path
        backtrack(nums, solution, perms);
        return perms;
    }

private:
    void backtrack(vector<int> &nums, vector<int> &solution, vector<vector<int>> &perms)
    {
        // Base case: if current path has all numbers, add to result
        if (solution.size() == nums.size())
        {
            perms.push_back(solution);
            return;
        }

        // Try all numbers
        for (int num : nums)
        {
            // Skip if already in current path
            if (find(solution.begin(), solution.end(), num) != solution.end())
                continue;

            solution.push_back(num);          // choose
            backtrack(nums, solution, perms); // recurse
            solution.pop_back();              // backtrack
        }
    }
};
