class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> list;    // Stores starting indices of anagrams
        int freqS[26] = {0}; // Frequency of current window in s
        int freqP[26] = {0}; // Frequency of characters in p

        // If s is smaller than p, no anagram is possible
        if (s.length() < p.length())
        {
            return list;
        }

        // Build frequency arrays for:
        // 1) First window of s (size = p.length())
        // 2) Pattern string p
        for (int i = 0; i < p.length(); i++)
        {
            freqS[s[i] - 'a']++; // Count characters in current window of s
            freqP[p[i] - 'a']++; // Count characters in p
        }

        int start = 0;        // Left pointer of sliding window
        int end = p.length(); // Right pointer of sliding window

        // Check if the first window itself is an anagram of p
        if (equal(freqS, freqS + 26, freqP))
        {
            list.push_back(start);
        }

        // Slide the window across the string s
        while (end < s.length())
        {

            // Remove the character leaving the window (left side)
            freqS[s[start] - 'a']--;

            // Add the new character entering the window (right side)
            freqS[s[end] - 'a']++;

            // If after sliding, the window matches p's frequency
            if (equal(freqS, freqS + 26, freqP))
            {
                list.push_back(start + 1); // New start index of the anagram
            }

            // Move the window forward
            start++;
            end++;
        }

        // Return all starting indices where anagrams were found
        return list;
    }
};


******************************************************************Brute Approach********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        // If p is longer than s, no substring of s can be an anagram of p
        if (m > n) return ans;

        // Sort p once because every anagram of p will have the same sorted form
        string sortedP = p;
        sort(sortedP.begin(), sortedP.end());

        // Check every substring of s having length equal to p
        for (int i = 0; i <= n - m; i++) {

            // Extract substring of length m starting from index i
            string current = s.substr(i, m);

            // Sort current substring
            // If current is an anagram of p, sorted current will equal sorted p
            sort(current.begin(), current.end());

            // If both sorted strings are equal, current substring is an anagram
            if (current == sortedP) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
*******************************************************************Better Appraoch*******************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        // If p is longer than s, no valid anagram substring exists
        if (m > n) return ans;

        // Frequency array for string p
        // Since only lowercase English letters are given, size 26 is enough
        vector<int> pFreq(26, 0);

        // Count frequency of every character in p
        for (char ch : p) {
            pFreq[ch - 'a']++;
        }

        // Check every substring of s having length m
        for (int i = 0; i <= n - m; i++) {

            // Frequency array for current window/substr
            vector<int> windowFreq(26, 0);

            // Count frequency of current substring s[i...i+m-1]
            for (int j = i; j < i + m; j++) {
                windowFreq[s[j] - 'a']++;
            }

            // If frequency arrays are equal, this substring is an anagram
            if (windowFreq == pFreq) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
********************************************************************Optimal Approach******************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        // If p is longer than s, no substring of s can match p
        if (m > n) return ans;

        // pFreq stores frequency of characters in p
        // windowFreq stores frequency of characters in current window of s
        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        // Step 1: Count frequency of characters in p
        for (char ch : p) {
            pFreq[ch - 'a']++;
        }

        // Step 2: Build frequency of the first window in s
        // Window size must be equal to p.length()
        for (int i = 0; i < m; i++) {
            windowFreq[s[i] - 'a']++;
        }

        // Step 3: Check if the first window is an anagram
        if (windowFreq == pFreq) {
            ans.push_back(0);
        }

        // Step 4: Slide the window from index m to n - 1
        for (int i = m; i < n; i++) {

            // Character entering the window from the right side
            char incomingChar = s[i];

            // Character leaving the window from the left side
            char outgoingChar = s[i - m];

            // Add incoming character to current window frequency
            windowFreq[incomingChar - 'a']++;

            // Remove outgoing character from current window frequency
            windowFreq[outgoingChar - 'a']--;

            // Current window starts at index i - m + 1
            int startIndex = i - m + 1;

            // If current window frequency matches p frequency,
            // then current window is an anagram of p
            if (windowFreq == pFreq) {
                ans.push_back(startIndex);
            }
        }

        return ans;
    }
};
