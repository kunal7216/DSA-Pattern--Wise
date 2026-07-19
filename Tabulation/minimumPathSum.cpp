// minimum path sum
// link: https://leetcode.com/problems/minimum-path-sum/
// leetcode question id: 64

// ===============================
// Approach 1: Brute Force (Recursion)
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)
// ===============================

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Reached destination
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        // Out of boundary
        if (i >= m || j >= n)
            return INT_MAX;

        // Move Down
        int down = solve(i + 1, j, grid);

        // Move Right
        int right = solve(i, j + 1, grid);

        return grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        return solve(0, 0, grid);
    }
};

// ===============================
// Approach 2: Memoization (Top-Down DP)
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// ===============================

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (i >= m || j >= n)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = solve(i + 1, j, grid, dp);
        int right = solve(i, j + 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, grid, dp);
    }
};

// ===============================
// Approach 3: Bottom-Up DP (Optimal)
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
// ===============================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // DP table where dp[i][j] stores
        // minimum path sum to reach cell (i,j)
        vector<vector<int>> dp(m, vector<int>(n));

        // Starting cell
        dp[0][0] = grid[0][0];

        // Fill first row
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];

        // Fill first column
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        // Fill remaining cells
        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                // Minimum of top and left path
                dp[i][j] = grid[i][j] +
                           min(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};

// ===============================
// Space Optimized DP
// Time Complexity: O(m*n)
// Space Complexity: O(n)
// ===============================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);

        dp[0] = grid[0][0];

        // First row
        for (int j = 1; j < n; j++)
            dp[j] = dp[j - 1] + grid[0][j];

        for (int i = 1; i < m; i++) {

            // First column
            dp[0] += grid[i][0];

            for (int j = 1; j < n; j++) {

                dp[j] = grid[i][j] +
                        min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};
