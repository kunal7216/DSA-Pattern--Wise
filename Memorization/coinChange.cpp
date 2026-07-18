// coin change 
// leetcode 322
// leetcode problem link: https://leetcode.com/problems/coin-change/


// ============================================
// Approach 1: Brute Force (Pure Recursion)
// Time Complexity: O(n^amount)
// Space Complexity: O(amount)
// ============================================

class Solution {
public:

    int solve(vector<int>& coins, int amount) {

        // Exact amount formed
        if (amount == 0)
            return 0;

        // Invalid
        if (amount < 0)
            return INT_MAX;

        int ans = INT_MAX;

        // Try every coin
        for (int coin : coins) {

            int res = solve(coins, amount - coin);

            if (res != INT_MAX)
                ans = min(ans, res + 1);
        }

        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        int ans = solve(coins, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};

// ============================================
// Approach 2: Memoization (Top-Down DP)
// Time Complexity: O(amount * n)
// Space Complexity: O(amount)
// ============================================

class Solution {
public:

    vector<int> dp;

    int solve(vector<int>& coins, int amount) {

        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int ans = INT_MAX;

        for (int coin : coins) {

            int res = solve(coins, amount - coin);

            if (res != INT_MAX)
                ans = min(ans, res + 1);
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        dp.assign(amount + 1, -1);

        int ans = solve(coins, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};
// ============================================
// Approach 3: Bottom-Up DP (Tabulation)
// Time Complexity: O(amount * n)
// Space Complexity: O(amount)
// ============================================

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        // Large value representing impossible
        const int INF = amount + 1;

        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, INF);

        // Base case
        dp[0] = 0;

        // Build the DP table
        for (int i = 1; i <= amount; i++) {

            for (int coin : coins) {

                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
