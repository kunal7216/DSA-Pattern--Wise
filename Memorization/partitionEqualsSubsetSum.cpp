// partition equals subset sum problem
// leetcode: https://leetcode.com/problems/partition-equal-subset-sum/
// leetcode question id: 416

// ============================
// Approach 1 : Pure Recursion (BRUTE)
// Time Complexity : O(2^N)
// Space Complexity : O(N)
// ============================

class Solution {
public:

    bool solve(int index, int target, vector<int>& nums)
    {
        // Target achieved
        if(target == 0)
            return true;

        // No elements left
        if(index == nums.size())
            return false;

        // Take current element
        if(nums[index] <= target)
        {
            if(solve(index + 1, target - nums[index], nums))
                return true;
        }

        // Skip current element
        return solve(index + 1, target, nums);
    }

    bool canPartition(vector<int>& nums) {

        int total = 0;

        for(int x : nums)
            total += x;

        // Odd sum cannot be divided equally
        if(total % 2)
            return false;

        return solve(0, total / 2, nums);
    }
};

// ==========================================================
// Approach 2 : Memoization (Top-Down DP)
//
// Time Complexity : O(N * Target)
// Space Complexity : O(N * Target) + O(N) recursion stack
//
// Idea:
// Instead of solving the same (index, target) state multiple
// times, store the answer in a DP table.
//
// State:
// dp[index][target] = Can we make 'target' using elements
// starting from 'index'?
// ==========================================================

class Solution {
public:

    // DP table
    // -1 = Not computed
    //  0 = False
    //  1 = True
    vector<vector<int>> dp;

    // Recursive function
    bool solve(int index, int target, vector<int>& nums)
    {
        // ==========================
        // Base Case 1
        // If target becomes 0,
        // we have successfully formed
        // the required subset sum.
        // ==========================
        if (target == 0)
            return true;

        // ==========================
        // Base Case 2
        // We have used all elements
        // but target is still not 0,
        // so subset is impossible.
        // ==========================
        if (index == nums.size())
            return false;

        // ==========================
        // If this state has already
        // been computed, return it.
        // This avoids repeated work.
        // ==========================
        if (dp[index][target] != -1)
            return dp[index][target];

        // Variable to store result
        bool take = false;

        // ==========================
        // Choice 1 : Take current element
        //
        // We can only take it if
        // nums[index] <= target.
        // ==========================
        if (nums[index] <= target)
        {
            take = solve(index + 1,
                         target - nums[index],
                         nums);
        }

        // ==========================
        // Choice 2 : Skip current element
        // ==========================
        bool notTake = solve(index + 1,
                             target,
                             nums);

        // ==========================
        // Store result in DP table.
        //
        // If either taking or skipping
        // makes the target possible,
        // answer is true.
        // ==========================
        dp[index][target] = take || notTake;

        return dp[index][target];
    }

    bool canPartition(vector<int>& nums)
    {
        // Calculate total sum
        int total = 0;

        for (int num : nums)
            total += num;

        // If total sum is odd,
        // equal partition is impossible.
        if (total % 2 != 0)
            return false;

        // Required subset sum
        int target = total / 2;

        // Create DP table
        //
        // Rows    -> index
        // Columns -> target values
        //
        // Initialize every cell with -1
        // meaning "not computed".
        dp.assign(nums.size(),
                  vector<int>(target + 1, -1));

        // Start recursion from index 0
        return solve(0, target, nums);
    }
};

// ============================
// Approach 3 : Space Optimized DP
// Time Complexity : O(N * Target)
// Space Complexity : O(Target)
// ============================

class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int total = 0;

        for(int x : nums)
            total += x;

        // Odd total cannot be partitioned equally
        if(total % 2)
            return false;

        int target = total / 2;

        // dp[j] = Can we make sum j?
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        // Process each number
        for(int num : nums)
        {
            // Traverse backwards to avoid reusing the same element
            for(int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
