// word break problem using memoization
// leetcode problem link: https://leetcode.com/problems/word-break/
// leetcode question id: 139

// ============================================================================
// Approach 1: Brute Force (Recursion)
// ============================================================================
//
// Intuition:
// ------------
// Start from index 0 and try every possible substring.
// If the current substring exists in the dictionary,
// recursively check whether the remaining string can also
// be segmented.
//
// This explores every possible way to split the string.
//
// Time Complexity:
// ----------------
// O(2^N)
//
// Each position can branch into multiple recursive calls.
//
// Space Complexity:
// -----------------
// O(N)
//
// Maximum recursion depth can be N.
// ============================================================================

class Solution1 {
public:

    bool solve(int start, string &s, unordered_set<string> &dict) {

        // Base Case:
        // If we have reached the end of the string,
        // the entire string has been segmented successfully.
        if (start == s.size())
            return true;

        // Try every possible substring starting from 'start'
        for (int end = start; end < s.size(); end++) {

            // Current substring
            string word = s.substr(start, end - start + 1);

            // If current substring exists in dictionary
            if (dict.count(word)) {

                // Recursively check remaining string
                if (solve(end + 1, s, dict))
                    return true;
            }
        }

        // No valid segmentation found
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        // Store words in HashSet for O(1) lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return solve(0, s, dict);
    }
};



// ============================================================================
// Approach 2: Memoization (Top-Down Dynamic Programming)
// ============================================================================
//
// Improvement:
// ------------
// In brute force, the same starting index is solved many times.
//
// Example:
//
// solve(5)
// solve(5)
// solve(5)
//
// We store the answer for every starting index.
//
// dp[i] = Can substring starting from index i be segmented?
//
// -1 = Not computed
//  0 = False
//  1 = True
//
// Time Complexity:
// ----------------
// O(N^3)
//
// N states
// × N substring checks
// × O(N) substring creation
//
// Space Complexity:
// -----------------
// O(N)
// ============================================================================

class Solution2 {
public:

    vector<int> dp;

    bool solve(int start, string &s, unordered_set<string> &dict) {

        // Entire string segmented
        if (start == s.size())
            return true;

        // Already computed
        if (dp[start] != -1)
            return dp[start];

        // Try every possible substring
        for (int end = start; end < s.size(); end++) {

            string word = s.substr(start, end - start + 1);

            if (dict.count(word)) {

                // If remaining string can also be segmented
                if (solve(end + 1, s, dict))
                    return dp[start] = true;
            }
        }

        // No valid segmentation
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // Initialize DP with -1 (Not Computed)
        dp.assign(s.size(), -1);

        return solve(0, s, dict);
    }
};



// ============================================================================
// Approach 3: Bottom-Up Dynamic Programming (Optimal)
// ============================================================================
//
// Key Idea:
// ---------
//
// dp[i] = true
// means first i characters can be segmented.
//
// dp[0] = true
// because an empty string is always valid.
//
// Transition:
//
// For every position i,
// try every previous cut j.
//
// If:
//
// dp[j] == true
//
// AND
//
// substring(j, i-j) exists in dictionary
//
// then
//
// dp[i] = true
//
// Time Complexity:
// ----------------
// O(N^3)
//
// Outer Loop = N
// Inner Loop = N
// substring() = O(N)
//
// Space Complexity:
// -----------------
// O(N)
// ============================================================================

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {

        // HashSet for O(1) lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();

        // dp[i] -> Can first i characters be segmented?
        vector<bool> dp(n + 1, false);

        // Empty string is always valid
        dp[0] = true;

        // Check every prefix length
        for (int i = 1; i <= n; i++) {

            // Try every possible previous cut
            for (int j = 0; j < i; j++) {

                // If prefix before j is valid
                if (dp[j]) {

                    // Current substring
                    string word = s.substr(j, i - j);

                    // If substring exists in dictionary
                    if (dict.count(word)) {

                        dp[i] = true;

                        // No need to check further cuts
                        break;
                    }
                }
            }
        }

        // Answer for complete string
        return dp[n];
    }
};
