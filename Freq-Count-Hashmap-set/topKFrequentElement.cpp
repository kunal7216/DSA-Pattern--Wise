// top K frequent element
// Leetcode Problem Link: https://leetcode.com/problems/top-k-frequent-elements/



class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        // Step 1: Map to store frequency of each number
        unordered_map<int, int> counts;

        // Step 2: Min-heap where
        // pair.first  = frequency
        // pair.second = element
        // The smallest frequency stays at the top
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            min_heap;

        // Step 3: Count frequency of each element in nums
        for (auto i : nums)
        {
            counts[i]++;
        }

        // Step 4: Push elements into min-heap
        for (auto &i : counts)
        {

            // Push {frequency, element} into heap
            min_heap.push({i.second, i.first});

            // If heap size exceeds k, remove least frequent element
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }

        // Step 5: Extract top k frequent elements from heap
        vector<int> res;
        while (k--)
        {

            // Get element with highest frequency among remaining
            res.push_back(min_heap.top().second);

            // Remove it from heap
            min_heap.pop();
        }

        // Step 6: Return result
        return res;
    }
};

*************************************************************Brute Solution****************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int maxFreq = -1;
            int maxElement = -1;

            for (auto it : freq) {
                if (it.second > maxFreq) {
                    maxFreq = it.second;
                    maxElement = it.first;
                }
            }

            ans.push_back(maxElement);
            freq[maxElement] = -1;
        }

        return ans;
    }
};
*************************************************************Better Solution****************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> v;

        for (auto it : freq) {
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};
*************************************************************Optimal Solution****************************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int n = nums.size();

        vector<vector<int>> bucket(n + 1);

        for (auto it : freq) {
            int element = it.first;
            int count = it.second;

            bucket[count].push_back(element);
        }

        vector<int> ans;

        for (int i = n; i >= 1; i--) {
            for (int element : bucket[i]) {
                ans.push_back(element);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
