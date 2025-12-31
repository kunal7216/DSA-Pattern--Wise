// Reverse vowels in a given string using the two pointers technique.

class Solution
{
public:
    // Helper function to check whether a character is a vowel
    bool isVowel(char a)
    {

        // Check for lowercase and uppercase vowels
        // If 'a' matches any vowel, return true
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||
            a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
            return true;

        // Otherwise, it is not a vowel
        return false;
    }

    // Function to reverse only the vowels in the string
    string reverseVowels(string s)
    {
        int n = s.size();

        // Two pointers:
        // start -> beginning of the string
        // end   -> end of the string
        int start = 0, end = n - 1;

        // Continue until the two pointers cross
        while (start < end)
        {

            // Case 1: Both characters are vowels
            // Swap them and move both pointers inward
            if (isVowel(s[start]) && isVowel(s[end]))
                swap(s[start++], s[end--]);

            // Case 2: Left character is NOT a vowel
            // Move the start pointer to the right
            else if (!isVowel(s[start]))
                start++;

            // Case 3: Right character is NOT a vowel
            // Move the end pointer to the left
            else
                end--;
        }

        // Return the string with vowels reversed
        return s;
    }
};
