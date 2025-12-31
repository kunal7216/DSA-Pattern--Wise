// pacific atlantic water flow
// leetcode: https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution
{
public:
    int m, n;

    // Possible directions: down, up, right, left
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        // Grid dimensions
        m = heights.size();
        n = heights[0].size();

        // visited matrices for each ocean
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // ---------------- Pacific Ocean DFS ----------------
        // Pacific touches top row
        for (int j = 0; j < n; j++)
        { 
            dfs(0, j, heights, pacific);
        }

        // Pacific touches left column
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, heights, pacific);
        }

        // ---------------- Atlantic Ocean DFS ----------------
        // Atlantic touches bottom row
        for (int j = 0; j < n; j++)
        {
            dfs(m - 1, j, heights, atlantic);
        }

        // Atlantic touches right column
        for (int i = 0; i < m; i++)
        {
            dfs(i, n - 1, heights, atlantic);
        }

        // ---------------- Find Intersection ----------------
        vector<vector<int>> result;

        // A cell that can reach both oceans is part of the answer
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    // Depth First Search to mark reachable cells
    void dfs(int i, int j, vector<vector<int>> &heights,
             vector<vector<bool>> &visited)
    {

        // Mark current cell as visited
        visited[i][j] = true;

        // Explore all 4 directions
        for (auto &d : directions)
        {
            int x = i + d[0];
            int y = j + d[1];

            // Boundary check
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;

            // Skip already visited cells
            if (visited[x][y])
                continue;

            // Only move uphill or on same height
            // (reverse water flow logic)
            if (heights[x][y] < heights[i][j])
                continue;

            dfs(x, y, heights, visited);
        }
    }
};
