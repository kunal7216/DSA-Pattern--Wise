// Two Pointer Approach

// i is at 0th index;
// j is at last index

// while checking for i and j pointers if they are equal than just move the pointers.
// if they aren't equal there could be two cases i != j
// if we delete ith index character check for the i+1 to j are they a palindrome? if yes than the whole string is palindrome.
// case 2:
// skip jth index character and see if i to j - 1 are a palindrome or not




class Solution{
public:
    // Helper function to check if substring s[i..j] is a palindrome
    bool ispalindrome(string s, int i, int j)
    {

        // Use two pointers within the given range
        while (i < j)
        {

            // If characters at both ends match,
            // move inward
            if (s.at(i) == s.at(j))
            {
                i++;
                j--;
            }
            // If mismatch occurs, it is not a palindrome
            else
            {
                return false;
            }
        }

        // All characters matched
        return true;
    }

    // Main function to check if the string can be a palindrome
    // after deleting at most one character
    bool validPalindrome(string s)
    {

        // Two pointers for the full string
        int i = 0;
        int j = s.size() - 1;

        // Traverse towards the center
        while (i < j)
        {

            // If characters match, move both pointers
            if (s.at(i) == s.at(j))
            {
                i++;
                j--;
            }
            // If a mismatch occurs
            else
            {
                // Try two possibilities:
                // 1. Skip character at i (i+1, j)
                // 2. Skip character at j (i, j-1)
                // If either forms a palindrome, return true
                return ispalindrome(s, i + 1, j) ||
                       ispalindrome(s, i, j - 1);
            }
        }

        // If no more than one mismatch was found,
        // the string is a valid palindrome
        return true;
    }
};
