// using hashmap

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // Step 1: If lengths are different, they cannot be anagrams
        if (s.length() != t.length())
        {
            return false;
        }

        // Step 2: Create a hashmap to store frequency of characters in string s
        unordered_map<char, int> counter;

        // Step 3: Count frequency of each character in string s
        for (char ch : s)
        {
            counter[ch] = counter[ch] + 1; // Increment count for character 'ch'
        }

        // Step 4: Traverse string t and reduce the frequency from the map
        for (char ch : t)
        {
            // If character is not found in map or count is 0, strings are not anagrams
            if (counter.find(ch) == counter.end() || counter[ch] == 0)
            {
                return false;
            }
            counter[ch] = counter[ch] - 1; // Decrement count for character 'ch'
        }

        // Step 5: All character counts matched, strings are anagrams
        return true;
    }
};




// using freq array
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // Step 1: If lengths are different, they cannot be anagrams
        if (s.length() != t.length())
        {
            return false;
        }

        // Step 2: Create an array of size 26 to store frequency of lowercase letters
        vector<int> count(26, 0); // Initialize all counts to 0

        // Step 3: Count frequency of each character in string s
        for (char c : s)
        {
            count[c - 'a'] += 1; // 'a' maps to index 0, 'b' -> 1, ..., 'z' -> 25
        }

        // Step 4: Traverse string t and decrement the frequency
        for (char c : t)
        {
            // If count is already 0, that means t has an extra character not in s
            if (count[c - 'a'] == 0)
            {
                return false;
            }
            count[c - 'a'] -= 1; // Reduce the count for this character
        }

        // Step 5: All counts matched perfectly, strings are anagrams
        return true;
    }
};

**************************************************************Brute Solution*****************************************************************************************
    class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        int n = s.length();

        // This array tells whether character at index j of t is already used or not
        vector<bool> used(n, false);

        // Try to match every character of s with some unused character of t
        for (int i = 0; i < n; i++) {
            bool found = false;

            for (int j = 0; j < n; j++) {
                // If t[j] is not used and matches s[i]
                if (!used[j] && s[i] == t[j]) {
                    used[j] = true;
                    found = true;
                    break;
                }
            }

            // If current character of s is not found in t
            if (!found) {
                return false;
            }
        }

        return true;
    }
};
**************************************************************Better Solution*****************************************************************************************
    class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // If sorted strings are equal, they are anagrams
        return s == t;
    }
};
**************************************************************Optimal Solution*****************************************************************************************
    class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // There are 26 lowercase English letters
        vector<int> freq(26, 0);

        // Increase count for characters in s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Decrease count for characters in t
        for (char ch : t) {
            freq[ch - 'a']--;
        }

        // If any count is not zero, strings are not anagrams
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};

