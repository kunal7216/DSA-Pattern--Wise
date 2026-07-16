// N- Queens Problem using Backtracking
// leetcode: https://leetcode.com/problems/n-queens/
//  leetcode - 51

// ===========================
// Approach 1: Brute Force (Generate All Boards)
// Time Complexity: O(2^(N*N) * N^2)
// Space Complexity: O(N^2)
// ===========================

class Solution1 {
public:
    vector<vector<string>> ans;

    bool isValid(vector<string>& board, int n) {

        int queens = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'Q') {
                    queens++;

                    // Check row
                    for (int k = j + 1; k < n; k++)
                        if (board[i][k] == 'Q')
                            return false;

                    // Check column
                    for (int k = i + 1; k < n; k++)
                        if (board[k][j] == 'Q')
                            return false;

                    // Check main diagonal
                    for (int x = i + 1, y = j + 1; x < n && y < n; x++, y++)
                        if (board[x][y] == 'Q')
                            return false;

                    // Check anti-diagonal
                    for (int x = i + 1, y = j - 1; x < n && y >= 0; x++, y--)
                        if (board[x][y] == 'Q')
                            return false;
                }
            }
        }

        return queens == n;
    }

    void generate(vector<string>& board, int idx, int n) {

        if (idx == n * n) {
            if (isValid(board, n))
                ans.push_back(board);
            return;
        }

        int row = idx / n;
        int col = idx % n;

        // Place Queen
        board[row][col] = 'Q';
        generate(board, idx + 1, n);

        // Don't Place Queen
        board[row][col] = '.';
        generate(board, idx + 1, n);
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        generate(board, 0, n);

        return ans;
    }
};



// ===========================
// Approach 2: Backtracking + Safety Check
// Time Complexity: O(N! * N)
// Space Complexity: O(N^2)
// ===========================

class Solution2 {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // Check left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Check right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void backtrack(vector<string>& board, int row, int n) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (!isSafe(board, row, col, n))
                continue;

            board[row][col] = 'Q';

            backtrack(board, row + 1, n);

            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        backtrack(board, 0, n);

        return ans;
    }
};



// ===========================
// Approach 3: Optimal (Backtracking + Hashing)
// Time Complexity: O(N!)
// Space Complexity: O(N^2)
// ===========================

class Solution {
public:
    vector<vector<string>> ans;

    void backtrack(vector<string>& board,
                   int row,
                   int n,
                   vector<int>& col,
                   vector<int>& diag,
                   vector<int>& antiDiag) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            int d = row - c + n - 1;
            int ad = row + c;

            if (col[c] || diag[d] || antiDiag[ad])
                continue;

            board[row][c] = 'Q';

            col[c] = 1;
            diag[d] = 1;
            antiDiag[ad] = 1;

            backtrack(board, row + 1, n, col, diag, antiDiag);

            board[row][c] = '.';

            col[c] = 0;
            diag[d] = 0;
            antiDiag[ad] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> diag(2 * n - 1, 0);
        vector<int> antiDiag(2 * n - 1, 0);

        backtrack(board, 0, n, col, diag, antiDiag);

        return ans;
    }
};
