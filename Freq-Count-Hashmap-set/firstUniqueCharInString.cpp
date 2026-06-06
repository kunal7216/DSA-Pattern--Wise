class Solution
{
public:
    int firstUniqChar(string s)
    {
        // HashMap to store frequency of each character
        unordered_map<char, int> freq;

        // Step 1: Count frequency of every character in the string
        for (char c : s)
        {
            freq[c]++; // Increment count for character c
        }

        // Step 2: Traverse the string again to find the first unique character
        for (int i = 0; i < s.size(); i++)
        {
            // If frequency of current character is exactly 1,
            // it is the first non-repeating character
            if (freq[s[i]] == 1)
            {
                return i; // Return its index
            }
        }

        // Step 3: If no unique character exists, return -1
        return -1;
    }
};

***************************************************************Brute Solution**************************************************************************************
    class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();

        // Check every character one by one
        for (int i = 0; i < n; i++) {
            int count = 0;

            // Count how many times s[i] appears in the whole string
            for (int j = 0; j < n; j++) {
                if (s[i] == s[j]) {
                    count++;
                }
            }

            // If this character appears only once,
            // then this is the first unique character
            if (count == 1) {
                return i;
            }
        }

        // No unique character found
        return -1;
    }
};
***************************************************************Better Solution**************************************************************************************
    class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Find the first character with frequency 1
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        // No unique character found
        return -1;
    }
};
***************************************************************Optimal Solution**************************************************************************************
    class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        // Step 1: Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Find first character whose frequency is 1
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        // Step 3: If no unique character exists
        return -1;
    }
};
    
