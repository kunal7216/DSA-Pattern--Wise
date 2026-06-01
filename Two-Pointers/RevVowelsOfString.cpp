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

****************************************************************************Brute Solution***********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);

        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        vector<char> vowels;

        // Step 1: Collect all vowels from the string
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }

        // Step 2: Replace vowels in reverse order
        int index = vowels.size() - 1;

        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[index];
                index--;
            }
        }

        return s;
    }
};
*******************************************************************************Better Solution********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);

        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        stack<char> st;

        // Step 1: Push all vowels into stack
        for (char ch : s) {
            if (isVowel(ch)) {
                st.push(ch);
            }
        }

        // Step 2: Replace vowels using stack top
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = st.top();
                st.pop();
            }
        }

        return s;
    }
};
***********************************************************************************Optimal Solution****************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);

        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // Move left pointer until it points to a vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            // Move right pointer until it points to a vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            // Now both left and right are vowels, so swap them
            swap(s[left], s[right]);

            // Move both pointers after swapping
            left++;
            right--;
        }

        return s;
    }
};
