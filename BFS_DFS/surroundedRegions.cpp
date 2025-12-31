// surrounded regions 
// leetcode 130

class Solution
{
private:
    // DFS function to mark all 'O' cells connected to boundary as safe
    void dfs(int row, int col,
             vector<vector<int>> &vis,
             vector<vector<char>> &board,
             int delrow[], int delcol[])
    {

        // Mark current cell as visited (safe)
        vis[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check:
            // 1. New cell is inside the grid
            // 2. Not visited yet
            // 3. Cell contains 'O'
            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O')
            {

                // Continue DFS for connected 'O'
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {

        int n = board.size();
        int m = board[0].size();

        // Visited array to track safe 'O' cells
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Direction arrays: up, right, down, left
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Step 1: Traverse first and last row
        for (int j = 0; j < m; j++)
        {

            // First row
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, vis, board, delrow, delcol);

            // Last row
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, vis, board, delrow, delcol);
        }

        // Step 2: Traverse first and last column
        for (int i = 0; i < n; i++)
        {

            // First column
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, vis, board, delrow, delcol);

            // Last column
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, vis, board, delrow, delcol);
        }

        // Step 3: Flip all unvisited 'O' to 'X'
        // Unvisited 'O' are completely surrounded
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
