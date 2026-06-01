class Solution
{
public:
    string reverseWords(string s)
    {

        // Create a stringstream object to break the string into words
        // It automatically ignores extra spaces
        stringstream ss(s);

        string word;          // Stores one word at a time
        vector<string> words; // Stores all extracted words

        // Extract words from the string one by one
        while (ss >> word)
        {
            words.push_back(word); // Store each word in the vector
        }

        string res; // Result string

        // Traverse the words vector from the end to the beginning
        // This reverses the order of words
        for (int i = words.size() - 1; i >= 0; i--)
        {
            res += words[i]; // Append the current word

            // Add a space after each word except the last one
            if (i != 0)
            {
                res += " ";
            }
        }

        // Return the final string with words reversed
        return res;
    }
};


***********************************************************************Brute Solution***************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.length();

        // Step 1: Extract all words
        for (int i = 0; i < n; i++) {

            // Skip spaces
            if (s[i] == ' ') {
                continue;
            }

            string word = "";

            // Build one word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Store the word
            words.push_back(word);
        }

        // Step 2: Build answer in reverse word order
        string ans = "";

        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];

            // Add one space between words
            if (i != 0) {
                ans += " ";
            }
        }

        return ans;
    }
};
************************************************************************Better Solution**************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n - 1;
        string ans = "";

        while (i >= 0) {

            // Step 1: Skip spaces from right side
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            // If no word is left
            if (i < 0) {
                break;
            }

            // Step 2: Mark end of current word
            int end = i;

            // Move left until space is found
            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            int start = i + 1;

            // Step 3: Add space before adding next word
            if (!ans.empty()) {
                ans += " ";
            }

            // Step 4: Add current word
            ans += s.substr(start, end - start + 1);
        }

        return ans;
    }
};
******************************************************************************Optimal solution********************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        // Step 1: Remove extra spaces in-place
        int slow = 0;

        for (int fast = 0; fast < n; fast++) {

            // Ignore spaces
            if (s[fast] == ' ') {
                continue;
            }

            // Add one space before every word except the first word
            if (slow != 0) {
                s[slow] = ' ';
                slow++;
            }

            // Copy the current word
            while (fast < n && s[fast] != ' ') {
                s[slow] = s[fast];
                slow++;
                fast++;
            }
        }

        // Remove leftover characters
        s.resize(slow);

        // Step 2: Reverse the entire cleaned string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word
        int start = 0;
        int len = s.length();

        for (int end = 0; end <= len; end++) {

            // If space or end of string is found, reverse current word
            if (end == len || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};

