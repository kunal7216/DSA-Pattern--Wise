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


**************************************************************Brute Solution***************************************************************************************
    class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, int r, int c, vector<vector<int>>& visited) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return true;
        }

        if (board[r][c] == 'X' || visited[r][c]) {
            return false;
        }

        visited[r][c] = 1;

        bool touchesBoundary = false;

        touchesBoundary |= dfs(board, r - 1, c, visited);
        touchesBoundary |= dfs(board, r + 1, c, visited);
        touchesBoundary |= dfs(board, r, c - 1, visited);
        touchesBoundary |= dfs(board, r, c + 1, visited);

        return touchesBoundary;
    }

    void mark(vector<vector<char>>& board, int r, int c, vector<vector<int>>& visited) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        if (board[r][c] == 'X' || visited[r][c]) {
            return;
        }

        visited[r][c] = 1;
        board[r][c] = 'X';

        mark(board, r - 1, c, visited);
        mark(board, r + 1, c, visited);
        mark(board, r, c - 1, visited);
        mark(board, r, c + 1, visited);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    vector<vector<int>> visited(m, vector<int>(n, 0));

                    bool connectedToBoundary = dfs(board, i, j, visited);

                    if (!connectedToBoundary) {
                        vector<vector<int>> markVisited(m, vector<int>(n, 0));
                        mark(board, i, j, markVisited);
                    }
                }
            }
        }
    }
};
**************************************************************Better Solution***************************************************************************************
    class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board,
             int r,
             int c,
             vector<vector<int>>& visited,
             vector<pair<int, int>>& component,
             bool& touchesBoundary) {
        
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        if (board[r][c] == 'X' || visited[r][c]) {
            return;
        }

        visited[r][c] = 1;
        component.push_back({r, c});

        if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
            touchesBoundary = true;
        }

        dfs(board, r - 1, c, visited, component, touchesBoundary);
        dfs(board, r + 1, c, visited, component, touchesBoundary);
        dfs(board, r, c - 1, visited, component, touchesBoundary);
        dfs(board, r, c + 1, visited, component, touchesBoundary);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    vector<pair<int, int>> component;
                    bool touchesBoundary = false;

                    dfs(board, i, j, visited, component, touchesBoundary);

                    if (!touchesBoundary) {
                        for (auto cell : component) {
                            int r = cell.first;
                            int c = cell.second;
                            board[r][c] = 'X';
                        }
                    }
                }
            }
        }
    }
};
**************************************************************optimal Solution***************************************************************************************
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;

        auto add = [&](int r, int c) {
            if (r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O') {
                board[r][c] = '#';
                q.push({r, c});
            }
        };

        for (int i = 0; i < m; i++) {
            add(i, 0);
            add(i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            add(0, j);
            add(m - 1, j);
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                add(nr, nc);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
