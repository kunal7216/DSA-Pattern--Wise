// Problem Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// this question is sovled based on frequency count hashmap and sliding window technique


class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {

        // If pattern length is greater than text length, no anagrams possible
        if (s1.size() > s2.size()) return {};

        // Vector to store starting indices of anagrams
        vector<int> q;

        // Frequency maps for pattern (mp1) and sliding window in text (mp2)
        map<char, int> mp1, mp2;

        // Initialize frequency of all lowercase letters to 0
        for (int i = 0; i < 26; i++) {
            mp1['a' + i] = 0;
            mp2['a' + i] = 0;
        }

        // Length of the pattern
        int len = s1.size();

        // Build frequency maps for:
        // mp1 → pattern string
        // mp2 → first window of text with size equal to pattern
        for (int i = 0; i < s1.size(); i++) {
            mp1[s1[i]]++;   // count character in pattern
            mp2[s2[i]]++;   // count character in current window
        }

        // If first window is an anagram, add index 0
        if (mp2 == mp1) q.push_back(0);

        // Slide the window over the text
        for (int i = len; i < s2.size(); i++) {

            // Add new character entering the window
            mp2[s2[i]]++;

            // Remove character leaving the window
            mp2[s2[i - len]]--;

            // If frequency maps match, an anagram is found
            if (mp2 == mp1) {
                q.push_back(i + 1 - len); // starting index of anagram
            }
        }

        // Return all starting indices of anagrams
        return q;
    }
};
