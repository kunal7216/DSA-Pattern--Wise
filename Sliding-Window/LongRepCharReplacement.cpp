class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();         // Length of the string
        int l = 0, r = 0;         // Left and right pointers of the window
        int maxlen = 0;           // Stores the maximum valid window length
        int maxf = 0;             // Frequency of the most common character in the window
        vector<int> count(26, 0); // Frequency count of characters A–Z in current window

        // Expand the window using the right pointer
        while (r < n)
        {

            // Include current character s[r] in the window
            count[s[r] - 'A']++;

            // Update the maximum frequency seen in the window
            maxf = max(maxf, count[s[r] - 'A']);

            /*
                Window size        = (r - l + 1)
                Characters to change = window size - maxf

                If characters to change > k,
                then this window is invalid and must be shrunk
            */
            if ((r - l + 1) - maxf > k)
            {
                // Remove the leftmost character from the window
                count[s[l] - 'A']--;
                l++; // Shrink the window from the left
            }

            // Update maximum valid window size
            maxlen = max(maxlen, r - l + 1);

            // Move the right pointer to expand the window
            r++;
        }

        // Return the length of the longest valid window
        return maxlen;
    }
};

****************************************************************Brute solution***************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;

        // Try every starting index
        for (int i = 0; i < n; i++) {

            // Try every ending index
            for (int j = i; j < n; j++) {

                vector<int> freq(26, 0);

                // Count frequency of characters in substring s[i...j]
                for (int x = i; x <= j; x++) {
                    freq[s[x] - 'A']++;
                }

                // Find the highest frequency character
                int maxFreq = 0;
                for (int c = 0; c < 26; c++) {
                    maxFreq = max(maxFreq, freq[c]);
                }

                int windowLength = j - i + 1;

                // Characters other than the most frequent one need replacement
                int replacementsNeeded = windowLength - maxFreq;

                if (replacementsNeeded <= k) {
                    ans = max(ans, windowLength);
                }
            }
        }

        return ans;
    }
};

****************************************************************Better Solution***************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;

        // Fix starting index
        for (int i = 0; i < n; i++) {

            vector<int> freq(26, 0);
            int maxFreq = 0;

            // Expand ending index
            for (int j = i; j < n; j++) {

                // Add current character to the current window
                freq[s[j] - 'A']++;

                // Update maximum frequency in this window
                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                int windowLength = j - i + 1;
                int replacementsNeeded = windowLength - maxFreq;

                if (replacementsNeeded <= k) {
                    ans = max(ans, windowLength);
                }
            }
        }

        return ans;
    }
};
************************************************************************Optimal solution***********************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character into the window
            freq[s[right] - 'A']++;

            // Maximum frequency of any character in the current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int windowLength = right - left + 1;

            // If more than k replacements are needed, shrink the window
            if (windowLength - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update longest valid window size
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
