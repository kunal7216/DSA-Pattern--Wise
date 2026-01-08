// decode ways
// leetcode: https://leetcode.com/problems/decode-ways/
// leetcode question id: 91

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();

        // dp[i] = number of ways to decode substring of length i
        vector<int> dp(n + 1, 0);

        // Base cases
        dp[0] = 1;                     // Empty string
        dp[1] = (s[0] == '0') ? 0 : 1; // First character

        for (int i = 2; i <= n; i++)
        {

            // One digit number (last character)
            int oneDigit = stoi(s.substr(i - 1, 1));

            // Two digit number (last two characters)
            int twoDigits = stoi(s.substr(i - 2, 2));

            // If valid single digit (1–9)
            if (oneDigit >= 1)
            {
                dp[i] += dp[i - 1];
            }

            // If valid two digit (10–26)
            if (twoDigits >= 10 && twoDigits <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
