// N- Queens Problem using Backtracking
// leetcode: https://leetcode.com/problems/n-queens/
//  leetcode - 51

class Solution
{
public:
    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        // Check horizontally (same row)
        for (int j = 0; j < n; j++)
        {
            if (board[row][j] == 'Q')
            {
                return false;
            }
        }

        // Check vertically (same column)
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // Check left upper diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // Check right upper diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    // Recursive function to place queens row by row
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
    {
        // Base case: all queens placed
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        // Try placing queen in each column of the current row
        for (int j = 0; j < n; j++)
        {
            if (isSafe(board, row, j, n))
            {
                board[row][j] = 'Q';             // Place queen
                nQueens(board, row + 1, n, ans); // Recurse
                board[row][j] = '.';             // Backtrack
            }
        }
    }

    // Main function to solve N-Queens
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans;
    }
};
