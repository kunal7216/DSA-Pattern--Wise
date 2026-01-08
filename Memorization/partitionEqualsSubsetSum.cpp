// partition equals subset sum problem
// leetcode: https://leetcode.com/problems/partition-equal-subset-sum/
// leetcode question id: 416

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        // If total sum is odd, cannot partition
        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;

        // dp[t] = can we form sum t?
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums)
        {
            // Traverse backwards to avoid reuse of same element
            for (int t = target; t >= num; t--)
            {
                dp[t] = dp[t] || dp[t - num];
            }
        }

        return dp[target];
    }
};
