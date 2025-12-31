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
