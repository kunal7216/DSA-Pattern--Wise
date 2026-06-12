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

**************************************************************Brute Solution***************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;

    // 4 possible movement directions: down, up, right, left
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // DFS function to check if water from cell (r, c) can reach oceans
    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             bool& canPacific,
             bool& canAtlantic) {
        
        // If cell touches Pacific boundary
        if (r == 0 || c == 0) {
            canPacific = true;
        }

        // If cell touches Atlantic boundary
        if (r == rows - 1 || c == cols - 1) {
            canAtlantic = true;
        }

        // Mark current cell as visited
        visited[r][c] = true;

        // Explore all 4 directions
        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            // Check boundary
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                continue;
            }

            // If already visited, skip
            if (visited[nr][nc]) {
                continue;
            }

            // Water can flow only from higher/equal to lower/equal height
            if (heights[nr][nc] <= heights[r][c]) {
                dfs(nr, nc, heights, visited, canPacific, canAtlantic);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<int>> answer;

        // Try DFS from every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));

                bool canPacific = false;
                bool canAtlantic = false;

                dfs(r, c, heights, visited, canPacific, canAtlantic);

                // If both oceans are reachable, store this cell
                if (canPacific && canAtlantic) {
                    answer.push_back({r, c});
                }
            }
        }

        return answer;
    }
};
**************************************************************Better Solution***************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;

    // 4 directions: down, up, right, left
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& oceanReachable) {
        
        // Mark current cell as reachable from this ocean
        oceanReachable[r][c] = true;

        // Explore all 4 neighbors
        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            // Boundary check
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                continue;
            }

            // If already visited for this ocean, skip
            if (oceanReachable[nr][nc]) {
                continue;
            }

            /*
                Reverse flow condition:

                Normal water flow:
                current cell can flow to neighbor if neighbor height <= current height.

                Reverse thinking:
                From ocean, we move to neighbor only if neighbor height >= current height.

                Why?
                Because then that neighbor can send water back to current cell.
            */
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, oceanReachable);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Start DFS from Pacific border cells
        for (int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific);          // Top row
            dfs(rows - 1, c, heights, atlantic); // Bottom row
        }

        for (int r = 0; r < rows; r++) {
            dfs(r, 0, heights, pacific);          // Left column
            dfs(r, cols - 1, heights, atlantic); // Right column
        }

        vector<vector<int>> answer;

        // A cell is valid if both oceans can reach it in reverse traversal
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    answer.push_back({r, c});
                }
            }
        }

        return answer;
    }
};
**************************************************************optimal Solution***************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // visited arrays for both oceans
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        /*
            Add Pacific border cells:
            Pacific touches top row and left column.
        */
        for (int c = 0; c < cols; c++) {
            pacific[0][c] = true;
            pacificQueue.push({0, c});
        }

        for (int r = 0; r < rows; r++) {
            pacific[r][0] = true;
            pacificQueue.push({r, 0});
        }

        /*
            Add Atlantic border cells:
            Atlantic touches bottom row and right column.
        */
        for (int c = 0; c < cols; c++) {
            atlantic[rows - 1][c] = true;
            atlanticQueue.push({rows - 1, c});
        }

        for (int r = 0; r < rows; r++) {
            atlantic[r][cols - 1] = true;
            atlanticQueue.push({r, cols - 1});
        }

        // Run BFS for both oceans
        bfs(heights, pacificQueue, pacific);
        bfs(heights, atlanticQueue, atlantic);

        vector<vector<int>> answer;

        // Intersection of Pacific reachable and Atlantic reachable cells
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    answer.push_back({r, c});
                }
            }
        }

        return answer;
    }

private:
    void bfs(vector<vector<int>>& heights,
             queue<pair<int, int>>& q,
             vector<vector<bool>>& visited) {
        
        int rows = heights.size();
        int cols = heights[0].size();

        // 4 directions: down, up, right, left
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                // Boundary check
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                    continue;
                }

                // Already visited for this ocean
                if (visited[nr][nc]) {
                    continue;
                }

                /*
                    Reverse flow condition:

                    We are going from ocean inward.

                    We can move from current cell to neighbor only if:
                    neighbor height >= current height

                    Because in normal direction, water from that neighbor
                    can flow down/equal to current cell.
                */
                if (heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
};
