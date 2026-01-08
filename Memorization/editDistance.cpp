// edit distance 
// leetcode 72
// leetcode problem link: https://leetcode.com/problems/edit-distance/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length(); // length of first word
        int n = word2.length(); // length of second word

        // dp[i][j] = minimum operations to convert
        // first i characters of word1 to first j characters of word2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Base case initialization
        // Convert word1[0..i] to empty string => i deletions
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;

        // Convert empty string to word2[0..j] => j insertions
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;

        // Fill the DP table
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                // If characters are same, no operation needed
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // Minimum of:
                    // 1. Replace (top-left)
                    // 2. Delete  (top)
                    // 3. Insert  (left)
                    dp[i][j] = 1 + min(
                                       dp[i - 1][j - 1], // replace
                                       min(dp[i - 1][j], // delete
                                           dp[i][j - 1]) // insert
                                   );
                }
            }
        }

        // Final answer
        return dp[m][n];
    }
};
