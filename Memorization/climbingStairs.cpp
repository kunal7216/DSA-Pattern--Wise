// climbing stairs
// leetcode: https://leetcode.com/problems/climbing-stairs/
// leetcode question id: 70

// ================================
// Approach 1: Brute Force Recursion
// Time Complexity: O(2^N)
// Space Complexity: O(N)
// ================================

class Solution {
public:

    int solve(int n)
    {
        // Exactly reached the top
        if(n==0)
            return 1;

        // Crossed the stairs
        if(n<0)
            return 0;

        // Choose 1 step or 2 steps
        return solve(n-1)+solve(n-2);
    }

    int climbStairs(int n) {
        return solve(n);
    }
};

// =====================================
// Approach 2: Memoization (Top Down DP)
// Time Complexity: O(N)
// Space Complexity: O(N)
// =====================================

class Solution {
public:

    int solve(int n, vector<int>& dp)
    {
        if(n==0)
            return 1;

        if(n<0)
            return 0;

        if(dp[n]!=-1)
            return dp[n];

        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }

    int climbStairs(int n) {

        vector<int> dp(n+1,-1);

        return solve(n,dp);
    }
};

// =====================================
// Approach 3: Space Optimized DP
// Time Complexity: O(N)
// Space Complexity: O(1)
// =====================================

class Solution {
public:

    int climbStairs(int n) {

        if(n<=2)
            return n;

        int prev2=1; // ways to reach stair 1
        int prev1=2; // ways to reach stair 2

        for(int i=3;i<=n;i++)
        {
            int curr=prev1+prev2;

            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};
