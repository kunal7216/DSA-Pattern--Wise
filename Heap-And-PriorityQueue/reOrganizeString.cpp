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

*****************************************************************Brute Solution********************************************************************************
    class Solution {
public:
    bool isValid(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                return false;
            }
        }
        return true;
    }

    string reorganizeString(string s) {
        sort(s.begin(), s.end());

        do {
            if (isValid(s)) {
                return s;
            }
        } while (next_permutation(s.begin(), s.end()));

        return "";
    }
};
*****************************************************************Better Solution********************************************************************************

    class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int maxFreq = 0;
        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        if (maxFreq > (n + 1) / 2) {
            return "";
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            int bestChar = -1;
            int bestFreq = 0;

            for (int c = 0; c < 26; c++) {
                if (freq[c] > bestFreq) {
                    char currentChar = 'a' + c;

                    if (ans.empty() || ans.back() != currentChar) {
                        bestFreq = freq[c];
                        bestChar = c;
                    }
                }
            }

            ans += char('a' + bestChar);
            freq[bestChar]--;
        }

        return ans;
    }
};
*****************************************************************Optimal Solution********************************************************************************

    class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int f : freq) {
            if (f > (n + 1) / 2) {
                return "";
            }
        }

        priority_queue<pair<int, char>> maxHeap;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], char('a' + i)});
            }
        }

        string ans = "";

        while (maxHeap.size() >= 2) {
            auto first = maxHeap.top();
            maxHeap.pop();

            auto second = maxHeap.top();
            maxHeap.pop();

            ans += first.second;
            ans += second.second;

            first.first--;
            second.first--;

            if (first.first > 0) {
                maxHeap.push(first);
            }

            if (second.first > 0) {
                maxHeap.push(second);
            }
        }

        if (!maxHeap.empty()) {
            ans += maxHeap.top().second;
        }

        return ans;
    }
};

