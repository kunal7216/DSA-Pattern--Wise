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
