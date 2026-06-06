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

**************************************************************Brute Solution******************************************************************************
    class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            int maxIndex1 = 0;

            for (int i = 1; i < stones.size(); i++) {
                if (stones[i] > stones[maxIndex1]) {
                    maxIndex1 = i;
                }
            }

            int first = stones[maxIndex1];
            stones.erase(stones.begin() + maxIndex1);

            int maxIndex2 = 0;

            for (int i = 1; i < stones.size(); i++) {
                if (stones[i] > stones[maxIndex2]) {
                    maxIndex2 = i;
                }
            }

            int second = stones[maxIndex2];
            stones.erase(stones.begin() + maxIndex2);

            if (first != second) {
                stones.push_back(first - second);
            }
        }

        if (stones.empty()) {
            return 0;
        }

        return stones[0];
    }
};
**************************************************************Better Solution******************************************************************************
    class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());

            int first = stones.back();
            stones.pop_back();

            int second = stones.back();
            stones.pop_back();

            if (first != second) {
                stones.push_back(first - second);
            }
        }

        if (stones.empty()) {
            return 0;
        }

        return stones[0];
    }
};
**************************************************************Optimal Solution******************************************************************************
    class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();

            int second = maxHeap.top();
            maxHeap.pop();

            if (first != second) {
                maxHeap.push(first - second);
            }
        }

        if (maxHeap.empty()) {
            return 0;
        }

        return maxHeap.top();
    }
};
