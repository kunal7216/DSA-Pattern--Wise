// Re-organize String
// leetcode: https://leetcode.com/problems/reorganize-string/

class Solution
{
public:
    string reorganizeString(string s)
    {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq_map;
        for (char c : s)
        {
            freq_map[c]++;
        }

        // Step 2: Max-heap to always get the character
        // with the highest remaining frequency
        priority_queue<pair<int, char>> max_heap;
        for (auto &[ch, freq] : freq_map)
        {
            max_heap.push({freq, ch});
        }

        string res;

        // Step 3: Pick two most frequent characters at a time
        // This avoids placing the same characters adjacent
        while (max_heap.size() >= 2)
        {
            auto [freq1, char1] = max_heap.top();
            max_heap.pop();

            auto [freq2, char2] = max_heap.top();
            max_heap.pop();

            // Append both characters
            res += char1;
            res += char2;

            // Decrease their frequencies and push back if still available
            if (--freq1 > 0)
                max_heap.push({freq1, char1});
            if (--freq2 > 0)
                max_heap.push({freq2, char2});
        }

        // Step 4: If one character remains
        if (!max_heap.empty())
        {
            auto [freq, ch] = max_heap.top();

            // If frequency > 1, reorganization is impossible
            if (freq > 1)
                return "";

            // Otherwise, append the last character
            res += ch;
        }

        return res;
    }
};
