
// ============================================================================
// LeetCode 131 - Palindrome Partitioning
//
// Approach 1 : Brute Force (Generate Every Partition + Validate Later)
// Approach 2 : Better (Backtracking + Palindrome Check While Building)
// Approach 3 : Optimal (DP + Backtracking)
//
// ============================================================================



// ============================================================================
// APPROACH 1 : BRUTE FORCE
// Generate every possible partition of the string.
// Once a partition is complete, check whether every substring
// inside that partition is a palindrome.
//
// Time Complexity : O(N² × 2^N)
// Space Complexity: O(N)
// ============================================================================

class Solution1 {
public:

    vector<vector<string>> ans;

    // Check whether an entire string is palindrome
    bool isPalindrome(string &str) {

        int left = 0;
        int right = str.size() - 1;

        while (left < right) {

            if (str[left] != str[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    // Generate every possible partition
    void generatePartitions(int index,
                            string &s,
                            vector<string> &currentPartition) {

        // Entire string has been partitioned
        if (index == s.size()) {

            // Validate every substring
            for (string &part : currentPartition) {

                if (!isPalindrome(part))
                    return;
            }

            ans.push_back(currentPartition);
            return;
        }

        string currentSubstring = "";

        // Create every possible substring starting from index
        for (int end = index; end < s.size(); end++) {

            currentSubstring += s[end];

            currentPartition.push_back(currentSubstring);

            generatePartitions(end + 1, s, currentPartition);

            // Backtrack
            currentPartition.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> currentPartition;

        generatePartitions(0, s, currentPartition);

        return ans;
    }
};



// ============================================================================
// APPROACH 2 : BETTER (Backtracking)
//
// Instead of generating every partition and validating later,
// immediately check whether the current substring is palindrome.
//
// Invalid branches are pruned early.
//
// Time Complexity : O(N × 2^N)
// Space Complexity: O(N)
// ============================================================================

class Solution2 {
public:

    vector<vector<string>> ans;

    // Check whether substring s[left...right] is palindrome
    bool isPalindrome(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(int start,
                   string &s,
                   vector<string> &path) {

        // Entire string has been partitioned
        if (start == s.size()) {

            ans.push_back(path);
            return;
        }

        // Try every possible ending position
        for (int end = start; end < s.size(); end++) {

            // Only continue if current substring is palindrome
            if (isPalindrome(s, start, end)) {

                path.push_back(s.substr(start, end - start + 1));

                backtrack(end + 1, s, path);

                // Undo choice
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> path;

        backtrack(0, s, path);

        return ans;
    }
};



// ============================================================================
// APPROACH 3 : OPTIMAL (DP + Backtracking)
//
// Observation:
// Same substring is checked many times.
//
// Precompute every palindrome using DP.
//
// dp[i][j] = true
// if substring s[i...j] is palindrome.
//
// During backtracking,
// palindrome checking becomes O(1).
//
// Time Complexity : O(N² + N × 2^N)
// Space Complexity: O(N²)
// ============================================================================

class Solution {
public:

    vector<vector<string>> ans;

    // DP table
    vector<vector<bool>> dp;

    void backtrack(int start,
                   string &s,
                   vector<string> &path) {

        // One valid partition found
        if (start == s.size()) {

            ans.push_back(path);
            return;
        }

        // Try every ending position
        for (int end = start; end < s.size(); end++) {

            // O(1) palindrome lookup
            if (dp[start][end]) {

                path.push_back(s.substr(start, end - start + 1));

                backtrack(end + 1, s, path);

                // Undo choice
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();

        // Create DP table
        dp.assign(n, vector<bool>(n, false));

        // ----------------------------------------------------------
        // Build DP Table
        //
        // Length = 1
        // Every single character is palindrome.
        //
        // Length = 2
        // Two characters are palindrome
        // only if both are equal.
        //
        // Length > 2
        //
        // Ends should be equal
        // and inside substring should already be palindrome.
        // ----------------------------------------------------------

        for (int length = 1; length <= n; length++) {

            for (int start = 0; start + length - 1 < n; start++) {

                int end = start + length - 1;

                if (length == 1) {

                    dp[start][end] = true;
                }

                else if (length == 2) {

                    dp[start][end] = (s[start] == s[end]);
                }

                else {

                    dp[start][end] =
                        (s[start] == s[end]) &&
                        dp[start + 1][end - 1];
                }
            }
        }

        vector<string> path;

        backtrack(0, s, path);

        return ans;
    }
};

/*
==============================================================================
COMPLEXITY SUMMARY
==============================================================================

Approach 1 (Brute Force)
------------------------
Time Complexity  : O(N² × 2^N)
Space Complexity : O(N)

Reason:
- Generates every possible partition.
- After generating, validates every substring again.


Approach 2 (Better)
-------------------
Time Complexity  : O(N × 2^N)
Space Complexity : O(N)

Reason:
- Prunes invalid partitions immediately.
- Still repeats palindrome checks.


Approach 3 (Optimal)
--------------------
Time Complexity  : O(N² + N × 2^N)
Space Complexity : O(N²)

Reason:
- O(N²) DP preprocessing.
- Palindrome lookup becomes O(1).
- Backtracking only explores valid partitions.

==============================================================================
*/
