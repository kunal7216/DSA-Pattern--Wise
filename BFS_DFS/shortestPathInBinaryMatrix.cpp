// Shortest path in a binary matrix
// leetcode: https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int n = grid.size();

        // If start or destination is blocked, no path exists
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // All 8 possible directions (horizontal, vertical, diagonal)
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        // Queue for BFS (stores row, col)
        queue<pair<int, int>> q;

        // Start from top-left corner
        q.push({0, 0});

        // Mark starting cell as visited
        grid[0][0] = 1;

        // Initial path length starts from 1
        int pathLength = 1;

        // Standard BFS loop
        while (!q.empty())
        {

            int levelSize = q.size(); // nodes at current BFS level

            // Process all nodes at current distance
            while (levelSize--)
            {

                auto [x, y] = q.front();
                q.pop();

                // If destination reached, return path length
                if (x == n - 1 && y == n - 1)
                    return pathLength;

                // Explore all 8 directions
                for (auto [dx, dy] : directions)
                {

                    int newX = x + dx;
                    int newY = y + dy;

                    // Check boundaries and if cell is unvisited & open
                    if (newX >= 0 && newY >= 0 &&
                        newX < n && newY < n &&
                        grid[newX][newY] == 0)
                    {

                        // Mark as visited
                        grid[newX][newY] = 1;

                        // Push next cell into queue
                        q.push({newX, newY});
                    }
                }
            }

            // Increment path length after finishing one level
            pathLength++;
        }

        // Destination not reachable
        return -1;
    }
};

**********************************************************Brute solution***********************************************************************
    class Solution {
public:
    int n;
    int answer = INT_MAX;

    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    void dfs(vector<vector<int>>& grid, int row, int col, int length) {
        // If out of bounds, return
        if (row < 0 || col < 0 || row >= n || col >= n) {
            return;
        }

        // If blocked cell, return
        if (grid[row][col] == 1) {
            return;
        }

        // If already visited in current path, return
        if (grid[row][col] == 2) {
            return;
        }

        // If reached destination
        if (row == n - 1 && col == n - 1) {
            answer = min(answer, length);
            return;
        }

        // Mark visited
        grid[row][col] = 2;

        // Explore all 8 directions
        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            dfs(grid, newRow, newCol, length + 1);
        }

        // Backtrack
        grid[row][col] = 0;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        // Start or end blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        dfs(grid, 0, 0, 1);

        return answer == INT_MAX ? -1 : answer;
    }
};
**********************************************************Better Solution***********************************************************************
    class Solution {
public:
    int n;
    int answer = INT_MAX;

    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    void dfs(vector<vector<int>>& grid, int row, int col, int length) {
        // Out of bounds
        if (row < 0 || col < 0 || row >= n || col >= n) {
            return;
        }

        // Blocked or visited
        if (grid[row][col] != 0) {
            return;
        }

        // Pruning:
        // If current path is already not better, stop
        if (length >= answer) {
            return;
        }

        // Destination reached
        if (row == n - 1 && col == n - 1) {
            answer = min(answer, length);
            return;
        }

        // Mark visited
        grid[row][col] = 2;

        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            dfs(grid, newRow, newCol, length + 1);
        }

        // Backtrack
        grid[row][col] = 0;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        dfs(grid, 0, 0, 1);

        return answer == INT_MAX ? -1 : answer;
    }
};
**********************************************************Optimal Solution***********************************************************************

    class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // If starting cell or ending cell is blocked, path is impossible
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // 8 possible directions
        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        queue<pair<int, int>> q;

        // Start BFS from top-left cell
        q.push({0, 0});

        // Mark start as visited
        grid[0][0] = 1;

        int pathLength = 1;

        while (!q.empty()) {
            int size = q.size();

            // Process one BFS level
            while (size--) {
                auto [row, col] = q.front();
                q.pop();

                // If destination reached, return current path length
                if (row == n - 1 && col == n - 1) {
                    return pathLength;
                }

                // Explore all 8 directions
                for (auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    // Check boundary
                    if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) {
                        continue;
                    }

                    // Only move to unblocked and unvisited cells
                    if (grid[newRow][newCol] != 0) {
                        continue;
                    }

                    // Mark visited
                    grid[newRow][newCol] = 1;

                    // Push into queue
                    q.push({newRow, newCol});
                }
            }

            // After completing current level, increase path length
            pathLength++;
        }

        // Destination not reachable
        return -1;
    }
};
