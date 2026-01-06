// word break problem using memoization
// leetcode problem link: https://leetcode.com/problems/word-break/
// leetcode question id: 139

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        // Convert wordDict into a set for O(1) average lookup
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // Find the maximum length of any word in the dictionary
        int maxLen = 0;
        for (string &word : wordDict)
        {
            maxLen = max(maxLen, (int)word.length());
        }

        int n = s.length();

        // dp[i] = true if substring s[0..i-1] can be segmented
        vector<bool> dp(n + 1, false);

        // Base case: empty string is always valid
        dp[0] = true;

        // Try to build solution for substrings ending at i
        for (int i = 1; i <= n; i++)
        {

            // Only check substrings of length up to maxLen
            for (int j = i - 1; j >= max(0, i - maxLen); j--)
            {

                // If left part is valid AND right part exists in dictionary
                if (dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break; // No need to check further splits
                }
            }
        }

        // Final answer: can full string be segmented?
        return dp[n];
    }
};
