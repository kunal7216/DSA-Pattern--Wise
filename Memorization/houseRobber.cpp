
// ============================================================================
// LeetCode 198 - House Robber
// Approach 1: Brute Force (Pure Recursion)
//
// Intuition:
// For every house, we have only two choices:
// 1. Rob the current house and skip the next one.
// 2. Skip the current house and move to the next house.
//
// We recursively explore both possibilities and return the maximum.
//
// Time Complexity: O(2^N)
// -> Every house creates two recursive calls.
// -> The recursion tree grows exponentially.
//
// Space Complexity: O(N)
// -> Maximum recursion depth can reach N.
// ============================================================================

class Solution1 {
public:
    // Recursive function that returns the maximum money
    // that can be robbed starting from index 'i'.
    int solve(vector<int>& nums, int i) {

        // Base Case:
        // If index goes outside the array,
        // there are no houses left to rob.
        if (i >= nums.size())
            return 0;

        // -------------------------
        // Choice 1: Rob current house
        // -------------------------
        // Add current house money and jump to i+2
        int robCurrent = nums[i] + solve(nums, i + 2);

        // -------------------------
        // Choice 2: Skip current house
        // -------------------------
        int skipCurrent = solve(nums, i + 1);

        // Return the better option.
        return max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};

// ============================================================================
// Approach 2: Memoization (Top-Down DP)
//
// Improvement:
// The brute force solution recalculates the same states many times.
//
// Example:
// solve(3) may be called from multiple recursion paths.
//
// We store the answer for every index so each state is solved only once.
//
// Time Complexity: O(N)
// -> Each index is computed once.
//
// Space Complexity: O(N)
// -> O(N) DP array
// -> O(N) recursion stack
// ============================================================================

class Solution2 {
public:
    vector<int> dp;

    // Returns maximum money that can be robbed
    // starting from house 'i'.
    int solve(vector<int>& nums, int i) {

        // No houses left.
        if (i >= nums.size())
            return 0;

        // If already computed, return stored answer.
        if (dp[i] != -1)
            return dp[i];

        // -------------------------
        // Option 1: Rob current house
        // -------------------------
        int robCurrent = nums[i] + solve(nums, i + 2);

        // -------------------------
        // Option 2: Skip current house
        // -------------------------
        int skipCurrent = solve(nums, i + 1);

        // Store answer before returning.
        return dp[i] = max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& nums) {

        // Initialize DP array with -1.
        dp.assign(nums.size(), -1);

        return solve(nums, 0);
    }
};

// ============================================================================

// Approach 3: Bottom-Up DP (Space Optimized)
//
// Key Observation:
//
// DP Relation:
//
// dp[i] = max(
//              dp[i-1],            // Skip current house
//              nums[i] + dp[i-2]   // Rob current house
//           )
//
// Notice that dp[i] depends only on:
//
// dp[i-1]
// dp[i-2]
//
// Therefore, instead of storing the entire DP array,
// we only keep the previous two answers.
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)
// ============================================================================

class Solution {
public:
    int rob(vector<int>& nums) {

        // prev2 = dp[i-2]
        // Maximum money till two houses before.
        int prev2 = 0;

        // prev1 = dp[i-1]
        // Maximum money till previous house.
        int prev1 = 0;

        // Traverse every house.
        for (int money : nums) {

            // -----------------------------
            // Option 1:
            // Skip current house
            // -----------------------------
            int skipCurrent = prev1;

            // -----------------------------
            // Option 2:
            // Rob current house
            // -----------------------------
            int robCurrent = money + prev2;

            // Best answer till current house.
            int current = max(skipCurrent, robCurrent);

            // Move DP window forward.
            prev2 = prev1;
            prev1 = current;
        }

        // prev1 stores the answer for the last house.
        return prev1;
    }
};
