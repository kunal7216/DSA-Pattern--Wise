// climbing stairs
// leetcode: https://leetcode.com/problems/climbing-stairs/
// leetcode question id: 70

class Solution
{
public:
    int climbStairs(int n)
    {

        // Base case:
        // If there is only 1 step, there is only 1 way to reach it
        if (n == 1)
            return 1;

        // dp[i] will store the number of ways to reach step i
        vector<int> dp(n + 1);

        // Initialization:
        // Only one way to reach step 1 -> (1)
        dp[1] = 1;

        // Two ways to reach step 2 -> (1+1) or (2)
        dp[2] = 2;

        // Fill the dp array from step 3 to n
        for (int i = 3; i <= n; i++)
        {

            // To reach step i:
            // 1. Come from step (i - 1) by taking 1 step
            // 2. Come from step (i - 2) by taking 2 steps
            // Total ways = ways to reach (i - 1) + ways to reach (i - 2)
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Final answer: number of ways to reach the nth step
        return dp[n];
    }
};
