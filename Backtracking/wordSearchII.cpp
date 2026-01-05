// word search II
// link: https://leetcode.com/problems/word-search-ii/
// leetcode 212

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // Step 1: Sort the array to group duplicates together
        sort(nums.begin(), nums.end());

        vector<vector<int>> res; // Stores all unique subsets
        vector<int> subset;      // Current subset being formed

        // Start recursion from index 0
        createSubset(nums, 0, res, subset);
        return res;
    }

    void createSubset(vector<int> &nums, int index,
                      vector<vector<int>> &res,
                      vector<int> &subset)
    {

        // Base case:
        // If we have considered all elements, store the subset
        if (index == nums.size())
        {
            res.push_back(subset);
            return;
        }

        // ---------------- INCLUDE CASE ----------------
        // Include nums[index] in the current subset
        subset.push_back(nums[index]);
        // Recurse to the next element
        createSubset(nums, index + 1, res, subset);
        // Backtrack: remove last added element to explore exclusion path
        subset.pop_back();

        // ---------------- EXCLUDE CASE ----------------
        // Skip all duplicates of nums[index] to avoid duplicate subsets
        while (index + 1 < nums.size() && nums[index] == nums[index + 1])
        {
            index++;
        }

        // Exclude nums[index] (and all its duplicates)
        createSubset(nums, index + 1, res, subset);
    }
};
