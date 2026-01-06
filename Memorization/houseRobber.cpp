// house robber problem using dynamic programming
// leetcode problem link: https://leetcode.com/problems/house-robber/
// leetcode question id: 198

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        // If there are no houses, return 0
        if (nums.size() == 0)
            return 0;

        // If there is only one house, rob it
        if (nums.size() == 1)
            return nums[0];

        // dp[i] stores the maximum money that can be robbed
        // from houses 0 to i
        vector<int> dp(nums.size());

        // Base cases
        dp[0] = nums[0];               // Rob first house
        dp[1] = max(nums[0], nums[1]); // Max of first two houses

        // Fill the dp array
        for (int i = 2; i < nums.size(); i++)
        {

            // Either:
            // 1. Rob current house -> dp[i - 2] + nums[i]
            // 2. Skip current house -> dp[i - 1]
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        // Last element contains the maximum loot
        return dp[nums.size() - 1];
    }
};
