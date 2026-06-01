class Solution {
    public:
        bool isPalindrome(string s) {
    
            // Initialize two pointers:
            // 'start' begins from the left (start of string)
            // 'end' begins from the right (end of string)
            int start = 0;
            int end = s.size() - 1;
    
            // Loop until the two pointers cross each other
            while (start <= end) {
    
                // If the left character is NOT alphanumeric,
                // skip it and move the start pointer forward
                if (!isalnum(s[start])) {
                    start++;
                    continue;
                }
    
                // If the right character is NOT alphanumeric,
                // skip it and move the end pointer backward
                if (!isalnum(s[end])) {
                    end--;
                    continue;
                }
    
                // Compare characters after converting both to lowercase
                // This ensures case-insensitive comparison
                if (tolower(s[start]) != tolower(s[end]))
                    return false;   // Not a palindrome
    
                // Move both pointers towards the center
                start++;
                end--;
            }
    
            // If all valid characters matched, the string is a palindrome
            return true;
        }
    };

**************************************************************************Brute Solution*****************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        // Build a cleaned string with only lowercase alphanumeric characters
        for (char ch : s) {
            if (isalnum(ch)) {
                cleaned += tolower(ch);
            }
        }

        // Create reversed version of cleaned string
        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());

        // If both are same, it is a palindrome
        return cleaned == reversed;
    }
};
*****************************************************************************Better Solution**************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        // Step 1: Store only lowercase alphanumeric characters
        for (char ch : s) {
            if (isalnum(ch)) {
                cleaned += tolower(ch);
            }
        }

        // Step 2: Check palindrome using two pointers
        int left = 0;
        int right = cleaned.size() - 1;

        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
**********************************************************************************Optimal Solution*********************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // Skip invalid characters from the left side
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip invalid characters from the right side
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare both characters in lowercase form
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Move both pointers inward
            left++;
            right--;
        }

        return true;
    }
};

    
