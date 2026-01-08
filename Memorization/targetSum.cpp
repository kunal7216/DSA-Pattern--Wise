// target sum
// leetcode: https://leetcode.com/problems/target-sum/
// leetcode question id: 494

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        // dp[sum] = number of ways to get this sum
        unordered_map<int, int> dp;

        // Base case: one way to achieve sum = 0
        dp[0] = 1;

        // Process each number
        for (int num : nums)
        {
            unordered_map<int, int> nextDp;

            // For each possible sum so far
            for (auto &it : dp)
            {
                int sum = it.first;
                int count = it.second;

                // Add current number
                nextDp[sum + num] += count;

                // Subtract current number
                nextDp[sum - num] += count;
            }

            // Move to next iteration
            dp = nextDp;
        }

        // Return number of ways to reach target
        return dp[target];
    }
};
