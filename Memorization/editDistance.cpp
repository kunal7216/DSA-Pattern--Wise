// edit distance 
// leetcode 72
// leetcode problem link: https://leetcode.com/problems/edit-distance/

// ==========================================================
// Approach 1: Brute Force (Pure Recursion)
// Time Complexity: O(3^(m+n))
// Space Complexity: O(m+n) (Recursion Stack)
// ==========================================================

class Solution {
public:
    int solve(string &word1, string &word2, int i, int j) {

        // If word1 is exhausted, insert remaining characters of word2
        if (i == word1.size())
            return word2.size() - j;

        // If word2 is exhausted, delete remaining characters of word1
        if (j == word2.size())
            return word1.size() - i;

        // Characters match → move both pointers
        if (word1[i] == word2[j])
            return solve(word1, word2, i + 1, j + 1);

        // Try all three operations
        int insertOp = solve(word1, word2, i, j + 1);
        int deleteOp = solve(word1, word2, i + 1, j);
        int replaceOp = solve(word1, word2, i + 1, j + 1);

        return 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};

// ==========================================================
// Approach 2: Memoization (Top-Down DP)
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
// ==========================================================

class Solution {
public:
    vector<vector<int>> dp;

    int solve(string &word1, string &word2, int i, int j) {

        if (i == word1.size())
            return word2.size() - j;

        if (j == word2.size())
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = solve(word1, word2, i + 1, j + 1);

        int insertOp = solve(word1, word2, i, j + 1);
        int deleteOp = solve(word1, word2, i + 1, j);
        int replaceOp = solve(word1, word2, i + 1, j + 1);

        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {

        dp.assign(word1.size(), vector<int>(word2.size(), -1));

        return solve(word1, word2, 0, 0);
    }
};

// ==========================================================
// Approach 3: Bottom-Up Dynamic Programming
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
// ==========================================================

class Solution {
public:
    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        // dp[i][j] = minimum operations to convert
        // first i characters of word1 into first j characters of word2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Base cases
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;

        for (int j = 0; j <= n; j++)
            dp[0][j] = j;

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // Characters match
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Characters differ
                else {
                    int insertOp = dp[i][j - 1];
                    int deleteOp = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[m][n];
    }
};

// ==========================================================
// Space Optimized DP
// Time Complexity: O(m * n)
// Space Complexity: O(n)
// ==========================================================

class Solution {
public:
    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<int> prev(n + 1), curr(n + 1);

        for (int j = 0; j <= n; j++)
            prev[j] = j;

        for (int i = 1; i <= m; i++) {

            curr[0] = i;

            for (int j = 1; j <= n; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + min({curr[j - 1], prev[j], prev[j - 1]});
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
