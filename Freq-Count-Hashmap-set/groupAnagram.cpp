// Leetcode 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/


// using sorting
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Hash map to group anagrams
        // Key   -> sorted version of the string
        // Value -> list of strings that are anagrams of each other
        unordered_map<string, vector<string>> ans;

        // Traverse each string in the input list
        for (string &s : strs)
        {
            // Create a copy of the current string
            string key = s;

            // Sort the copied string
            // All anagrams will result in the same sorted string
            sort(key.begin(), key.end());

            // Store the original string under its sorted key
            ans[key].push_back(s);
        }

        // Result vector to store grouped anagrams
        vector<vector<string>> result;

        // Extract all groups from the hash map
        for (auto &entry : ans)
        {
            // entry.second contains all anagrams for one key
            result.push_back(entry.second);
        }

        // Return the grouped anagrams
        return result;
    }
};


// using frequency count
class Solution
{
public:
    // Helper function to generate a unique frequency-based key for a string
    string getFrequencyString(const string &str)
    {
        // Array to store frequency of each character (a–z)
        vector<int> freq(26, 0);

        // Count occurrences of each character in the string
        for (char c : str)
        {
            freq[c - 'a']++;
        }

        // Build a frequency string as the key
        // Example: "aabcc" → "a2b1c2"
        string frequencyString;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                frequencyString += char('a' + i);      // character
                frequencyString += to_string(freq[i]); // its count
            }
        }
        return frequencyString;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Edge case: if input is empty, return empty result
        if (strs.size() == 0)
        {
            return {};
        }

        // Hash map to group anagrams
        // Key   -> frequency string (unique representation)
        // Value -> list of anagram strings
        unordered_map<string, vector<string>> frequencyStringsMap;

        // Process each string in the input
        for (string str : strs)
        {
            // Generate frequency-based key for current string
            string frequencyString = getFrequencyString(str);

            // Insert the string into the corresponding anagram group
            frequencyStringsMap[frequencyString].push_back(str);
        }

        // Vector to store the final grouped anagrams
        vector<vector<string>> result;

        // Collect all anagram groups from the map
        for (auto &entry : frequencyStringsMap)
        {
            result.push_back(entry.second);
        }

        // Return the grouped anagrams
        return result;
    }
};
