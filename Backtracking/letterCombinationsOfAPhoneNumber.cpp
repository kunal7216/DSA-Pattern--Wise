// ============================================================================
// LeetCode 17 - Letter Combinations of a Phone Number
//
// Approach 1: Brute Force Backtracking (String Copy)
// Approach 2: Better Backtracking (Push & Pop)
// Approach 3: Iterative BFS (Level-by-Level Combination Building)
//
// Time Complexity Analysis:
// Let N = number of digits
// Let K = average letters per digit (3 or 4)
//
// Total combinations = O(4^N)
//
// ============================================================================



// ============================================================================
// APPROACH 1: Brute Force Backtracking (String Copy)
// ============================================================================
//
// Intuition:
// ------------
// At every digit, try every possible letter mapped to that digit.
//
// Example:
// digits = "23"
//
// 2 -> abc
// 3 -> def
//
//                  ""
//            /      |      \
//           a       b       c
//        / | \    / | \   / | \
//      ad ae af bd be bf cd ce cf
//
// Here, every recursive call creates a NEW string:
//
// curr + ch
//
// Therefore, many temporary strings are created.
//
// Time Complexity:
// O(4^N × N)
//
// Why?
// - There are approximately 4^N combinations.
// - Every stored string has length N.
//
// Space Complexity:
// O(N)
// (Recursion stack)
//
// ============================================================================

class Solution1 {
public:

    // Stores final answer
    vector<string> ans;

    // Phone keypad mapping
    vector<string> keypad = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    // Recursive function
    void backtrack(string &digits, int index, string current)
    {
        // Base Case:
        // One complete combination has been formed.
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }

        // Letters corresponding to current digit
        string letters = keypad[digits[index] - '0'];

        // Try every possible letter
        for(char ch : letters)
        {
            // Create a NEW string every recursion
            backtrack(digits, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};

        backtrack(digits, 0, "");

        return ans;
    }
};



// ============================================================================
// APPROACH 2: Better Backtracking (Push & Pop)
// ============================================================================
//
// Improvement:
// ------------
// Instead of creating a new string every recursive call,
// modify the SAME string.
//
// current.push_back(ch);
// recurse
// current.pop_back();
//
// This avoids unnecessary string copying.
//
// Example:
//
// current = ""
//
// push a
// current = "a"
//
// push d
// current = "ad"
//
// store answer
//
// pop d
// current = "a"
//
// push e
//
// ...
//
// Time Complexity:
// O(4^N × N)
//
// Space Complexity:
// O(N)
//
// Better than Approach 1 because:
// - No temporary strings are created.
// - Memory allocations are reduced.
//
// ============================================================================

class Solution2 {
public:

    vector<string> ans;

    vector<string> keypad = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string &current)
    {
        // Base Case
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }

        // Letters of current digit
        string letters = keypad[digits[index] - '0'];

        // Explore every choice
        for(char ch : letters)
        {
            // Choose
            current.push_back(ch);

            // Explore
            backtrack(digits, index + 1, current);

            // Undo (Backtrack)
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};

        string current;

        backtrack(digits, 0, current);

        return ans;
    }
};



// ============================================================================
// APPROACH 3: Iterative BFS (Optimal Iterative Solution)
// ============================================================================
//
// Intuition:
// ------------
// Instead of recursion, build answers level by level.
//
// Example:
//
// digits = "23"
//
// Initially:
//
// ans = [""]
//
// Process digit 2:
//
// ""
//  |
// abc
//
// ans =
// a
// b
// c
//
// ----------------------------
//
// Process digit 3:
//
// a -> ad ae af
// b -> bd be bf
// c -> cd ce cf
//
// Final:
//
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf
//
// Time Complexity:
// O(4^N × N)
//
// Space Complexity:
// O(4^N × N)
//
// Why?
// Because all combinations are stored.
//
// ============================================================================

class Solution3 {
public:

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};

        // Phone keypad mapping
        vector<string> keypad = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        // Start with one empty string
        vector<string> ans = {""};

        // Process every digit
        for(char digit : digits)
        {
            vector<string> nextLevel;

            // Letters corresponding to current digit
            string letters = keypad[digit - '0'];

            // Expand every existing combination
            for(string current : ans)
            {
                for(char ch : letters)
                {
                    nextLevel.push_back(current + ch);
                }
            }

            // Move to next level
            ans = nextLevel;
        }

        return ans;
    }
};


/*
==============================================================================
COMPLEXITY COMPARISON
==============================================================================

Approach                  Time Complexity      Space Complexity

1. Brute Force            O(4^N × N)          O(N)
2. Better Backtracking    O(4^N × N)          O(N)
3. Iterative BFS          O(4^N × N)          O(4^N × N)

==============================================================================
Which one should you use in interviews?
==============================================================================

✓ Preferred:
Approach 2 (Backtracking using Push & Pop)

Reason:
- Classical Backtracking solution
- Minimal extra memory
- No unnecessary string copies
- Most interviewers expect this solution

Approach 3 is also accepted and is easier to understand iteratively.

==============================================================================
