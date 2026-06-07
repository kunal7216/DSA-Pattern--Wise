// Top k frequent words in a list using a min-heap (priority queue).
// leetcode problem: https://leetcode.com/problems/top-k-frequent-words/

// Custom comparator class for priority_queue
class cmp
{
public:
    // This operator defines the ordering of elements in the heap
    // Each element is a pair: {frequency, word}
    bool operator()(pair<int, string> a, pair<int, string> b) const
    {

        // Case 1: If frequency of 'a' is smaller than frequency of 'b'
        // return true → 'a' has lower priority than 'b'
        // This ensures higher frequency words come first
        if (a.first < b.first)
            return true;

        // Case 2: If both words have the same frequency
        // compare words lexicographically
        // return true when 'a' is lexicographically greater
        // so that lexicographically smaller word has higher priority
        else if (a.first == b.first && a.second > b.second)
            return true;

        // Otherwise, 'a' has higher or equal priority than 'b'
        return false;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        // Step 1: Count frequency of each word using hashmap
        unordered_map<string, int> ump;
        for (auto &w : words)
        {
            ump[w]++; // Increment count of word w
        }

        // Step 2: Create a max-heap (priority_queue) using custom comparator
        // Heap elements are {frequency, word}
        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       cmp>
            pq;

        // Step 3: Push all word-frequency pairs into the heap
        for (auto &m : ump)
        {
            pq.push({m.second, m.first});
        }

        // Step 4: Extract top k frequent words from the heap
        vector<string> vec;
        while (k--)
        {
            // Top element has highest frequency
            // and lexicographically smallest word if tied
            vec.push_back(pq.top().second);
            pq.pop();
        }

        // Step 5: Return the result
        return vec;
    }
};

******************************************************************Brute Solution*************************************************************************


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string, int>> freq;

        for (int i = 0; i < words.size(); i++) {
            bool alreadyAdded = false;

            for (int j = 0; j < freq.size(); j++) {
                if (freq[j].first == words[i]) {
                    alreadyAdded = true;
                    break;
                }
            }

            if (alreadyAdded) continue;

            int count = 0;

            for (int j = 0; j < words.size(); j++) {
                if (words[j] == words[i]) {
                    count++;
                }
            }

            freq.push_back({words[i], count});
        }

        sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
******************************************************************Better Solution*************************************************************************


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (string word : words) {
            freq[word]++;
        }

        vector<string> uniqueWords;

        for (auto it : freq) {
            uniqueWords.push_back(it.first);
        }

        sort(uniqueWords.begin(), uniqueWords.end(), [&](string &a, string &b) {
            if (freq[a] == freq[b]) {
                return a < b;
            }
            return freq[a] > freq[b];
        });

        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(uniqueWords[i]);
        }

        return ans;
    }
};
******************************************************************optimal Solution*************************************************************************


class Solution {
public:
    struct Compare {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (string word : words) {
            freq[word]++;
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

        for (auto it : freq) {
            pq.push({it.first, it.second});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
