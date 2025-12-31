// last stone weight

// leetcode link: https://leetcode.com/problems/last-stone-weight/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        // Max-heap (priority_queue by default is max-heap)
        // It always gives the largest element on top
        priority_queue<int> pq;

        // Push all stone weights into the max-heap
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        // Continue until there is at most one stone left
        while (pq.size() > 1)
        {

            // Extract the heaviest stone
            int x = pq.top();
            pq.pop();

            // Extract the second heaviest stone
            int y = pq.top();
            pq.pop();

            // If the stones are not equal,
            // push the remaining weight back into the heap
            if (x > y)
                pq.push(x - y);
        }

        // If no stones remain, return 0
        // Otherwise, return the weight of the last remaining stone
        return pq.empty() ? 0 : pq.top();
    }
};
