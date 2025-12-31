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
