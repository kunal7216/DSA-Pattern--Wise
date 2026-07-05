// word search I -- 79
// link: https://leetcode.com/problems/word-search/



// Brute Force -- without visited matrix 
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        if (board[i][j] != word[idx])
            return false;

        return dfs(board, word, i + 1, j, idx + 1) ||
               dfs(board, word, i - 1, j, idx + 1) ||
               dfs(board, word, i, j + 1, idx + 1) ||
               dfs(board, word, i, j - 1, idx + 1);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};


// Better Solution -- with Visited matrix
class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             string &word, int i, int j, int idx) {

        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        if (visited[i][j] || board[i][j] != word[idx])
            return false;

        visited[i][j] = true;

        bool found = dfs(board, visited, word, i + 1, j, idx + 1) ||
                     dfs(board, visited, word, i - 1, j, idx + 1) ||
                     dfs(board, visited, word, i, j + 1, idx + 1) ||
                     dfs(board, visited, word, i, j - 1, idx + 1);

        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size(), n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(board, visited, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};


// optimal Solution -- in place backtracking

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word,
             int i, int j, int idx) {

        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        if (board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
