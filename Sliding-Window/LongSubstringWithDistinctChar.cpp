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



*******************************************************************Brute solution*************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();

        // Edge case: if string is empty or k is 0,
        // no valid non-empty substring can exist
        if (n == 0 || k == 0) {
            return 0;
        }

        int maxLength = 0;

        // Choose starting index of substring
        for (int start = 0; start < n; start++) {

            // Choose ending index of substring
            for (int end = start; end < n; end++) {

                unordered_set<char> distinctChars;

                // Count distinct characters in substring s[start...end]
                for (int i = start; i <= end; i++) {
                    distinctChars.insert(s[i]);
                }

                // If current substring has at most k distinct characters,
                // update maximum length
                if (distinctChars.size() <= k) {
                    int currentLength = end - start + 1;
                    maxLength = max(maxLength, currentLength);
                }
            }
        }

        return maxLength;
    }
};
**********************************************************************Better solution**********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();

        // Edge case
        if (n == 0 || k == 0) {
            return 0;
        }

        int maxLength = 0;

        // Fix the starting index of the substring
        for (int start = 0; start < n; start++) {

            unordered_map<char, int> freq;

            // Expand the ending index of the substring
            for (int end = start; end < n; end++) {

                // Add current character into frequency map
                freq[s[end]]++;

                // If distinct characters become more than k,
                // this substring is invalid.
                // Further expansion will not reduce distinct count,
                // so we can stop for this start index.
                if (freq.size() > k) {
                    break;
                }

                // Current substring s[start...end] is valid
                int currentLength = end - start + 1;
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};
*************************************************************************Optimal solution*******************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();

        // If string is empty or k is 0,
        // answer will be 0 because no non-empty valid substring exists
        if (n == 0 || k == 0) {
            return 0;
        }

        // This map stores frequency of characters
        // inside the current sliding window
        unordered_map<char, int> freq;

        // Left pointer of the sliding window
        int left = 0;

        // Stores the maximum valid substring length
        int maxLength = 0;

        // Right pointer expands the window one character at a time
        for (int right = 0; right < n; right++) {

            // Add current character into the window
            char rightChar = s[right];
            freq[rightChar]++;

            // If distinct characters become more than k,
            // shrink the window from the left side
            while (freq.size() > k) {

                // Character that is going to be removed from the left side
                char leftChar = s[left];

                // Reduce its frequency because it is leaving the window
                freq[leftChar]--;

                // If frequency becomes 0, that means this character
                // no longer exists in the current window
                if (freq[leftChar] == 0) {
                    freq.erase(leftChar);
                }

                // Move left pointer forward to shrink the window
                left++;
            }

            // At this point, the window is valid
            // because it contains at most k distinct characters
            int currentLength = right - left + 1;

            // Update the answer
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
