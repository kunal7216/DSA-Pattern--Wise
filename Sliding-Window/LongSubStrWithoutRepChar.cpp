// code for the  longest subsdtring without repeating characters.

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();          // Length of the input string
        int maxLength = 0;           // Stores the maximum length found
        unordered_set<char> charSet; // Stores unique characters in current window
        int left = 0;                // Left pointer of the sliding window

        // Right pointer moves from start to end of the string
        for (int right = 0; right < n; right++)
        {

            // If current character is NOT already in the set
            // it means we can safely expand the window
            if (charSet.count(s[right]) == 0)
            {
                charSet.insert(s[right]);
                // Update the maximum length of substring found so far
                maxLength = max(maxLength, right - left + 1);
            }
            else
            {
                // If the character already exists in the set,
                // we need to shrink the window from the left
                // until the duplicate character is removed
                while (charSet.count(s[right]))
                {
                    charSet.erase(s[left]); // Remove leftmost character
                    left++;                 // Move left pointer forward
                }
                // Insert the current character after removing duplicates
                charSet.insert(s[right]);
            }
        }

        // Return the maximum length of substring without repeating characters
        return maxLength;
    }
};
