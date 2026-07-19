// triangle 
// leetcode 120
// https://leetcode.com/problems/triangle/

// ================================
// Approach 1 : Pure Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n) recursion stack
// ================================

class Solution {
public:

    int solve(vector<vector<int>>& triangle, int i, int j)
    {
        // Reached last row
        if(i == triangle.size()-1)
            return triangle[i][j];

        // Go downward
        int down = solve(triangle, i+1, j);

        // Go diagonal
        int diagonal = solve(triangle, i+1, j+1);

        // Current value + minimum path
        return triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle,0,0);
    }
};

// ==================================
// Approach 2 : Memoization (Top Down)
// Time Complexity : O(n²)
// Space Complexity : O(n²) + O(n)
// ==================================

class Solution {
public:

    vector<vector<int>> dp;

    int solve(vector<vector<int>>& triangle, int i, int j)
    {
        // Base case
        if(i == triangle.size()-1)
            return triangle[i][j];

        // Already computed
        if(dp[i][j] != -1)
            return dp[i][j];

        int down = solve(triangle,i+1,j);
        int diagonal = solve(triangle,i+1,j+1);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        dp.assign(n, vector<int>(n,-1));

        return solve(triangle,0,0);
    }
};

// ==========================================
// Approach 3 : Bottom-Up DP (Space Optimized)
// Time Complexity : O(n²)
// Space Complexity : O(n)
// ==========================================

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        // Copy last row as initial DP
        vector<int> dp = triangle[n-1];

        // Process from second last row upwards
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                // Current value + minimum of two children
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};
