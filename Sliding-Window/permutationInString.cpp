class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        // If s1 is longer than s2, s2 cannot contain any permutation of s1
        if (s1.length() > s2.length())
        {
            return false;
        }

        // Frequency maps to store character counts
        // s1Count → frequency of characters in s1
        // s2Count → frequency of current window in s2
        unordered_map<char, int> s1Count;
        unordered_map<char, int> s2Count;

        // Build frequency maps for s1 and the first window of s2
        for (int i = 0; i < s1.length(); i++)
        {
            s1Count[s1[i]]++; // Count characters of s1
            s2Count[s2[i]]++; // Count characters of first window in s2
        }

        // If the first window itself is a permutation of s1
        if (s1Count == s2Count)
        {
            return true;
        }

        int left = 0; // Left pointer of sliding window

        // Slide the window over s2, one character at a time
        for (int right = s1.length(); right < s2.length(); right++)
        {

            // Include the new character on the right side of the window
            s2Count[s2[right]]++;

            // Remove the character going out from the left side of the window
            s2Count[s2[left]]--;

            // If frequency becomes zero, erase it to keep maps clean
            if (s2Count[s2[left]] == 0)
            {
                s2Count.erase(s2[left]);
            }

            // Move the left pointer forward
            left++;

            // Check if current window is a permutation of s1
            if (s1Count == s2Count)
            {
                return true;
            }
        }

        // No permutation of s1 was found in s2
        return false;
    }
};

