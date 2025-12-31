// find the number of islands in a 2D grid
// leetcode 200: https://leetcode.com/problems/number-of-islands/

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {

        // Edge case: if grid is empty, no islands exist
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int numIslands = 0;

        // Traverse each cell in the grid
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {

                // If land ('1') is found, it starts a new island
                if (grid[i][j] == '1')
                {
                    numIslands++;    // Count the new island
                    dfs(grid, i, j); // Mark entire island as visited
                }
            }
        }

        return numIslands;
    }

private:
    // Depth First Search to explore all connected land cells
    void dfs(vector<vector<char>> &grid, int i, int j)
    {

        // Base case:
        // 1. Out of bounds
        // 2. Water cell ('0')
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] != '1')
        {
            return;
        }

        // Mark the current land cell as visited
        grid[i][j] = '0';

        // Explore all 4 possible directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
};
