// target sum
// leetcode: https://leetcode.com/problems/target-sum/
// leetcode question id: 494

// ==========================================================
// Approach 1: Brute Force (Recursion)
// ==========================================================
// Intuition:
// For every number, we have only two choices:
// 1. Add it (+)
// 2. Subtract it (-)
//
// Explore every possible combination recursively.
//
// Time Complexity: O(2^n)
// - Every element has two choices.
//
// Space Complexity: O(n)
// - Maximum recursion depth.
//
// ----------------------------------------------------------

class Solution1 {
public:

    // Recursive function
    int solve(vector<int>& nums, int index, int currentSum, int target) {

        // Base Case:
        // If all numbers are processed,
        // check whether we reached the target.
        if(index == nums.size()) {
            return (currentSum == target);
        }

        // Choose '+' sign
        int add = solve(nums,
                        index + 1,
                        currentSum + nums[index],
                        target);

        // Choose '-' sign
        int subtract = solve(nums,
                             index + 1,
                             currentSum - nums[index],
                             target);

        // Total number of valid expressions
        return add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(nums, 0, 0, target);
    }
};

// ==========================================================
// Approach 2: Memoization (Top-Down DP)
// ==========================================================
// Intuition:
//
// Brute force recalculates the same state multiple times.
//
// State:
// (index, currentSum)
//
// Store already computed answers to avoid repeated work.
//
// Time Complexity: O(n × totalSum)
//
// Space Complexity: O(n × totalSum)
//
// ----------------------------------------------------------

class Solution2 {
public:

    // Memoization map
    // Key = "index,currentSum"
    unordered_map<string, int> dp;

    int solve(vector<int>& nums, int index, int currentSum, int target) {

        // Base Case
        if(index == nums.size()) {
            return (currentSum == target);
        }

        // Create unique key for current state
        string key = to_string(index) + "," + to_string(currentSum);

        // Return cached answer
        if(dp.count(key))
            return dp[key];

        // Take current number as positive
        int add = solve(nums,
                        index + 1,
                        currentSum + nums[index],
                        target);

        // Take current number as negative
        int subtract = solve(nums,
                             index + 1,
                             currentSum - nums[index],
                             target);

        // Store result
        return dp[key] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(nums, 0, 0, target);
    }
};

// ==========================================================
// Approach 3: Optimal (1D DP - Subset Sum Count)
// ==========================================================
//
// Mathematical Transformation:
//
// Let
// Positive subset = P
// Negative subset = N
//
// P - N = target
// P + N = totalSum
//
// Adding both equations:
//
// 2P = totalSum + target
//
// P = (totalSum + target) / 2
//
// Therefore,
// Count subsets whose sum equals:
//
// subsetSum = (totalSum + target)/2
//
// This becomes a classic "Count Subsets with Given Sum" DP.
//
// ----------------------------------------------------------
//
// Time Complexity: O(n × subsetSum)
//
// Space Complexity: O(subsetSum)
//
// ----------------------------------------------------------

class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = 0;

        // Calculate total array sum
        for(int num : nums)
            totalSum += num;

        // Impossible Case 1:
        // Target is greater than total sum.
        if(abs(target) > totalSum)
            return 0;

        // Impossible Case 2:
        // subsetSum must be an integer.
        if((totalSum + target) % 2 != 0)
            return 0;

        // Required subset sum
        int subsetSum = (totalSum + target) / 2;

        // dp[i] =
        // Number of subsets having sum i
        vector<int> dp(subsetSum + 1, 0);

        // Empty subset always forms sum 0
        dp[0] = 1;

        // Process every number
        for(int num : nums) {

            // Traverse backwards
            //
            // Backward traversal ensures that every
            // element is used only once.
            //
            // If we iterate forward,
            // one element could be counted multiple times.
            for(int sum = subsetSum; sum >= num; sum--) {

                // Include current number
                dp[sum] += dp[sum - num];
            }
        }

        // Number of subsets having required sum
        return dp[subsetSum];
    }
};
