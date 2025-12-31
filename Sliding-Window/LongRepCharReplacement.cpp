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
