class Solution
{
public:
    string minWindow(string s, string t)
    {

        // If s is smaller than t, it is impossible to find a valid window
        if (s.length() < t.length())
        {
            return "";
        }

        // Map to store the frequency of characters required from string t
        unordered_map<char, int> charCount;
        for (char ch : t)
        {
            charCount[ch]++; // Count each character in t
        }

        int targetCharsRemaining = t.length(); // Total characters still needed
        int minWindow[2] = {0, INT_MAX};       // Stores best window [start, end]
        int startIndex = 0;                    // Left pointer of sliding window

        // Right pointer expands the window
        for (int endIndex = 0; endIndex < s.length(); endIndex++)
        {
            char ch = s[endIndex];

            // If current character is required and still needed
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0)
            {
                targetCharsRemaining--; // One required character found
            }

            // Decrease count for current character (even if not required)
            charCount[ch]--;

            // When all characters of t are included in the current window
            if (targetCharsRemaining == 0)
            {

                // Try to shrink the window from the left
                while (true)
                {
                    char charAtStart = s[startIndex];

                    // Stop shrinking if removing this character
                    // would make the window invalid
                    if (charCount.find(charAtStart) != charCount.end() &&
                        charCount[charAtStart] == 0)
                    {
                        break;
                    }

                    // Otherwise, remove the character from window
                    charCount[charAtStart]++;
                    startIndex++;
                }

                // Update the minimum window if the current one is smaller
                if (endIndex - startIndex < minWindow[1] - minWindow[0])
                {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                // Move left pointer forward to look for a new window
                charCount[s[startIndex]]++; // Put back the required character
                targetCharsRemaining++;     // One required character is now missing
                startIndex++;
            }
        }

        // If no valid window was found, return empty string
        return minWindow[1] >= s.length()
                   ? ""
                   : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};
