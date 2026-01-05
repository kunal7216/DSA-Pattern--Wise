// combinations sum 
// link: https://leetcode.com/problems/combination-sum/
// leetcode 39

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result; // stores all valid combinations
        vector<int> combination;    // current combination
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(vector<int> &candidates, int target, int index,
                   vector<int> &combination, vector<vector<int>> &result)
    {
        int sum = accumulate(combination.begin(), combination.end(), 0);

        // Base case: valid combination found
        if (sum == target)
        {
            result.push_back(combination);
            return;
        }

        // Base case: end of array or exceeded target
        if (index == candidates.size() || sum > target)
            return;

        // Case 1: skip current number
        backtrack(candidates, target, index + 1, combination, result);

        // Case 2: include current number (can reuse)
        combination.push_back(candidates[index]);
        backtrack(candidates, target, index, combination, result); // reuse allowed
        combination.pop_back();                                    // backtrack
    }
};
