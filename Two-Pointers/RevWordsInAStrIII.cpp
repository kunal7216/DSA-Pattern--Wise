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


**************************************************************************Brute Solution*************************************************************************
    
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";

        // Step 1: Split the string into words
        for (char ch : s) {
            if (ch == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += ch;
            }
        }

        // Push the last word
        words.push_back(word);

        // Step 2: Reverse every word
        for (int i = 0; i < words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
        }

        // Step 3: Join all words with spaces
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];

            // Do not add space after the last word
            if (i != words.size() - 1) {
                ans += ' ';
            }
        }

        return ans;
    }
};
*****************************************************************************Better Solution**********************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                // Reverse the current word
                reverse(word.begin(), word.end());

                // Add reversed word to answer
                ans += word;
                ans += ' ';

                // Clear word for the next word
                word = "";
            } else {
                word += s[i];
            }
        }

        // Reverse and add the last word
        reverse(word.begin(), word.end());
        ans += word;

        return ans;
    }
};
*******************************************************************************Optimal Solution********************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;

        for (int i = 0; i <= n; i++) {
            // A word ends when we find a space or reach the end of string
            if (i == n || s[i] == ' ') {
                int left = start;
                int right = i - 1;

                // Reverse the current word using two pointers
                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }

                // Move start to the first character of the next word
                start = i + 1;
            }
        }

        return s;
    }
};

