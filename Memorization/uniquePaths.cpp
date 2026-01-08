// unique paths
// https://leetcode.com/problems/unique-paths/
// leetcode question id: 62

class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        // DP grid where grid[i][j] = number of ways to reach cell (i, j)
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Iterate over the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // First row or first column has only one way
                if (i == 0 || j == 0)
                {
                    grid[i][j] = 1;
                }
                // Ways come from top and left cells
                else
                {
                    grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
                }
            }
        }

        // Return ways to reach bottom-right cell
        return grid[m - 1][n - 1];
    }
};
