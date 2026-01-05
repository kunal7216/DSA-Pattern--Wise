// sudoku solver using backtracking
// leetcode: https://leetcode.com/problems/sudoku-solver/
// leetcode - 37

class Solution
{
public:
    // Check if placing digit is valid at (row, col)
    bool isSafe(vector<vector<char>> &board, int row, int col, char dig)
    {
        for (int i = 0; i < 9; i++)
        {
            // Check row
            if (board[row][i] == dig)
                return false;

            // Check column
            if (board[i][col] == dig)
                return false;

            // Check 3x3 subgrid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == dig)
                return false;
        }
        return true;
    }

    // Recursive helper function
    bool helper(vector<vector<char>> &board, int row, int col)
    {
        // If we reach beyond the last row, sudoku is solved
        if (row == 9)
            return true;

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9)
        {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If cell is already filled, move to next cell
        if (board[row][col] != '.')
        {
            return helper(board, nextRow, nextCol);
        }

        // Try placing digits from 1 to 9
        for (char dig = '1'; dig <= '9'; dig++)
        {
            if (isSafe(board, row, col, dig))
            {
                board[row][col] = dig;

                if (helper(board, nextRow, nextCol))
                {
                    return true;
                }

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    // Main function
    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board, 0, 0);
    }
};
