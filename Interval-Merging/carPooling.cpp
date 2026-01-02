// car pooling 
// leetcode problem link: https://leetcode.com/problems/car-pooling/

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {

        // Min-heap based on location (time)
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            heap;

        // Create events
        for (int i = 0; i < trips.size(); i++)
        {
            // Pick up passengers at start location
            heap.push({trips[i][1], trips[i][0]});

            // Drop off passengers at end location
            heap.push({trips[i][2], -trips[i][0]});
        }

        int onboard = 0;

        // Process events in increasing order of location
        while (!heap.empty())
        {
            onboard += heap.top().second;
            heap.pop();

            if (onboard > capacity)
                return false;
        }

        return true;
    }
};
