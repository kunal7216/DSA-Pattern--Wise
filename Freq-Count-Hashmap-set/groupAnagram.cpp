// Leetcode 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/


****************************************************************Brute Solution*************************************************************************************

class Solution {
public:
    bool isAnagram(string a, string b) {
        // If lengths are different, they cannot be anagrams
        if (a.length() != b.length()) {
            return false;
        }

        // Sort both strings
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // If sorted strings are same, they are anagrams
        return a == b;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        // visited[i] tells whether strs[i] is already grouped
        vector<bool> visited(n, false);

        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            // If current string is already grouped, skip it
            if (visited[i]) {
                continue;
            }

            vector<string> group;

            // Add current string to group
            group.push_back(strs[i]);
            visited[i] = true;

            // Compare current string with all remaining strings
            for (int j = i + 1; j < n; j++) {
                if (!visited[j] && isAnagram(strs[i], strs[j])) {
                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};
****************************************************************Better Solution*************************************************************************************

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map sorted string key to list of anagrams
        unordered_map<string, vector<string>> mp;

        for (string word : strs) {
            // Create key by sorting the word
            string key = word;
            sort(key.begin(), key.end());

            // All anagrams will have the same sorted key
            mp[key].push_back(word);
        }

        vector<vector<string>> result;

        // Convert map values into answer
        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
****************************************************************Optimal Solution*************************************************************************************


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key: frequency pattern of characters
        // Value: group of anagrams
        unordered_map<string, vector<string>> mp;

        for (string word : strs) {
            vector<int> freq(26, 0);

            // Count frequency of each character
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            // Create a unique key from frequency array
            string key = "";

            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(freq[i]);
            }

            // Same frequency key means same anagram group
            mp[key].push_back(word);
        }

        vector<vector<string>> result;

        // Collect all groups
        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
