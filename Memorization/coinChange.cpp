// coin change 
// leetcode 322
// leetcode problem link: https://leetcode.com/problems/coin-change/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        // If the required amount is 0, we do not need any coins
        if (amount == 0)
            return 0;

        // dp[i] will store the minimum number of coins needed to make amount i
        // Initialize all values with a large number (amount + 1 works as "infinity")
        vector<int> dp(amount + 1, amount + 1);

        // Base case: 0 coins are needed to make amount 0
        dp[0] = 0;

        // Compute the minimum coins required for every amount from 1 to amount
        for (int i = 1; i <= amount; i++)
        {

            // Try using each coin denomination
            for (int coin : coins)
            {

                // Check if the coin can contribute to the current amount
                if (coin <= i)
                {

                    // Update dp[i] by choosing the minimum:
                    // current value OR using this coin (1 + dp[i - coin])
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] is still greater than amount,
        // it means we could not form the amount using given coins
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
