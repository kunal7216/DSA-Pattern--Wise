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
