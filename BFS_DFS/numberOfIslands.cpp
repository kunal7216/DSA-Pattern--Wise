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

*************************************************************Brute Solution*************************************************************************************


class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }

        if (grid[r][c] == '0' || visited[r][c] == 1) {
            return;
        }

        visited[r][c] = 1;

        dfs(grid, visited, r + 1, c);
        dfs(grid, visited, r - 1, c);
        dfs(grid, visited, r, c + 1);
        dfs(grid, visited, r, c - 1);
    }

    bool isSameIsland(vector<vector<char>>& grid, int r1, int c1, int r2, int c2) {
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        dfs(grid, visited, r1, c1);

        return visited[r2][c2] == 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<pair<int, int>> lands;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    lands.push_back({i, j});
                }
            }
        }

        int count = 0;

        for (int i = 0; i < lands.size(); i++) {
            bool alreadyCounted = false;

            for (int j = 0; j < i; j++) {
                if (isSameIsland(grid, lands[i].first, lands[i].second,
                                 lands[j].first, lands[j].second)) {
                    alreadyCounted = true;
                    break;
                }
            }

            if (!alreadyCounted) {
                count++;
            }
        }

        return count;
    }
};
*************************************************************Better Solution*************************************************************************************


class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }

        if (grid[r][c] == '0' || visited[r][c] == 1) {
            return;
        }

        visited[r][c] = 1;

        dfs(grid, visited, r + 1, c);
        dfs(grid, visited, r - 1, c);
        dfs(grid, visited, r, c + 1);
        dfs(grid, visited, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    islands++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return islands;
    }
};
*************************************************************Optimal Solution*************************************************************************************


class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }

        if (grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};
