// decode ways
// leetcode: https://leetcode.com/problems/decode-ways/
// leetcode question id: 91

// ==============================
// Approach 1 : Pure Recursion
// Time Complexity : O(2^N)
// Space Complexity : O(N)
// ==============================

class Solution {
public:

    int solve(string &s, int i)
    {
        // Successfully decoded entire string
        if(i == s.size())
            return 1;

        // Cannot decode numbers starting with 0
        if(s[i]=='0')
            return 0;

        // Option 1 : Decode one character
        int ways = solve(s,i+1);

        // Option 2 : Decode two characters if valid
        if(i+1<s.size())
        {
            int num=(s[i]-'0')*10+(s[i+1]-'0');

            if(num>=10 && num<=26)
                ways += solve(s,i+2);
        }

        return ways;
    }

    int numDecodings(string s) {

        return solve(s,0);
    }
};

// ==============================
// Approach 2 : Memoization (Top Down DP)
// Time Complexity : O(N)
// Space Complexity : O(N)
// ==============================

class Solution {
public:

    // Recursive function that returns the number of ways
    // to decode the substring starting from index 'i'
    int solve(string &s, int i, vector<int> &dp)
    {
        // Base Case:
        // If we have processed the entire string,
        // we found one valid decoding.
        if(i == s.size())
            return 1;

        // If the current character is '0',
        // it cannot be decoded by itself.
        if(s[i] == '0')
            return 0;

        // If this state has already been computed,
        // return the stored answer.
        if(dp[i] != -1)
            return dp[i];

        // -------------------------------
        // Choice 1:
        // Decode only the current digit.
        //
        // Example:
        // "226"
        //  ^
        // Decode '2' -> solve remaining "26"
        // -------------------------------
        int ways = solve(s, i + 1, dp);

        // -------------------------------
        // Choice 2:
        // Decode two digits together.
        //
        // This is possible only if:
        // 1. There is a next digit.
        // 2. The formed number lies between 10 and 26.
        // -------------------------------
        if(i + 1 < s.size())
        {
            // Convert two characters into an integer.
            //
            // Example:
            // '2' and '6'
            // (2 * 10) + 6 = 26
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            // Valid two-digit letter?
            if(num >= 10 && num <= 26)
            {
                // Decode both digits together
                // and move two positions ahead.
                ways += solve(s, i + 2, dp);
            }
        }

        // Store the computed answer so that
        // if this index is reached again,
        // we don't recompute it.
        return dp[i] = ways;
    }

    int numDecodings(string s)
    {
        // dp[i] stores the number of ways
        // to decode the substring starting at index i.
        //
        // Initially all values are -1,
        // meaning "not computed yet".
        vector<int> dp(s.size(), -1);

        // Start decoding from index 0.
        return solve(s, 0, dp);
    }
};


// ==============================
// Approach 3 : Space Optimized DP
// Time Complexity : O(N)
// Space Complexity : O(1)
// ==============================

class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();

        // next1 = dp[i+1]
        // next2 = dp[i+2]

        int next1 = 1;
        int next2 = 0;

        // Process from right to left
        for(int i=n-1;i>=0;i--)
        {
            int curr=0;

            // Cannot decode if current digit is 0
            if(s[i]!='0')
            {
                // Decode one digit
                curr = next1;

                // Decode two digits if valid
                if(i+1<n)
                {
                    int num=(s[i]-'0')*10+(s[i+1]-'0');

                    if(num>=10 && num<=26)
                        curr += next2;
                }
            }

            // Shift DP states
            next2=next1;
            next1=curr;
        }

        return next1;
    }
};
