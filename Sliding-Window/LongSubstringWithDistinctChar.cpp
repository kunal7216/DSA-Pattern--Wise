// longest substring with at most k distinct characters

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0;                   // Left pointer of sliding window
        int maxLen = 0;              // Stores maximum valid window length
        int maxFreq = 0;             // Highest frequency of any character in window
        unordered_map<char, int> mp; // Frequency map of characters in window

        // Right pointer expands the window
        for (int r = 0; r < s.size(); r++)
        {

            // Add current character to the map
            mp[s[r]]++;

            // Update the maximum frequency in current window
            maxFreq = max(maxFreq, mp[s[r]]);

            /*
                If replacements needed > k
                window size - maxFreq > k
                then shrink the window from the left
            */
            while ((r - l + 1) - maxFreq > k)
            {
                mp[s[l]]--; // Remove left character from window
                l++;        // Move left pointer
            }

            // Update the maximum valid window length
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
