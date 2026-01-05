// word search I
// link: https://leetcode.com/problems/word-search/

class Solution
{
public:
    // DFS function to search the word starting from board[i][j]
    bool search(int index, int i, int j,
                vector<vector<char>> &board,
                string word)
    {

        // Base case: if all characters of the word are matched
        if (index == word.size())
            return true;

        // Boundary check: if indices go out of grid
        if (i < 0 || j < 0 ||
            i >= board.size() ||
            j >= board[0].size())
            return false;

        // If current cell does not match the required character
        if (board[i][j] != word[index])
            return false;

        // Store the current character
        char temp = board[i][j];

        // Mark the cell as visited to avoid reuse
        board[i][j] = '*';

        // Explore all 4 possible directions
        bool ans =
            search(index + 1, i + 1, j, board, word) || // down
            search(index + 1, i - 1, j, board, word) || // up
            search(index + 1, i, j + 1, board, word) || // right
            search(index + 1, i, j - 1, board, word);   // left

        // Backtrack: restore the original character
        board[i][j] = temp;

        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        // Try starting DFS from every cell in the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // Start search only if first character matches
                if (board[i][j] == word[0])
                {
                    if (search(0, i, j, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};
