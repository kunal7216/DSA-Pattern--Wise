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
*************************************************************************Brute Solution*********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string temp) {
        int left = 0;
        int right = temp.size() - 1;

        while (left < right) {
            if (temp[left] != temp[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();

        // Case 1: already palindrome
        if (isPalindrome(s)) {
            return true;
        }

        // Case 2: delete each character one by one
        for (int i = 0; i < n; i++) {
            string temp = "";

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    temp += s[j];
                }
            }

            if (isPalindrome(temp)) {
                return true;
            }
        }

        return false;
    }
};
****************************************************************************Bettter Solution******************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindromeAfterSkipping(string &s, int skipIndex) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Skip the deleted character from left side
            if (left == skipIndex) {
                left++;
                continue;
            }

            // Skip the deleted character from right side
            if (right == skipIndex) {
                right--;
                continue;
            }

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();

        // Case 1: no deletion
        if (isPalindromeAfterSkipping(s, -1)) {
            return true;
        }

        // Case 2: skip every index one by one
        for (int i = 0; i < n; i++) {
            if (isPalindromeAfterSkipping(s, i)) {
                return true;
            }
        }

        return false;
    }
};
********************************************************************************Optimal Solution**************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Checks whether s[left...right] is a palindrome
    bool isPalindromeRange(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Characters match, continue normal palindrome check
            if (s[left] == s[right]) {
                left++;
                right--;
            } 
            else {
                // First mismatch found.
                // We can delete either the left character or the right character.

                bool skipLeft = isPalindromeRange(s, left + 1, right);
                bool skipRight = isPalindromeRange(s, left, right - 1);

                return skipLeft || skipRight;
            }
        }

        // No mismatch found, already palindrome
        return true;
    }
};
