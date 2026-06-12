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


**************************************************************Brute Solution***************************************************************************************
    class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int minutes = 0;

        while (true) {
            bool changed = false;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        if (i > 0 && grid[i - 1][j] == 1) {
                            grid[i - 1][j] = 3;
                            changed = true;
                        }

                        if (i < m - 1 && grid[i + 1][j] == 1) {
                            grid[i + 1][j] = 3;
                            changed = true;
                        }

                        if (j > 0 && grid[i][j - 1] == 1) {
                            grid[i][j - 1] = 3;
                            changed = true;
                        }

                        if (j < n - 1 && grid[i][j + 1] == 1) {
                            grid[i][j + 1] = 3;
                            changed = true;
                        }
                    }
                }
            }

            if (!changed) {
                break;
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 3) {
                        grid[i][j] = 2;
                    }
                }
            }

            minutes++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minutes;
    }
};
**************************************************************Better Solution***************************************************************************************
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> rotten;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    rotten.push_back({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        int minutes = 0;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!rotten.empty()) {
            vector<pair<int, int>> nextRotten;

            for (auto cell : rotten) {
                int row = cell.first;
                int col = cell.second;

                for (int k = 0; k < 4; k++) {
                    int newRow = row + dx[k];
                    int newCol = col + dy[k];

                    if (newRow >= 0 && newRow < m &&
                        newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 1) {
                        
                        grid[newRow][newCol] = 2;
                        fresh--;
                        nextRotten.push_back({newRow, newCol});
                    }
                }
            }

            if (nextRotten.empty()) {
                break;
            }

            rotten = nextRotten;
            minutes++;
        }

        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};
**************************************************************optimal Solution***************************************************************************************

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Add all rotten oranges to queue
        // and count fresh oranges.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If there are no fresh oranges, answer is 0.
        if (fresh == 0) {
            return 0;
        }

        int minutes = 0;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Step 2: BFS level by level
        while (!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;

            for (int i = 0; i < size; i++) {
                auto cell = q.front();
                q.pop();

                int row = cell.first;
                int col = cell.second;

                for (int k = 0; k < 4; k++) {
                    int newRow = row + dx[k];
                    int newCol = col + dy[k];

                    if (newRow >= 0 && newRow < m &&
                        newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 1) {
                        
                        grid[newRow][newCol] = 2;
                        fresh--;
                        q.push({newRow, newCol});
                        rottedThisMinute = true;
                    }
                }
            }

            if (rottedThisMinute) {
                minutes++;
            }
        }

        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};
    
