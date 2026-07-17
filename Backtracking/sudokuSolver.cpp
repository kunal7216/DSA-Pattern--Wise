// ============================================================
// Approach 1: Brute Force Backtracking
//
// Intuition:
// -----------
// 1. Traverse the Sudoku board to find the first empty cell ('.').
// 2. Try placing every digit from '1' to '9'.
// 3. Before placing a digit, check whether it is valid:
//      - Not already present in the current row.
//      - Not already present in the current column.
//      - Not already present in the current 3x3 sub-grid.
// 4. If valid:
//      - Place the digit.
//      - Recursively solve the remaining board.
// 5. If recursion fails, remove the digit (Backtrack).
// 6. If all digits fail, return false.
//
// Time Complexity:
// ----------------
// Worst Case: O(9^E * 9)
// E = Number of empty cells.
// Each empty cell can try up to 9 numbers.
// Validity checking takes O(9).
//
// Space Complexity:
// -----------------
// O(E)
// Recursive call stack.
// ============================================================

class Solution {
public:

    // Check whether placing 'num' at (row, col) is valid.
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {

        for (int i = 0; i < 9; i++) {

            // Check row
            if (board[row][i] == num)
                return false;

            // Check column
            if (board[i][col] == num)
                return false;

            // Check 3x3 box
            int newRow = 3 * (row / 3) + i / 3;
            int newCol = 3 * (col / 3) + i % 3;

            if (board[newRow][newCol] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        // Find next empty cell
        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    // Try every digit
                    for (char num = '1'; num <= '9'; num++) {

                        if (isValid(board, row, col, num)) {

                            // Choose
                            board[row][col] = num;

                            // Explore
                            if (solve(board))
                                return true;

                            // Undo (Backtrack)
                            board[row][col] = '.';
                        }
                    }

                    // No valid number found
                    return false;
                }
            }
        }

        // Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// ============================================================
// Approach 2: Backtracking + Hash Arrays
//
// Improvement over Brute Force:
// -----------------------------
// Instead of scanning row/column/box every time,
// maintain three lookup tables:
//
// row[i][num]
// col[j][num]
// box[k][num]
//
// This makes validity checking O(1).
//
// Time Complexity:
// ----------------
// O(9^E)
//
// Space Complexity:
// -----------------
// O(E) recursion
// + O(9×10×3) lookup arrays
// ============================================================

class Solution {
public:

    // row[i][num] = true if num already exists in row i
    bool row[9][10] = {};

    // col[j][num] = true if num already exists in column j
    bool col[9][10] = {};

    // box[k][num] = true if num already exists in box k
    bool box[9][10] = {};

    bool solve(vector<vector<char>>& board) {

        for (int r = 0; r < 9; r++) {

            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.') {

                    int boxIndex = (r / 3) * 3 + (c / 3);

                    for (int num = 1; num <= 9; num++) {

                        // Check in O(1)
                        if (!row[r][num] &&
                            !col[c][num] &&
                            !box[boxIndex][num]) {

                            // Choose
                            board[r][c] = num + '0';

                            row[r][num] = true;
                            col[c][num] = true;
                            box[boxIndex][num] = true;

                            // Explore
                            if (solve(board))
                                return true;

                            // Undo
                            board[r][c] = '.';

                            row[r][num] = false;
                            col[c][num] = false;
                            box[boxIndex][num] = false;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        // Fill lookup arrays using initial Sudoku board
        for (int r = 0; r < 9; r++) {

            for (int c = 0; c < 9; c++) {

                if (board[r][c] != '.') {

                    int num = board[r][c] - '0';
                    int boxIndex = (r / 3) * 3 + (c / 3);

                    row[r][num] = true;
                    col[c][num] = true;
                    box[boxIndex][num] = true;
                }
            }
        }

        solve(board);
    }
};

// ============================================================
// Approach 3: Backtracking + Bitmask
//
// Intuition:
// ----------
// Instead of boolean arrays, store digits using bits.
//
// Example:
//
// Bit Position:
// 1 2 3 4 5 6 7 8 9
//
// If digit 5 exists,
// corresponding bit becomes 1.
//
// Checking validity:
//
// if(mask & (1<<digit))
//
// becomes O(1) using bit operations.
//
// Time Complexity:
// ----------------
// O(9^E)
//
// Space Complexity:
// -----------------
// O(E)
//
// This is the fastest practical solution.
// ============================================================

class Solution {
public:

    // Bitmask for every row
    int rowMask[9] = {};

    // Bitmask for every column
    int colMask[9] = {};

    // Bitmask for every box
    int boxMask[9] = {};

    bool solve(vector<vector<char>>& board) {

        for (int r = 0; r < 9; r++) {

            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.') {

                    int boxIndex = (r / 3) * 3 + (c / 3);

                    // Try every digit
                    for (int num = 1; num <= 9; num++) {

                        int bit = (1 << num);

                        // Check whether digit already exists
                        if (!(rowMask[r] & bit) &&
                            !(colMask[c] & bit) &&
                            !(boxMask[boxIndex] & bit)) {

                            // Choose
                            board[r][c] = num + '0';

                            rowMask[r] |= bit;
                            colMask[c] |= bit;
                            boxMask[boxIndex] |= bit;

                            // Explore
                            if (solve(board))
                                return true;

                            // Undo (Backtrack)
                            board[r][c] = '.';

                            rowMask[r] ^= bit;
                            colMask[c] ^= bit;
                            boxMask[boxIndex] ^= bit;
                        }
                    }

                    // No digit works
                    return false;
                }
            }
        }

        // Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        // Build initial bitmasks
        for (int r = 0; r < 9; r++) {

            for (int c = 0; c < 9; c++) {

                if (board[r][c] != '.') {

                    int num = board[r][c] - '0';
                    int bit = (1 << num);

                    int boxIndex = (r / 3) * 3 + (c / 3);

                    rowMask[r] |= bit;
                    colMask[c] |= bit;
                    boxMask[boxIndex] |= bit;
                }
            }
        }

        solve(board);
    }
};
