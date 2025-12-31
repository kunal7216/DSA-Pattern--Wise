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
