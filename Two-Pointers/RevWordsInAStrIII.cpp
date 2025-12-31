// reverse words in a string III

class Solution
{
public:
    // Function to reverse each word in the string individually
    // Words are separated by spaces
    string reverseWords(string &s)
    {

        int i = 0;
        // 'i' marks the starting index of the current word

        for (int j = 0; j < s.size(); ++j)
        {
            // 'j' scans the string character by character

            if (s[j] == ' ')
            {
                // When a space is found, it means the current word ends at index j-1

                // Reverse the current word from index i to j-1
                reverse(s.begin() + i, s.begin() + j);

                // Move 'i' to the start of the next word (after the space)
                i = j + 1;
            }
        }

        // After the loop, the last word will not be reversed
        // because it does not end with a space
        // So we reverse it explicitly
        reverse(s.begin() + i, s.end());

        // Return the modified string
        return s;
    }
};
