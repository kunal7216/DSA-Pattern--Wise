// Rotting oranges 
// leetcode 994

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        // Number of rows and columns
        int n = grid.size();
        int m = grid[0].size();

        // Queue will store:
        // {{row, column}, time_taken}
        queue<pair<pair<int, int>, int>> q;

        // Visited array to mark oranges that are already rotten
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntFresh = 0; // Count of total fresh oranges

        // Step 1: Traverse the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // If orange is already rotten
                if (grid[i][j] == 2)
                {
                    // Push into queue with time = 0
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark as rotten
                }

                // Count fresh oranges
                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }

        int tm = 0;  // Maximum time required
        int cnt = 0; // Number of fresh oranges that became rotten

        // Direction arrays for Up, Right, Down, Left movement
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        // Step 2: Perform BFS
        while (!q.empty())
        {

            // Current cell position
            int r = q.front().first.first;
            int c = q.front().first.second;

            // Time taken to reach this cell
            int t = q.front().second;
            q.pop();

            // Update maximum time
            tm = max(tm, t);

            // Check all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check boundaries, unvisited, and fresh orange
                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 &&
                    grid[nrow][ncol] == 1)
                {

                    // Make the fresh orange rotten
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++; // Increment rotten count
                }
            }
        }

        // Step 3: If some fresh oranges never rotted
        if (cnt != cntFresh)
            return -1;

        // Otherwise, return time taken
        return tm;
    }
};
