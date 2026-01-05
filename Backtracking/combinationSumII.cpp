// combination sum II
// link: https://leetcode.com/problems/combination-sum-ii/
// leetcode 40

class Solution
{
public:
    // Main function to return all unique combinations
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res; // To store the final combinations
        vector<int> comb;        // Current combination being built

        // Sort candidates to make it easier to handle duplicates
        sort(candidates.begin(), candidates.end());

        // Start the backtracking process from index 0
        backtrack(candidates, target, 0, comb, res);

        return res; // Return all valid combinations
    }

    // Helper function for backtracking
    void backtrack(vector<int> &candidates, int target, int start,
                   vector<int> &comb, vector<vector<int>> &res)
    {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0)
        {
            res.push_back(comb); // Add current combination to the result
            return;
        }

        // Iterate over candidates starting from 'start' index
        for (int i = start; i < candidates.size(); i++)
        {
            // Skip duplicates: if current number is same as previous and it's not the first in this loop
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // If the candidate is greater than the remaining target, stop (array is sorted)
            if (candidates[i] > target)
                break;

            // Include the current candidate in the combination
            comb.push_back(candidates[i]);

            // Recurse with updated target and next index (i+1 because we can't reuse elements)
            backtrack(candidates, target - candidates[i], i + 1, comb, res);

            // Backtrack: remove the last element and try next candidate
            comb.pop_back();
        }
    }
};
