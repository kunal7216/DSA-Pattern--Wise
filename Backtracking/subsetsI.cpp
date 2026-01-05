// subset I
// link: https://leetcode.com/problems/subsets/
//leetcode 78

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> res; // Stores all subsets
        vector<int> subset;      // Current subset being built

        // Start backtracking from index 0
        createSubset(nums, 0, res, subset);

        return res;
    }

    void createSubset(vector<int> &nums, int index,
                      vector<vector<int>> &res,
                      vector<int> &subset)
    {

        // Base case:
        // If we have processed all elements,
        // store the current subset and return
        if (index == nums.size())
        {
            res.push_back(subset);
            return;
        }

        // ---------- INCLUDE CURRENT ELEMENT ----------
        // Choose the current element
        subset.push_back(nums[index]);

        // Move to the next index
        createSubset(nums, index + 1, res, subset);

        // ---------- EXCLUDE CURRENT ELEMENT ----------
        // Backtrack: remove last added element
        subset.pop_back();

        // Skip the current element and move forward
        createSubset(nums, index + 1, res, subset);
    }
};
