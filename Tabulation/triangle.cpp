// triangle 
// leetcode 120
// https://leetcode.com/problems/triangle/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        // DP array: dp[i] = min path sum to reach bottom from current row
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Bottom-up calculation
        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = 0; col <= row; col++)
            {
                dp[row][col] = triangle[row][col] + min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }

        return dp[0][0]; // minimum path sum from top
    }
};
