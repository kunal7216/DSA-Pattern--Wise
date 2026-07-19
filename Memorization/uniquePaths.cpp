// unique paths
// https://leetcode.com/problems/unique-paths/
// leetcode question id: 62

// ==========================================
// Approach 1: Brute Force (Recursion)
//
// Intuition:
// From every cell we have only two choices:
// 1. Move Down
// 2. Move Right
//
// Explore both possibilities recursively.
//
// Time Complexity : O(2^(m+n))
// Space Complexity: O(m+n)   (Recursion stack)
// ==========================================

class Solution {
public:

    // Recursive function that returns the number of
    // unique paths from cell (i, j) to destination.
    int solve(int i, int j, int m, int n) {

        // Base Case:
        // If we reach the bottom-right cell,
        // we found one valid path.
        if (i == m - 1 && j == n - 1)
            return 1;

        // If indices go outside the grid,
        // this path is invalid.
        if (i >= m || j >= n)
            return 0;

        // Move Down
        int down = solve(i + 1, j, m, n);

        // Move Right
        int right = solve(i, j + 1, m, n);

        // Total paths = Down paths + Right paths
        return down + right;
    }

    int uniquePaths(int m, int n) {

        // Start from top-left corner (0,0)
        return solve(0, 0, m, n);
    }
};

// ==========================================
// Approach 2: Memoization (Top-Down DP)
//
// Improvement:
// Store already computed states so that
// each cell is calculated only once.
//
// Time Complexity : O(m*n)
// Space Complexity: O(m*n)
// ==========================================

class Solution {
public:

    // DP table
    vector<vector<int>> dp;

    int solve(int i, int j, int m, int n) {

        // Destination reached
        if (i == m - 1 && j == n - 1)
            return 1;

        // Invalid cell
        if (i >= m || j >= n)
            return 0;

        // If answer already computed,
        // simply return it.
        if (dp[i][j] != -1)
            return dp[i][j];

        // Calculate paths by moving
        // Down and Right.
        int down = solve(i + 1, j, m, n);
        int right = solve(i, j + 1, m, n);

        // Store result for future use.
        dp[i][j] = down + right;

        return dp[i][j];
    }

    int uniquePaths(int m, int n) {

        // Initialize DP table with -1
        // (-1 means not computed yet)
        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, m, n);
    }
};

// ==========================================
// Approach 3: Space Optimized DP
//
// Observation:
// Current cell depends only on:
// 1. Upper cell
// 2. Left cell
//
// Therefore we only need one row.
//
// Time Complexity : O(m*n)
// Space Complexity: O(n)
// ==========================================

class Solution {
public:

    int uniquePaths(int m, int n) {

        // First row always contains 1
        // because there is only one way
        // to move continuously to the right.
        vector<int> dp(n, 1);

        // Process remaining rows
        for (int i = 1; i < m; i++) {

            // First column always remains 1
            // because we can only move down.
            for (int j = 1; j < n; j++) {

                // dp[j]     -> value from upper cell
                // dp[j-1]   -> value from left cell
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        // Bottom-right cell answer
        return dp[n - 1];
    }
};
